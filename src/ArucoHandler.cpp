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

void ArucoHandler::setup(ofxOscSender s) {


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

	sender = s;

}

void ArucoHandler::update() {
    if(TRACK) {
        trackVideo->update();

        if(trackVideo->isFrameNew()){
            aruco.detectBoards(trackVideo->getPixels());

        }
    }

}

void ArucoHandler::draw(SurfaceGenerator* surfaces, bool DEBUG_MODE, bool DISPLAY_INTERACTION) {
	INTERACTION = DISPLAY_INTERACTION;

    if(DEBUG_MODE) {
        trackVideo->draw(0, 0, ofGetWidth(), ofGetHeight());
    }
    vector<aruco::Marker> markers = aruco.getMarkers();
	if (DEBUG_MODE) {
		ofDrawBitmapStringHighlight("numMarkers: " + ofToString(markers.size()), 50, 50);
	}
	if (markers.size() == 1) {
		drawOSC(surfaces, markers, DEBUG_MODE);
	}
	else {
		drawFile(surfaces, markers, DEBUG_MODE);
	}
}

void ArucoHandler::drawFile(SurfaceGenerator* surfaces, vector<aruco::Marker> markers, bool DEBUG_MODE) {

	for (int i = 0; i < markers.size(); i++) {

		aruco.begin(i);
		if (DEBUG_MODE) {
			drawMarker(0.15, ofColor::white, markers.at(i).id);
		}
		for (int j = 0; j < markerList.size(); j++) {
			if (markerList.at(j).id == markers.at(i).id) {
				MarkerClass m = markerList.at(j);
				surfaces->draw(m.outputX, m.outputY, m.outputWidth, m.outputHeight, m.position, m.scale, m.videoX, m.videoY, m.videoWidth, m.videoHeight, INTERACTION);
			}
		}

		aruco.end();
	}

}

void ArucoHandler::drawOSC(SurfaceGenerator* surfaces, vector<aruco::Marker> markers, bool DEBUG_MODE) {
	for (int i = 0; i < markers.size(); i++) {

		aruco.begin(i);
		if (DEBUG_MODE) {
			drawMarker(0.15, ofColor::white, markers.at(i).id);
		}
		if (curID != markers.at(i).id) {

			curID = markers.at(i).id;
			for (int j = 0; j < markerList.size(); j++) {
				if (markerList.at(j).id == curID) {
					MarkerClass m = markerList.at(j);
					OSCPosition = m.position;
					sendMessage("/position", m.position);
					OSCScale = m.scale;
					std::cout << "current scale: " << m.scale << endl;
					sendMessage("/scale", m.scale);
					OSCOutputX = m.outputX;
					sendMessage("/outputX", m.outputX);
					OSCOutputY = m.outputY;
					sendMessage("/outputY", m.outputY);
					OSCOutputWidth = m.outputWidth;
					sendMessage("/outputWidth", m.outputWidth);
					OSCOutputHeight = m.outputHeight;
					sendMessage("/outputHeight", m.outputHeight);
					OSCVideoX = m.videoX;
					sendMessage("/videoX", m.videoX);
					OSCVideoY = m.videoY;
					sendMessage("/videoY", m.videoY);
					OSCVideoWidth = m.videoWidth;
					sendMessage("/videoWidth", m.videoWidth);
					OSCVideoHeight = m.videoHeight;
					sendMessage("/videoHeight", m.videoHeight);
				}
			}
		}
		surfaces->draw(OSCOutputX, OSCOutputY, OSCOutputWidth, OSCOutputHeight, OSCPosition, OSCScale, OSCVideoX, OSCVideoY, OSCVideoWidth, OSCVideoHeight, INTERACTION);
			
		aruco.end();
	}

	if (DEBUG_MODE) {

		ofDrawBitmapStringHighlight("id:" + ofToString(curID), 50, 290);
		ofDrawBitmapStringHighlight("ox:" + ofToString(OSCOutputX), 50, 90);
		ofDrawBitmapStringHighlight("oy:" + ofToString(OSCOutputY), 50, 110);
		ofDrawBitmapStringHighlight("ow:" + ofToString(OSCOutputWidth), 50, 130);
		ofDrawBitmapStringHighlight("oh:" + ofToString(OSCOutputHeight), 50, 150);
		ofDrawBitmapStringHighlight("vx:" + ofToString(OSCVideoX), 50, 170);
		ofDrawBitmapStringHighlight("vy:" + ofToString(OSCOutputY), 50, 190);
		ofDrawBitmapStringHighlight("vw:" + ofToString(OSCVideoWidth), 50, 210);
		ofDrawBitmapStringHighlight("vh:" + ofToString(OSCVideoHeight), 50, 230);
		ofDrawBitmapStringHighlight("s:" + ofToString(OSCScale), 50, 250);
		ofDrawBitmapStringHighlight("p:" + ofToString(OSCPosition), 50, 270);
	}
}

