## software setup

Visual content created either :

- in Unity (see [video creation](software_video_creation.md))
- in directory //TODO// (=> ga ervan uit dat iemand dit net gecloned heeft!)

### Prerequisites 


* an installed version of [Openframeworks](https://openframeworks.cc/download/)



### Openframeworks

Openframeworks is an open source C++ based framework, supercharged with addons. 

//TODO// Waarom gebruiken we ofx? Wat is dit voor software?

The application uses the following addons:

* [ofxAruco](https://github.com/arturoc/ofxAruco)
* [ofxCv](https://github.com/kylemcdonald/ofxCv)
* ofxGui - (included)
* [ofxHapPlayer](https://github.com/bangnoise/ofxHapPlayer)
* ofxOpenCv - (included)
* ofxOsc - (included)
* ofxPoco - (included)
* ofxXmlSettings - (included)

To run the actual application, you will need to compile it specifically for your machine (or crosscompile for the intended machine). First use the project generator to create the appropriate files. If the build and adding of plugins succeed, us the appropriate editor (xcode for mac, VS code for windows) to build and execute the project. After doing this, the application can be run by using the application that can be found in the `/bin` folder. 

There are ways to run openframeworks by just using `make` and `make run`, by setting the openframeworks path in `.bash_profile`.

#### OSC

The application has two modes, either preset or live. This can be altered using the numpad remote. To setup the presets, we made use of OSC. 

For those unfamiliar with OSC: it is a communications standard along the lines of MIDI, which uses channels and accompanying values to correspond with another OSC enabled application. 

I specifically used touchOsc, a (sadly paying) app that can connect to the openframeworks application using the IP of the NUC. 

//TODO//: keystone?

#### Aruco

Aruco markers are used to determine how far the wall is and which orientation should be used. The markers used in the final application are printed on A3-size at least. We had to do this to ensure the image would be stable and easily findable by the physicians (TODO: when focusing the projector or how should I interprete this?). 

Each aruco marker has a unique ID, which is (using the OSC app) connected to a certain part of the video, and a certain transformation (width, height, x- and y-offset). This can be set up by having a connected OSC app and only haveing one marker visible by the system. The editmode is automatically activated when only one can be found.


#### video settings and surfaces

The video input works with 3 layers for the wall, and 3 layers for the ceiling, all encoded in HAP (to enable transparency). Both for the ceiling and the walls, the setup is the same.

The first layer is the background, and should be named as follows:

* `~/[water or space]/[wall or ceiling]_background.mov`
* `~/[water or space]/[wall or ceiling]_foreground.mov`
* `~/[water or space]/[wall or ceiling]_interaction.mov`

These three video's will be layered on top of each other each loop, in an FBO. In the draw function, every surface can ask for a part of the FBO to display in the right orientation.

The hospital makes use of a mascot to calm the kids in the initial intake video they watch. We tried to have it come back in the installation, as a common, recognisable element might calm them down even further. There are three video files used for this, representing three different positions this mascot (called "Groene Louis") can display. 

The touchOsc app allows for adapting the orientation of the video displays. This is applied to each surface individually, and not from a global perspective.

Every surface knows a few properties in the touchOsc setup. 
initially, you can set the part of the video you want to use. You can set the x- and y-offset, and the width and height of the subsection in the videoframe.

Secondly, you can adjust the positioning and size of the surface, with the following settings:

* X-, Y- and Z-offset
* Width
* Height
* Scale

#### Presets

The presets can be used in area's where the markers are not available or not an option. This was added after conversations where it became clear sometimes the installation could have been usefull in examine rooms or other area's of the hospital. 

One of the standard presets we added was a fortyfive degrees angle up, so that the projector and setup could be aimed at a corner and work out of the box. These are basically three areas (two for the walls and one for the ceiling), angled at ninety degrees of each other. 

The presets know a lot of settings while adding them, listed bellow

* Width and height
* X-, Y- and Z-offset
* Rotation on three axis
* Video X- and Y-offset
* Video width and height


#### Shortcuts

To work with the application, a few "shortcuts" have been defined. In the initial run, we used a wireless numpad to controll the application

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



* Debug mode: Display the boxes around found markers

### Tutorial
//TODO// build tutorial: step by step: copy the git folder, then what?