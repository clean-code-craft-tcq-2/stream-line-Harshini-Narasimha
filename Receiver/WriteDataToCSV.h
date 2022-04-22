#ifndef _WRITEDATATOCSV_H_
#define _WRITEDATATOCSV_H_
#include <iostream>
#include <string>
#include <fstream>

class WriteDataToCSV
{
private:
    std::ofstream BmsReceiverDataFile;

public:
    WriteDataToCSV()
    {
        BmsReceiverDataFile.open("BmsReceiverProcessedData.csv", std::ios::out | std::ios::trunc);
        BmsReceiverDataFile << "count, Soc Maximum, SOC Minimum, Temperature Maximum, Temperature Minimum, Temperature Soc Average , Soc Average, \n";
    }

    ~WriteDataToCSV()
    {
        BmsReceiverDataFile.flush();
        BmsReceiverDataFile.close();
    }
   void printBMSReceiverData(std::string formattedString) 
   {  
       BmsReceiverDataFile <<formattedString<< "\n";
       std::cout<<formattedString;
   }
};
#endif
