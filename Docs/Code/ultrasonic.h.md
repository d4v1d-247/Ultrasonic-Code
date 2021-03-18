# Infos zu ultrasonic.h

## Beschreibung 
Hier wird die Funktion um den Abstand zu messen definiert.

## Bereiche
### 011
Das ist die Geschwindigkeit von Schall in Millimeter pro Mikrosekunde geteielt durch 2

### 013 - 020
Hier ist die funktion zum berechnen der Entfernung.
Zuerst wird ein kurzes Signal an den Sensor gegeben (Z. 14 - 16) und dann wird die Zeit gemessen, bis das Echo kommt (Z. 18) und das ergebnis berechnet und zurückgegeben.
