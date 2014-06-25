#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	ofBackground(0,0,0);
	ofSetFrameRate(60);
}

//--------------------------------------------------------------
void testApp::update()
{
	rT.update();
}

//--------------------------------------------------------------
void testApp::draw()
{
	ofSetColor(12,158,248);
	rT.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{

}

