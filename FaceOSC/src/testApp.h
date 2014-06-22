#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "FaceOsc.h"
#include "ofxXmlSettings.h"

#include "ofxFaceTrackerThreaded.h"

class testApp : public ofBaseApp, public FaceOsc {
public:
	void loadSettings();

	void setup();
	void update();
	void draw();
	void keyPressed(int key);

	bool bPaused;

	int camWidth, camHeight;
	int movieWidth, movieHeight;
	int sourceWidth, sourceHeight;

    ofImage flipper;
	ofVideoGrabber cam;
    
	ofxFaceTrackerThreaded tracker;
	ofMatrix4x4 rotationMatrix;
	
	bool bDrawMesh;
};
