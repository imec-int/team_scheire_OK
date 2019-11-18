#pragma once

#include "ofMain.h"
#include "ArucoHandler.hpp"
#include "SurfaceGenerator.hpp"
#include "PresetSurfaceClass.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
    ArucoHandler aruco;
    SurfaceGenerator* surfaceGenerator;
    PresetSurfaceClass presets;



	ofxOscSender sender;
	ofxOscReceiver receiver;

    
    ofSoundPlayer sound;
    
    int DISPLAY_MODE = 0;
	bool DISPLAY_CAM = false;
    bool DEBUG_MODE = false;
	bool DISPLAY_INTERACTION = false;
	bool DISPLAY_LOUIS = false;
	bool MUTE = false;
		
};
