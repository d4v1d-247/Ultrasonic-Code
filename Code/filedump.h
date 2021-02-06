char folder[16] = { 0 };
char filename[16] = { 0 };
char path[32] = { 0 };
char* str_date = (char*)"2000-00-00\0";
char* str_time = (char*)"00.00.00\0";

bool filedumping = false;

void start_filedump(DS3231& Clock) {
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

void filedump(uint16_t this_data, float velocity, DS3231& Clock) {
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
