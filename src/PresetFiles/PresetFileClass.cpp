//
//  PresetFileClass.cpp
//  testVideoMap
//
//  Created by Jan Everaert on 09/08/2019.
//

#include "PresetFileClass.hpp"


void PresetFileClass::setup(vector<PresetItemClass> presetI) {
    presetItems = presetI;
}

void PresetFileClass::draw(SurfaceGenerator* surfaces, bool INTERACTION) {
    for(int i = 0; i < presetItems.size(); i++) {
        presetItems[i].draw(surfaces, INTERACTION);
    }
}
