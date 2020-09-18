//
//  PresetItemClass.cpp
//  TeamScheireV2
//
//  Created by Jan Everaert on 09/10/2019.
//

#ifndef PresetItemClass_hpp
#define PresetItemClass_hpp

#include <stdio.h>
#include "ofMain.h"

#include "SurfaceGenerator.hpp"

class PresetItemClass {
public:
    void setup(int p, int w, int h, int xO, int yO, int zO, float xR, float yR, float zR, int vSX, int VSY, int vW, int vH);
	void update(int p, int w, int h, int xO, int yO, int zO, float xR, float yR, float zR, int vSX, int VSY, int vW, int vH);
    void draw(SurfaceGenerator* surfaces, bool INTERACTION, bool DISPLAY_LOUIS);
    
    
    ofPlanePrimitive videoProjection;
    ofFbo texture;
    
	int position = -1;
	int width;
    int height;
    int xOffset;
    int yOffset;
    int zOffset;
    float xRotation;
    float yRotation;
    float zRotation;
    
    
    int vStartX;
    int vStartY;
    int vWidth;
    int vHeight;
    
    
    
};
#endif /* PresetItemClass_hpp */
