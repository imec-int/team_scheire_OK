# Video creatie

- [Video creatie](#video-creatie)
	- [Technische vereisten](#technische-vereisten)
		- [Video afmetingen](#video-afmetingen)
		- [Bestandsformaat](#bestandsformaat)
	- [Compositing](#compositing)
		- [Achtergrond](#achtergrond)
		- [Interactie](#interactie)
		- [Voorgrond](#voorgrond)
	- [Beeldmateriaal maken met Unity](#beeldmateriaal-maken-met-unity)
		- [Unity installeren](#unity-installeren)
		- [Project openen](#project-openen)
		- [Opbouw van het project](#opbouw-van-het-project)
		- [Een simpele animatie maken](#een-simpele-animatie-maken)
			- [Voorbereiding](#voorbereiding)
			- [Animatie opzetten](#animatie-opzetten)
			- [Animeren](#animeren)
		- [De animatie uitrenderen](#de-animatie-uitrenderen)
		- [Waar kan ik extra modellen vinden?](#waar-kan-ik-extra-modellen-vinden)
	- [Converteren naar hap formaat](#converteren-naar-hap)
		- [Een bestaande video omzetten](#een-bestaande-video-omzetten)
		- [Een afbeeldingen sequentie omzetten](#een-afbeeldingen-sequentie-omzetten)

Om een mooie interatieve projectie te maken hebben we meerdere video files nodig. Je kan deze video files maken met veel verschillende open en gesloten software of met bestaand beeldmateriaal. Je kan bijvoorbeeld aan de slag gaan met 3D animatie software zoals [Blender](https://www.blender.org/) of misschien werk je liever met 2D animatie software? Voor Team Scheire zijn we gegaan voor een game engine als animatie software: [Unity](https://unity.com/).

Welke software je gebruikt maakt niet uit, maar verifieer of de software de onderstaande technische vereisten kan ondersteunen.

#TODO: add some more software suggestions

## Technische vereisten

Voor elk thema hebben we 6 video bestanden nodig:

1. plafond/achtergrond.mov
2. plafond/interactie.mov
3. plafond/voorgrond.mov
4. muren/achtergrond.mov
5. muren/interactie.mov
6. muren/voorgrond.mov

### Video afmetingen

- De voorgrond en interactie videos bevatten een alpha kanaal #todo waarom, waarvoor dient een alpha kanaal
- De video moet loopen (eerste en laatste frame zijn hetzelfde, opdat een gebruiker niet merkt dat er een einde is aan de video)
- Bij voorkeur is elke video 2048x1024 pixels #todo minimaal?
- Bij voorkeur is de framerate 30 afbeeldingen per seconde(fps) #todo minimaal?

### Bestandsformaat

Alle 6 van deze bestanden moeten van het `.mov` formaat zijn en daarbovenop moeten ze in het [hap](https://hap.video/) formaat geëncodeerd worden. Het voordeel van het `hap` formaat is dat het efficiënt kan afgespeeld worden, hierdoor heeft de projectie hardware lagere performantie vereisten. Het formaat kan ook goed om met transparantie in de video files wat we nodig hebben voor de `interactie` en `voorgrond` video files.

Je kan bijna eender welk videoformaat of afbeeldingen sequentie eenvoudig omzetten naar hap zie: [Converteren naar hap](#converteren-naar-hap)

## Compositing

De drie videos gaan in lagen over elkaar getoond worden door de [projectie software](./software_video_map_NL.md), dit proces van samenvoegen heet compositing.
Let dus op dat je video files rekening houden met de mogelijkheden en beperkingen van compositing.

In de afbeelding zie je goed hoe de drie lagen over elkaar gelegd worden om het uiteindelijk resultaat te bekomen. Let op de (voorgrond) visjes die bovenop de kist (interactie laag) zwemmen.
![Compositing](./images/Compositing.gif)

### Achtergrond

De achtergrond video is de basislaag voor de projectie, zorg er dus voor dat deze volledig gevuld is. Elk geanimeerd object dat nooit voor de interactie laag komt kan in deze laag gestoken worden.

![Achtergrond](./images/background.png)

### Interactie
De interactie laag is de tussenlaag waar het kind of de arts controle over zal hebben. Deze laag zit bovenop de achtergrond. Zorg er dus voor dat je transparantie gebruikt.

![Interactie](./images/interaction.png)

### Voorgrond
De voorgrond laag komt bovenop de interactie laag en geeft meer diepte aan de projectie door nog animatie bovenop de interactie laag mogelijk te maken.

![Voorgrond](./images/foreground.png)


## Beeldmateriaal maken met Unity

Deze tutorial gaat enkel over de basis van Unity heb je interesse om er meer over te leren kan je de officiële cursussen volgen (Engelstalig): [https://learn.unity.com/](https://learn.unity.com/)

### Unity installeren

Om te starten download je de Unity Hub: [https://unity3d.com/get-unity/download](https://unity3d.com/get-unity/download)

Dit is een launcher om verschillende Unity installaties te beheren.

Na installatie van de hub installeer je de laatste LTS release van Unity. Dit zijn stabielere versies met lange ondersteuning in de voorbeelden hieronder is dat 2019.4. 
> ❗Latere versies kunnen mogelijk afwijken van deze handleiding.

![Unity Installatie](./images/UnityInstall.png)

### Project openen

Je kan een startproject vinden in de folder `unity_base_project`. Je kan ook je eigen project aanmaken maar dit startproject staat al vooraf ingesteld met de nodige dependencies (specifieke benodigdheden) en configuraties.

Voeg het project eerst toe aan de Unity Hub met de `Add` knop. Open daarna het project door op het project in de lijst te klikken.

![Unity Project](./images/UnityProject.png)

### Opbouw van het project

In de folder Scenes vind je 3 Scenes:

 - Background
 - Interaction
 - Foreground 

Elke scene gaan we uitrenderen als een aparte video. Dit maakt het makkelijker om ze te onderscheiden.

Je kan ook kijken naar de scene in `Scenes/Validation/VideoTestScene` deze scene is opgezet om je finale .mov files uit te testen en te valideren binnenin Unity.

### Een simpele animatie maken

Omdat Unity een game engine is, kan je een animatie maken via code maar ook via een timeline zoals andere animatiesoftware. In deze handleiding beperken we ons tot het gebruiken van een timeline, voor meer info over hoe je met code animeert zie: [https://learn.unity.com/](https://learn.unity.com/)

#### Voorbereiding
Vooraleer we beginnen, moeten we ervoor zorgen dat de resolutie correct staat.

1. Open de game window (zie afbeelding)
2. Klik op de resolutie knop: `Free Aspect`
![Capsule maken](./images/SetResolution.png)
3. Hier kies je voor 2048x1024, als deze preset nog niet bestaat kan je het zelf aanmaken door op het plus icoontje te klikken.
![Capsule maken](./images/CreateResolution.png)

#### Animatie opzetten
1. Plaats je object in de scene door het vanuit je project folder in de scene te slepen
   - Als voorbeeld gaan we werken met een capsule object, dit kan je aanmaken in het menu via `GameObject/3D Object/Capsule`.
   ![Capsule maken](./images/CreateCapsule.png)
2. Open de timeline window ![Timeline openen](./images/OpenTimeline.png)
   - Je kan deze timeline overal plaatsen door de titel van de window te slepen naar een andere locatie
3. Zorg ervoor dat je object geselecteerd is, daarna kan je in de timeline window op create klikken om de animatie director aan te maken. ![Director maken](./images/CreateDirector.png)
    - Unity gaat vragen waar je deze wil opslaan, dit mag eender waar in het project maar zorg ervoor dat de naam overeenkomt met de naam van je scene om het overzichtelijk te houden.
4. Open het menu van je nieuwe animatie director door het aan te klikken in de Project window. Zorg ervoor dat de Frame rate op 30 staat ipv van 60. ![Director Settings](./images/InteractionAnimation.png)

#### Animeren
1. Start de opnamesessie door op de rode knop te drukken in de timeline 
   - De balk zal rood worden en het knopje zal flikkeren om aan te duiden dat je animatie aan het opnemen is. ![Opname starten](./images/Record.png)
2. Je kan nu het object bewegen met de gizmo ![Gizmo](./images/Gizmo.png) in de `Scene` view of via de `Transform` in de `Inspector` window. ![Animatie bouwen](./images/Animatie.png) #todo kort zeggen wat gizmo is
3. Door stapsgewijs het object te verplaatsen of roteren en de timeline in tijd verder te slepen kan je je animatie opbouwen. ![Voorbeeld animatie](./images/Playback.gif)
4. Je kan meerdere objecten animeren door ze vanuit de `Hierarchy` Window in je timeline te slepen en ze als `animation track` toe te voegen.
   ![Complexere voorbeeld animatie](./images/LightAnimation.gif)

### De animatie uitrenderen

Als je klaar bent met je animatie, is het tijd om het uit te renderen: We gaan van onze animatie een video maken door het eerst uit te renderen als afzonderlijke afbeeldingen.

1. Open de Unity `recorder` window ![Recorder openen](./images/OpenRecorder.png)
2. Alles staat al vooraf correct ingesteld, je kan dus gewoon op `Start	recording` drukken.
![Recorder window](./images/Recorder.png)
3. Afhankelijk van hoe zwaar je animatie is, kan dit proces even duren. Als je animatie uitgespeeld is, kan je drukken op `Stop recording`.

Je kan nu je volledige animatie terug vinden in de `recordings` folder. Je zal zien dat hier nu een hele hoop `.png` afbeeldingen staan. Deze png's nemen ook het alpha kanaal mee maar moeten nu nog omgezet worden naar een `.mov`, zie [Converteren naar hap](#converteren-naar-hap).

### Waar kan ik extra modellen vinden?

Een rijk gevulde scene met veel mooie modellen maken van de projectie een mooi spektakel. 

Je kan deze modellen zelf maken met software (zoals Blender) maar je kan ook online mooie modellen vinden op:

- [Sketchfab](https://sketchfab.com/3d-models?date=week&features=downloadable&sort_by=-likeCount) 
- [Unity Asset Store](https://assetstore.unity.com/?category=3d&free=true&orderBy=1)

Er zijn nog vele andere model bibliotheken let wel op sommige zijn betalend of hebben een limiterende licentie en mag je mogelijk niet gebruiken. Als de licentie [CreativeCommons](https://creativecommons.org/licenses/by/4.0/) is kan je het vrij gebruiken.

Voorbeeld Sketchfab CreativeCommons: 

![Sketchfab CreativeCommons](./images/License.png)

## Converteren naar hap

#TODO: write proper installation guide and on how to open a command line?

Om te converteren kan je gebruik maken van [ffmpeg](https://ffmpeg.org).

ffmpeg kan je installeren op Mac, Windows of Linux, de installers kan je hier vinden: [https://ffmpeg.org/download.html](https://ffmpeg.org/download.html)


### Een bestaande video omzetten

Voor achtergrond lagen kan je bijna alles gebruiken van video materiaal omdat transparantie niet nodig is hier.

Je kan bijna eender welke video omzetten via:
`ffmpeg -i mijnVideo.mp4 -c:v hap mijnVideo.mov`

Heb je een video die alsnog transparantie bevat?
Gebruik dan: `ffmpeg -i mijnVideoBron.mov -c:v hap -format hap_alpha mijnVideoOutput.mov`

> ℹ️ Tip: Sommige online footage zijn gemaakt met green screens. Dergelijke video met een effen achtergrond kan je via [chroma keying](https://www.youtube.com/watch?v=HEdRzRJIQLU) in video software alsnog omzetten naar een transparantie laag geschikt voor de interactie of voorgrond lagen.

### Een afbeeldingen sequentie omzetten

Heb je zelf een afbeeldingen sequentie uitgerendered met Unity of andere software?
Je kan dan deze afbeeldingen in éen enkele stap samenvoegen en converteren naar een video van het juiste formaat.

- Met transparantie: `ffmpeg -r 30 -s 2048x1024 -i image_%04d.png -vcodec hap -format hap_alpha -pix_fmt rgba mijnVideo.mov`
- Zonder transparantie: `ffmpeg -r 30 -s 2048x1024 -i image_%04d.png -vcodec hap -format hap -pix_fmt rgb mijnVideo.mov`

Afhankelijk van de gebruikte software kan de naamgeving verschillen van de gemaakte afbeeldingen. Bij Unity is elk afbeelding genummerd met een prefix: 0001, 0002, 0003, ...
Zijn je afbeeldingen zonder prefix gebruikt dan `image_%d.png` in het commando.
