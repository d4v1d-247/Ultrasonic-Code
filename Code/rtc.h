/* Things of the RealTimeClock
This file includes the init function that gets called in setup,
a function to get the time printed to the serial monitor and
a function, that updates <str_date> and <str_time>, which are used in filedump.h
to determine folder- and filename of data reads.
*/

char str_date[12] = {0};
char str_time[10] = {0};

void print_time(RtcDateTime& t, const char* prefix) {
  /* Prints the given time to Serial
  This function outputs <prefix> followed by the DateTime <t> to
  the Serial Monitor. */
  
  Serial.printf(
    "%s %04d-%02d-%02d %02d:%02d:%02d\n",
    prefix,
    t.Year(), t.Month(), t.Day(),
    t.Hour(), t.Minute(), t.Second()
  );
}

void clock_setup() {
  /* Sets up the RTC
  Does three things:
  1. Disables the Write Protection of the Clock, if it was enabled
  2. Starts the Clock if it was paused
  3. Updates the Time on the Clock if it was:
     a. Behind the Time of Compilation
     b. Matches the Number that the RTC Library somehow returns,
      when the Clock hasn't been initialized yet. */

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

  // 2nd applies when clock hasn't been set yet
  if (t < COMP_TIME || t == 1367256704) {
    Serial.println(
      "WARN: RTC time is behind compile time. "
      "Setting RTC to compile time."
    );
    Clock.SetDateTime(COMP_TIME);
  }
}

void update_str_time() {
  /* Updates the stringified time stored in <str_date> and <str_time>
  These are used by the SD Card system for
  folder creation (Date) and
  file creation (Time) */

  RtcDateTime t = Clock.GetDateTime();
  snprintf(str_time, 10, "%02d.%02d.%02d", t.Hour(), t.Minute(), t.Second());
  snprintf(str_date, 12, "%04d-%02d-%02d", t.Year(), t.Month(), t.Day());
}
