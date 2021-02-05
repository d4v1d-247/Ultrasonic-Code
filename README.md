# Ultrasonic-Code

This repo contains code for a school project, where an ESP32 reads an ultrasonic
sensor and saves the data to an SD card.

## Pin connections
Some of the VCC Pins that are connected to 3.3V may need to be changed to VIN later.
3.3V is better though if it works, because it's a regulated source, while VIN is 
a direct connection to the power source.

### Pins that are in use
- 0 + 2
- 17 - 12
- 21 - 23
- 25 - 27
- GND, VIN, 3.3V

### Ultrasonic Sensor
| ESP32 | Sensor |
| ----- | ------ |
| VIN   | VCC    |
| GND   | GND    |
| 0     | Echo   |
| 2     | Trig   |

### SD-Card Reader
| ESP32 | SD Reader |
| ----- | --------- |
| 15    | CS        |
| 14    | SCK       |
| 13    | MOSI      |
| 12    | MISO      |
| 3.3V  | VCC       |
| GND   | GND       |

### Clock
| ESP32 | Clock |
| ----- | ----- |
| 22    | SCL   |
| 21    | SDA   |
| 23    | SQW   |
| 3.3V  | VCC   |
| GND   | GND   |

### LCD Display
| ESP32 | LCD   |
| ----- | ----- |
| 16    | SCL   |
| 17    | SDA   |
| 3.3V  | VCC   |
| GND   | GND   |

### Rotary Encoder
| ESP32 | Rot.	|
| ----- | ----- |
| 3.3V	| +		|
| GND	| GND	|
| 25	| CLK	|
| 26	| DT	|
| 27	| SW	|
