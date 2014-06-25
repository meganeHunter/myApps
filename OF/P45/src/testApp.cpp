#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	font.loadFont("automat.ttf",128,true,false,false);
	font2.loadFont("automat2.ttf",80,true,false,false);

	sch1 = new showChar(&font);
	sch2 = new showChar(&font2);
	
	sch1->setStr("R");
	sch2->setStr("G");
}

//--------------------------------------------------------------
void testApp::update()
{
	
}

//--------------------------------------------------------------
void testApp::draw()
{

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

