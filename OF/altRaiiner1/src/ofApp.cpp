#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    k = 0;
    j = 0;
    
    fw = ofGetWidth();
    fh = ofGetHeight();
    
    ofSeedRandom();
    
    lineColor.set(0, 0, 255, 255);
    lineSpeed.set(0, 0);
    lineFriction = 0;
    
    alr1.setup();
    
    stat1 = " ";
}

//--------------------------------------------------------------
void ofApp::update()
{
    lineColor.r += ofRandom(-0.1, 0.1);
    lineColor.g += ofRandom(-0.2, 0.5);
    lineColor.b += ofRandom(-0.1, 1.6);
    
    lineSpeed.x = ofRandom(0.3, 3.5);
    lineSpeed.y = ofRandom(0.4, 0.6);
    
    lineFriction = ofRandom(-1.1, 0.9);
    
    alr1.setLColor(lineColor);
    alr1.setLSpeed(lineSpeed);
    alr1.setLFriction(lineFriction);
    
    alr1.update();
    
    stat1  = "linePos x: " + ofToString(alr1.getLPos().x, 0) + " ";
    stat1 += "y: " + ofToString(alr1.getLPos().y, 0) + " ";
    //stat1 += "lineSpeed x: " + ofToString(alr1.getLSpeed().x, 0) + " ";
    //stat1 += "y: " + ofToString(alr1.getLSpeed().y, 0) + " ";
    stat1 += "lineFrix: " + ofToString(lineFriction, 0) + " ";
    
}

//--------------------------------------------------------------
void ofApp::draw()
{
    alr1.draw();
    
    ofSetColor(255, 255, 255);
    ofDrawBitmapString(stat1, 24, fh - 24);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
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
