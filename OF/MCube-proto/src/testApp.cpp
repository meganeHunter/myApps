#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	k = 0;
	j = 0;
	
	fw = ofGetWidth();
	fh = ofGetHeight();
	
	//ofBackground(181,79,74);
	//ttf1.loadFont("Futura.dfont",24);
	
	MQP.setup();
		
	}

//--------------------------------------------------------------
void testApp::update()
{
	MQP.update();
	
	/*
	stat  = "xcurs: ";
	stat += ofToString(xcurs) + ", ";
	stat += "ycurs: ";
	stat += ofToString(ycurs) + "/ ";
	stat += "cPos: ";
	stat += ofToString(Nh2.getCursorCPos()) + "/ ";
	stat += "mode: ";
	stat += ofToString(Nh2.getMode()) + "/ ";
	stat += "ansCount: ";
	stat += ofToString(Nh2.getAnsCount()) + "/ ";
	stat += "point: ";
	stat += ofToString(Nh2.getPoint()) + "/ ";
	stat += "time: ";
	stat += ofToString(Nh2.getTime()) + "/ ";
	*/
}

//--------------------------------------------------------------
void testApp::draw()
{	
	ofPushStyle();
	//ofSetColor(255,255,255,255);
	
	MQP.draw();
	
	//ofDrawBitmapString(stat,20,fh - 50);
	
	ofPopStyle();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
	switch(key)
	{
	case OF_KEY_UP:
		MQP.setMode(1); 
		
		break;
		
	case OF_KEY_RIGHT:
		
		break;

	case OF_KEY_LEFT:
		MQP.setMode(2);
		
		break;
		
	case OF_KEY_DOWN:
		
		break;
		
	case OF_KEY_RETURN:
		
		break;
						
	case OF_KEY_DEL:
		
		break;

		
	default:
		break;
	}
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

