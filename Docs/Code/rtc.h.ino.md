# Infos zu aaaaa.ino

## Beschreibung 
Hier werden funktionen für die Echtzeituhr (RTC) definiert.

## Bereiche
### 011 - 022
Funktion um ein Datum über den Seriellen Monitor auszugeben.

### 024 - 055
Stellt die Uhr ein beim Start.

Wenn die Zeit der Uhr nicht eingestellt wurde, dann wird sie automatisch auf das Datum des letzten Hochladens vom Code gestellt, was zwar immer ein paar Sekunden ungenau sein wird, aber ausreichend genau sein sollte.

### 057 - 066
Hier wird eine Textversion des Datums und Uhrzeit erstellt, die für Dateinamen genutzt wird.
