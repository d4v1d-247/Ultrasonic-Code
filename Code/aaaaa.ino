/*
 * Additional Libraries needed:
 * - ESP32: https://dl.espressif.com/dl/package_esp32_index.json
 *          File->Preferences->Additional Boards Manager URLs->Insert above link
 *          Tools->Board->Boards Manager->install ESP32
 */

#include <Wire.h>
#include <DS3231.h>    // https://github.com/NorthernWidget/DS3231     // The Unlicense
#include <Button2.h>   // https://github.com/LennartHennigs/Button2    // MIT License
#include <ESPRotary.h> // https://github.com/LennartHennigs/ESPRotary/ // MIT License
#include <LiquidCrystal_I2C.h> // https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library

#include "pins.h"
#include "misc.h"
#include "pinsetup.h"
#include "ultrasonic.h"
#include "sd_card.h"
#include "serial_commands.h"
#include "filedump.h"

DS3231 Clock;
LiquidCrystal_I2C Lcd(LCD_ADR, 16, 2);

uint32_t last_time = 0;
uint16_t last_data = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  Lcd.begin();

  pinsetup();
  
  // SD Card
  if(!SD.begin()){ Serial.println("ERROR: Card Mount Failed"); return; }
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
  float velocity = (float) (this_data - last_data) / (float) (this_time - last_time);  // speed is a keyword :(
  Serial.printf("Time: %d ms  Distance: %d mm  Speed: %d mm/s", this_time, this_data, int(velocity * 1000));
  
  Lcd.clear();
  Lcd.home();
  Lcd.printf("Distanz  %04dmm \nSchnelle %01d.%02dm/s", this_data, int(velocity), int((int(velocity)-velocity)*100));

  if(filedumping) {
    filedump(this_data, velocity, Clock);
  }

  last_time = this_time;
  last_data = this_data;
}
