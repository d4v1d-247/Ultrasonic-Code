/* This file contains a user interface for the 16x2 char LCD display.
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
volatile bool S_set = false;

// So that it doesn't do multiple steps during one
// Display update, gets reset during show_ui()
volatile bool S_change = false;


void ui_return() {
  /* Goes to the parent level in the ui */
  ui_pos[ui_depth] = 0;
  ui_depth--;
  exp_running = false;
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

void print_lcd(const char* line0, const char* line1) {
  Lcd.print(line0);
  Lcd.setCursor(0, 1);
  Lcd.print(line1);
}

/* const char ui_str_back[] = "Zur" UE "ck";
const char ui_str_end[] = "-----";

const char ui_str_exp[] = "Experiment";
const char ui_str_exp_vol[] = "Raumvolumen";
const char ui_str_exp_dist[] = "Dist. & Geschw.";

const char ui_str_sett[] = "Einstellungen";
const char ui_str_sett_sunit[] = "Distanz Einheit";
const char ui_str_sett_vunit[] = "Geschw. Einheit";
const char ui_str_sett_tshow[] = "Zeit Anzeigen";
const char ui_str_sett_tset[] = "Zeit einstellen";


void show_ui() {
  Lcd.clear();
  Lcd.home();

  switch(ui_pos[0]) {
    // Experiment
    case 0: {
      if (ui_depth == 0) {
        print_lcd(ui_str_exp, ui_str_sett);
      } else {
        switch(ui_pos[1]) {
          // Zurück
          case 0: {
            print_lcd(ui_str_back, ui_str_exp_dist);
            break;
          }
          // Distanz und Geschw. Experiment
          case 1: {
            if (ui_depth == 1) {
              print_lcd(ui_str_exp_dist, ui_str_exp_vol);
            } else {
              distance_experiment();
            }
            break;
          }
          // Raumvolumen Experiment
          case 2: {
            if (ui_depth == 1) {
              print_lcd(ui_str_exp_vol, ui_str_end);
            } else {

            }
            break;
          }
        
          default: ui_pos[1] = 2;
        }
      }
      break;
    }
    // Settings
    case 1: {
      if (ui_depth == 0) {
        print_lcd(ui_str_sett, ui_str_end);
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
} */

void show_ui() {
  /* There is not much interface and more display here. 
  This function just does either the experiment or shows an info.
  */
  Lcd.clear();
  Lcd.home();

  if (ui_depth) {
    distance_experiment();
  } else {
    info_screen();
  }

  delay(200);
  S_change = false;
}
