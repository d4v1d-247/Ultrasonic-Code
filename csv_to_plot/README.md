# Erklärung zu csv_to_plot
## Installation
### Über Python
1. Python 3.7 oder neuer installieren. Dabei darauf achten, dass die "install PIP Package Manager" Option aktiviert ist
2. CSV_to_Radar.py und das Pipfile herunterladen
3. Mit ```python3 -m pip3 install pipenv --yes && python3 -m pipenv install``` Die benötigten Bibliotheken installieren (U.U. python3 durch py ersetzen, wenn Windows Python nicht finden kann)
4. Die CSV Datei, die man nutzen möchte in den gleichen Ordner kopieren, wie die .py Datei
5. Mit ```python3 -m pipenv run python3 CSV_to_Radar.py``` das Programm ausführen

### Mit der Exe Datei
1. CSV_to_Radar.exe herunterladen
2. Auf die Datei Rechtsklick machen und in den Eigenschaften unten bei Sicherheit auf "zulassen" klicken. Dies ist nötig, da ich die Datei nicht Signieren kann und sie von Windows als unsicher gekennzeichnet wurde.
3. Die CSV Datei, die man nutzen möchte in den gleichen Ordner kopieren, wie die .exe Datei
4. Mit Doppelklick das .exe Programm ausführen. Dies öffnet ein Schwarzes Fenster, was besonders beim ersten mal ein paar Sekunden braucht um das Diagramm zu erzeugen.

## Nutzung
Das Programm sucht nach .csv Dateien in dem Ordner, wo es sich befindet. Wenn mehrere existieren, ist nicht klar, welche genutzt wird :|

Es zeigt dann eine Interaktive Version des Diagramms an, welches wenn man mit der Maus rüberfährt unten Rechts die Werte der Mausposition anzeigt.
Gleichzeitig wird eine Bilddatei vom Diagramm erstellt.
