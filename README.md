# Ultrasonic-Code

Dieses Repo enthält Code für ein Schulprojekt, in dem ein ESP32 mit einem Ultraschallsensor
Entfernung misst und die Daten auf eine SD-Karte speichert.

Kommentare im Code sind größtenteils in Englisch geschrieben um mit dem Rest konsistent
zu bleiben.

## Pin Verbindungen
Einige der 3.3V Pins müssen u.U. später auf VIN umgesteckt werden. Wenn es funktioniert
sollte 3.3V aber bevorzugt werden, da es eine regulierte Spannungsquelle ist und
VIN nur eine Verbindung zum Eingangsstrom.

### Pins die benutzt werden
- 0 + 2
- 17 - 12
- 21 - 23
- 25 - 27
- GND, VIN, 3.3V

### Ultraschall Sensor
| ESP32 | Sensor |
| ----- | ------ |
| VIN   | VCC    |
| GND   | GND    |
| 0     | Echo   |
| 2     | Trig   |

### SD-Karten Leser
| ESP32 | SD Leser |
| ----- | -------- |
| 15    | CS       |
| 14    | SCK      |
| 13    | MOSI     |
| 12    | MISO     |
| 3.3V  | VCC      |
| GND   | GND      |

### Uhr & LCD Display
Das Interface, mit dem die Uhr und das Display angesteuert werden (I²C) kann mehrere
Geräte an den gleichen Pins angeschlossen haben.

| ESP32 | Uhr   | LCD	|
| ----- | ----- | ----- |
| 22    | SCL   | SCL   |
| 21    | SDA   | SDA   |
| 23    | SQW   |		|
| 3.3V  | VCC   | VCC	|
| GND   | GND   | GND	|

### Drehgeber
| ESP32 | Rot.	|
| ----- | ----- |
| 3.3V	| +		|
| GND	| GND	|
| 25	| CLK	|
| 26	| DT	|
| 27	| SW	|
