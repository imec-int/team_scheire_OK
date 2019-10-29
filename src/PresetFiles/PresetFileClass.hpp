//
//  PresetFileClass.hpp
//  teamScheireV2
//
//  Created by Jan Everaert on 09/09/2019.
//

#ifndef PresetFileClass_hpp
#define PresetFileClass_hpp

#include <stdio.h>
#include "ofMain.h"
#include "PresetItemClass.hpp"
#include "SurfaceGenerator.hpp"

class PresetFileClass {
public:
    void setup(vector<PresetItemClass> presetI);
    void draw(SurfaceGenerator* surfaces, bool INTERACTION);
    
    vector<PresetItemClass> presetItems;
    
};
#endif /* PresetFileClass_hpp */