void ArucoHandler::sendMessage(string channel, int value) {
	ofxOscMessage msg;
	msg.setAddress(channel);
	msg.addFloatArg(value);
	sender.sendMessage(msg);
} 
void ArucoHandler::setupSurfaces() {
	markerList.clear();
    if(xml.loadFile("markers.xml")){
        xml.pushTag("markers");
        int numberOfMarkers = xml.getNumTags("marker");
        std::cout << "num markers found: " << numberOfMarkers << endl;
        for(int j = 0; j < numberOfMarkers; j++){
            xml.pushTag("marker", j);
            MarkerClass marker;
            std::cout << "xml pos: " << xml.getValue("position", 0) << endl;

            marker.setup(xml.getValue("ID", 0), xml.getValue("position", 0), xml.getValue("outputX", 0), xml.getValue("outputY", 0), xml.getValue("outputWidth", 0), xml.getValue("outputHeight", 0), xml.getValue("videoX", 0), xml.getValue("videoY", 0), xml.getValue("videoWidth", 0), xml.getValue("videoHeight", 0), xml.getValue("scale", 0));
            markerList.push_back(marker);
            xml.popTag();
        }
        xml.popTag();
    }
    else{
        ofLogError("Position file did not load!");
    }
}

void ArucoHandler::handleOSC(ofxOscMessage msg) {
	string a = msg.getAddress();

	if (a == "/accxyz") {
		// do nothing, always coming in
	}
	else if (a == "/write") {
		// write to the file 
		std::cout << "saving" << endl;
		ofxXmlSettings set;
		set.loadFile("markers.xml");
		set.pushTag("markers");


		int numberOfMarkers = set.getNumTags("marker");
		int indexFound = -1;
		std::cout << "num markers found: " << numberOfMarkers << endl;
		for (int j = 0; j < numberOfMarkers; j++) {
			set.pushTag("marker", j);
			std::cout << set.getValue("ID", 0) << endl;
			if (set.getValue("ID", 0) == curID) {
				indexFound = j;
			}
			set.popTag();
		}
		if (indexFound != -1) {
			set.removeTag("marker", indexFound);
		}
		int lineNum = set.addTag("marker");
		set.setValue("marker:ID", curID, lineNum);
		set.setValue("marker:position", OSCPosition, lineNum);
		set.setValue("marker:scale", OSCScale, lineNum);
		set.setValue("marker:outputX", OSCOutputX, lineNum);
		set.setValue("marker:outputY", OSCOutputY, lineNum);
		set.setValue("marker:outputWidth", OSCOutputWidth, lineNum);
		set.setValue("marker:outputHeight", OSCOutputHeight, lineNum);
		set.setValue("marker:videoX", OSCVideoX, lineNum);
		set.setValue("marker:videoY", OSCVideoY, lineNum);
		set.setValue("marker:videoWidth", OSCVideoWidth, lineNum);
		set.setValue("marker:videoHeight", OSCVideoHeight, lineNum);
		set.popTag();
		set.saveFile("markers.xml");

		setupSurfaces();

	}

	else if (a == "/position") {
		OSCPosition = msg.getArgAsInt(0);
	}
	else if (a == "/scale") {
		OSCScale = msg.getArgAsFloat(0);
	}
	else if (a == "/outputX") {
		OSCOutputX = msg.getArgAsInt(0);
	}
	else if (a == "/outputY") {
		OSCOutputY = msg.getArgAsInt(0);
	}
	else if (a == "/outputWidth") {
		OSCOutputWidth = msg.getArgAsInt(0);
	}
	else if (a == "/outputHeight") {
		OSCOutputHeight = msg.getArgAsInt(0);
	}
	else if (a == "/videoX") {
		OSCVideoX = msg.getArgAsInt(0);
	}
	else if (a == "/videoY") {
		OSCVideoY = msg.getArgAsInt(0);
	}
	else if (a == "/videoWidth") {
		OSCVideoWidth = msg.getArgAsInt(0);
	}
	else if (a == "/videoHeight") {
		OSCVideoHeight = msg.getArgAsInt(0);
	}
	if (a != "/accxyz") {

		std::cout << msg.getAddress() << "val: " << msg.getArgAsInt(0) << endl;
	}
}