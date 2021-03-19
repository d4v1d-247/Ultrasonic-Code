# Beschreibung
## Materialien
* LCD Display mit mindestens 16x2 Zeichen und PCF8574 IO Expander
* ESP-WROOM-32 Microcontroller
* DS1302 RTC Board
* HC-SR04 Ultraschallsensor
* SPI microSD-Karten Adapter
* KY-040 Drehgeber
* 4 M-F Jumper Kabel
* 18 M-M Jumper Kabel
* 2 Große Breadbords

## Benötigt Software
* Arduino IDE
* Bibliotheken vom Arduino Paketmanager

## Beschreibung
Das Radar. Erfunden von Heinrich Hertz im Jahr 1886 hat heutzutage in vielen Bereichen Anwendung. Es wird im Militär für U-Boote genutzt, um Hindernisse zu erkennen oder in der zivilen Luftfahrt, um die Position der Flugzeuge ausfindig zumachen. Eine Sachen haben sie gemeinsam. Beide Radare benötigen ein Ultraschallmessgerät um zu funktionieren. Ein Ultraschallmessgerät kann Distanzen in kürzester Zeit messen. Unsere Gruppe kam auf eine ähnliche Idee. Unser Ultraschallmessgerät kann zwar nur auf geringe Distanz messen, aber wenn man auf geringe Distanz misst kann man es so ähnlich nutzen wie bei U-Booten. Mit diesem Ultraschallmessgerät wollen wir Distanzen messen. Beachtet werden muss, dass es nur zwischen den Werten 5-150 cm funktioniert.  Wird unter oder über dieser Distanz gemessen werden die Werte ungenau und springt zwischen den Werten hin und her.

## Häufige Fragen und Probleme
### Pobleme bei der Programmierung
Die Pins des ESP-Controller wurden falsch genutzt. Das heißt ein Eingang wurde z.B. als Ausgang benutzt. Das funktioniert natürlich nicht. Es wäre wie, wenn man eine Tür von der falschen Seite öffnen würde.
### Allgemein
Das Ultraschallmessgerät kann ab einer Entfernung von unter 5 cm und über 150 cm nicht mehr genau messen und springt zwischen den Werten hin und her. Außerdem musste das Menü gelöscht werden, da nicht mehr genung Zeit zur Verfügung stand.
