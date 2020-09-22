# fysieke opstelling

Voor het team scheire project:

- een operatie kamer met daarin:
	- een projectorsetup (zie [hardware setup](hardware_NL.md))
![Image of physical setup](images/physical-scheme.png)
	- markers op beide muren en op het plafond.
![Image of marker locations setup](images/markerloc.png)
		

## Markers

De markers zijn belangerijk voor de Aruco library. Indien deze gedetecteerd worden door de library kan deze afleiden welke marker het is en in welke orientatie deze zich bevindt. Door deze orientatie dan toe te passen op de beelden komt de automatische mapping tot stand. 

Het is dan ook belangrijk dat de markers groot genoeg zijn (in ons geval minstens A3), en niet op reflecterend papier afgeprint worden (don't make our mistakes). 

Markers kunnen gegenereerd worden met bijvoorbeeld [een online tool](https://chev.me/arucogen/), het is echter aangeraden de ID van de gegenereerde marker reeds toe te voegen aan de `bin/data/presets.xml` file.

![Image of a marker](images/marker.png)
