ThreeWire clock_wire(CLOCK_DAT, CLOCK_CLK, CLOCK_RST);
RtcDS1302<ThreeWire> Clock(clock_wire);
char str_date[12] = {0};
char str_time[10] = {0};
RtcDateTime COMP_TIME = RtcDateTime(__DATE__, __TIME__);

void update_str_time() {
  RtcDateTime t = Clock.GetDateTime();
  snprintf(str_time, 10, "%02d.%02d.%02d", t.Hour(), t.Minute(), t.Second());
  snprintf(str_date, 12, "%04d-%02d-%02d", t.Year(), t.Month(), t.Day());
}

void print_time(RtcDateTime& t, char* prefix) {
  Serial.printf("%s %04d-%02d-%02d %02d:%02d:%02d\n", prefix, t.Year(), t.Month(), t.Day(), t.Hour(), t.Minute(), t.Second());
}

volatile uint16_t ms = 0;
uint32_t old_millis = 0;
void update_ms() {
  ms = millis() - old_millis;
}
