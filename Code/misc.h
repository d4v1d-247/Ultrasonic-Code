bool century = false;
bool ampm = false;
bool use12h = false;

void update_str_date(char* str_date, DS3231 &Clock) {
  sprintf(str_date, "20%02d-%02d-%02d", Clock.getYear(), Clock.getMonth(century), Clock.getDate());
}

void update_str_time(char* str_time, DS3231 &Clock) {
  sprintf(str_time, "%02d.%02d.%02d", Clock.getHour(use12h, ampm), Clock.getMinute(), Clock.getSecond());
}


volatile uint16_t ms = 0;
uint32_t old_millis = 0;
void update_ms() {
  ms = millis() - old_millis;
}
