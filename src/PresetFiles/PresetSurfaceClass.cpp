//
//  PresetSurfaceClass.cpp
//  TeamScheireV2
//
//  Created by Jan Everaert on 09/10/2019.
//

#include "PresetSurfaceClass.hpp"


void PresetSurfaceClass::setup(ofxOscSender s) {
	sender = s;
	setupPresets();
}


void PresetSurfaceClass::setupPresets() {
	presetFiles.clear();
	if (xmlPresets.loadFile("presets.xml")) {
		xmlPresets.pushTag("presets");

		int numPresets = xmlPresets.getNumTags("preset");
		std::cout << "found num preset" << numPresets << endl;
		for (int i = 0; i < numPresets; i++) {
			PresetFileClass presetFile;
			vector<PresetItemClass> presetItems;
			xmlPresets.pushTag("preset", i);

			int numPanels = xmlPresets.getNumTags("panel");
			std::cout << "found num panel" << numPanels << endl;
			for (int j = 0; j < numPanels; j++) {
				xmlPresets.pushTag("panel", j);

				PresetItemClass presetItem;


				int p = xmlPresets.getValue("position", 0);
				int w = xmlPresets.getValue("width", 200);
				int h = xmlPresets.getValue("height", 200);
				int xO = xmlPresets.getValue("xOffset", 0);
				int yO = xmlPresets.getValue("yOffset", 0);
				int zO = xmlPresets.getValue("zOffset", 0);
				float xR = xmlPresets.getValue("xRotation", 0);
				float yR = xmlPresets.getValue("yRotation", 0);
				float zR = xmlPresets.getValue("zRotation", 0);


				xmlPresets.pushTag("video");
				int vSX = xmlPresets.getValue("startX", 0);
				int vSY = xmlPresets.getValue("startY", 0);
				int vW = xmlPresets.getValue("width", 0);
				int vH = xmlPresets.getValue("height", 0);

				xmlPresets.popTag();

				presetItem.setup(p, w, h, xO, yO, zO, xR, yR, zR, vSX, vSY, vW, vH);

				// assign preset to preset class
				presetItems.push_back(presetItem);
				std::cout << "added panel" << endl;
				xmlPresets.popTag();
			}
			std::cout << "found num of items in XML: " << presetItems.size() << endl;
			presetFile.setup(presetItems);

			xmlPresets.popTag();
			presetFiles.push_back(presetFile);
			std::cout << "added a preset file" << endl;
		}
		xmlPresets.popTag();
	}
	else {
		ofLogError("Preset file did not load!");
	}
	std::cout << "num presets found: " << presetFiles.size() << endl;

	sendMessage("/positionPreset", 0);
	sendMessage("/editPreset", 0);
}

void PresetSurfaceClass::update(int PN) {
	PRESET_NUM = PN - 1;
	if (EDIT_MODE) {
		item.update(OSCPosition, OSCWidth, OSCHeight, OSCOutputX, OSCOutputY, OSCOutputZ, OSCOutputRX, OSCOutputRY, OSCOutputRZ, OSCVideoX, OSCVideoY, OSCVideoWidth, OSCVideoHeight);
	}
}

void PresetSurfaceClass::draw(SurfaceGenerator* surfaces, bool DISPLAY_INTERACTION, bool DISPLAY_LOUIS) {
    presetFiles[PRESET_NUM].draw(surfaces, DISPLAY_INTERACTION, DISPLAY_LOUIS, selectedPresetNum);
	if (EDIT_MODE) {
		item.draw(surfaces, DISPLAY_INTERACTION, DISPLAY_LOUIS);
	}

}


