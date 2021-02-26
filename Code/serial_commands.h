void parse_serial() {
  char serial_buf[64] = { 0 };
  char command[64] = { 0 };
  char argument[64] = { 0 };
  Serial.readBytesUntil('\n', serial_buf, 64);
  
  uint8_t success = sscanf(serial_buf, "%s %s", command, argument);

  if (!strcmp(command, "help") || success == EOF) {
    Serial.print("\
setdate\n\
Stellt das Datum der Uhr ein.\n\
Syntax: setdate YYYY-MM-DD HH:MM:SS\n\
\n\
getdate\n\
Gibt das Datum der Uhr und der Kompilierung zurück.\n\
\n\
startdump\n\
Startet das Schreiben auf die SD Karte.\n\
Diese muss schon beim Start des Messgeräts eingesetzt sein.\n\
\n\
stopdump\n\
Stoppt das Schreiben auf die SD Karte.\n\
\n\
startsdump\n\
Startet das Ausgeben der Daten über den Seriellen Monitor.\n\
\n\
stopsdump\n\
Stoppt das Ausgeben der Daten über den Seriellen Monitor.\n\
");
  } else if (!strcmp(command, "setdate")) {
    uint16_t Year = 0;
    uint8_t Month = 0, Date = 0, Hour = 0, Minute = 0, Second = 0;
    sscanf(argument, "%hu-%hhu-%hhu %hhu:%hhu:%hhu", &Year, &Month, &Date, &Hour, &Minute, &Second);
    RtcDateTime t(Year, Month, Date, Hour, Minute, Second);
    Clock.SetDateTime(t);
    //Serial.printf("Set time to %lu using arg %s, RTC-Time is now %lu\n", (unsigned long)t, argument, (unsigned long)Clock.GetDateTime());
  } else if (!strcmp(command, "getdate")) {
    RtcDateTime t = Clock.GetDateTime();
    print_time(t, "RTC-Time is");
    print_time(COMP_TIME, "Compilertime is");
    Lcd.clear();
    Lcd.home();
    Lcd.printf("%04d-%02d-%02d", t.Year(), t.Month(), t.Day());
    Lcd.setCursor(0, 1);
    Lcd.printf("  %02d:%02d:%02d", t.Hour(), t.Minute(), t.Second());
  } else if (!strcmp(command, "startdump")) {
    start_filedump(SD);
  } else if (!strcmp(command, "stopdump")) {
    filedumping = false;
  } else if (!strcmp(command, "startsdump")) {
    serialdumping = true;
  } else if (!strcmp(command, "stopsdump")) {
    serialdumping = false;
  }
}
