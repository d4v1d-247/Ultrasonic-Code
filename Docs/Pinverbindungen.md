# Pin Verbindungen
Einige der 3.3V Pins müssen u.U. später auf VIN umgesteckt werden. Wenn es funktioniert
sollte 3.3V aber bevorzugt werden, da es eine regulierte Spannungsquelle ist und
VIN nur eine Verbindung zum Eingangsstrom.

## Ultraschall Sensor
| ESP32 | Sensor |
| ----- | ------ |
| VIN   | VCC    |
| GND   | GND    |
| 15    | Echo   |
| 4     | Trig   |

## SD-Karten Leser
| ESP32 | SD Leser |
| ----- | -------- |
| 15    | CS       |
| 14    | SCK      |
| 13    | MOSI     |
| 12    | MISO     |
| 3.3V  | VCC      |
| GND   | GND      |

## LCD Display
| ESP32 | LCD	|
| ----- | ----- |
| 22    | SCL   |
| 21    | SDA   |
| 3.3V  | VCC	|
| GND   | GND	|

## Drehgeber
| ESP32 | Rot.	|
| ----- | ----- |
| 3.3V	| +		|
| GND	| GND	|
| 25	| CLK	|
| 26	| DT	|
| 27	| SW	|

## DS1302 RTC
| ESP32 | RTC	 |
| ----- | ------ |
| 5V	| VCC    |
| GND   | GND    |
| 33    | CLK    |
| 32    | DAT    |
| 17	| RST	 |
