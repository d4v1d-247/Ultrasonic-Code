/*
 * Additional Libraries needed:
 * - ESP32: https://dl.espressif.com/dl/package_esp32_index.json
 *          File->Preferences->Additional Boards Manager URLs->Insert above link
 *          Tools->Board->Boards Manager->install ESP32
 */

#include <Wire.h>
#include <SPI.h>
#include <DS3231.h>    // https://github.com/NorthernWidget/DS3231     // The Unlicense
#include <LiquidCrystal_I2C.h> // https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library

#include "pins.h"
#include "misc.h"
#include "rotary.h"
#include "pinsetup.h"
#include "ultrasonic.h"
#include "sd_card.h"
#include "serial_commands.h"
#include "filedump.h"

SPIClass spi = SPIClass(HSPI);
DS3231 Clock;
LiquidCrystal_I2C Lcd(LCD_ADR, 16, 2);

uint32_t last_time = 0;
uint16_t last_data = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  Lcd.begin();

  pinsetup();
  
  spi.begin(18, 19, 23, 5); // SCK, MISO, MOSI, CS

  // SD Card
  if(!SD.begin(13, spi)){ Serial.println("ERROR: Card Mount Failed"); return; }
  uint8_t cardType = SD.cardType();
  if(cardType == CARD_NONE){ Serial.println("ERROR: No SD card attached"); return; }

  start_filedump(Clock);
}

void loop() {
  if (Serial.available()) {
    parse_serial(Clock);
  }
  
  uint32_t this_time = millis();
  uint16_t this_data = US_dist_mm();
  float velocity = ( (float) (this_data) - (float) (last_data) ) / (float) (this_time - last_time);  // speed is a keyword :(
  Serial.printf("Time: %08d ms  Distance: %04d mm  Speed: %+f mm/s\n", this_time, this_data, velocity);
  
  Lcd.clear();
  Lcd.home();
  Lcd.printf("s         % 4dmm", this_data);
  Lcd.setCursor(0, 1);
  Lcd.printf("v   %+fm/s", velocity);

  if(filedumping) {
    filedump(this_data, velocity, Clock);
  }

  last_time = this_time;
  last_data = this_data;

  Serial.println(encoderPos);
  delay(encoderPos*encoderPos); // Adds a delay to slow down the readings. Between 0ms and 65000ms changed by RotaryEncoder
}
