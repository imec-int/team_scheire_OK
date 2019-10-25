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
#include "MarkerClass.hpp"

class ArucoHandler {
public:
    
    void setup();
    void update();
    void draw(SurfaceGenerator* surfaces, bool DISPLAY_CAMERA);
    void setupSurfaces();
    
    ofxAruco aruco;
    ofVideoGrabber grabber;
    ofBaseVideoDraws * trackVideo;
    
    ofxXmlSettings xml;

    vector<MarkerClass> markerList;

    
    bool TRACK = false;
};



#endif /* MarkerClass_hpp */
