/* The Stuff for filedumping 
<start_filedump> enables the filedumping in the <loop()>.
*/

char path[32] = { 0 }; // The currently used filepath

void start_filedump(fs::FS &SD) {
  /* Enables the filedumping in the <loop()>.
  It updates the strings of the current time and date and converts them into
  paths and filenames into <folder>, <filename> and <path> respectively.
  Then the headers of the .csv file gets written.
  */
  char filename[16] = { 0 };
  char folder[16] = { 0 };

  update_str_time();

  strcat(folder, "/");
  strcat(folder, str_date);

  if (!SD_exists(SD, folder)) {
    SD_mkDir(SD, folder);
  }

  strcat(filename, "/");
  strcat(filename, str_time);
  strcat(filename, ".csv");

  strcat(path, folder);
  strcat(path, filename);

  SD_writeFile(SD, path, "Time;Millisecond;Distance in mm;Speed in m/s\n");
  filedumping = true;
}

void filedump(uint16_t distance, float velocity, fs::FS &SD) {
  /* Dumps a reading of distance and velocity into the current file.
  Here we append the given data to the current path in <path>.
  First an emtpy char-array gets created, which is then filled using sprintf.
  */

  update_str_time();

  char out[128] = { 0 };
  sprintf(out,
    "%s;%8lu;%4d;%.3f\n",
    str_time,
    millis(),
    distance,
    velocity
  );
  SD_appendFile(SD, path, out);
}
