//
//  SurfaceGenerator.cpp
//  TeamScheireV2
//
//  Created by Jan Everaert on 07/10/2019.
//

#include "SurfaceGenerator.hpp"

SurfaceGenerator::SurfaceGenerator() {
	ofEnableAlphaBlending();

	loadNewSource("water");

	wall_videoFBO.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
	ceiling_videoFBO.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);

	wall_videoFBO.begin();
	ofClear(0, 0, 0, 0);
	wall_videoFBO.end();

	ceiling_videoFBO.begin();
	ofClear(0, 0, 0, 0);
	ceiling_videoFBO.end();

	

}


void SurfaceGenerator::handleOSC(ofxOscMessage msg) {
	string a = msg.getAddress();
	if (a == "/keystoneV") {
		keyStoneV = msg.getArgAsFloat(0);
	}
	if (a == "/keystoneH") {
		keyStoneH = msg.getArgAsFloat(0);
	}
}

void SurfaceGenerator::update() {
    

    wall_background.update();
    wall_foreground.update();
    wall_interaction.update();

	ceiling_background.update();
	ceiling_foreground.update();
	ceiling_interaction.update();

	// prep walls
	wall_videoFBO.begin();
    ofEnableAlphaBlending();
    ofClear(0, 0, 0, 0);
	wall_background.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
	wall_interaction.draw(0, 0, ofGetWidth(), ofGetHeight());
	wall_foreground.draw(0, 0, ofGetWidth(), ofGetHeight());
    ofDisableAlphaBlending();
    wall_videoFBO.end();
  
	
    // prep ceiling
	ceiling_videoFBO.begin();
	ofEnableAlphaBlending();
	ofClear(0, 0, 0, 0);
	ceiling_background.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
	ceiling_interaction.draw(0, 0, ofGetWidth(), ofGetHeight());
	ceiling_foreground.draw(0, 0, ofGetWidth(), ofGetHeight());
	ofDisableAlphaBlending();
	ceiling_videoFBO.end();
	
}

void SurfaceGenerator::draw(int drawX, int drawY, int drawWidth, int drawHeight, int position, float scale, int subX, int subY, int subWidth, int subHeight, bool INTERACTION) {
	if (INTERACTION) {
		if (!wall_interaction.isPlaying()) {
			wall_interaction.play();
		}
		
		if (!ceiling_interaction.isPlaying()) {
			ceiling_interaction.play();
		}
		
	}

	ofPushMatrix();
	ofScale(scale / 10000);
	ofTranslate(drawWidth / 2, drawHeight / 2);
	ofRotateY(keyStoneV);
	ofRotateX(keyStoneH);
	ofTranslate(-drawWidth / 2, -drawHeight / 2);
	if (position == 0) {

		if (wall_background.isLoaded()) {
			wall_videoFBO.getTexture().drawSubsection(drawX, drawY, drawWidth, drawHeight, subX, subY, subWidth, subHeight);
		}
		else {
			if (wall_background.getError().length())
			{
				// std::cout << background.getError() << endl;
				ofDrawBitmapStringHighlight(wall_background.getError(), ofGetWidth() / 2, 20);
			}
			else
			{
				ofDrawBitmapStringHighlight("Background is loading...", ofGetWidth() / 2, 20);
			}

			if (wall_foreground.getError().length())
			{
				// std::cout << background.getError() << endl;
				ofDrawBitmapStringHighlight(wall_foreground.getError(), ofGetWidth() / 2, 20);
			}
			else
			{
				ofDrawBitmapStringHighlight("foreground is loading...", ofGetWidth() / 2, 20);
			}
			if (wall_interaction.getError().length())
			{
				// std::cout << background.getError() << endl;
				ofDrawBitmapStringHighlight(wall_interaction.getError(), ofGetWidth() / 2, 20);
			}
			else
			{
				ofDrawBitmapStringHighlight("interaction is loading...", ofGetWidth() / 2, 20);
			}
		}
	}
	else {

		if (ceiling_background.isLoaded()) {
			ceiling_videoFBO.getTexture().drawSubsection(drawX, drawY, drawWidth, drawHeight, subX, subY, subWidth, subHeight);
		}
		else {
			if (ceiling_background.getError().length())
			{
				// std::cout << background.getError() << endl;
				ofDrawBitmapStringHighlight(ceiling_background.getError(), ofGetWidth() / 2, 20);
			}
			else
			{
				ofDrawBitmapStringHighlight("Background is loading...", ofGetWidth() / 2, 20);
			}

			if (ceiling_foreground.getError().length())
			{
				// std::cout << background.getError() << endl;
				ofDrawBitmapStringHighlight(ceiling_foreground.getError(), ofGetWidth() / 2, 20);
			}
			else
			{
				ofDrawBitmapStringHighlight("foreground is loading...", ofGetWidth() / 2, 20);
			}
			if (ceiling_interaction.getError().length())
			{
				// std::cout << background.getError() << endl;
				ofDrawBitmapStringHighlight(ceiling_interaction.getError(), ofGetWidth() / 2, 20);
			}
			else
			{
				ofDrawBitmapStringHighlight("interaction is loading...", ofGetWidth() / 2, 20);
			}
		}
	}

	ofPopMatrix();
    
}

void SurfaceGenerator::loadNewSource(std::string source) {
    
	wall_background.load(source + "/wall_background.mov");
	wall_background.play();
	wall_foreground.load(source + "/wall_foreground.mov");
	wall_foreground.play();
	wall_interaction.load(source + "/wall_interaction.mov");
	wall_interaction.setLoopState(OF_LOOP_NONE);
	wall_interaction.play();

	
	ceiling_background.load(source + "/ceiling_background.mov");
	ceiling_background.play();
	ceiling_foreground.load(source + "/ceiling_foreground.mov");
	ceiling_foreground.play();
	ceiling_interaction.load(source + "/ceiling_interaction.mov");
	ceiling_interaction.setLoopState(OF_LOOP_NONE);
	ceiling_interaction.play();
    
}



