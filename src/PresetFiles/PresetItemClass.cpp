//
//  PresetItemClass.cpp
//  TeamScheireV2
//
//  Created by Jan Everaert on 09/10/2019.
//

#include "PresetItemClass.hpp"


void PresetItemClass::setup(string ha = "test", int w = 200, int h = 200, int xO = 50, int yO = 50, int zO = 50, float xR = 0, float yR = 0, float zR = 0, int vSX = 0, int vSY = 0, int vW = 200, int vH = 200) {
    handle = ha;
    width = w;
    height =h;
    xOffset = xO;
    yOffset = yO;
    zOffset = zO;
    xRotation = xR;
    yRotation = yR;
    zRotation = zR;
    
    vStartX = vSX;
    vStartY = vSY;
    vWidth = vW;
    vHeight = vH;
    
}

void PresetItemClass::draw(SurfaceGenerator* surfaces, bool INTERACTION) {
    
    ofDrawAxis(200);
    
    ofPushMatrix();
    ofTranslate(xOffset, yOffset, zOffset);
    ofRotateXDeg(xRotation);
    ofRotateYDeg(yRotation);
    ofRotateZDeg(zRotation);
    ofPushStyle();
    //    ofSetColor(255, 255, 255, 255);
    ofNoFill();
    // ofDrawRectangle(-width / 2, -height / 2, width, height);
	if (handle == "wall") {
		surfaces->draw(0, 0, width, height, 0, 6000, vStartX, vStartY, vWidth, vHeight, INTERACTION);
	}
	if (handle == "ceiling") {
		surfaces->draw(0, 0, width, height, 1, 6000, vStartX, vStartY, vWidth, vHeight, INTERACTION);
	}

    
    ofPopStyle();
    ofPopMatrix();
}
