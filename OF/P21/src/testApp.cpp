#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	ofBackground(0,0,0);
	ofSetFrameRate(60);

	fx = ofGetWidth();
	fy = ofGetHeight();
	p1 = ofPoint(fx * 2/6,fy * 2/5);
	p2 = ofPoint(fx * 3/6,fy * 4/5);
	p3 = ofPoint(fx * 4/6,fy * 2/5);
	
	pos = ofPoint(fx * 2/5,fy/8);
	dim = 45.3;
	spd = ofPoint(0.0,5.0);

	
}

//--------------------------------------------------------------
void testApp::update()
{
	
	pos += spd;

	ly1 = 3/2 * pos.x + 1/10;

	if(p1.x < pos.x && pos.x < p2.x)
	{
		if(pos.y > ly1)
		{
			spd.y *= -1;
			spd.x = 3;
		}
	}

	if(pos.x < dim || fx - dim < pos.x)
	{
		spd.x *= -1;
		spd.y *= 0.4;
	}
	if(pos.y < dim || fy - dim < pos.y)
	{
		spd.y *= -1;
		spd.x *= 0.2;
	}

	if(-3 < spd.x && spd.x < 3)
	{
		spd.x *= 1.2;
	}
	if(-3 < spd.y && spd.y < 3)
	{
		spd.y *= 1.2;
	}

		
	for(i=0;i<N;i++)
	{
		sna[i].update();
	}

}

//--------------------------------------------------------------
void testApp::draw()
{
	ofNoFill();
	ofSetColor(248,12,56);
	ofTriangle(p1.x,p1.y,p2.x,p2.y,p3.x,p3.y);

	ofFill();
	ofSetColor(220,12,120);
	ofCircle(pos.x,pos.y,dim);

	for(i=0;i<N;i++)
	{
		sna[i].draw();
	}

	ofSetColor(248,12,56);
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

