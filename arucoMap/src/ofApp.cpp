#include "ofApp.h"
#include "settings.hpp"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(_framerate);
	sound.load("sounds/background.mp3"); 
	if (sound.isLoaded())
	{
		sound.setVolume(5);
		sound.play();
		sound.setLoop(true);
	}
	else
	{
		std::cout << "could not find sound";
	}
	surfaceGenerator = new SurfaceGenerator();

	sender.setup(_ip, _sendport);
	receiver.setup(_recport);
	aruco.setup(sender);

	presets.setup(sender);
}

//--------------------------------------------------------------
void ofApp::update()
{
	aruco.update();
	surfaceGenerator->update();
	presets.update(DISPLAY_MODE);
	while (receiver.hasWaitingMessages())
	{
		ofxOscMessage msg;
		receiver.getNextMessage(&msg);

		surfaceGenerator->handleOSC(msg);
		presets.handleOSC(msg);
		aruco.handleOSC(msg);
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofClear(0, 0, 0);

	if (DISPLAY_MODE == 0)
	{
		aruco.draw(surfaceGenerator, DEBUG_MODE, DISPLAY_INTERACTION, DISPLAY_LOUIS, DISPLAY_CAM);
	}
	else
	{
		presets.draw(surfaceGenerator, DISPLAY_INTERACTION, DISPLAY_LOUIS);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	switch (key)
	{
	case 't':
	case '6':
		aruco.TRACK = !aruco.TRACK;
		break;
	case '0':
		DISPLAY_MODE = 0;
		break;
	case '1':
		DISPLAY_MODE = 1;
		break;
	case '2':
		DISPLAY_MODE = 2;
		break;
	case '3':
		DISPLAY_MODE = 3;
		break;
	case '4':
	case 'l':
		DISPLAY_LOUIS = true;
		break;
	case '5':
	case 'i':
		DISPLAY_INTERACTION = true;
		break;
	case '7':
	case 'v':
		DEBUG_MODE = !DEBUG_MODE;
		break;
	case '8':
	case 'c':
		DISPLAY_CAM = !DISPLAY_CAM;
		break;
	case '9':
	case 'm':
		MUTE = !MUTE;
		if (MUTE)
		{
			sound.setVolume(0);
		}
		else
		{
			sound.setVolume(5);
		}
		break;
	case '+':
	case 'w':
		surfaceGenerator->loadNewSource("water");
		break;
	case '-':
	case 's':
		surfaceGenerator->loadNewSource("space");
		break;
	case '.':
		if (sound.isPlaying())
		{
			sound.stop();
		}
		else
		{
			sound.play();
		}
		break;
	default:
		// std::cout << "wrong command used" << key;
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
	switch (key)
	{
	case 't':
	case '6':
		aruco.TRACK = false;
		break;
	case 'i':
	case '5':
		DISPLAY_INTERACTION = false;
		break;
	case 'l':
	case '4':
		DISPLAY_LOUIS = false;
		break;
	default:
		// std::cout << "wrong command used" << key;
		break;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
