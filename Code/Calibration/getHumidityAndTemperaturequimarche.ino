
#include "DFRobot_SHT20.h"

DFRobot_SHT20 sht20(&Wire, SHT20_I2C_ADDR);

void setup()
{
  Serial.begin(115200);

  // Init SHT20 Sensor
  sht20.initSHT20();
  delay(100);
  Serial.println("Sensor init finish!");

  /**
   * Check the current status information of SHT20
   * Status information: End of battery, Heater enabled, Disable OTP reload
   * Check result: yes, no
   */
  sht20.checkSHT20();
}

void loop()
{
  /**
   * Read the measured data of air humidity
   * Return the measured air humidity data of float type, unit: %
   */
  float humd = sht20.readHumidity();

  /**
   * Read the measured temp data
   * Return the measured temp data of float type, unit: C
   */
  float temp = sht20.readTemperature();

  Serial.print("Time:");
  Serial.print(millis());   // Get the system time from Arduino
  Serial.print(" Temperature:");
  Serial.print(temp, 1);   // Only print one decimal place
  Serial.print("C");
  Serial.print(" Humidity:");
  Serial.print(humd, 1);   // Only print one decimal place
  Serial.print("%");
  Serial.println();

  delay(1000);
}
