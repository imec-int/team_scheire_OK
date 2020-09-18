//
//  SurfaceGenerator.cpp
//  TeamScheireV2
//
//  Created by Jan Everaert on 07/10/2019.
//

#include "SurfaceGenerator.hpp"

SurfaceGenerator::SurfaceGenerator()
{
	ofEnableAlphaBlending();

	loadNewSource("water");

	wall_videoFBO.allocate(WIDTH, HEIGHT, GL_RGBA);
	ceiling_videoFBO.allocate(WIDTH, HEIGHT, GL_RGBA);

	wall_videoFBO.begin();
	ofClear(0, 0, 0, 0);
	wall_videoFBO.end();

	ceiling_videoFBO.begin();
	ofClear(0, 0, 0, 0);
	ceiling_videoFBO.end();
}

void SurfaceGenerator::handleOSC(ofxOscMessage msg)
{
	string a = msg.getAddress();
	if (a == "/keystoneV")
	{
		keyStoneV = msg.getArgAsFloat(0);
	}
	if (a == "/keystoneH")
	{
		keyStoneH = msg.getArgAsFloat(0);
	}
}

void SurfaceGenerator::update()
{

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
	wall_background.draw(0, HEIGHT, WIDTH, -HEIGHT);
	wall_interaction.draw(0, HEIGHT, WIDTH, -HEIGHT);
	wall_foreground.draw(0, HEIGHT, WIDTH, -HEIGHT);
	if (louis_bottom.isPlaying())
	{
		louis_bottom.draw(0, HEIGHT, WIDTH, -HEIGHT);
	}
	if (louis_left.isPlaying())
	{
		louis_left.draw(0, HEIGHT, WIDTH, -HEIGHT);
	}
	if (louis_top.isPlaying())
	{
		louis_top.draw(0, HEIGHT, WIDTH, -HEIGHT);
	}
	ofDisableAlphaBlending();
	wall_videoFBO.end();

	// prep ceiling
	ceiling_videoFBO.begin();
	ofEnableAlphaBlending();
	ofClear(0, 0, 0, 0);
	ceiling_background.draw(0, 0, WIDTH, HEIGHT);
	ceiling_foreground.draw(0, 0, WIDTH, HEIGHT);
	ceiling_interaction.draw(0, 0, WIDTH, HEIGHT);
	if (louis_bottom.isPlaying())
	{
		louis_bottom.draw(0, 0, WIDTH, HEIGHT);
	}
	if (louis_left.isPlaying())
	{
		louis_left.draw(0, 0, WIDTH, HEIGHT);
	}
	if (louis_top.isPlaying())
	{
		louis_top.draw(0, 0, WIDTH, HEIGHT);
	}
	ofDisableAlphaBlending();
	ceiling_videoFBO.end();
}

void SurfaceGenerator::draw(int drawX, int drawY, int drawZ, int drawWidth, int drawHeight, int position, float scale, int subX, int subY, int subWidth, int subHeight, bool INTERACTION, bool LOUIS)
{
	if (INTERACTION)
	{
		if (!wall_interaction.isPlaying())
		{
			wall_interaction.play();
		}

		if (!ceiling_interaction.isPlaying())
		{
			ceiling_interaction.play();
		}
		if (interactionSound.isLoaded())
		{
			interactionSound.play();
		}
	}

	if (LOUIS)
	{
		int select = floor((ofGetFrameNum() / 24 / 2) % 3);

		if (select == 0)
		{
			louis_bottom.play();
		}
		if (select == 1)
		{
			louis_top.play();
		}
		if (select == 2)
		{
			louis_left.play();
		}
	}

	ofPushMatrix();

	// this is a problematic thing
	ofScale(scale / 10000);
	ofTranslate(drawWidth / 2, drawHeight / 2);
	ofRotateYDeg(keyStoneV);
	ofRotateXDeg(keyStoneH);
	ofTranslate(-drawWidth / 2, -drawHeight / 2, 0);
	if (position == 0)
	{
		wall_videoFBO.getTexture().drawSubsection(drawX, drawY, drawWidth, drawHeight, subX, subY, subWidth, subHeight);
		if (wall_background.getError().length())
		{
			std::cout << wall_background.getError() << endl;
			ofDrawBitmapStringHighlight(wall_background.getError(), ofGetWidth() / 2, 20);
		}
		if (wall_foreground.getError().length())
		{
			std::cout << wall_foreground.getError() << endl;
			ofDrawBitmapStringHighlight(wall_foreground.getError(), ofGetWidth() / 2, 20);
		}
		if (wall_interaction.getError().length())
		{
			std::cout << wall_interaction.getError() << endl;
			ofDrawBitmapStringHighlight(wall_interaction.getError(), ofGetWidth() / 2, 20);
		}
	}

	else
	{

		ceiling_videoFBO.getTexture().drawSubsection(drawX, drawY, drawWidth, drawHeight, subX, subY, subWidth, subHeight);

		if (ceiling_background.getError().length())
		{
			std::cout << ceiling_background.getError() << endl;
			ofDrawBitmapStringHighlight(ceiling_background.getError(), ofGetWidth() / 2, 20);
		}

		if (ceiling_foreground.getError().length())
		{
			std::cout << ceiling_foreground.getError() << endl;
			ofDrawBitmapStringHighlight(ceiling_foreground.getError(), ofGetWidth() / 2, 20);
		}
		if (ceiling_interaction.getError().length())
		{
			std::cout << ceiling_interaction.getError() << endl;
			ofDrawBitmapStringHighlight(ceiling_interaction.getError(), ofGetWidth() / 2, 20);
		}
	}

	ofPopMatrix();
}

void SurfaceGenerator::loadNewSource(std::string source)
{

	wall_background.load(source + "/wall_background.mov");
	wall_background.play();
	wall_foreground.load(source + "/wall_foreground.mov");
	wall_foreground.play();
	wall_interaction.load(source + "/wall_interaction.mov");
	wall_interaction.play();
	wall_interaction.setLoopState(OF_LOOP_NONE);

	ceiling_background.load(source + "/ceiling_background.mov");
	ceiling_background.play();
	ceiling_foreground.load(source + "/ceiling_foreground.mov");
	ceiling_foreground.play();
	ceiling_interaction.load(source + "/ceiling_interaction.mov");
	ceiling_interaction.play();
	ceiling_interaction.setLoopState(OF_LOOP_NONE);

	louis_top.load("louis/top.mov");
	louis_top.setLoopState(OF_LOOP_NONE);
	louis_bottom.load("louis/bottom.mov");
	louis_bottom.setLoopState(OF_LOOP_NONE);
	louis_left.load("louis/left.mov");
	louis_left.setLoopState(OF_LOOP_NONE);

	interactionSound.load(source + "/interaction.mp3");
	if (interactionSound.isLoaded())
	{
		interactionSound.setLoop(false);
	}
}
