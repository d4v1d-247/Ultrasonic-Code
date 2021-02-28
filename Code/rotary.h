volatile uint8_t encoderPos = 10;

volatile bool A_set = false;
volatile bool B_set = false;
volatile bool S_set = false;

volatile bool S_change = false; // So that it doesn't do multiple steps during one
volatile bool A_change = false; // Display update
volatile bool B_change = false;

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
  if(!S_set) {
    S_set = true;
    //delay(10); // Debounce
    if(!digitalRead(ROT_SW) && !S_change) {
      S_change = true;
      encoder_click();
    }
    //delay(50); //Debounce
    S_set = false;
  }
  
}
