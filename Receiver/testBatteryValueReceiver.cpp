#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"
#include "Receiver.cpp"
#include <iostream>

TEST_CASE("Fetches data from a console, checks the conditions and writes in the csv file") {
  bool expectedOutput = true;
  REQUIRE(readFromConsole() == expectedOutput);
}

TEST_CASE("Test to separate the data ") {
  std::string inputData = "25,50"; 
  receivedSOCData.clear();
  receivedTempData.clear();
  separateData(inputData);

  REQUIRE(receivedSOCData.at(0)== 25);
  REQUIRE(receivedTempData.at(0)== 50);
  
  std::string inputData1 = "30,-60";
  separateData(inputData1);
  REQUIRE(receivedSOCData.at(1)== 30);
  REQUIRE(receivedTempData.at(1)== -60);
}

TEST_CASE("Test Minimum Values ") {
  REQUIRE(getMinValue(0,-1) == -1);
  REQUIRE(getMinValue(-1,1) == -1);
  REQUIRE(getMinValue(0,0) == 0);
  REQUIRE(getMinValue(-1,-5) == 0);
  REQUIRE(getMinValue(5, 10) == 0);
}

TEST_CASE("Test Maximum Values ") {
  REQUIRE(getMaxValue(0,-1) == 0);
  REQUIRE(getMaxValue(-1,1) == 1);
  REQUIRE(getMaxValue(0,0) == 0);
  REQUIRE(getMaxValue(-1,-5) == -1);
  REQUIRE(getMaxValue(5, 10) == 10);
}

TEST_CASE("Tests Average with positive values") {
  const std::vector<int> receivedInputData = {1,2,3,4,5};
  int storedLastFourValues = 0;
  REQUIRE( averageData(receivedInputData, storedLastFourValues)  == 3);
  REQUIRE(averageDataOneByone(1,storedLastFourValues, 26) == 8);

  const std::vector<int> receivedInputData1 = {49,74,23,74,27};
  int storedLastFourValues1 = 0;
  REQUIRE( averageData(receivedInputData1, storedLastFourValues1)  == 49);
  REQUIRE(averageDataOneByone(49,storedLastFourValues1, 69) == 53);
  REQUIRE(averageDataOneByone(74,storedLastFourValues1, 67) == 52);   
}

TEST_CASE("Average Data OneByone with 0") {
  int lastStoredAverageValue0= 0;
  REQUIRE(averageDataOneByone(0,lastStoredAverageValue0, 0) == 0);
  const std::vector<int> receivedInputData = {0,0,0,0,0};
  int storedLastFourValues = 0;
  REQUIRE( averageData(receivedInputData, storedLastFourValues)  == 0);
  REQUIRE(averageDataOneByone(0,storedLastFourValues, 0) == 0);
}

TEST_CASE("Tests Average with negative values") {
  const std::vector<int> receivedInputData = {-1,-2,-3,-4,-5};
  int storedLastFourValues = 0;
  REQUIRE( averageData(receivedInputData, storedLastFourValues)  == -3);
  REQUIRE(averageDataOneByone(1,storedLastFourValues, -26) == -8);

  const std::vector<int> receivedInputData1 = {-49,-74,-23,-74,-27};
  int storedLastFourValues1 = 0;
  REQUIRE( averageData(receivedInputData1, storedLastFourValues1)  == -49);
  REQUIRE(averageDataOneByone(-49,storedLastFourValues1, -69) == -53);
  REQUIRE(averageDataOneByone(-74,storedLastFourValues1, -67) == -52);   
}
