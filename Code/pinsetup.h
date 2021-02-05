#define US_TRIGGER_PIN 4
#define US_ECHO_PIN 5

#define CLOCK_SQW 2



void pinsetup() {
  pinMode(US_TRIGGER_PIN, OUTPUT);
  pinMode(US_ECHO_PIN, INPUT);

  pinMode(CLOCK_SQW, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(CLOCK_SQW), update_ms, RISING);
}
