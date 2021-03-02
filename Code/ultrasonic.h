/* Implements methods to read out the ultrasonic sensor.
Both methods work the same way:
First send a short Trigger pulse to the sensor and then wait and measure
the time it takes for it to answer.
Last multiply or devide the number convert from microseconds of soundtravel
to a more readable format.
If the functions doesn't receive a response from the sensor within 30ms 
(roughly 5 meters) it will give up and return 0.*/

const float mmPerMicroS2 = 0.1716; // The doubled Distance of sound in mm per microsecond

uint16_t US_dist_mm() {
  digitalWrite(US_TRIGGER, HIGH);
  delay(50);
  digitalWrite(US_TRIGGER, LOW);

  uint16_t microseconds = pulseIn(US_ECHO, HIGH, 30000); // Timeout after about 5m
  return (uint16_t)(microseconds * mmPerMicroS2); // Rounds down. Change later?
}

uint16_t US_dist_ms() {
  digitalWrite(US_TRIGGER, HIGH);
  delay(50);
  digitalWrite(US_TRIGGER, LOW);

  uint16_t microseconds = pulseIn(US_ECHO, HIGH, 30000); // Timeout after about 5m
  return microseconds / 1000; // Rounds down. Change later?
}
