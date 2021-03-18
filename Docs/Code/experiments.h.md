# Infos zu experiments.h
## Beschreibung
In dieser Datei werden die Inhalte fürs Display generiert.
Dies ist entweder die aktuelle Uhrzeit oder die aktuelle Distanz.

## Bereiche
### 005 - 009
Hier werden variablen definiert, die später wichtig sind.
```exp_starttime``` und ```exp_runninng``` sind für die Berechnung der aktuell vergangenen Zeit und ```exp_time``` und ```exp_data``` ist für die Berechnung der Geschwindigkeit.

### 011 - 046
In Zeile 15 bis 20 wird gecheckt, ob das Experiment schon am laufen war oder gerade gestartet wurde. Wenn es gerade gestartet wurde werden Variablen zur Berechnung der relativen Zeit seit dem Start gesetzt.

In Zeile 22 bis 28 wird dann die aktuelle Entfernung gemessen und die Geschwindigkeit berechnet.

In Zeile 30 bis 39 werden die Daten und die relative Zeit auf dem Display angezeigt.

Zeile 42 speichert die Daten auf der SD Karte.

### 048 - 066
Dieser Teil ist die "Standard" funktion fürs Display, die immer dann angezeigt wird, wenn gerade kein Experiment läuft.

Zeile 52 bis 58 zeigt die aktuelle Uhrzeit und das Datum auf dem Display an

und Zeile 60 bis 65 gibt eine kurze Fehlermeldung auf dem Display aus, wenn es ein Problem mit der SD Karte gibt.
