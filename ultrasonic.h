const float mmPerMicroS2 = 0.6864; // The doubled Distance of sound in mm per microsecond

uint16_t dist_mm(byte trigger_pin, byte echo_pin) {
  digitalWrite(trigger_pin, HIGH);
  delay(1);
  digitalWrite(trigger_pin, LOW);

  uint16_t microseconds = pulseIn(echo_pin, HIGH, 30000); // Timeout after about 5m
  return microseconds / mmPerMicroS2;
}

uint16_t dist_ms(byte trigger_pin, byte echo_pin) {
  digitalWrite(trigger_pin, HIGH);
  delay(1);
  digitalWrite(trigger_pin, LOW);

  uint16_t microseconds = pulseIn(echo_pin, HIGH, 30000); // Timeout after about 5m
  return microseconds / 1000;
}
