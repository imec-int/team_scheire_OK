# Zelf aan de slag gaan - Git

Om dit project op je eigen computer te kunnen uitvoeren dien je eerst de hele online mapstructuur ("de repository") te downloaden naar je eigen lokale computer. Dit kun je doen door ofwel een `zip`file te downloaden, of door te werken via [git](https://git-scm.com/).

[git](https://git-scm.com/) is een versiebeheersysteem dat ervoor zorgt dat je code kan downloaden én kan zien welke aanpassingen er allemaal gebeurd zijn in het verleden. Dus ook als je zélf toevoegingen wilt doen kan dit via Git (denk: zelf code aanpassen, zelf nieuw beeldmateriaal toevoegen, zelf...)

Voor dit project wordt er gebruik gemaakt van zowel Git, voor alles code gerelateerd als Azure Blob storage om de media files te downloaden (audio en video bestanden).

## Stap 1: git installeren

Enkele intuïtieve grafische git programma's vind je op: [GUI clients](https://git-scm.com/downloads/guis/)

Voor Windows en Mac OS X kunnen we [Sourcetree](https://www.sourcetreeapp.com/) aanraden.


## Stap 2: deze repository clonen via sourcetree

om een lokale variant van de repository te hebben kun je in sourcetree volgende stappen ondernemen.

1. Open de Sourcetree applicatie
2. Klik boven in de applicatie op "new..." en "clone from URL" 
![sourcetree](images/sourcetree1.png)

3. Vul in het dialoogvenster:
	1. de link naar de website in: `https://github.com/imec-int/team_scheire_OK`
	2. de locatie naar waar je de folder wilt kopiëren
![sourcetree2](images/sourcetree2.png)

4. klik dan op `clone`
5. nu wordt de folder lokaal gekopieerd, wijzigingen die je hier in aan brengt zijn enkel aan je lokale kopie.
6. Heb je toevoegingen die je wilt bijbrengen aan de online repository, zodat alle gebruikers deze kunnen zien, dan kun je een "pull request" aanvragen. Je dient een aanvraag in tot verandering, die goed gekeurd kan worden door iemand anders. Een (engelstalige) tutorial kun je hier vinden: [youtube sourcetree pull request](https://www.youtube.com/watch?v=hxP3hzspSWs)



## Stap 3: Downloaden van media files

In de folder `team_scheire_OK/media` dienen audio- en video bestanden geplaatst te worden. Deze kun je downloaden via [volgende link](https://teamscheire2020.blob.core.windows.net/operatiekwartier). Download en plaats ze in deze folder zo dat de folderstructuur eruit ziet als:
`team_scheire_OK/media`

* `/audio_material`
* `/video_material`
* `file_format_NL.md`

