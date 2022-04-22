#include "WriteDataToCSV.h"
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>

std::string receivedInput;
std::string seperatorDelimeter = ",";
std::string stopingDelimeter = "=";
std::vector<int> receivedSOCData;
std::vector<int> receivedTempData;
int count = 0;
const int NUMBEROFVALUES = 5;
int maxSocValue = INT_MIN, minSocValue = INT_MAX;
int maxTempValue = INT_MIN, minTempValue = INT_MAX;
int lastReceivedSocData = 0, lastReceivedTempData = 0;
int totalOfLastSocValues = 0, totalOfLastTempValues = 0;
WriteDataToCSV writeData;

template <typename Tmax> Tmax getMaxValue(Tmax lastReceivedData, Tmax currentMaxvalue) {
    return (lastReceivedData > currentMaxvalue) ? lastReceivedData : currentMaxvalue;
}
template <typename Tmin> Tmin getMinValue(Tmin lastReceivedData, Tmin currentMinvalue) {
    return (lastReceivedData < currentMinvalue) ? lastReceivedData : currentMinvalue;
}
void separateData(std::string receivedInput) {
    int pos = receivedInput.find(seperatorDelimeter);
    std::stringstream firstData(receivedInput.substr(0, pos));
    std::stringstream secondData(receivedInput.substr(pos + 1, receivedInput.length() - 1));
    firstData >> lastReceivedSocData;
    secondData >> lastReceivedTempData;
    receivedSOCData.push_back(lastReceivedSocData);
    receivedTempData.push_back(lastReceivedTempData);
}
int averageData(const std::vector<int> receivedInputData, int &storedTotalValues) {
    try {    
        storedTotalValues = std::accumulate(receivedInputData.begin(), receivedInputData.end(), 0L);
    }
    catch (const std::out_of_range &ex) {
        std::cout << "out_of_range Exception Caught :: " << ex.what() << std::endl;
    }
    return (storedTotalValues / NUMBEROFVALUES);
}
int averageDataOneByone(int startingValue, int &storedTotalValues, int lastReceivedData) {
    storedTotalValues -= startingValue;
    storedTotalValues += lastReceivedData;
    return (storedTotalValues / NUMBEROFVALUES);
}
std::string formatPrintData(int count, int minimumSocValue, int maximumSocValue, int socAverage, int minimumTempValue, int maximumTempValue, int TempAverage) {
    std::ostringstream os;
    auto cout_buff = std::cout.rdbuf(os.rdbuf());
    std::cout << count << "," << minimumSocValue << "," << maximumSocValue << "," << socAverage << "," << minimumTempValue << "," << maximumTempValue << "," << TempAverage << "\n";    
    std::cout.rdbuf(cout_buff);
    std::string formattedString = os.str();
    return formattedString;
}
void calculateSensorValues() {
    int socAverage = 0, TempAverage = 0;
    minSocValue = getMinValue<int>(lastReceivedSocData, minSocValue);
    maxSocValue = getMaxValue<int>(lastReceivedSocData, maxSocValue);
    minTempValue = getMinValue<int>(lastReceivedTempData, minTempValue);
    maxTempValue = getMaxValue<int>(lastReceivedTempData, maxTempValue);    
    if (count == NUMBEROFVALUES) {
        socAverage = averageData(receivedSOCData, totalOfLastSocValues);
        TempAverage = averageData(receivedTempData, totalOfLastTempValues);
        std::string formattedString = formatPrintData(count, minSocValue, maxSocValue, socAverage, minTempValue, maxTempValue, TempAverage);
        writeData.printBMSReceiverData(formattedString);
    }
    else if (count > NUMBEROFVALUES) {
        socAverage = averageDataOneByone(receivedSOCData.at(count - NUMBEROFVALUES), totalOfLastSocValues, lastReceivedSocData);
        TempAverage = averageDataOneByone(receivedTempData.at(count - NUMBEROFVALUES), totalOfLastTempValues, lastReceivedTempData);
        std::string formattedString = formatPrintData(count, minSocValue, maxSocValue, socAverage, minTempValue, maxTempValue, TempAverage);
        writeData.printBMSReceiverData(formattedString);
    }
}
bool readFromConsole() {
    while (std::getline(std::cin, receivedInput)) {
        count++;
        if (receivedInput.find(stopingDelimeter) != std::string::npos) {
            break;
        }
        else {
            separateData(receivedInput);
            calculateSensorValues();
        }
    }
    return true;
}
