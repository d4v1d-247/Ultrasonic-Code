# Projekt Ultraschallmessgerät

## Kurzbeschreibung
Von der Schule aus organisiertes Projekt zum Bau von Messgeräten.
In diesem Fall ein Ultraschallmessgerät, welches Entfernung und Geschwindigkeit messen und tabellarisch darstellen kann.

## Einleitung
Das Projekt "Ultraschallmessgerät" beschäftigt sich damit, ein Ultraschallmessgerät zu bauen und zu programmieren, dass später in der Schule zum Einsatz kommen soll. 

Dabei wird ein Schallimpuls vom Sensor ausgesendet und abgewartet, bis dieser von einem Objekt zurückreflektiert wird. Aus der Zeit vom aussenden bis zum Zurückkehren kann man nun mit der Schallgeschwindigkeit die Entfernung des Objekts vom Sensor berrechnen.

## Besonderheiten
- Da der Arduino Uno für diesen Fall nur begrenzt Pins und Speicher hat, haben wir uns für den Leistungsstärkeren ESP32 entschieden.
- Beim Hochladen muss man den _BOOT_ knopf des ESPs gedrückt halten, da er sonst keine Daten annimmt.
- Die Echtzeituhr, die auch wenn das Gerät ausgeschaltet ist weiterhin die Zeit misst, braucht alle paar Jahre eine neue Batterie. Falls diese einmal ausfällt, muss man das Datum über den Seriellen Monitor neu setzen, damit Ordner- und Dateinamen richtig sind. Dies funktioniert indem man ```setdate YYYY-MM-DD HH:MM:SS``` sendet, wobei YYYY durch das Jahr, MM durch den Monat, DD durch den Tag, HH durch die Stunde, MM durch die Minute und SS durch die aktuelle Sekunde ersetzt wird. (In die Sekunde kann man auch einfach 00 schreiben, dass ist nicht so wichtig.)
- Der Grund, warum ein Drehknopf statt einem normalen verwendet wurde ist, dass Anfangs geplant war, ein Menü mit verschiedenen Auswahlmöglichkeiten einzubauen. Dies war dann aber aus Zeitgründen nicht möglich.

## Aufgaben zum Projekt
1. Mache der Anleitung entgegenführend den Testaufbau
2. Baue danach den richtigen Aufbau auf und lade den _großen_ Code hoch.
3. Messe eine Strecke mit dem Ultraschallmessgerät und prüfe das Ergebnis z.B. mit einem Linear nach.
5. Drücke den Start/Stopknopf. Nimm das Gerät in die Hand und richte den Ultraschallsensor so aus, dass er von dir weg zeigt. Mache eine 360° Drehung um dich selbst. Drücke den Start/Stopknopf.
5. Messe sehr kleine und besonders große Strecken. Beobachte die Ergebnisse
6. Stelle eine Theorie auf, weshalb die Ergebnisse der Messung bei sehr kleinen/großen Strecken falsch sind.
