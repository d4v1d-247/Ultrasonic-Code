void pinsetup() {
  pinMode(US_TRIGGER, OUTPUT);
  pinMode(US_ECHO, INPUT);

  pinMode(CLOCK_SQW, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(CLOCK_SQW), update_ms, RISING);

  pinMode(ROT_CLK, INPUT);
  pinMode(ROT_DT, INPUT);
  pinMode(ROT_SW, INPUT);

  attachInterrupt(digitalPinToInterrupt(ROT_CLK), doEncoderA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ROT_DT), doEncoderB, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ROT_SW), EncoderButton, CHANGE);
}
