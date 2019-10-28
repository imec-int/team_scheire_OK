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



	videoFBO.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);

	videoFBO.begin();
	ofClear(0, 0, 0, 0);
	videoFBO.end();

	

}


void SurfaceGenerator::update() {
    
    background.update();
    foreground.update();
    interaction.update();
    
    videoFBO.begin();

	
    ofEnableAlphaBlending();
    ofClear(0, 0, 0, 0);
    
	
    background.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());

	interaction.draw(0, 0, ofGetWidth(), ofGetHeight());
	foreground.draw(0, 0, ofGetWidth(), ofGetHeight());

    
    
    ofDisableAlphaBlending();
	
    videoFBO.end();
    
    
}

void SurfaceGenerator::draw(int drawX, int drawY, int drawWidth, int drawHeight, int SOURCE, float scale, int subX, int subY, int subWidth, int subHeight) {
	std::cout << scale << endl;
	if (background.isLoaded()) {
		
		ofPushMatrix();
		ofScale(scale / 10000);
		videoFBO.getTexture().drawSubsection(drawX, drawY, drawWidth, drawHeight, subX, subY, subWidth, subHeight);


		ofPopMatrix();
		
		// background.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
	}
	else {

		if (background.getError().length())
		{
			// std::cout << background.getError() << endl;
			ofDrawBitmapStringHighlight(background.getError(), 20, 20);
		}
		else
		{
			ofDrawBitmapStringHighlight("Background is loading...", 20, 20);
		}

		if (foreground.getError().length())
		{
			// std::cout << background.getError() << endl;
			ofDrawBitmapStringHighlight(foreground.getError(), 20, 20);
		}
		else
		{
			ofDrawBitmapStringHighlight("foreground is loading...", 20, 20);
		}
		if (interaction.getError().length())
		{
			// std::cout << background.getError() << endl;
			ofDrawBitmapStringHighlight(interaction.getError(), 20, 20);
		}
		else
		{
			ofDrawBitmapStringHighlight("interaction is loading...", 20, 20);
		}
	}
    
}

void SurfaceGenerator::loadNewSource(std::string source) {
    
    background.load(source + "/background.mov");
    background.play();
    foreground.load(source + "/foreground.mov");
    foreground.play();
    interaction.load(source + "/interaction.mov");
    interaction.play();
    
}



