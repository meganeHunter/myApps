#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	ofBackground(0,0,0);
	ofSetFrameRate(60);
	ofEnableAlphaBlending();
	
}

//--------------------------------------------------------------
void testApp::update()
{
	vTable.setPosd(vPaddle.getPosd());
	vTable.setScore(sBall.getScore());
	vTable.update();
	vPaddle.setPos1r(sBall.getPos());
	vPaddle.update();
	sBall.setpHeight(vPaddle.getHeight());
	sBall.setp1Pos(vPaddle.getPos1());
	sBall.setp2Pos(vPaddle.getPos2());
	sBall.update();

}

//--------------------------------------------------------------
void testApp::draw()
{
	ofSetColor(255,255,255);
	ofNoFill();
	ofRect(ofGetWidth()*1/8,ofGetHeight()*1/8,ofGetWidth()*6/8,ofGetHeight()*5/8);

	ofFill();
	sBall.draw();
	vTable.draw();
	vPaddle.draw();

	ofSetColor(255,255,255);
	ofNoFill();
	ofSetRectMode(OF_RECTMODE_CORNER);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
	sBall.setMode(key);
	vTable.setMode(key);
}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y )
{
	vPaddle.setPos2(mouseY);
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{
	vPaddle.setPos2(mouseY);
	//sBall.setMpos(ofPoint(x,y));
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{
	sBall.setMmode(true);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{

}