void PresetSurfaceClass::handleOSC(ofxOscMessage msg) {
	string a = msg.getAddress();

	if (a == "/accxyz") {
		// do nothing, always coming in
	}
	else if (a == "/editPreset") {
		if (msg.getArgAsInt(0) == 0) {
			EDIT_MODE = false;
		}
		else {
			EDIT_MODE = true;
			if(item.position == -1)
			item.setup(OSCPosition, OSCWidth, OSCHeight, OSCOutputX, OSCOutputY, OSCOutputZ, OSCOutputRX, OSCOutputRY, OSCOutputRZ, OSCVideoX, OSCVideoY, OSCVideoWidth, OSCVideoHeight);
		}
	}
	else if (a == "/savePreset") {
		// write to the file 
		std::cout << "saving" << endl;
		ofxXmlSettings set;
		set.loadFile("presets.xml");
		set.pushTag("presets");
		set.pushTag("preset", PRESET_NUM);
		

		int numberOfMarkers = set.getNumTags("panel");

		std::cout << "saving at line " << numberOfMarkers << endl;

		int lineNum = set.addTag("panel");
		set.setValue("panel:video:startX", OSCVideoX, lineNum);
		set.setValue("panel:video:startY", OSCVideoY, lineNum);
		set.setValue("panel:video:width", OSCVideoWidth, lineNum);
		set.setValue("panel:video:height", OSCVideoHeight, lineNum);
		set.setValue("panel:position", OSCPosition, lineNum);
		set.setValue("panel:handle", "wall", lineNum);
		set.setValue("panel:width", OSCWidth, lineNum);
		set.setValue("panel:height", OSCHeight, lineNum);
		set.setValue("panel:xOffset", OSCOutputX, lineNum);
		set.setValue("panel:yOffset", OSCOutputY, lineNum);
		set.setValue("panel:zOffset", OSCOutputZ, lineNum);
		set.setValue("panel:xRotation", OSCOutputRX, lineNum);
		set.setValue("panel:yRotation", OSCOutputRY, lineNum);
		set.setValue("panel:zRotation", OSCOutputRZ, lineNum);

		set.popTag();
		set.popTag();
		string s;
		set.copyXmlToString(s);

		std::cout << s << endl;

		set.saveFile("presets.xml");


		// reload

		setupPresets(); 
		EDIT_MODE = false;

	}
	
	
	else if (a == "/nextPreset") {
		selectedPresetNum++;
		if (selectedPresetNum >= presetFiles[PRESET_NUM].presetItems.size()) {
			selectedPresetNum = 0;
		}
	}
	else if (a == "/prevPreset") {
		selectedPresetNum--;
		if (selectedPresetNum < 0) {
			selectedPresetNum = presetFiles[PRESET_NUM].presetItems.size() -1;
		}
	}
	else if (a == "/deletePreset") {
		// delete handle
		std::cout << "deleting preset" << endl;
		// write to the file 
		std::cout << "saving" << endl;

		ofxXmlSettings set;
		set.loadFile("presets.xml");
		set.pushTag("presets");
		set.pushTag("preset", PRESET_NUM);


		int numberOfMarkers = set.getNumTags("panel");

		std::cout << "delete at line " << numberOfMarkers << endl;
		set.removeTag("panel", selectedPresetNum);

		set.popTag();
		set.popTag();
		string s;
		set.copyXmlToString(s);

		std::cout << s << endl;

		set.saveFile("presets.xml");

		setupPresets();


	}
	else if (a == "/managePresets") {
		managePresets = msg.getArgAsBool(0);
		if (!managePresets) {
			selectedPresetNum = -1;
		}
	}



	else if (a == "/positionPreset") {
		OSCPosition = msg.getArgAsInt(0);
	}
	else if (a == "/outputXPreset") {
		OSCOutputX = msg.getArgAsInt(0);
	}
	else if (a == "/outputYPreset") {
		OSCOutputY = msg.getArgAsInt(0);
	}
	else if (a == "/outputZPreset") {
		OSCOutputZ = msg.getArgAsInt(0);
	}
	else if (a == "/outputRXPreset") {
		OSCOutputRX = msg.getArgAsInt(0);
	}
	else if (a == "/outputRYPreset") {
		OSCOutputRY = msg.getArgAsInt(0);
	}
	else if (a == "/outputRZPreset") {
		OSCOutputRZ = msg.getArgAsInt(0);
	}
	else if (a == "/widthPreset") {
		OSCWidth = msg.getArgAsInt(0);
	}
	else if (a == "/heightPreset") {
		OSCHeight = msg.getArgAsInt(0);
	}
	else if (a == "/videoXPreset") {
		OSCVideoX = msg.getArgAsInt(0);
	}
	else if (a == "/videoYPreset") {
		OSCVideoY = msg.getArgAsInt(0);
	}
	else if (a == "/videoWidthPreset") {
		OSCVideoWidth = msg.getArgAsInt(0);
	}
	else if (a == "/videoHeightPreset") {
		OSCVideoHeight = msg.getArgAsInt(0);
	}
	if (a != "/accxyz") {

		std::cout << msg.getAddress() << "val: " << msg.getArgAsInt(0) << endl;
	}
}

void PresetSurfaceClass::sendMessage(string channel, int value) {
	ofxOscMessage msg;
	msg.setAddress(channel);
	msg.addFloatArg(value);
	sender.sendMessage(msg);
}