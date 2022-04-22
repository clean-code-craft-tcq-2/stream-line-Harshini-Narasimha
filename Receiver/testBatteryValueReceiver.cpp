#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"
#include "Receiver.cpp"

TEST_CASE("Fetches data from a sensor and writtens to CSV FilE and tests the values reading from the CSV file ") {
  bool expectedOutput = true;
  REQUIRE(readFromConsole() == expectedOutput);
}

TEST_CASE("Test Average   ") {
  int lastStoredAverageValue= 100;
  REQUIRE(averageDataOneByone(20,lastStoredAverageValue, 45) == 25);

  const std::vector<int> receivedInputData = {1,2,3,4,5};
  int storedLastFourValues = 0;
  REQUIRE( averageData(receivedInputData, storedLastFourValues)  == 3);
  REQUIRE(averageDataOneByone(1,storedLastFourValues, 26) == 7);
}

TEST_CASE("Average Data OneByone with 0") {
  int lastStoredAverageValue0= 0;
  REQUIRE(averageDataOneByone(0,lastStoredAverageValue0, 0) == 0);
   const std::vector<int> receivedInputData = {0,0,0,0,0};
  int storedLastFourValues = 0;
  REQUIRE( averageData(receivedInputData, storedLastFourValues)  == 0);
  REQUIRE(averageDataOneByone(0,storedLastFourValues, 0) == 0);
}
