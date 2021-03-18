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
#define ROT_SW  27

LiquidCrystal_I2C Lcd(LCD_ADR, 16, 2);
ThreeWire clock_wire(CLOCK_DAT, CLOCK_CLK, CLOCK_RST);
RtcDS1302<ThreeWire> Clock(clock_wire);
RtcDateTime COMP_TIME = RtcDateTime(__DATE__, __TIME__);

bool filedumping = false;


#include "rtc.h"
#include "pinsetup.h"
#include "ultrasonic.h"
#include "sd_card.h"
#include "filedump.h"
#include "experiments.h"
#include "lcd_ui.h"
#include "serial_commands.h"

// For the calculation of speed
// uint32_t last_time = 0;
// uint16_t last_data = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  Lcd.begin();
  Clock.Begin();
  pinsetup();
  clock_setup();
  sd_setup();
}

void loop() {
  if (Serial.available()) {
    parse_serial();
  }
  
  show_ui();
}
