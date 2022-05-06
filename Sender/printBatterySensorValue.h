#include <iostream>
#include "Sensor.h"

class printSensorDataInterface
{
public:
     virtual void printDataOnconsole(std::string text)=0;
     virtual std::string sensorValueDisplayFormatter(unsigned int SOCValue,signed int tempValue)=0;
};

class printSensorData: public printSensorDataInterface
{
   public:
       void printDataOnconsole(std::string text)
       {
    	   std::cout<<text<<std::endl;
       }

       std::string sensorValueDisplayFormatter(unsigned int SOCValue,signed int tempValue)
       {
    	   std::string formattedSensorValues;
    	   formattedSensorValues = std::to_string(SOCValue) + "," + std::to_string(tempValue);
   	   return formattedSensorValues;
       }
};

class mockPrintSensorData: public printSensorDataInterface
{
  public:
       int printCounter=0, formatCounter=0;
       void printDataOnconsole(std::string /*text*/)
       {
          printCounter++;
       }
       std::string sensorValueDisplayFormatter(unsigned int /*SOCValue*/,signed int /*tempValue*/)
       {
          formatCounter++;       
     	  return "";     
       }
};
