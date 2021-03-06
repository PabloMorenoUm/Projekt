# Projekt
C++ game project for karrieretutor® (team work, NOT my own work!!!)

# Zielsetzung
Ziel ist ein Rollenspiel, bestehend aus mehreren "Unterspielen", mit der Bibliothek 
[SFML](https://gamecodeschool.com/sfml-projects/). 

# Spielanleitung

Der Hauptcharakter namens Bob hat die Möglichkeit eines der vier Häuser zu betreten.
In jedem Haus verbirgt sich eines der folgenden Unterspiele.

## Pong
Der Klassiker unter den Computerspielen:
Bewege mit den Pfeiltasten [links] und [rechts] die Scheibe, um den Ball vor dem Aus 
(welches die untere Kante des Spielfelds ist) zu bewahren.
Sobald die obere Kante getroffen wurde, erhöht sich der Punktestand um einen Punkt.
Bei zehn Punkten ist dieses Spiel erfolgreich absolviert.
Allerdings wird der Ball bei jedem Aufprall gegen die bewegliche Scheibe und gegen die obere Kante schneller.

## Reaktionsspiel
Alle drei Sekunden leuchtet einer der Buchstaben rot oder grün.
Tippe bei grün diesen Buchstaben auf der Tastatur und du erhältst einen Punkt.
Tippe bei rot diesen Buchstaben auf der Tastatur und du verlierst einen Punkt.
Allerdings kann der Punktestand nicht negativ werden.
Auch hier ist das Spiel mit zehn Punkten absolviert.

## Vier Gewinnt
Auch ein Klassiker: Du spielst gegen den Computer und fängst an.
Du hast rote und der Computer gelbe Münzen.
Wer zuerst vier Münzen in einer Reihe (egal ob horizontal, vertikel oder diagonal) hat, gewinnt.
Sobald du dran bist, wähle eine Spalte aus, indem du eine der Zahlen 1 bis 7 auf deiner Tastatur tippst.
Drückst du anschließend auf [Enter], wirfst du deine rote Münze in die entsprechende Spalte.
Gleichzeitig wirft der Computer seine gelbe Münze in eine Spalte.
Dabei handelt der Computer nach dem [Minimax-Algorithmus](https://de.wikipedia.org/wiki/Minimax-Algorithmus) 
und durchsucht in jedem Zug mehrere [Spielbäume](https://de.wikipedia.org/wiki/Tiefensuche#Programmierung).

# Danksagung
Außerordenlichen Dank möchte ich Andreas Peterson und insbesondere Benedikt Schenk aussprechen für ihre
Hilfsbereitschaft und Geduld bei Fragen verschiedenster Art!!!
