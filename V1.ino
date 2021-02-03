/*
 * Additional Libraries needed:
 * - ESP32: https://dl.espressif.com/dl/package_esp32_index.json
 *          File->Preferences->Additional Boards Manager URLs->Insert above link
 *          Tools->Board->Boards Manager->install ESP32
 */

//#include <Rotary.h>  // https://github.com/brianlow/Rotary // GNU GPL V3
#include <DS3231.h>  // https://github.com/NorthernWidget/DS3231 // The Unlicense
#include "ultrasonic.h"
#include "sd_card.h"
#include "serial_commands.h"
#include "misc.h"
#include "pinsetup.h"

DS3231 Clock;

char folder[16] = { 0 };
char filename[16] = { 0 };
char path[32] = { 0 };
char* str_date = (char*)"2000-00-00\0";
char* str_time = (char*)"00.00.00\0";

uint32_t last_time = 0;
uint16_t last_data = 0;

bool filedumping = false;

void start_filedump() {
  memset(folder, 0, 16);
  strcat(folder, "/");
  update_str_date(str_date, Clock);
  strcat(folder, str_date);

  if (!SD_exists(SD, folder)) {
    SD_mkDir(SD, folder);
  }

  memset(filename, 0, 16);
  strcat(filename, "/");
  update_str_time(str_time, Clock);
  strcat(filename, str_time);
  strcat(filename, ".csv");

  char path[32] = { 0 };
  strcat(path, folder);
  strcat(path, filename);

  SD_writeFile(SD, path, "Millisecond;Distance in mm;Speed in mm/s\n");
  filedumping = true;
}

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  // SD Card
  if(!SD.begin()){ Serial.println("ERROR: Card Mount Failed"); return; }
  uint8_t cardType = SD.cardType();
  if(cardType == CARD_NONE){ Serial.println("ERROR: No SD card attached"); return; }

  start_filedump();
}

void loop() {
  if (Serial.available()) {
    parse_serial(Clock);
  }
  
  uint32_t this_time = millis();
  uint16_t this_data = US_dist_mm(2, 3);
  float velocity = (float) (this_data - last_data) / (float) (this_time - last_time);  // speed is a keyword :(
  Serial.printf("Time: %d ms  Distance: %d mm  Speed: %d mm/s", this_time, this_data, int(velocity * 1000));
  
  if(filedumping) {
    update_str_time(str_time, Clock);
    
    char out[128] = { 0 };
    sprintf(out,
      "%s.%04d;%04d;%d.%02d\n",
      str_time,
      ms,
      this_data,
      int(velocity),
      int((int(velocity)-velocity)*100)
    );
    SD_appendFile(SD, path, out);
  }
  
  last_time = this_time;
  last_data = this_data;
}
