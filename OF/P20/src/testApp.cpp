#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	ofBackground(0,0,0);
	ofSetFrameRate(60);

	pos = ofPoint(ofGetWidth()/2,ofGetHeight()/2);
	speed = ofPoint(ofRandom(-1,1),ofRandom(-1,1));

	width = 24;
	height = 24;

	speed.x = 2.3;
	speed.y = 10.5;

	pos2.x = 0;
	pos2.y = ofGetHeight() * 1/2;

	cPos.x = pos2.x + dim * sin(phase);
	cPos.y = pos2.y + dim * cos(phase);

	phase = PI/2;
	dim = 180.5;

	swc = false;
	swc2 = 0;
}

//--------------------------------------------------------------
void testApp::update()
{
	if(speed.x < 5)
	{
		speed.x += 0.4 * speed.x/100;
	}
	else
	{
		speed.x -= 0.4 * speed.x/100;
	}

	pos.x += speed.x;
	pos.y += speed.y;

	if(pos.x < 0 || ofGetWidth() - width < pos.x)
	{
		speed.x *= -1;
		
	}
	if(pos.y < 0 || ofGetHeight() - height < pos.y)
	{
		speed.y *= -1;
		
	}


	if(cPos.x < width)
	{
		if(swc2 == 0)
		{
			if(pos2.y >= 2 * dim)
			{
				pos2.y -= 2 * dim;
				phase += PI;
			}
			else 
			{
				swc2 = 1;
			}
		}
	}
	if(ofGetWidth() - width < cPos.x)
	{
		if(swc2 == 0)
		{
			if(pos2.y <= ofGetHeight() - 2 * dim)
			{
				pos2.y += 2 * dim;
				phase += PI;
			}
			else
			{
				swc2 = 2;
			}
		}
	}
	if(cPos.y < width)
	{
		if(swc2 == 0)
		{
			if(pos2.x <= ofGetWidth() - 2 * dim)
			{
				pos2.x += 2 * dim;
				phase += PI;
			}
			else 
			{
				swc2 = 3;
			}
		}
	}
	if(ofGetHeight() - width < cPos.y)
	{
		if(swc2 == 0)
		{
			if(pos2.x >= 2 * dim)
			{
				pos2.x -=  2 * dim;
				phase += PI;
			}
			else
			{
				swc2 = 4;
			}
		}
	}

	switch(swc2)
	{
	case 1:
		if(cPos.y < width)
		{
			pos2.x = cPos.x + dim;
			pos2.y = 0.0;
			phase += PI;
			swc2 = 0;
			
		}
		if(pos2.y >= dim)
		{
			if(cPos.x < width)
			{
				pos2.x = dim;
				pos2.y = 0.0;
				phase += PI;
				swc2 = 0;
			}
		}
		
		break;

	case 2:
		if(cPos.y > ofGetHeight() - width)
		{
			pos2.x = cPos.x - dim;
			pos2.y = ofGetHeight();
			phase += PI;
			swc2 = 0;
		}
		break;

	case 3:
		if(cPos.x > ofGetWidth() - width)
		{
			pos2.y = cPos.y + dim;
			pos2.x = ofGetWidth();
			phase += PI;
			swc2 = 0;
		}
		
		break;

	case 4:
		if(cPos.x < width)
		{
			pos2.y = cPos.y - dim;
			pos2.x = 0.0;
			phase += PI;
			swc2 = 0;
		}
		break;

	default:
		break;
	}

	if(swc == true)
	{
		phase -= PI/120;
	}
	else
	{
		phase += PI/120;
	}

	if(phase > TWO_PI)
	{
		phase -= TWO_PI;
	}
}

//--------------------------------------------------------------
void testApp::draw()
{
	ofSetColor(248,12,85);
	ofRect(pos.x,pos.y,width,height);

	cPos.x = pos2.x + dim * sin(phase);
	cPos.y = pos2.y + dim * cos(phase);
	ofSetColor(248,180,201);
	ofCircle(cPos.x,cPos.y,width);

	ofSetColor(248,12,85);
	ofLine(ofGetWidth()/2,ofGetHeight()/2,ofGetWidth()/2 + 80 * sin(phase),ofGetHeight()/2 + 80 * cos(phase));
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

