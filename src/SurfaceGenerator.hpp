//
//  SurfaceClass.hpp
//  testVideoMap
//
//  Created by Jan Everaert on 30/07/2019.
//

#ifndef SurfaceClass_hpp
#define SurfaceClass_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxHapPlayer.h"
#include "ofxOsc.h"

class SurfaceGenerator {
    
public:
	SurfaceGenerator();
    void update();
    void draw(int drawX, int drawY, int drawWidth, int drawHeight, int SOURCE, float scale, int subX, int subY, int subWidth, int subHeight, bool INTERACTION, bool LOUIS);
    void loadNewSource(std::string source);
	void handleOSC(ofxOscMessage msg);

	float keyStoneH = 0;
	float keyStoneV = 0;

	ofFbo wall_videoFBO;
    ofxHapPlayer wall_background;
	ofxHapPlayer wall_foreground;
	ofxHapPlayer wall_interaction;

	
	ofFbo ceiling_videoFBO;
	ofxHapPlayer ceiling_background;
	ofxHapPlayer ceiling_foreground;
	ofxHapPlayer ceiling_interaction;

	ofxHapPlayer louis_top;
	ofxHapPlayer louis_left;
	ofxHapPlayer louis_bottom;
    
	int WIDTH = 1400;
	int HEIGHT = 900;
    
};

#endif /* SurfaceClass_hpp */
