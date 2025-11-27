#include <Arduino.h>
#include <Wire.h>
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"
#include <MAX30100.h>

MAX30100 sensor;

void setup() {
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); // Desactiva brownout
  Serial.begin(115200);
  delay(1000);
  Serial.println("Iniciando MAX30100...");

  Wire.begin(21, 22); // Pines I2C del ESP32

  sensor.begin();
  sensor.setMode(MAX30100_MODE_SPO2_HR);
  sensor.setLedsCurrent(MAX30100_LED_CURR_24MA, MAX30100_LED_CURR_24MA);
  sensor.setLedsPulseWidth(MAX30100_SPC_PW_1600US_16BITS);
  sensor.setSamplingRate(MAX30100_SAMPRATE_100HZ);
  sensor.setHighresModeEnabled(true);

  Serial.println("Sensor inicializado correctamente.");
}

void loop() {
  sensor.update();

  uint16_t ir, red;
  sensor.getRawValues(&ir, &red);

  Serial.print("IR: ");
  Serial.print(ir);
  Serial.print(" | RED: ");
  Serial.println(red);

  delay(1000);
}