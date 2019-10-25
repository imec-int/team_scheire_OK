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
    void setup();
    void update();
    void draw(SurfaceGenerator* surfaces, int PRESET_NUM);
    
    ofxXmlSettings xmlPresets;
    vector<PresetFileClass> presetFiles;
    int currentPreset = 0;
    

};
#endif /* PresetSurfaceClass_hpp */
