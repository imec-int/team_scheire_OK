//
//  PresetSurfaceClass.cpp
//  TeamScheireV2
//
//  Created by Jan Everaert on 09/10/2019.
//

#include "PresetSurfaceClass.hpp"


void PresetSurfaceClass::setup() {
    
    if(xmlPresets.loadFile("presets.xml")){
        xmlPresets.pushTag("presets");
        
        int numPresets = xmlPresets.getNumTags("preset");
        for(int i = 0; i < numPresets; i++){
            PresetFileClass presetFile;
            vector<PresetItemClass> presetItems;
            xmlPresets.pushTag("preset", i);
            
            int numPanels = xmlPresets.getNumTags("panel");
            for(int j = 0; j < numPanels; j++){
                xmlPresets.pushTag("panel", j);
                
                PresetItemClass presetItem;
                
                
                string ha = xmlPresets.getValue("handle", "test");
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
                
                presetItem.setup(ha, w, h, xO, yO, zO, xR, yR, zR, vSX, vSY, vW, vH);
                
                // assign preset to preset class
                presetItems.push_back(presetItem);
                xmlPresets.popTag();
            }
            std::cout << "found num of items: " << presetItems.size() << endl;
            xmlPresets.popTag();
            presetFile.setup(presetItems);
            
            xmlPresets.popTag();
            presetFiles.push_back(presetFile);
        }
        xmlPresets.popTag();
    }
    else{
        ofLogError("Preset file did not load!");
    }
    std::cout << "num presets found: " << presetFiles.size() << endl;
}

void PresetSurfaceClass::draw(SurfaceGenerator* surfaces, int PRESET_NUM) {
    presetFiles[PRESET_NUM - 1].draw(surfaces);
}
