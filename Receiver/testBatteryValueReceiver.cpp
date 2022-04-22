#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"
#include "Receiver.cpp"

TEST_CASE("Fetches data from a sensor and writtens to CSV FilE and tests the values reading from the CSV file ") {
  bool expectedOutput = true;
  REQUIRE(readFromConsole() == expectedOutput);
}


TEST_CASE("Average Data OneByone ") {
  int lastStoredAverageValue= 100
  REQUIRE(averageDataOneByone(20,lastStoredAverageValue, 45) == 25);
}
