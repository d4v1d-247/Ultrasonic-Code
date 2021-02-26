void pinsetup() {
  pinMode(US_TRIGGER, OUTPUT);
  pinMode(US_ECHO, INPUT);


  pinMode(ROT_CLK, INPUT);
  pinMode(ROT_DT, INPUT);
  pinMode(ROT_SW, INPUT);

  attachInterrupt(digitalPinToInterrupt(ROT_CLK), doEncoderA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ROT_DT), doEncoderB, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ROT_SW), EncoderButton, RISING);
}
