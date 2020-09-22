## software setup

Visual content created either:

- in Unity (see [video creation](./software_video_creation))
- in directory //TODO// (=> ga ervan uit dat iemand dit net gecloned heeft!)





### Prerequisites 


* Een reeds geïnstalleerde versie van [Openframeworks](https://openframeworks.cc/download/), beschikbaar op zowel OSX, windows als op linux.
* TouchOSX, geïnstalleerd op GSM


### Openframeworks

Openframeworks is een open source C++ based framework, supercharged met addons. 

//TODO// Waarom gebruiken we ofx? Wat is dit voor software?

Openframeworks is een framework ontwikkeld door Zach Lieberman als een toolbox voor creative coding (oa dus voor interactieve video installaties zoals in dit project). Het is sindsdien opgenomen door de open source crowd en kent nog steeds uitbreidingen en updates. We kozen voor openframeworks omdat de detectie van Aruco markers (gezien onze deadline) het snelst implementeerbaar was door het gebruik van addons. Daarbij komende de addons voor OSC en interface design.


om het project te kunnen builden hebben we nood aan volgende plugins. Sommigen zijn reeds in openframeworks aanwezig, anderen moeten aan deze folder toegevoegd worden. Je kan dit doen door deze  manueel te downloaden en toe te voegen aan de `addons` folder in openframeworks.

* [ofxAruco](https://github.com/arturoc/ofxAruco)
* [ofxCv](https://github.com/kylemcdonald/ofxCv)
* ofxGui - (included)
* [ofxHapPlayer](https://github.com/bangnoise/ofxHapPlayer)
* ofxOpenCv - (included)
* ofxOsc - (included)
* ofxPoco - (included)
* ofxXmlSettings - (included)

#### Install OpenFrameWorks

//TODO// link plaatsen voor installeren op NUC

#### From git to build

* Download en extract deze repository via zipfile of download via git 
* Kopieer `arucoMap` naar  `openframeworks/apps/myApps`
* Gebruik de projectGenerator om het project aan te maken

//TODO// Heb je hier een afbeelding van? (Of nog beter: een GIF! => screen record en dan via ffmpeg converteren, supereasy)

Het builden van het project verschilt van OS tot OS

##### Mac

!!! ofxHapPlayer is niet beschikbaar voor mac, deze kan vervangen worden door ofVideoPlayer, maar dan moeten bepaalde lijnen (getError) verwijderd worden. Daarnaast mag je ook niet vergeten deze uit de addons.make file te halen.

* Open het project in xcode
* gebruik de build functionaliteiten om de applicatie te builden en te runnen

Je kan dit ook builden en runnen met "make" en "make run", daarvoor neem je volgende stappen:

* kopieer de emptyproject folder (VAN WAAR NAAR WAAR?)
* kopieer de `/src` en `/bin` folder naar de nieuw aangemaakte folder
* kopieer (en vervang dus) de `addons.make` file door deze uit het gedownloade project
* in een terminal, navigeer naar deze folder, en run volgend command: `make && make run`

//TODO// Probeer hier nog te verduidelijken wat waar komt, geef eventueel een projectstructuur mee hoe die er op het einde moet uitzien

##### windows
* Open het project in VSCode
* gebruik de build functionaliteiten om de applicatie te builden en te runnen

##### Linux
* kopieer de emptyproject folder
* kopieer de `/src` en `/bin` folder naar de nieuw aangemaakte folder
* kopieer (en vervang dus) de `addons.make` file door deze uit het gedownloadde project
* in een terminal, navigeer naar deze folder, en run volgend command: `make && make run`


Na het builden van het project kan u de applicatie opstarten. Deze geeft echter initieel een zwart scherm. Dit is omdat de applicatie draait in "Live" modus, en nog geen markers kan detecteren. Markers worden namelijk enkel gedetecteerd indien de tracking modus aan staat. dit gebeurt terwijl de knop "T" of "6" ingehouden wordt. Indien er slechts 1 marker gedetecteerd word, kan je hiervan het te projecteren vlak instellen via OSC (zie hfst OSC). Dit moet natuurlijk initieel gebeuren om de eerste vlakken aan te maken. 



#### OSC

//TODO// Hier 'snap' ik niet waarvoor OSC gebruikt wordt, kun je ofwel afbeeldingen toevoegen ofwel eerst vertellen hoe de opstelling eruit ziet? Anders is het moeilijk om in te beelden waarom OSC of projection mapping gebruikt wordt. Vandaar dan zeggen wanneer we 'preset' gebruiken en wanneer 'live'. Ook wat die presets zijn. Ik heb reeds ook [fysieke opstelling](fysieke_opstelling.md) gemaakt om te kunnen verwijzen naar hoe de ruimte eruit had gezien.

De applicatie kent twee modi, zowel preset als live. Je kan dit aanpassen via de remote numpad (0 zijnde live, 1 tot 3 zijnde presets). De presets tonen een vooringestelde configuratie van vlakken, de live view staat toe de camera te gebruiken om markers te detecteren en op basis hiervan vlakken te projecteren. Om deze vlakken, of die van de presets in te stellen maken we gebruik van OSC. OSC is een communicatiemethode die te vergelijken valt met MIDI, waar deze kan communiceren met anderen OSC enabled devices via channels.

TouchOSC werd gebruikt om deze vlakken in te stellen. De file die hiervoor nodig is bevind zich in de "additions" folder.
I specifically used touchOsc, a (sadly paying) app that can connect to the openframeworks application using the IP of the NUC. 

Indien de applicatie is ingesteld op "live", en er slechts een marker zichtbaar is, kan je hiervan de view instellen via TouchOSC. Vergeet niet het juiste IP adres in te stellen in `settings.hpp`.

//TODO// Voeg de afbeelding toe van je GSM voor touchOSC

##### Live


| Name | Function |
| ------------- |:-------------:|
| Scale | Schaal van het projectievlak |
| **Output** | **Projectievlak instellingen** |
| X | Horizontale positie | 
| Y | Verticale positie  |
| Z | Diepte positie |
| Width | Breedte van het vlak |
| Height | Hoogte van het vlak |
| **Video** | **Video input instellingen** |
| X | Horizontale positie | 
| Y | Verticale positie  |
| Width | Breedte van de crop |
| Height | Hoogte van de crop |
| Ceiling | Gebruik de ceiling video ipv de wall video | 
| Write | Instellingen oplaan |


##### Presets

❗️❗️❗️ "Edit mode" moet ingeschakeld staan om wijzigingen te kunnen aanbrengen. ❗️❗️❗️

| Name | Function |
| ------------- |:-------------:|
| Previous preset | Vorige preset |
| Next preset | Volgende preset |
| Delete preset | Verwijder huidige preset |
| **Video** | **Video input instellingen** |
| X | Horizontale positie | 
| Y | Verticale positie  |
| Width | Breedte van de crop |
| Height | Hoogte van de crop |
| **Positionering** | **Positie instellingen** |
| Width | Breedte van de preset |
| Height | Hoogte van de preset |
| X | Horizontale positie | 
| Y | Verticale positie  |
| Z | Diepte positie  |
| RX | Horizontale rotatie | 
| RY | Verticale rotatie  |
| RZ | Diepte rotatie  |


#### Aruco

Aruco markers worden gebruikt om de applicatie te vertellen op welke vlakken (de muren, het plafond, ...)  deze behoort te projecteren. De markers die wij gebruikten zijn ten minste A3 formaat om zeker te zijn dat de webcam deze accurraat kan detecteren. Hoe groter deze zijn, hoe beter de resultaten. Eens de applicatie opstart, en de gebruiker de tracking activeert, worden de markers gezocht door de `ArucoHandler.cpp` class. Dit is het moment waarop het belangrijk is de projector en de webcam juist te aligneren. 

Elke aruco marker kent een uniek ID, die gebruikt kan worden om een bepaald deel van een video te projecteren, met een bepaalde transformatie (width, height, x- and y-offset). 


#### video settings and surfaces

De video input kent drie video lagen voor de muren, en drie voor het plafond, allen geëncodeerd in [HAP](https://hap.video/) (om transparantie te ondersteunen).

De eerste laag is de achtergrond, de opeenvolgenden worden hierover gelegd:

* `~/[water or space]/[wall or ceiling]_background.mov`
* `~/[water or space]/[wall or ceiling]_foreground.mov`
* `~/[water or space]/[wall or ceiling]_interaction.mov`

//TODO// Waarvoor de tilde? Refereert dit echt naar /home/pi/ ofzo? 

 Dit kan welliswaar worden aangepast in de code om slechts 1 video te gebruiken, al zou dit ervoor zorgen dat het interactiegedeelte niet meer werkt.

//TODO// FBO?

**Een FBO wordt eerst opgebouwt in de update functie door de drie videolagen opeen gelegd. Deze kan nadien in de draw fucntie gebruikt worden door de transformatie aangehaald door de aruco class.** //TODO// vreemde zinsbouw 
Dit gebeurt door de transformatie, die de aruco class herkent, aan te vullen met informatie ingegeven door de OSC class. 

Het hospitaal maakt gebruik van een mascotte, genaamd groene Louis. We probeerden deze terug te laten komen in de installatie, om de kinderen een vertrouwd beeld te geven in een onzeker moment. Groene Louis springt in beeld vanuit één zijde door gebruik te maken van shortcut "4" of "L". Hierdoor konden de dokters dit aanroepen wanneer ze deze nodig hadden.


#### Presets

De presets kunnen gebruikt worden in locaties waar de markers niet opgehangen kunnen worden of niet aanwezig zijn. Dit bijvoorbeeld in een dokterskwartier of dergelijke. De presets geven een voor-ingestelde opstelling weer van vlakken. De eerste hiervan kan gebruikt worden op de kruising tussen twee muren en het plafond. De tweede is een vast projectievlak (rechtvoor).

//TODO// rechtvoor = recht tegenover de projector?

Om deze presets in te stellen, zie OSC.


#### Shortcuts

We gebruikten een draadloze numpad om binnen een steriele omgeving de applicatie te kunnen gebruiken. 

| Function | Key |
| ------------- |:-------------:|
| Track markers | 6 / T |
| Display live | 0 | 
| Display Preset 1 | 1 |
| Display Preset 2 | 2 |
| Display Preset 3 | 3 |
| Display overlay interaction | 4 / L |
| Display in-video interaction | 5 / I |
| Debug mode* | 7 / V |
| Show webcam image | 8 / C |
| Mute sound | 9 |
| Load space scene | - / S |
| Load water scene | + / W |
| Play sound | . |



* Debug mode: Weergave van de indicatie rond gevonden aruco markers

### Known issues

Er zijn een paar problemen waar we weet van hebben, maar waar we ten tijde van filmen niet de tijd voor hadden om deze op te lossen

#### Mapping Z-offset

1. De locatie van de projecties op basis van de markers kent een probleem waarbij de Z offset slecht ingesteld staat. Dit heeft invloed op de multiplier van de grootte van de projecties. 

2. De OSC layout mist een aantal labels.