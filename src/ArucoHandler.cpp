//
//  ArucoHandler.cpp
//  TeamScheireV2
//
//  Created by Jan Everaert on 07/10/2019.
//

#include "ArucoHandler.hpp"

#include <stdio.h>
#include "ofMain.h"



void drawMarker(float size, const ofColor & color, int id){
    ofDrawAxis(size);
    ofPushMatrix();
    ofPushStyle();
    ofTranslate(0,size*0.5,0);
    ofFill();
    ofSetColor(color,50);
    ofDrawBox(size);
    ofNoFill();
    ofSetColor(color);
    ofDrawBox(size);
    ofDrawBitmapString(id, 0, 0);
    ofPopStyle();
    ofPopMatrix();
    
}

void ArucoHandler::setup() {


	//     setting aruco track
	for (int i = 0; i < grabber.listDevices().size(); i++)
	{		
		std::cout << grabber.listDevices().at(i).deviceName << endl;
	}
	grabber.setDeviceID(0);
    grabber.initGrabber(1024, 768);
    trackVideo = &grabber;

    aruco.setup("intrinsics.int", trackVideo->getWidth(), trackVideo->getHeight());
    
    setupSurfaces();

}

void ArucoHandler::update() {
    if(TRACK) {
        trackVideo->update();

        if(trackVideo->isFrameNew()){
            aruco.detectBoards(trackVideo->getPixels());

        }
    }
}

void ArucoHandler::draw(SurfaceGenerator* surfaces, bool DISPLAY_CAMERA) {
    if(DISPLAY_CAMERA) {
        trackVideo->draw(0, 0, ofGetWidth(), ofGetHeight());
    }
    vector<aruco::Marker> markers = aruco.getMarkers();
    for(int i = 0; i < markers.size(); i++) {
        
        aruco.begin(i);
        drawMarker(0.15, ofColor::white, markers.at(i).id);
        
        for(int j = 0; j < markerList.size(); j++) {
            if(markerList.at(j).id == markers.at(i).id) {
                MarkerClass m = markerList.at(j);
                surfaces->draw(m.outputX, m.outputY, m.outputWidth, m.outputHeight, 0, m.scale, m.videoX, m.videoY, m.videoWidth, m.videoHeight);
            }
        }
        
        aruco.end();
    }
}


void ArucoHandler::setupSurfaces() {
    if(xml.loadFile("markers.xml")){
        xml.pushTag("markers");
        int numberOfMarkers = xml.getNumTags("marker");
        std::cout << "num markers found: " << numberOfMarkers << endl;
        for(int j = 0; j < numberOfMarkers; j++){
            xml.pushTag("marker", j);
            MarkerClass marker;
            std::cout << "xml scale: " <<  xml.getValue("scale", 1) << endl;

            marker.setup(xml.getValue("ID", 0), xml.getValue("outputX", 0), xml.getValue("outputY", 0), xml.getValue("outputWidth", 0), xml.getValue("outputHeight", 0), xml.getValue("videoX", 0), xml.getValue("videoY", 0), xml.getValue("videoWidth", 0), xml.getValue("videoHeight", 0), xml.getValue("scale", 1));
            markerList.push_back(marker);
            xml.popTag();
        }
        xml.popTag();
    }
    else{
        ofLogError("Position file did not load!");
    }
}
