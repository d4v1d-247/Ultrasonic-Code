#define AE "\xe1"
#define UE "\xf5"
#define OE "\xef"

uint8_t ui_pos[8] = { 0 };
uint8_t ui_depth = 0;


const char ui_str_back[] = "Zur" UE "ck";
const char ui_str_end[] = "-----";

const char ui_str_1[] = "Experiment";
const char ui_str_1_1[] = "Radar";
const char ui_str_1_2[] = "Raumvolumen";
const char ui_str_1_3[] = "Dist. & Geschw.";

const char ui_str_2[] = "Einstellungen";
const char ui_str_2_1[] = "Geschwindigkeit";
const char ui_str_2_2[] = "Zeit";


void encoder_pos() {
	ui_pos[ui_depth]++;
}

void encoder_neg() {
	ui_pos[ui_depth]--;
	if (ui_pos[ui_depth] > 200) {
		ui_pos[ui_depth] = 0;
	}
}

void encoder_click() {
	if(ui_pos[ui_depth] == 0 && ui_depth > 0) {
		ui_depth--;
	} else {
		ui_depth++;
	}
}


void ui_return() {
	ui_pos[ui_depth] = 0;
	ui_depth--;
}

void show_ui() {
	A_change = false;
	B_change = false;
	S_change = false;

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
}
