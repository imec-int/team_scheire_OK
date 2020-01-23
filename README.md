# TeamScheire

## project topic

[Team Scheire](https://www.canvas.be/team-scheire) is a canvas production in which they present the maker movement.

The use-case chosen for the 2nd season of Team Scheire by imec is creating an aid for anaesthetize children. Very often they are terrified in the hospitals.

A solution has been created in the form of an immersive enviroment in which the kids themselves interact.

### the immersive environment

By ways of projection we create an immersive environment. Kids get to choose between two worlds (ocean or space) in which actions have been mapped which they need to perform in real life. 

### the props

kids get to choose their props, making the transition to the Operations Room a lot smoother. Plus, they are less afraid of the 'tools' being handed to them, as they had the chance to familiarize themselves with it

## hardware setup


### Components
* Projector:  H11ST optoma
* Computer: Intel NUC
  * Intel core i5
  * 8GB DDR4
  * 240GB SSD
* Audio shield: [Any](https://www.adafruit.com/product/1752) stereo amplifier
* Webcam: Logitech C270
* Power supply: Stadium SRS100
* Remote: any wireless numpad

## software setup

Visual content created in Unity

### Prerequisits 

OSX: 

* [Openframeworks](https://openframeworks.cc/download/)
* xcode
  *	 [Setup guide](https://openframeworks.cc/setup/xcode/) 

Windows: 

* Visual studio
  * [Setup guide](https://openframeworks.cc/setup/vs)


### Openframeworks

Openframeworks is an open source C++ based framework, supercharged with addons. The application uses the following addons:

* [ofxAruco](https://github.com/arturoc/ofxAruco)
* [ofxCv](https://github.com/kylemcdonald/ofxCv)
* ofxGui - (included)
* [ofxHapPlayer](https://github.com/bangnoise/ofxHapPlayer)
* ofxOpenCv - (included)
* ofxOsc - (included)
* ofxPoco - (included)
* ofxXmlSettings - (included)

To run the actual application, you will need to build it specifically for your machine, first use the project generator to create the appropriate files. If the build and adding of plugins succeed, us the appropriate editor (xcode for mac, VS code for windows) to build and execute the project. After doing this, the application can be run by using the application that can be found in the `/bin` folder. 

#### OSC

The application has two modes, either preset or live. This can be altered using the numpad remote. To setup the presets, we made use of OSC. 

For those unfamiliar with OSC: it is a communications standard along the lines of MIDI, which uses channels and accompanying values to correspond with another OSC enabled application. 

I specifically used touchOsc, a (sadly paying) app that can connect to the openframeworks application using the IP of the NUC. 

#### Aruco

Aruco markers are used to determine how far the wall is and which orientation should be used. The markers used in the final application are printed on A3 at least. We had to do this to ensure the image would be stable and easily findable by the physicians. 

Each aruco marker has an unique ID, which is (using the OSC app) connected to a certain part of the video, and a certain transformation (width, height, x- and y-offset). This can be set up by having a connected OSC app and only haveing one marker visible by the system. The editmode is automatically activated when only one can be found.

#### Presets
