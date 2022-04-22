#define CATCH_CONFIG_MAIN
#include "Sender/test/catch.hpp"
#include "Sender/BatterySensorDataSender.h"

// SCENARIO("Test whether the battery sensor data values are generated properly")
// {
//     GIVEN("The battery parameters contain SOC and Temperature Sensor. The SOC value should be in range 20 to 80, temperature value should be in range -20 to 60. And the total count of values from each sensor is 100 ")
//     {
//         WHEN("The battery sensor values should be read in the beginning")
//         {
//             batterySensorValue batterySensorReadings = getBatteryParamterValuesFromSensor();
//             THEN("Random sensor value list of size 100 within given range is generated")
//             {
//                 REQUIRE(batterySensorReadings.stateOfChargeSensorValueList.size() == 100);
//                 for (int i = 0; i < 100; i++)
//                 {
//                     REQUIRE(20 <= batterySensorReadings.stateOfChargeSensorValueList[i]);
//                     REQUIRE(batterySensorReadings.stateOfChargeSensorValueList[i] <= 80);
//                 }
//                 REQUIRE(batterySensorReadings.temperatureSensorValueList.size() == 100);
//                 for (int i = 0; i < 100; i++)
//                 {
//                     REQUIRE(-20 <= batterySensorReadings.temperatureSensorValueList[i]);
//                     REQUIRE(batterySensorReadings.temperatureSensorValueList[i] <= 60);
//                 }
//             }
//         }
//     }
// }

// SCENARIO("Test whether the sensorValueDisplayFormatter is formatting the values in expected CSV format")
// {
//     GIVEN("Send two valid integer values as input")
//     {
//         WHEN("Before printing the data on console, format them")
//         {
//             printSensorData printSensorDataObj;
//             std::string formattedText = printSensorDataObj.sensorValueDisplayFormatter(10, -20);
//             THEN("The formatted string will be in CSV format, ie.value1,value2")
//             {
//                 std::string expectedText = "10,-20";
//                 REQUIRE(formattedText == expectedText);
//             }
//         }
//     }
// }

// SCENARIO("Test whether the displayBatterySensorValueList is displaying all the values on console using mocking")
// {
//     GIVEN("Sensor values are geneated using random functionality")
//     {
//         batterySensorValue batterySensorReadings = getBatteryParamterValuesFromSensor();
//         WHEN("After reading the sensor value, print them on the console")
//         {
//             mockPrintSensorData mockPrintSensorDataObj;
//             displayBatterySensorValueList(batterySensorReadings, mockPrintSensorDataObj);
//             THEN("Format and print functionality should be called 100 times, as its the count of sendor data to be read")
//             {
//                 REQUIRE(mockPrintSensorDataObj.printCounter == 100);
//                 REQUIRE(mockPrintSensorDataObj.formatCounter == 100);
//             }
//         }
//     }
// }

SCENARIO("Test whether the data is sent to the reciever successfully")
{
    GIVEN("Using actual functionality, the sensor values are generated")
    {
        WHEN("After the sensor value generation value will be formatted and then print them on the console")
        {
            printSensorData actualPrintSensor;
            THEN("The value should be printed successfully on console")
            {
                bool expectedOutput = true;
                REQUIRE(sendBatteryParameterValues(actualPrintSensor) == expectedOutput);
            }
        }
    }
}

// SCENARIO("Test whether the data is sent to the reciever successfully with mock functionality")
// {
//     GIVEN("Using actual functionality, the sensor values are generated")
//     {
//         WHEN("After the sensor value generation value, mock interface is used to verify")
//         {
//             mockPrintSensorData mockPrintSensorDataObj;
//             THEN("The value should be printed successfully on console, mock interface is used to verify whether the formatting and print functionality are called 100 times")
//             {
//                 bool expectedOutput = true;
//                 REQUIRE(sendBatteryParameterValues(mockPrintSensorDataObj) == expectedOutput);
//                 REQUIRE(mockPrintSensorDataObj.printCounter == 100);
//                 REQUIRE(mockPrintSensorDataObj.formatCounter == 100);
//             }
//         }
//     }
// }
