/* Functions regarding the SD Card and filesystem */

void sd_setup() {
  /* Sets up the SD Card */
  if(!SD.begin()){
    Serial.println("ERROR: Card Mount Failed");
  }
  
  uint8_t cardType = SD.cardType();
  if(cardType == CARD_NONE){
    Serial.println("ERROR: No SD card attached");
  }
  return;
}


void SD_listDir(fs::FS &fs, const char* dirname, uint8_t levels){
  /* Recursively lists the files and folders on the sd card down to the specified
  depth */
  File root = fs.open(dirname);
  if(!root){
    Serial.printf("ERROR: Failed to open path %s\n", dirname);
    return;
  }
  if(!root.isDirectory()){
    Serial.printf("ERROR: %s is not a directory\n", dirname);
    return;
  }

  File file = root.openNextFile();
  while(file){
    if(file.isDirectory()){
      Serial.print("  DIR : ");
      Serial.println(file.name());
      if(levels){
        SD_listDir(fs, file.name(), levels -1);
      }
    } else {
      Serial.print("  FILE: ");
      Serial.print(file.name());
      Serial.print("  SIZE: ");
      Serial.println(file.size());
    }
    file = root.openNextFile();
  }
}

void SD_mkDir(fs::FS &fs, const char* path) {
  /* Creates a folder */
  if(fs.mkdir(path)){
    Serial.printf("INFO: Created path %s\n", path);
  } else {
    Serial.printf("ERROR: Failed to create path %s\n", path);
  }
}

void SD_writeFile(fs::FS &fs, const char* path, const char* message) {
  /* writes data to the specified folder,
  creates a file, if it doesn't exist yet and deletes its content if it already
  exists */
  File file = fs.open(path, FILE_WRITE);
  if(!file) {
    Serial.printf("ERROR: Failed to open file %s for writing\n", path);
    return;
  }
  if(file.print(message)) {
    Serial.printf("INFO: Wrote to file %s\n", path);
  } else {
    Serial.printf("ERROR: Failed to write to file %s\n", path);
  }
  file.close();
}

void SD_appendFile(fs::FS &fs, const char* path, const char* message) {
  /* writes data to the end of a file */
  File file = fs.open(path, FILE_APPEND);
  if(!file){
    Serial.printf("ERROR: Failed to open file %s for appending\n", path);
    return;
  }
  if(file.print(message)){
    //Serial.printf("INFO: Appended to file %s\n", path);
  } else {
    Serial.printf("ERROR: Failed to append to file %s\n", path);
  }
  file.close();
}

bool SD_exists(fs::FS &fs, const char* path) {
  /* returns <true> if a path exists */
  return fs.exists(path);
}
