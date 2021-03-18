# Anleitung

## Wie im Bild das Gerät aufbauen

## Bibliotheken installieren
* _Arduino-IDE -> Datei -> Voreinstellungen -> Zusätzliche Boardverwalter-URLs ->_ ```https://dl.espressif.com/dl/package_esp32_index.json,http://arduino.esp8266.com/stable/package_esp8266com_index.json``` einfügen
* ```RTC by Makuna``` Version 2.3.4 und ```LiquidCrystal I2C``` von Frank de Brabander Version 1.1.2 über _Werkzeuge -> Bibliotheken verwalten..._ installieren

## Testcode hochladen
```C++
// Hier werden die Pins für den Sensor definiert.
// Wenn der Code nicht funktioniert, musst du diese 
// u.U. auf andere umstellen.
const byte sensor_trigger = 2;
const byte sensor_echo = 3;

void setup() {
  Serial.begin(9600);
}

// Die Millimeter, die Schall in einer Mikrosekunde zurücklegt mal 2
const float mmPerMicroS2 = 0.1716;

uint16_t dist_mm(byte trigger_pin, byte echo_pin) {
  /* Diese Funktion misst den Abstand zum nächsten Objekt und gibt
  ihn in Millimeter zurück. */
  
  // Einen kurzen Impuls am Ultraschallsensor ausgeben
  digitalWrite(trigger_pin, HIGH);
  delay(50);
  digitalWrite(trigger_pin, LOW);

  // Ab dem Aufruf der Funktion wird die Zeit gemessen, bis am
  // Pin der Wert auf HIGH geht.
  // Wird in Mikrosekunden ausgegeben
  uint16_t microseconds = pulseIn(echo_pin, HIGH, 30000);
  
  // Die Mikrosekunden geteielt durch die Konstante zurückgeben
  return microseconds / mmPerMicroS2;
}

void loop() {
  // hier wird die Messung vom Sensor immer wieder am Seriellen Monitor ausgegeben.
  Serial.print("Disatanz:" );
  Serial.println(dist_mm(sensor_trigger, sensor_echo));
}
```
Wenn das Hochladen nicht funktioniert, aber der Code erfolgreich getestet wird, dann muss man beim Hochladen den _BOOT_ Knopf gedrückt halten.
Das Messgerät sollte nun die Entfernung zum Sensor in Millimeter über den Seriellen Monitor ausgeben.

## Kompletten Code hochladen
Wenn alles funktioniert hat, dann kannst du nun den "großen" Code herunterladen und installieren.

1. Den Code von GitHub herunterladen: ```https://github.com/d4v1d-247/Ultrasonic-Code/archive/master.zip```
2. Dann muss man die Datei irgendwohin entpacken.
3. Dort befindet sich dann ein Unterordner mit dem Namen _Code_ in dem du dann die Datei _aaaaa.ino_ öffnen musst. 
4. Nun noch den Code hochladen und fertig! Auf dem Display sollte jetzt der Hauptbildschirm angezeigt werden.
