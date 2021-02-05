const float mmPerMicroS2 = 0.6864; // The doubled Distance of sound in mm per microsecond

uint16_t US_dist_mm() {
  digitalWrite(US_TRIGGER, HIGH);
  delay(1);
  digitalWrite(US_TRIGGER, LOW);

  uint16_t microseconds = pulseIn(US_ECHO, HIGH, 30000); // Timeout after about 5m
  return (uint16_t)(microseconds / mmPerMicroS2); // Rounds down. Change later?
}

uint16_t US_dist_ms() {
  digitalWrite(US_TRIGGER, HIGH);
  delay(1);
  digitalWrite(US_TRIGGER, LOW);

  uint16_t microseconds = pulseIn(US_ECHO, HIGH, 30000); // Timeout after about 5m
  return microseconds / 1000; // Rounds down. Change later?
}
