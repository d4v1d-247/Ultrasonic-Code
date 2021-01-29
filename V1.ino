#include "ultrasonic.h"

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(dist_mm(2, 3));
  Serial.println(dist_ms(2, 3));
}
