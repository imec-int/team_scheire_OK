//
//  ArucoHandler.cpp
//  TeamScheireV2
//
//  Created by Jan Everaert on 07/10/2019.
//


#ifndef ArucoHandler_hpp
#define ArucoHandler_hpp

#include "ArucoHandler.hpp"

#include <stdio.h>
#include "ofMain.h"

#include "ofxAruco.h"
#include "SurfaceGenerator.hpp"
#include "ofxXmlSettings.h"
#include "ofxOsc.h"
#include "MarkerClass.hpp"
#include "ofXml.h"
class ArucoHandler {
public:
    
    void setup(ofxOscSender s);
    void update();
    void draw(SurfaceGenerator* surfaces, bool DEBUG_MODE, bool DISPLAY_INTERACTION);
    void setupSurfaces();
    
	void handleOSC(ofxOscMessage msg);
	void drawFile(SurfaceGenerator* surfaces, vector<aruco::Marker> markers, bool DEBUG_MODE);
	void drawOSC(SurfaceGenerator* surfaces, vector<aruco::Marker> markers, bool DEBUG_MODE);
	void sendMessage(string channel, int value);

    ofxAruco aruco;
    ofVideoGrabber grabber;
    ofBaseVideoDraws * trackVideo;

	ofxOscSender sender;
    
    ofxXmlSettings xml;

    vector<MarkerClass> markerList;

    
    bool TRACK = false;
	bool INTERACTION = false;


	float OSCScale = 0.001;
	int OSCOutputX = 0;
	int OSCOutputY = 0;
	int OSCOutputWidth = 200;
	int OSCOutputHeight = 200;
	int OSCVideoX = 0;
	int OSCVideoY = 0;
	int OSCVideoWidth = 1024;
	int OSCVideoHeight = 512;
	int OSCPosition = 0;

	int curID = 0;
};



#endif /* MarkerClass_hpp */
