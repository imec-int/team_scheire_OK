#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFrameRate(24);
    
    sound.load("water/music.mp3");
    sound.setVolume(5);
    sound.play();
    
    surfaceGenerator = new SurfaceGenerator();
    

	sender.setup("192.168.137.241", 9000);
	receiver.setup(8000);
	aruco.setup(sender);

	presets.setup(sender);
}

//--------------------------------------------------------------
void ofApp::update(){
    aruco.update();
    surfaceGenerator->update();    
	presets.update(DISPLAY_MODE);
	while (receiver.hasWaitingMessages()) {
		ofxOscMessage msg;
		receiver.getNextMessage(&msg);
		
		surfaceGenerator->handleOSC(msg); 
		presets.handleOSC(msg);
		aruco.handleOSC(msg);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(40, 40, 40);
    
	if(DISPLAY_MODE == 0) {
        aruco.draw(surfaceGenerator, DEBUG_MODE, DISPLAY_INTERACTION, DISPLAY_LOUIS);
    }
    else {
        presets.draw(surfaceGenerator, DISPLAY_INTERACTION, DISPLAY_LOUIS);
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
	if (key == 'l') {
		DISPLAY_LOUIS = true;
	}
	if (key == 'i') {
		DISPLAY_INTERACTION = true;
	}
    if(key == 'v') {
        DEBUG_MODE = !DEBUG_MODE;
	}
    
    if(key == 'w'){
        surfaceGenerator->loadNewSource("water");
		sound.load("water/music.mp3");
    }
    if(key == 's'){
        surfaceGenerator->loadNewSource("space");
		sound.load("space/music.mp3");
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
	if (key == 'l') {
		DISPLAY_LOUIS = false;
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
