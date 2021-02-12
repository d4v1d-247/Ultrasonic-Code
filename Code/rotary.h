volatile uint8_t encoderPos = 0;

bool A_set = false;
bool B_set = false;

void doEncoderA() {
  if( digitalRead(ROT_CLK) != A_set ) {
    A_set = !A_set;
    if ( A_set && !B_set ) 
	  if (encoderPos < 255) {
		encoderPos += 1;
	  }
  }
}

void doEncoderB() {
  if( digitalRead(ROT_DT) != B_set ) {
    B_set = !B_set;
    if( B_set && !A_set ) 
	  if (encoderPos > 0) {
		encoderPos -= 1;
	  }
  }
}

void EncoderButton() {
	// ISR for buttonpress
}
