volatile uint8_t encoderPos = 10;

bool A_set = false;
bool B_set = false;

bool S_change = false; // So that it doesn't do multiple steps during one
bool A_change = false; // Display update
bool B_change = false;

extern void encoder_pos();
extern void encoder_neg();
extern void encoder_click();

void doEncoderA() {
  if( digitalRead(ROT_CLK) != A_set ) {
    A_set = !A_set;
    if ( A_set && !B_set && !A_change) {
      A_change = true;
      encoder_pos();
    }
  }
  delayMicroseconds(100); //Debounce
}

void doEncoderB() {
  if( digitalRead(ROT_DT) != B_set ) {
    B_set = !B_set;
    if( B_set && !A_set && !B_change) {
      B_change = true;
      encoder_neg();
    }
  }
  delayMicroseconds(100); //Debounce
}

void EncoderButton() {
  delay(10); // Debounce
  if(digitalRead(ROT_SW) && !S_change) {
    S_change = true;
	  encoder_click();
  }
  delayMicroseconds(100); //Debounce
}
