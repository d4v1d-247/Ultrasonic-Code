/* Here I defined the possible experiments that the device should be able to do.
*/


RtcDateTime exp_starttime = RtcDateTime(0);
bool exp_running = false;

uint32_t exp_time = 0;
uint16_t exp_data = 0;

void distance_experiment() {
  /* This function just shows the current Data and saves it to the SD-Card,
  which makes it useful for a lot of experiments.
  */
  if(!exp_running) {
    Serial.println("INFO: Started Experiment");
    exp_starttime = Clock.GetDateTime();
    exp_running = true;
    start_filedump(SD);
  }

  // Get Time, Data and velocity
  uint32_t time = millis();
  uint16_t data = US_dist_mm();
  float velocity = 
    (float) (data - exp_data) / (float) (time - exp_time);
  uint32_t exp_runningtime =
    Clock.GetDateTime().TotalSeconds() - exp_starttime.TotalSeconds();
  
  // Print runningtime to Display
  char str_running[17] = { 0 };
  snprintf(str_running, 17, "t: %02d:%02d", exp_runningtime/60, exp_runningtime%60);
  Lcd.print(str_running);
  Lcd.setCursor(0, 1);

  // Print data to Display
  char str_data[17] = { 0 };
  snprintf(str_data, 17, "%4dmm %+1.3fm/s", data, velocity);
  Lcd.print(str_data);

  // Write Data to SD-Card
  filedump(data, velocity, exp_runningtime, SD);

  exp_time = time;
  exp_data = data;
}

void info_screen() {
  /* This is the *Standby* function that'll run, when no experiment is selected.
  It shows the Date in DD.MM HH:MM:SS format and info about the sd card */

  RtcDateTime t = Clock.GetDateTime();
  char time_for_lcd[17] = { 0 };
  snprintf(time_for_lcd, 17, "%02d.%02d %02d:%02d:%02d",
    t.Day(), t.Month(),
    t.Hour(), t.Minute(), t.Second()
  );
  Lcd.print(time_for_lcd);

  Lcd.setCursor(0, 1);
  if(no_sd) {
    Lcd.print("Keine SD Karte");
  } else if(sd_error) {
    Lcd.print("SD Kartenfehler");
  }
}
