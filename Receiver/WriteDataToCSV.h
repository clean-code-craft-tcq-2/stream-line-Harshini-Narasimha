#ifndef _WRITEDATATOCSV_H_
#define _WRITEDATATOCSV_H_
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
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
  std::string printBMSReceiverData(int count, int minimumSocValue, int maximumSocValue, int socAverage, int minimumTempValue, int maximumTempValue, int TempAverage) 
  {
    ostringstream oss;
    auto cout_buff = cout.rdbuf(oss.rdbuf());
    cout << count << "," << minimumSocValue << "," << maximumSocValue << "," << socAverage << "," << minimumTempValue << "," << maximumTempValue << "," << TempAverage << "\n";    cout.rdbuf(cout_buff);
    std::string formattedString = oss.str();
    
    BmsReceiverDataFile << count << "," << minimumSocValue << "," << maximumSocValue << "," << socAverage << "," << minimumTempValue << "," << maximumTempValue << "," << TempAverage << "\n";
    return formattedString;
   }
};
#endif
