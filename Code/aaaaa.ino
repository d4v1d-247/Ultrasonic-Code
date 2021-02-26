/*
 * Additional Libraries needed:
 * - ESP32: https://dl.espressif.com/dl/package_esp32_index.json
 *          File->Preferences->Additional Boards Manager URLs->Insert above link
 *          Tools->Board->Boards Manager->install ESP32
 */

#include <Wire.h>
#include <SPI.h>
#include <ThreeWire.h> // https://github.com/Makuna/Rtc
#include <RtcDS1302.h> // https://github.com/Makuna/Rtc
#include <LiquidCrystal_I2C.h> // https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library

#include "pins.h"
#include "misc.h"
#include "rtc.h"
#include "rotary.h"
#include "pinsetup.h"
#include "ultrasonic.h"
#include "sd_card.h"
#include "filedump.h"
#include "lcd_ui.h"
#include "serial_commands.h"


uint32_t last_time = 0;
uint16_t last_data = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  Lcd.begin();
  Clock.Begin();

  pinsetup();

  if(Clock.GetIsWriteProtected()) {
    Clock.SetIsWriteProtected(false);
    Serial.println("WARN: Clock was Write Protected. Changed.");
  }
  if(!Clock.GetIsRunning()) {
    Clock.SetIsRunning(true);
    Serial.println("WARN: Clock was paused. Changed.");
  }
  RtcDateTime t = Clock.GetDateTime();
  print_time(t, "INFO: RTC-Time is");
  if (t < COMP_TIME || t == 1367256704) { // 2nd applies when clock hasn't been set yet
    Serial.println("WARN: RTC is older than compile time. Setting RTC to compile time.");
    Clock.SetDateTime(COMP_TIME);
  }

  // SD Card
  if(!SD.begin()){
    Serial.println("ERROR: Card Mount Failed");
    uint8_t cardType = SD.cardType();
    if(cardType == CARD_NONE){
      Serial.println("ERROR: No SD card attached");
      return;
    }
    return;
  }
  uint8_t cardType = SD.cardType();
  if(cardType == CARD_NONE){
    Serial.println("ERROR: No SD card attached");
    return;
  }

  start_filedump(SD);
}

void loop() {
  if (Serial.available()) {
    parse_serial();
  }
  
  uint32_t this_time = millis();
  uint16_t this_data = US_dist_mm();
  float velocity = (float) (this_data - last_data) / (float) (this_time - last_time);  // speed is a keyword :(
  
  if(serialdumping) {
    Serial.printf("Time: %08d ms  Distance: %04d mm  Speed: %+f m/s\n", this_time, this_data, velocity);
  }

  /*Lcd.clear();
  Lcd.home();
  Lcd.printf("s        %5dmm", this_data);
  Lcd.setCursor(0, 1);
  Lcd.printf("v   %+fm/s", velocity);*/
  for (byte i = 0; i < 8; i++) {
    Serial.print(ui_pos[i]);
  }
  Serial.println("");
  Serial.println(ui_depth);
  show_ui();

  if(filedumping) {
    filedump(this_data, velocity, SD);
  }

  last_time = this_time;
  last_data = this_data;

  //Serial.println(encoderPos);
  delay(encoderPos*encoderPos); // Adds a delay to slow down the readings. Between 0ms and 65000ms changed by RotaryEncoder
}
