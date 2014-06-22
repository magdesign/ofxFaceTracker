#include "testApp.h"

using namespace ofxCv;
using namespace cv;

void testApp::loadSettings() {
	ofxXmlSettings xml;
	xml.loadFile("settings.xml");


    xml.pushTag("camera");
	cam.setDeviceID(xml.getValue("device", 0));
	if(xml.getNumTags("framerate") > 0) {
		cam.setDesiredFrameRate(xml.getValue("framerate", 30));
	}
	camWidth = xml.getValue("width", 640);
	camHeight = xml.getValue("height", 480);
	cam.initGrabber(camWidth, camHeight);
	xml.popTag();
    
	ofSetWindowShape(camWidth, camHeight);
    
	xml.pushTag("face");
	if(xml.getNumTags("rescale")) {
		tracker.setRescale(xml.getValue("rescale", 1.0));
	}
	if(xml.getNumTags("iterations")) {
		tracker.setIterations(xml.getValue("iterations", 5));
	}
	if(xml.getNumTags("clamp")) {
		tracker.setClamp(xml.getValue("clamp", 3.));
	}
	if(xml.getNumTags("tolerance")) {
		tracker.setTolerance(xml.getValue("tolerance", .01));
	}
	if(xml.getNumTags("attempts")) {
		tracker.setAttempts(xml.getValue("attempts", 1));
	}
	bDrawMesh = true;
	if(xml.getNumTags("drawMesh")) {
		bDrawMesh = (bool) xml.getValue("drawMesh", 1);
	}
	tracker.setup();
	xml.popTag();

	xml.pushTag("osc");
	host = xml.getValue("host", "localhost");
	port = xml.getValue("port", 8338);
	osc.setup(host, port);
	xml.popTag();

	osc.setup(host, port);
}

void testApp::setup() {
	ofSetVerticalSync(false);
	loadSettings();
}

void testApp::update() {
	cam.update();
	if(cam.isFrameNew()) {
        flipper.setFromPixels(cam.getPixelsRef());
        flipper.mirror(false, true);
		tracker.update(toCv(flipper));
        sendFaceOsc(tracker);
	}
}

void testApp::draw() {
	ofSetColor(255);
	flipper.draw(0, 0);

	if(tracker.getFound()) {
		ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);

		if(bDrawMesh) {
			ofSetLineWidth(1);
		    //tracker.draw();
			tracker.getImageMesh().drawWireframe();
		}
	}
}

void testApp::keyPressed(int key) {
	switch(key) {
		case 'r':
			tracker.reset();
			break;
	}
}
