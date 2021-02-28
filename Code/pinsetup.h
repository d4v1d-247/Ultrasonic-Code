void pinsetup() {
  pinMode(US_TRIGGER, OUTPUT);
  pinMode(US_ECHO, INPUT);


  pinMode(ROT_CLK, INPUT_PULLUP);
  pinMode(ROT_DT, INPUT_PULLUP);
  pinMode(ROT_SW, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(ROT_CLK), doEncoderA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ROT_DT), doEncoderB, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ROT_SW), EncoderButton, FALLING);
}
