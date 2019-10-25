//
//  MarkerClass.cpp
//  TeamScheireV2
//
//  Created by Jan Everaert on 09/10/2019.
//

#include "MarkerClass.hpp"


void MarkerClass::setup(int markerId, float oX, float oY, float oW, float oH, float vX, float vY, float vW, float vH, float s) {
    
    id = markerId;
    
    outputX = oX;
    outputY = oY;
    outputWidth = oW;
    outputHeight = oH;
    
    videoX = vX;
    videoY = vY;
    videoWidth = vW;
    videoHeight = vH;
    
    scale = s / 1000;
}
