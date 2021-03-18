/* Sets the pinmodes for all the pins, that are used outside of librarys. 
The Rotary encoder gets Pullup Resistors because, unlike the Ultrasonic Sensor,
it's a physical switch.
Then the InterruptServiceRoutines for the Rotary-encoder get attached to the 
according pinchanges.
*/

// Written here, because these functions will be defined in lcd_ui.h but are
// already referenced here.
extern void EncoderButton();

void pinsetup() {
  /* Sets the pinmodes and attaches the intterrupts for the rotary-encoder */
  pinMode(US_TRIGGER, OUTPUT);
  pinMode(US_ECHO, INPUT);

  pinMode(ROT_SW, INPUT_PULLUP);

  // Attaches an Interrupt to the Pins of the Rotary Encoder,
  // which trigger a function when the value at the Pins change.
  attachInterrupt(digitalPinToInterrupt(ROT_SW), EncoderButton, CHANGE);
}
