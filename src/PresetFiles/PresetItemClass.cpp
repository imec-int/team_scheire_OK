//
//  PresetItemClass.cpp
//  TeamScheireV2
//
//  Created by Jan Everaert on 09/10/2019.
//

#include "PresetItemClass.hpp"


void PresetItemClass::setup(int p, int w = 200, int h = 200, int xO = 50, int yO = 50, int zO = 50, float xR = 0, float yR = 0, float zR = 0, int vSX = 0, int vSY = 0, int vW = 200, int vH = 200) {
	position = p;
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


void PresetItemClass::update(int p, int w = 200, int h = 200, int xO = 50, int yO = 50, int zO = 50, float xR = 0, float yR = 0, float zR = 0, int vSX = 0, int vSY = 0, int vW = 200, int vH = 200) {
	position = p;
	width = w;
	height = h;
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

void PresetItemClass::draw(SurfaceGenerator* surfaces, bool INTERACTION, bool DISPLAY_LOUIS) {
    
    ofDrawAxis(200);
    
    ofPushMatrix();

	ofTranslate(xOffset, yOffset, zOffset);

	ofTranslate(height / 2, width / 2);
    ofRotateXDeg(xRotation);
    ofRotateYDeg(yRotation);
    ofRotateZDeg(zRotation);
	ofTranslate(-height / 2, -width / 2);


    ofPushStyle();
    //    ofSetColor(255, 255, 255, 255);
    ofNoFill();
    // ofDrawRectangle(-width / 2, -height / 2, width, height);
	surfaces->draw(0, 0, width, height, position, 6000, vStartX, vStartY, vWidth, vHeight, INTERACTION, DISPLAY_LOUIS);
	
    
    ofPopStyle();
    ofPopMatrix();
}
