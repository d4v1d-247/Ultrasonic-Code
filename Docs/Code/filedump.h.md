# Infos zu filedump.h
## Beschreibung
Diese Datei enthält Funktionen zum Schreiben auf die SD Karte.

## Bereiche
### 007 - 038
Hier wird das Schreiben auf die SD Karte vorbereitet.
Zuerst wird ein Ordner mit dem aktuellen Datum und dann eine Datei mit der aktuellen Uhrzeit erstellt.

In diese Datei wird dann die Spaltenüberschrift der Tabelle geschrieben.

### 040 - 073
Hier werden Funktionen definiert, die die eigentlichen Daten auf die Speicherkarte schreiben.
