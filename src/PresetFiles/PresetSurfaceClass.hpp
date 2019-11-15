//
//  PresetSurfaceClass.hpp
//  TeamScheireV2
//
//  Created by Jan Everaert on 09/10/2019.
//

#ifndef PresetSurfaceClass_hpp
#define PresetSurfaceClass_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxXmlSettings.h"

#include "PresetFileClass.hpp"
#include "PresetItemClass.hpp"
#include "PresetFileClass.hpp"

#include "SurfaceGenerator.hpp"

class PresetSurfaceClass {
public:
    void setup(ofxOscSender s);
    void update(int PRESET_NUM);
    void draw(SurfaceGenerator* surfaces, bool DISPLAY_INTERACTION, bool DISPLAY_LOUIS);
	void setupPresets();
	void handleOSC(ofxOscMessage msg);
	void sendMessage(string channel, int value);


    ofxXmlSettings xmlPresets;
    vector<PresetFileClass> presetFiles;
    int PRESET_NUM = 0;
	bool EDIT_MODE = false;

	ofxOscSender sender;
	
	PresetItemClass item;

	int OSCHeight = 768;
	int OSCWidth = 1024;
	int OSCOutputX = 0;
	int OSCOutputY = 0;
	int OSCOutputZ = 0;
	int OSCOutputRX = 0;
	int OSCOutputRY = 0;
	int OSCOutputRZ = 0;
	int OSCOutputWidth = 200;
	int OSCOutputHeight = 200;
	int OSCVideoX = 0;
	int OSCVideoY = 0;
	int OSCVideoWidth = 1024;
	int OSCVideoHeight = 512;
	int OSCPosition = 0;

	bool managePresets = false;
	int selectedPresetNum =- -1;

};
#endif /* PresetSurfaceClass_hpp */
