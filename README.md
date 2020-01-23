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


