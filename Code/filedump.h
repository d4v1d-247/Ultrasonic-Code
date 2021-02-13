char folder[16] = { 0 };
char filename[16] = { 0 };
char path[32] = { 0 };

bool filedumping = false;

void start_filedump(fs::FS &SD) {
  memset(folder, 0, 16);
  strcat(folder, "/");
  update_str_time();
  strcat(folder, str_date);

  if (!SD_exists(SD, folder)) {
    SD_mkDir(SD, folder);
  }

  memset(filename, 0, 16);
  strcat(filename, "/");
  strcat(filename, str_time);
  strcat(filename, ".csv");

  strcat(path, folder);
  strcat(path, filename);

  SD_writeFile(SD, path, "Time;Millisecond;Distance in mm;Speed in m/s\n");
  filedumping = true;
}

void filedump(uint16_t this_data, float velocity, fs::FS &SD) {
  update_str_time();

  char out[128] = { 0 };
  sprintf(out,
    "%s;%8lu;%4d;%.3f\n",
    str_time,
    millis(),
    this_data,
    velocity
  );
  SD_appendFile(SD, path, out);
}
