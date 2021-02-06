void parse_serial(DS3231& Clock) {
  char serial_buf[64] = { 0 };
  char * strtokIndex;
  char command[64] = { 0 };
  char argument[64] = { 0 };
  Serial.readBytesUntil('\n', serial_buf, 64);
  
  strtokIndex = strtok(serial_buf, " ");
  strcpy(command, strtokIndex);

  strtokIndex = strtok(NULL, " ");
  strcpy(argument, strtokIndex);

  if (!strcmp(command, "help")) {
    Serial.println("\
setdate\n\
Stellt das Datum der Uhr ein.\n\
Syntax: setdate YYMMDDHHMMSS\
");
  } else if (!strcmp(command, "setdate")) {
    uint16_t Temp1, Temp2;

    // Year
    Temp1 = (byte)argument[0] -48;
    Temp2 = (byte)argument[1] -48;
    Clock.setYear(Temp1 * 10 + Temp2);

    // Month
    Temp1 = (byte)argument[2] -48;
    Temp2 = (byte)argument[3] -48;
    Clock.setMonth(Temp1 * 10 + Temp2);

    // Date
    Temp1 = (byte)argument[4] -48;
    Temp2 = (byte)argument[5] -48;
    Clock.setDate(Temp1 * 10 + Temp2);

    // Hour
    Temp1 = (byte)argument[6] -48;
    Temp2 = (byte)argument[7] -48;
    Clock.setHour(Temp1 * 10 + Temp2);

    // Minute
    Temp1 = (byte)argument[8] -48;
    Temp2 = (byte)argument[9] -48;
    Clock.setMinute(Temp1 * 10 + Temp2);

    // Second
    Temp1 = (byte)argument[10] -48;
    Temp2 = (byte)argument[11] -48;
    Clock.setSecond(Temp1 * 10 + Temp2);

    Clock.setClockMode(false); // 24h mode
    Clock.setDoW(3); // It's Wednesday, my dudes
    Clock.enableOscillator(true, false, 0);
    
  }
}
