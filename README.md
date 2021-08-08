# Projekt
C++ game project for karrieretutor® (team work, NOT my own work!!!)

# Zielsetzung, Quellen, Urheberrechte
Ziel ist ein Rollenspiel, bestehend aus mehreren "Unterspielen", mit der Bibliothek 
[SFML](https://gamecodeschool.com/sfml-projects/). 
In Anlehnung an die [hierin](https://gamecodeschool.com/sfml-projects/) enthaltenen Tutorials wurde das Spiel 
entwickelt und einige Figuren übernommen. 
Vier Gewinnt ist inspiriert durch [diese](https://www.igpm.rwth-aachen.de/Download/ss17/mapra/ma4.pdf) Empfehlung.

Zum Testen nutzen wir die Frameworks 
[doctest](https://github.com/onqtam/doctest) und 
[fakeit](https://github.com/eranpeer/FakeIt).

Alle Hintergrundbilder wurden aus [Freepik](http://www.freepik.com) 
(Aufrufdatum: 19., 24., 25., 28. Juli und 8. August 2021) übernommen 
und einige Icons aus [Flaticon](https://www.flaticon.com/de/) und 
[icons8](https://icons8.com/icon/set/popular/doodle) (Aufrufdatum beide 28.7.). 
Wir besitzen keine Urheberrechte darauf, ebenso wenig auf den 
[Helenenmarsch](https://www.youtube.com/watch?v=cetLSNBnPiA) 
(Aufrufdatum 6. April 2021), der in diesem Spiel verarbeitet wurde.

Für die Entwicklung verwenden wir C++20 und [CLion](https://www.jetbrains.com/de-de/clion/).


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