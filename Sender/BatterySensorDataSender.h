#include "printBatterySensorValue.h"

void displayBatterySensorValueList(batterySensorValue sensorValue,printSensorDataInterface &printSensorDataObject)
{
    for(int sensorValueIndex = 0; sensorValueIndex < READING_COUNT; sensorValueIndex++)
    {
       std::string formattedSensorValue=printSensorDataObject.sensorValueDisplayFormatter(sensorValue.stateOfChargeSensorValueList.at(sensorValueIndex),sensorValue.temperatureSensorValueList.at(sensorValueIndex));
       printSensorDataObject.printDataOnconsole(formattedSensorValue);
    }
}

bool sendBatteryParameterValues(printSensorDataInterface &printSensorDataObject)
{
  batterySensorValue batterySensorReadings=getBatteryParamterValuesFromSensor();
  if(batterySensorReadings.stateOfChargeSensorValueList.empty() || batterySensorReadings.temperatureSensorValueList.empty()) 
  {
    return false;
  }
  displayBatterySensorValueList(batterySensorReadings,printSensorDataObject);
  return true;
}
