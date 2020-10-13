# Hardware setup

Hier lees je bondig welke materialen je nodig hebt om de audiovisuele installatie te kunnen bouwen, met een voorstel van mogelijke componenten en prijsindicaties.

## Componenten
* Projector:  H116ST Optoma (579€)
* Computer: Intel NUC (599€)
  * Intel Core i5
  * 8GB DDR4
  * 240GB SSD
* Audio shield: [Any](https://www.adafruit.com/product/1752) stereo amplifier (22,74€)
* Webcam: Logitech C270 (59€)
* Power supply: Stadium SRS100 (165€)
  * Deze voorziet zowel de NUC als het audio shield (en de speakers) van stroom
* Remote: om het even welke draadloze numpad (13€)
  * De applicatie gebruikt numerieke input om modi te selecteren
* [Speaker](https://benl.rs-online.com/web/p/speaker-drivers/1218639/) (2 x 22,10€)
  * De projector heeft een ingebouwde speaker, maar om kwalitatief beter geluid te krijgen plaats je best extra speakers
* Staander voor projector: [Quicklock QL400](https://www.gear4music.be/nl/PA-DJ-and-Verlichting/Quiklok-QL-400-Studio-Locator-Stand-for-Equipment/AEG?origin=product-ads&gclid=EAIaIQobChMIjYqWpLqT7AIVCtd3Ch0fogbVEAQYASABEgL5dvD_BwE) (109€)
* Plexiplaat om projector te monteren op de staander (30€)
* Kabels: zie schematische voorstelling voor de benodigde kabels

![Image of inside](images/inside.JPG)


![Image of inside](images/schematic.png)


### Assemblage

⚠️⚠️⚠️ *Werken met Power Supply Units houdt in dat je met blootliggende kabels onder hoge stroom werkt. Wees dus voorzichtig en werk onder toezicht!* ⚠️⚠️⚠️

Om ervoor te zorgen dat de encasing (zie onder) niet al te vaak moet worden opengevezen, besloten we te werken met invijsbare _throughplug adapters_.

### Projector

We selecteerden de H116ST Optoma omdat deze een voldoende brede projectiehoek aanbiedt tegen een aanvaardbare prijs. Bovendien ondersteunt de Optoma ook seriële input voor eventuele latere uitbreidingen.
De brede projectiehoek zorgt ervoor dat we vanop korte afstand toch op een groot oppervlak kunnen projecteren. Dit is uiteraard geen verplichting: als de ruimte groot genoeg is, kan men ook met een standaard projector werken. 
Let wel op: de webcam moet hetzelfde perspectief hebben als de projector om accuraat te calculeren waar die moet projecteren. Dit wil ook zeggen dat hoe verder de webcam moet 'kijken', hoe groter de markers moeten zijn.

De hoeveelheid [(ansi)-lumen](https://nl.wikipedia.org/wiki/Lumen_(eenheid)#:~:text=De%20lumen%20(symbool%3A%20lm),lichtbron%20in%20alle%20richtingen%20uitstraalt.) is ook van belang bij het selecteren van de projector: afhankelijk van hoeveel licht er in de ruimte valt, moet men al dan niet voor een hogere lichtopbrengst gaan. Dit is zeker het geval bij veel direct zonlicht.


### Raspberry Pi

In eerste instantie werd ernaar gekeken om de oplossing op een Raspberry Pi te laten draaien. Na verschillende videoproblemen met de RPI3 werd gekeken naar de RPI4 om ze op te lossen. Openframeworks bleken op het moment van opname van het tweede seizoen van Team Scheire (najaar 2019) nog niet te werken op de RPI4. We verlieten deze piste en besloten verder te gaan met de Intel NUC (beschreven in [Componenten](## Componenten)).

Ten tijde van dit schrijven (september 2020) deden we nieuwe tests met de RPI4. Openframeworks is nu compileerbaar, en de oplossing lijkt te builden. Helaas waren er nog steeds problemen met het loopen van video, het gebruik van transparante video en het algemeen gebruik van de computing power. Zo was het niet duidelijk of we een aanvaardbare framerate zouden verkrijgen. 

Om de oplossing op de RPI4 te laten draaien moet de rendering opgedeeld worden in verschillende threads, en moet de transparante video vervangen worden door een minder zwaar alternatief (bijvorbeeld GIF). Dit werd nog niet gerealiseerd, maar zou een logische en nuttige next step kunnen zijn.

## Encasing

We besloten het geheel in een 3D-geprinte case te omvatten. Dit was noodzakelijk om de steriele omgeving van het operatiekwartier te garanderen. Voor thuisgebruik is dit uiteraard optioneel (maar aan te raden om de setup bij elkaar te houden). We kozen ervoor de case meteen ook te gebruiken als klankkast voor de speakers. 
Alle bekabeling zit in de case. Onderaan de case werd een universal power cable plug voorzien voor stroom. Deze had zowel een schakelaar (om projector, NUC en speakers uit te zetten) als een zekering.

Het resultaat werd gemonteerd op een [mixer stand](https://www.bax-shop.be/nl/19-inch-racks/quiklok-ql-400-desktopstand?gclid=EAIaIQobChMIs6SFkMzG5QIViIxRCh3yJQK5EAQYGCABEgIFMPD_BwE). Omdat deze de projector zowel naar boven als naar beneden kan richten, kan er vlot gewisseld worden tussen muur- of plafondprojectie. 

