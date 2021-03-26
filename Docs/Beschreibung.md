# Beschreibung
## Benötigt Software
* Arduino IDE
* _ESP32_ Boardmanager -> installation in [Anleitung.md](https://github.com/d4v1d-247/Ultrasonic-Code/blob/master/Docs/Anleitung.md#bibliotheken-installieren)
* _RTC by Makuna_ -> über Arduino Bibliothekverwaltung installieren
* _LiquidCrytal I2C_ von <https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library/archive/refs/heads/master.zip> -> mit Sketch>Bibliothek einbinden>.ZIP-Bibliothek hinzufügen installieren
* Tabellenkalkulationsprogramm mit CSV funktion zum auswerten der Daten
* [csv_to_plot](https://github.com/d4v1d-247/Ultrasonic-Code/tree/master/csv_to_plot) um eine Radargrafik zu erstellen

## Beschreibung
Das Radar. Erfunden von Heinrich Hertz im Jahr 1886 hat heutzutage in vielen Bereichen Anwendung. Es wird im Militär für U-Boote genutzt, um Hindernisse zu erkennen oder in der zivilen Luftfahrt, um die Position der Flugzeuge ausfindig zumachen. Eine Sachen haben sie gemeinsam. Beide Radare benötigen ein Ultraschallmessgerät um zu funktionieren. Ein Ultraschallmessgerät kann Distanzen in kürzester Zeit messen. Unsere Gruppe kam auf eine ähnliche Idee. Unser Ultraschallmessgerät kann zwar nur auf geringe Distanz messen, aber wenn man auf geringe Distanz misst kann man es so ähnlich nutzen wie bei U-Booten. Mit diesem Ultraschallmessgerät wollen wir Distanzen messen. Beachtet werden muss, dass es nur zwischen den Werten 5-150 cm funktioniert.  Wird unter oder über dieser Distanz gemessen werden die Werte ungenau und springt zwischen den Werten hin und her.

## Häufige Fragen und Probleme
### Pobleme bei der Programmierung
Die Pins des ESP-Controller wurden falsch genutzt. Das heißt ein Eingang wurde z.B. als Ausgang benutzt. Das funktioniert natürlich nicht. Es wäre wie, wenn man eine Tür von der falschen Seite öffnen würde.
### Allgemein
Das Ultraschallmessgerät kann ab einer Entfernung von unter 5 cm und über 150 cm nicht mehr genau messen und springt zwischen den Werten hin und her. Außerdem musste das Menü gelöscht werden, da nicht mehr genung Zeit zur Verfügung stand.
