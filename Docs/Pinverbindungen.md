# Pin Verbindungen

| ESP32 | SD Leser | LCD Display | Sensor | Drehgeber | RTC |
| ----- | -------- | ----------- | ------ | --------- | --- |
| 5V    | VCC      | VCC         | VCC    |           |     |
| 3.3V  |          |             |        | +         | VCC |
| GND   | GND      | GND         | GND    | GND       | GND |
| 5     | CS       |             |        |           |     |
| 18    | SCK      |             |        |           |     |
| 19    | MISO     |             |        |           |     |
| 23    | MOSI     |             |        |           |     |
| 21    |          | SDA         |        |           |     |
| 22    |          | SCL         |        |           |     |
| 4     |          |             | Trig.  |           |     |
| 15    |          |             | Echo   |           |     |
| 25    |          |             |        | CLK       |     |
| 26    |          |             |        | DT        |     |
| 27    |          |             |        | SW        |     |
| 17    |          |             |        |           | RST |
| 32    |          |             |        |           | DAT |
| 33    |          |             |        |           | CLK |

# Materialliste
- LCD Display mit mindestens 16x2 Zeichen und PCF8574 IO Expander
- ESP-WROOM-32 Microcontroller
- DS1302 RTC Board
- HC-SR04 Ultraschallsensor
- SPI microSD-Karten Adapter
- KY-040 Drehgeber
- 4  M-F Jumper Kabel
- 18 M-M Jumper Kabel
- 2 Große Breadbords
- 4-fach AA Batteriefach
