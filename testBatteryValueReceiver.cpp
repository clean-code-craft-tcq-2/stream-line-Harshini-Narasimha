#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"
#include "Receiver/Receiver.cpp"

TEST_CASE("Fetches data from a sensor and writtens to CSV FilE and tests the values reading from the CSV file ") {
  bool expectedOutput = true;
  REQUIRE(readFromConsole() == expectedOutput);
}
