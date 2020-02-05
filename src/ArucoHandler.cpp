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
    ofTranslate(0,0,0);
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

    aruco.setup("intrinsics.int", grabber.getWidth(), grabber.getHeight());
    
    setupSurfaces();

	sender = s;


	saveBtn.addListener(this, &ArucoHandler::saveButtonPressed);


	ofxXmlSettings settings;
	settings.loadFile("settings.xml");
	
	ofVec3f v = ofVec3f(settings.getValue("settings:translateX", 0), settings.getValue("settings:translateY", 0), settings.getValue("settings:translateZ", 0));
	ofVec3f r = ofVec3f(settings.getValue("settings:rotateX", 0), settings.getValue("settings:rotateY", 0), settings.getValue("settings:rotateZ", 0));

	gui.setup();
	gui.add(translate.setup("translate", v, ofVec3f(-ofGetWidth(), -ofGetHeight(), -1000), ofVec3f(ofGetWidth(), ofGetHeight(), 1000)));
	gui.add(rotate.setup("rotate", r, ofVec3f(-90, -90, -90), ofVec3f(90, 90, 90)));
	gui.add(saveBtn.setup("save"));

	fbo.allocate(ofGetWidth(), ofGetHeight());
}

void ArucoHandler::update() {
	ofPushMatrix();
	
	ofRotateXDeg(rotate->x);
	ofRotateYDeg(rotate->y);
	ofRotateZDeg(rotate->z);

	
	
	ofTranslate(translate->x, translate->y, translate->z);

    if(TRACK) {
		grabber.update();

        if(grabber.isFrameNew()){

			grabber.getPixelsRef().mirror(true, false);
            aruco.detectBoards(grabber.getPixels());

        }
    }
	ofPopMatrix();

}

void ArucoHandler::draw(SurfaceGenerator* surfaces, bool DEBUG_MODE, bool DISPLAY_INTERACTION, bool DISPLAY_LOUIS, bool DISPLAY_CAM) {
	
    fbo.begin();
	ofClear(0, 0, 0);

	INTERACTION = DISPLAY_INTERACTION;
	LOUIS = DISPLAY_LOUIS;

    if(DISPLAY_CAM) { 
        grabber.draw(0, 0, ofGetWidth(), ofGetHeight());
    }
    vector<aruco::Marker> markers = aruco.getMarkers();
    
//    for (int i = 0; i < markers.size(); i++) {
//        
//        aruco.begin(i);
//        drawMarker(0.15, ofColor::white, markers.at(i).id);
////        ofDrawRectangle(-5, -5, 10, 10);
//        aruco.end();
//    }
//    
    
    if (markers.size() == 1) {
        drawOSC(surfaces, markers, DEBUG_MODE);
    }
    else {
        drawFile(surfaces, markers, DEBUG_MODE);
    }

	fbo.end();

	ofPushMatrix();
	

	ofTranslate(translate->x, translate->y, translate->z);
	
	
	ofTranslate(fbo.getWidth() / 2, fbo.getHeight() / 2);
	ofRotateXDeg(rotate->x);
	ofRotateYDeg(rotate->y);
	ofRotateZDeg(rotate->z);
	ofTranslate(-fbo.getWidth() / 2, -fbo.getHeight() / 2);

	
	//draw FBO
	fbo.draw(0, 0);
	ofPopMatrix();

	if (DEBUG_MODE) {
		int offset = 200;
		ofDrawBitmapStringHighlight("ox:" + ofToString(OSCOutputX), 50, offset);
		ofDrawBitmapStringHighlight("oy:" + ofToString(OSCOutputY), 50, offset + 20);
		ofDrawBitmapStringHighlight("ow:" + ofToString(OSCOutputWidth), 50, offset + 40);
		ofDrawBitmapStringHighlight("oh:" + ofToString(OSCOutputHeight), 50, offset + 60);
		ofDrawBitmapStringHighlight("vx:" + ofToString(OSCVideoX), 50, offset + 80);
		ofDrawBitmapStringHighlight("vy:" + ofToString(OSCOutputY), 50, offset + 100);
		ofDrawBitmapStringHighlight("vy:" + ofToString(OSCOutputZ), 50, offset + 120);
		ofDrawBitmapStringHighlight("vw:" + ofToString(OSCVideoWidth), 50, offset + 140);
		ofDrawBitmapStringHighlight("vh:" + ofToString(OSCVideoHeight), 50, offset + 160);
		ofDrawBitmapStringHighlight("s:" + ofToString(OSCScale), 50, offset + 180);
		ofDrawBitmapStringHighlight("p:" + ofToString(OSCPosition), 50, offset + 200);
		ofDrawBitmapStringHighlight("id:" + ofToString(curID), 50, offset + 220);
		ofDrawBitmapStringHighlight("numMarkers: " + ofToString(markers.size()), 50, offset + 240);

		gui.draw();

	}
}

void ArucoHandler::saveButtonPressed() {
	ofxXmlSettings settings;
	settings.setValue("settings:translateX", translate->x);
	settings.setValue("settings:translateY", translate->y);
	settings.setValue("settings:translateZ", translate->z);
	settings.saveFile("settings.xml");
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
				surfaces->draw(m.outputX, m.outputY, m.outputZ, m.outputWidth, m.outputHeight, m.position, m.scale, m.videoX, m.videoY, m.videoWidth, m.videoHeight, INTERACTION, LOUIS);
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
					sendMessage("/videoPosition", m.position);
					OSCScale = m.scale;
					std::cout << "current scale: " << m.scale << endl;
					sendMessage("/scale", m.scale);
					OSCOutputX = m.outputX;
					sendMessage("/outputX", m.outputX);
					OSCOutputY = m.outputY;
					sendMessage("/outputY", m.outputY);
					OSCOutputZ = m.outputZ;
					sendMessage("/outputZ", m.outputZ);
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
		
		surfaces->draw(OSCOutputX, OSCOutputY, OSCOutputZ, OSCOutputWidth, OSCOutputHeight, OSCPosition, OSCScale, OSCVideoX, OSCVideoY, OSCVideoWidth, OSCVideoHeight, INTERACTION, LOUIS);
			
		aruco.end();
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
        for(int j = 0; j < numberOfMarkers; j++){
            xml.pushTag("marker", j);
            MarkerClass marker;

            marker.setup(xml.getValue("ID", 0), xml.getValue("position", 0), xml.getValue("outputX", 0), xml.getValue("outputY", 0), xml.getValue("outputZ", 0), xml.getValue("outputWidth", 0), xml.getValue("outputHeight", 0), xml.getValue("videoX", 0), xml.getValue("videoY", 0), xml.getValue("videoWidth", 0), xml.getValue("videoHeight", 0), xml.getValue("scale", 0));
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

	ofDrawBitmapStringHighlight("msg:" + a, 50, 370);
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
		set.setValue("marker:outputZ", OSCOutputZ, lineNum);
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

	else if (a == "/videoPosition") {
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
	else if (a == "/outputZ") {
		OSCOutputZ = msg.getArgAsInt(0);
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
