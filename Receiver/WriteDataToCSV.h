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
        BmsReceiverDataFile.open("BmsReceiverData.csv", std::ios::out | std::ios::trunc);
        BmsReceiverDataFile << "count, Soc Maximum, SOC Minimum, Temperature Maximum, Temperature Minimum, Temperature Soc Average , Soc Average, \n";
    }

    ~WriteDataToCSV()
    {
        BmsReceiverDataFile.flush();
        BmsReceiverDataFile.close();
    }

    void printBMSReceiverData(int count, int minimumSocValue, int maximumSocValue, int socAverage, int minimumTempValue, int maximumTempValue, int TempAverage)
    {
        std::cout << count << "," << minimumSocValue << "," << maximumSocValue << "," << socAverage << "," << minimumTempValue << "," << maximumTempValue << "," << TempAverage << "\n";
        BmsReceiverDataFile << count << "," << minimumSocValue << "," << maximumSocValue << "," << socAverage << "," << minimumTempValue << "," << maximumTempValue << "," << TempAverage << "\n";
    }
};
#endif