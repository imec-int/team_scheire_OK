//
//  MarkerClass.hpp
//  TeamScheireV2
//
//  Created by Jan Everaert on 09/10/2019.
//

#ifndef MarkerClass_hpp
#define MarkerClass_hpp

#include <stdio.h>
#include "ofMain.h"

class MarkerClass {
public:
    
    void setup(int markerId, int p,float oX, float oY, float oW, float oH, float vX, float vY, float vW, float vH, float s);
    
    int id;
	int position;
    
    int outputX;
    int outputY;
    int outputWidth;
    int outputHeight;
    
    int videoX;
    int videoY;
    int videoWidth;
    int videoHeight;
    
    float scale;
};

#endif /* MarkerClass_hpp */
