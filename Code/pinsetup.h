void pinsetup() {
  pinMode(US_TRIGGER, OUTPUT);
  pinMode(US_ECHO, INPUT);

  pinMode(CLOCK_SQW, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(CLOCK_SQW), update_ms, RISING);
}
