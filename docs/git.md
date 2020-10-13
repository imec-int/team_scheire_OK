# Zelf aan de slag gaan

Om dit project op je eigen computer te kunnen uitvoeren dien je eerst de hele online mapstructuur ("de repository") te downloaden naar je eigen lokale computer. Dit kun je doen door ofwel een zipfile te downloaden, of door te werken via [git](https://git-scm.com/).

[git](https://git-scm.com/) is een versiebeheersysteem dat ervoor zorgt dat je code kan downloaden én kan zien welke aanpassingen er allemaal gebeurd zijn in het verleden. Ook als je zélf toevoegingen wil doen kan dit via Git (denk bijvoorbeeld aan zelf code aanpassen, zelf nieuw beeldmateriaal toevoegen, ...)

Voor dit project wordt gebruik gemaakt van zowel Git -voor alles code gerelateerd- als Azure Blob storage om de media files te downloaden (audio en video bestanden).

## Stap 1: git installeren

Enkele intuïtieve grafische git programma's vind je op: [GUI clients](https://git-scm.com/downloads/guis/)

Voor Windows en Mac OS X kunnen we [Sourcetree](https://www.sourcetreeapp.com/) aanraden.


## Stap 2: deze repository clonen via sourcetree

Om een lokale variant van de repository te hebben, kan je in Sourcetree volgende stappen ondernemen:

1. Open de Sourcetree-applicatie
2. Klik bovenaan de applicatie op "New..." en "Clone from URL" 
![sourcetree](images/sourcetree1.png)
3. Vul volgende info aan in het dialoogvenster:
	1. Link naar de website:`https://github.com/imec-int/team_scheire_OK`
	2. Locatie naar waar je de folder wil kopiëren
![sourcetree2](images/sourcetree2.png)

4. Klik op "Clone"
5. De folder wordt nu lokaal gekopiëerd. Wijzigingen die je hier aanbrengt worden *enkel* lokaal opgeslagen!
6. Wil je toevoegingen of wijzigingen delen met andere gebruikers in de online repository? Vraag dan een "Pull request" aan in Sourcetree. Je dient dan een aanvraag tot verandering in die goedgekeurd kan worden door iemand anders. Een Engelstalige tutorial kan je hier vinden: [YouTube sourcetree pull request](https://www.youtube.com/watch?v=hxP3hzspSWs)



## Stap 3: Downloaden van media files

In de folder `team_scheire_OK/media` dienen audio- en video bestanden geplaatst te worden. Deze kun je downloaden via [volgende link](https://teamscheire2020.blob.core.windows.net/operatiekwartier/files.zip). Download de files, pak ze uit en plaats ze in deze folder zo dat de folderstructuur eruit ziet als:
`team_scheire_OK/media/`

* `audio_material/`
* `video_material/`
* `file_format_NL.md`

