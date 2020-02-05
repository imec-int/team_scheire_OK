#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(24);
    sound.load("sounds/background.mp3");
	if (sound.isLoaded()) {
		sound.setVolume(5);
		sound.play();
        sound.setLoop(true);
	}
	else {
		std::cout << "could not find sound";
	}
    surfaceGenerator = new SurfaceGenerator();
    

	sender.setup("192.168.0.167", 9000);
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
        receiver.getNextMessage(msg);
        surfaceGenerator->handleOSC(msg);
        presets.handleOSC(msg);
        aruco.handleOSC(msg);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(0, 0, 0);

    if(DISPLAY_MODE == 0) {
        aruco.draw(surfaceGenerator, DEBUG_MODE, DISPLAY_INTERACTION, DISPLAY_LOUIS, DISPLAY_CAM);
    }
    else {
        presets.draw(surfaceGenerator, DISPLAY_INTERACTION, DISPLAY_LOUIS);
    }
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // Look for new markers
    if(key == 't' || key == '6') {
        aruco.TRACK = !aruco.TRACK;
    }
    // Marker display mode
    if(key == '0') {
        DISPLAY_MODE = 0;
    }
    // Preset 1
    if(key == '1') {
        DISPLAY_MODE = 1;
    }
    // Preset 2
    if(key == '2') {
        DISPLAY_MODE = 2;
    }
    // Preset 3
	if (key == '3') {
		DISPLAY_MODE = 3;
	}
    // Display the mascotte animation
	if (key == 'l' || key == '4') {
		DISPLAY_LOUIS = true;
	}
    // Display the interaction component
	if (key == 'i' || key == '5') {
		DISPLAY_INTERACTION = true;
	}
    // Display the UI
    if(key == 'v' || key == '7') {
        DEBUG_MODE = !DEBUG_MODE;
	}
    // Dislay camera image
	if (key == 'c' || key == '8') {
		DISPLAY_CAM = !DISPLAY_CAM;
	}
    // Mute the footage
	if (key == 'm' || key == '9') {
		MUTE = !MUTE;
		if (MUTE) { sound.setVolume(0); }
		else { sound.setVolume(5); }
	}
    // Switch to the water scenery
    if(key == 'w' || key == '+'){
        surfaceGenerator->loadNewSource("water");
    }
    // Switch to the space scenery
    if(key == 's' || key == '-'){
        surfaceGenerator->loadNewSource("space");
    }
    // Stop or start playing the sound
    if(key == '.') {
      if(sound.isPlaying()) {
        sound.stop();
      } else {
        sound.play();
        sound.setLoop(true);
      }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == 't' || key == '6') {
		aruco.TRACK = false;
	}
	if (key == 'i' || key=='5') {
		DISPLAY_INTERACTION = false;
	}
	if (key == 'l' || key=='4') {
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
