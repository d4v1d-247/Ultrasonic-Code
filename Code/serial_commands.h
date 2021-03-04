/* A function to parse serial input */

void parse_serial() {
  /* Reads stuff from the serial input runs a command if it matches.
  This reads from the serial inpt until a newline (\n) character is found and
  then parses it into a command and an argument using <sscanf()>.
  Then one of a command is executed.
  */
  char serial_buf[64] = { 0 };
  char command[64] = { 0 };
  char argument[64] = { 0 };
  Serial.readBytesUntil('\n', serial_buf, 64);
  
  uint8_t success = sscanf(serial_buf, "%s %s", command, argument);

  // Prints the Help if the command "help" was used or
  // sscanf() was unsuccessful (hence EOF)
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

  // sets the date of the RTC, takes date and time in ISO 8601 format
  } else if (!strcmp(command, "setdate")) {
    uint16_t Year = 0;
    uint8_t Month = 0, Date = 0, Hour = 0, Minute = 0, Second = 0;
    sscanf(
      argument,
      "%hu-%hhu-%hhu %hhu:%hhu:%hhu",
      &Year, &Month, &Date,
      &Hour, &Minute, &Second
    );
    RtcDateTime t(Year, Month, Date, Hour, Minute, Second);
    Clock.SetDateTime(t);

  // prints the date from the RTC to to Serial	
  } else if (!strcmp(command, "getdate")) {
    RtcDateTime t = Clock.GetDateTime();
    print_time(t, "RTC-Time is");
    print_time(COMP_TIME, "Compilertime is");

  // starts the dumping of data from the sensor to the sd_card
  } else if (!strcmp(command, "startdump")) {
    start_filedump(SD);
  
  // stops the filedumping
  } else if (!strcmp(command, "stopdump")) {
    filedumping = false;
  
  // starts fumping to serial (start*s*dump)
  } else if (!strcmp(command, "startsdump")) {
    serialdumping = true;
  
  // stops dumping to serial
  } else if (!strcmp(command, "stopsdump")) {
    serialdumping = false;
  }
}
