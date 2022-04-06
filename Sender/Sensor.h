#pragma once
#include <iostream>
using namespace std;
#include <vector>

#define MIN_SOC 20
#define MAX_SOC 80
#define MIN_TEMP -20
#define MAX_TEMP 60
#define READING_COUNT 100

struct batterySensorValue{
    vector<unsigned int> stateOfChargeSensorValueList;
    vector<signed int> temperatureSensorValueList;
};

template<typename T>
vector<T> generateRandomSensorValues(T minValue, T maxValue)
{
  vector<T> sensorValueList;
  for(int sensorValueItr = 0; sensorValueItr < READING_COUNT; sensorValueItr++)
  {
    T randSensorValue = rand()%(maxValue-minValue + 1) + minValue;
    sensorValueList.push_back(randSensorValue);
  }
  return sensorValueList;
}

batterySensorValue getBatteryParamterValuesFromSensor()
{
    batterySensorValue batterySensorReadings;
    batterySensorReadings.stateOfChargeSensorValueList = generateRandomSensorValues<unsigned int>(MIN_SOC, MAX_SOC);
    batterySensorReadings.temperatureSensorValueList = generateRandomSensorValues<signed int>(MIN_TEMP, MAX_TEMP);
    return batterySensorReadings;
}

