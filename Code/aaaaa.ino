/*
 * Additional Libraries needed:
 * - ESP32: https://dl.espressif.com/dl/package_esp32_index.json
 *          File->Preferences->Additional Boards Manager URLs->Insert above link
 *          Tools->Board->Boards Manager->install ESP32
 */

// Standard Librarys
#include <Wire.h>
#include <SPI.h>
#include "SD.h"
#include "FS.h"

// https://github.com/Makuna/Rtc
#include <ThreeWire.h> 
#include <RtcDS1302.h>

// https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library
#include <LiquidCrystal_I2C.h>


// Ultrasonic Sensor
#define US_TRIGGER  4
#define US_ECHO    15

// RTC
#define CLOCK_CLK 33
#define CLOCK_DAT 32
#define CLOCK_RST 17

// LC Display
#define LCD_SDA 21
#define LCD_SCL 22
#define LCD_ADR 0x27

// Rotary Encoder
#define ROT_CLK 25
#define ROT_DT  26
#define ROT_SW  27

LiquidCrystal_I2C Lcd(LCD_ADR, 16, 2);
ThreeWire clock_wire(CLOCK_DAT, CLOCK_CLK, CLOCK_RST);
RtcDS1302<ThreeWire> Clock(clock_wire);
RtcDateTime COMP_TIME = RtcDateTime(__DATE__, __TIME__);

bool serialdumping = true;
bool filedumping = false;


#include "rtc.h"
#include "pinsetup.h"
#include "ultrasonic.h"
#include "sd_card.h"
#include "filedump.h"
#include "lcd_ui.h"
#include "serial_commands.h"

// For the calculation of speed
uint32_t last_time = 0;
uint16_t last_data = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  Lcd.begin();
  Clock.Begin();
  pinsetup();
  clock_setup();
  sd_setup();

  start_filedump(SD);
}

void loop() {
  if (Serial.available()) {
    parse_serial();
  }
  
  uint32_t this_time = millis();
  uint16_t this_data = US_dist_mm();
  
  float velocity = // speed is a keyword :(
    (float) (this_data - last_data) / (float) (this_time - last_time); 
  
  if(serialdumping) {
    Serial.printf(
      "Time: %08d ms  Distance: %04d mm  Speed: %+f m/s\n",
      this_time,
      this_data,
      velocity
    );
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
}
