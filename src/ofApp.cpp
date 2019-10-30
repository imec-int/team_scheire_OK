#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFrameRate(24);
    
    sound.load("space.wav");
    sound.setVolume(10);
//    sound.play();
    
    surfaceGenerator = new SurfaceGenerator();
    
    presets.setup();


	sender.setup("10.100.17.95", 9000);
	receiver.setup(8000);
	aruco.setup(sender);

}

//--------------------------------------------------------------
void ofApp::update(){
    aruco.update();
    surfaceGenerator->update();
    

	while (receiver.hasWaitingMessages()) {
		ofxOscMessage msg;
		receiver.getNextMessage(&msg);
		
		surfaceGenerator->handleOSC(msg); 
		aruco.handleOSC(msg);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(0, 0, 0);
    
	if(DISPLAY_MODE == 0) {
        aruco.draw(surfaceGenerator, DEBUG_MODE, DISPLAY_INTERACTION);
    }
    else {
        presets.draw(surfaceGenerator, DISPLAY_MODE, DISPLAY_INTERACTION);
    }
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == 't') {
        aruco.TRACK = !aruco.TRACK;
    }
    if(key == '0') {
        DISPLAY_MODE = 0;
    }
    if(key == '1') {
        DISPLAY_MODE = 1;
    }
    if(key == '2') {
        DISPLAY_MODE = 2;
    }
	if (key == 'i') {
		DISPLAY_INTERACTION = true;
	}
    if(key == 'v') {
        DEBUG_MODE = !DEBUG_MODE;
	}
    
    if(key == 'w'){
        surfaceGenerator->loadNewSource("water");
    }
    if(key == 's'){
        surfaceGenerator->loadNewSource("space");
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    //if(key == 't') {
    //    aruco.TRACK = false;
    //}
	if (key == 'i') {
		DISPLAY_INTERACTION = false;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
