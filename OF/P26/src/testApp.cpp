#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	ofBackground(0,0,0);
	fx = ofGetWidth();
	fy = ofGetHeight();
	pos = ofPoint(fx/2,fy/2);
	speed = ofPoint(0.0,0.0);
	sMax = ofPoint(12.0,12.0);
	dim = 0.1;
	cion = false;

	gui.addSlider("Dim",dim,0.0,24.0);
	gui.addSlider2d("Speed",speed,-sMax.x,sMax.x,-sMax.y,sMax.y);
	gui.addToggle("Switch",cion);

	gui.show();
}

//--------------------------------------------------------------
void testApp::update()
{
	pos += speed;
	if(cion)
	{
		pos = ofPoint(fx/2,fy/2);
		speed = ofPoint(0.0,0.0);
	}
}

//--------------------------------------------------------------
void testApp::draw()
{
	gui.draw();
	ofSetColor(200,48,54);
	ofCircle(pos.x,pos.y,dim);

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

