/* This file contains a user interface for the 16x2 char LCD display.
The gist of it:
Turning the knob changes your position in the menu,
pressing down lets you go down a level deeper.
When you want to go back to the "parent" level, you go to the first entry and
press the button.

The Interface tree is later supposed to look like this:
Experiment
  Radar
    Start, Stop
  Raumvolumen
    Höhe: Ok
      Länge: Ok
        Tiefe: Ok
  Dist. & Geschw.
Einstellungen
  Einheiten
    Geschwindigkeit
      [Single Select] m/s, mm/s, km/h
    Entfernung
      [Single Select] mm, cm, Schallsekunden
  Zeit
    Zeit anzeigen
    Zeit einstellen
*/

// defines ✨Umlaute✨ for use in strings.
#define AE "\xe1"
#define UE "\xf5"
#define OE "\xef"

// The current positions in the ui with the depth
// When you select, say, the third element <ui_pos[0] == 3> and if you click the
// <ui_depth == 1> further rotations to the button will now change <ui_pos[1]>.
uint8_t ui_pos[8] = { 0 };
uint8_t ui_depth = 0;


// vars for the rotary encoder and button

// Measures the time of the last buttonpress in order to ignore clicks that are
// not made by the user but the bouncy button
uint32_t buttonpresstime = 0; 
volatile bool A_set = false;
volatile bool B_set = false;
volatile bool S_set = false;

volatile bool S_change = false; // So that it doesn't do multiple steps during one
volatile bool A_change = false; // Display update, gets reset during show_ui()
volatile bool B_change = false;


void ui_return() {
  /* Goes to the parent level in the ui */
  ui_pos[ui_depth] = 0;
  ui_depth--;
}


void doEncoderA() {
  if(digitalRead(ROT_CLK) != A_set) {
    A_set = !A_set;
    if (A_set && !B_set && !A_change) {
      A_change = true;
      ui_pos[ui_depth]++;
    }
  }
  delayMicroseconds(100); //Debounce
}

void doEncoderB() {
  if(digitalRead(ROT_DT) != B_set) {
    B_set = !B_set;
    if(B_set && !A_set && !B_change) {
      B_change = true;
      ui_pos[ui_depth]--;
      if (ui_pos[ui_depth] > 200) {
        ui_pos[ui_depth] = 0;
      }
    }
  }
  delayMicroseconds(100); //Debounce
}

void EncoderButton() {
  /* Button ISR
  This function is triggered, whenever the Pushbutton of the Rotaryknob changes
  it's state.
  <S_set> makes sure, the function isn't paused by another call of itself.
  Then <if digitalRead(ROT_SW)> changes <buttonpresstime> when the button *isn't*
  pressed. That's because the Button sometimes calls this function a few times
  when the button is released (LOW to HIGH state change). To avoid multiple
  actions the function records the time of releasing the button
  <buttonpresstime = millis();> and ignores all *presses* (HIGH to LOW change)
  that happen within the specified time in <if millis() - 20 < buttonpresstime>.

  When a valid buttonpress has been recorded, the function will enter the selected
  submenu, except the selection is at 0, where the [Back] button is. This isn't
  the case at <ui_depth == 0>, because there is no more to go back to. 
  */
  if(!S_set) {
    S_set = true;
    if(digitalRead(ROT_SW)) {
      buttonpresstime = millis();
    } else {
      if (millis() - 20 < buttonpresstime && !S_change) {
        S_change = true;
        if(ui_pos[ui_depth] == 0 && ui_depth > 0) {
          if(ui_depth > 0) {
            ui_return();
          }
        } else {
          if(ui_depth < 7) {
            ui_depth++;
          }
        }
      }
    }
    S_set = false;
  }
  
}


const char ui_str_back[] = "Zur" UE "ck";
const char ui_str_end[] = "-----";

const char ui_str_1[] = "Experiment";
const char ui_str_1_1[] = "Radar";
const char ui_str_1_2[] = "Raumvolumen";
const char ui_str_1_3[] = "Dist. & Geschw.";

const char ui_str_2[] = "Einstellungen";
const char ui_str_2_1[] = "Geschwindigkeit";
const char ui_str_2_2[] = "Zeit";

void show_ui() {
  Lcd.clear();
  Lcd.home();

  switch(ui_pos[0]) {
    // Experiment
    case 0: {
      if (ui_depth == 0) {
        Lcd.print(ui_str_1);
        Lcd.setCursor(0, 1);
        Lcd.print(ui_str_2);
      } else {
        switch(ui_pos[1]) {
          case 0: {
            if (ui_depth == 1) {
              Lcd.print(ui_str_back);
              Lcd.setCursor(0, 1);
              Lcd.print(ui_str_1_1);
            } else {
              
            }
            break;
          }
          case 1: {
            if (ui_depth == 1) {
              Lcd.print(ui_str_1_1);
              Lcd.setCursor(0, 1);
              Lcd.print(ui_str_1_2);
            } else {

            }
            break;
          }
          case 2: {
            if (ui_depth == 1) {
              Lcd.print(ui_str_1_2);
              Lcd.setCursor(0, 1);
              Lcd.print(ui_str_1_3);
            } else {

            }
            break;
          }
          case 3: {
            if (ui_depth == 1) {
              Lcd.print(ui_str_1_3);
              Lcd.setCursor(0, 1);
              Lcd.print(ui_str_end);
            } else {

            }
            break;
          }
          default: ui_pos[1] = 3;
        }
      }
      break;
    }
    // Settings
    case 1: {
      if (ui_depth == 0) {
        Lcd.print(ui_str_2);
        Lcd.setCursor(0, 1);
        Lcd.print(ui_str_end);
      } else {

      }
      break;
    }
    default: ui_pos[0] = 1;
  }
  delay(200);
  A_change = false;
  B_change = false;
  S_change = false;
}
