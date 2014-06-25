#include "polyRect.h"

pRect::pRect()
{
	//ofSetRectMode(OF_RECTMODE_CENTER);
	
	fw = ofGetWidth();
	fh = ofGetHeight();

	rectMov = true;
	nearX = false;
	rectW = rectH = 0.0;

	r = g = b = a = 255;
	size = ofPoint(5.6,5.6);
	pos = ofPoint(fw/2.0,fh/2.0);

}

pRect::pRect(ofRectangle * rect)
{
	fw = ofGetWidth();
	fh = ofGetHeight();

	rectMov = true;
	nearX = false;
	rectW = rectH = 0.0;

	r = g = b = a = 255;
	
	size.x = rect->width;
	size.y = rect->height;
	
	pos.x = rect->x;
	pos.y = rect->y;

}

void pRect::draw()
{
	ofSetColor(r,g,b,a);
	ofRect(pos.x,pos.y,size.x,size.y);
}

void pRect::setPos(ofPoint rPos)
{
	pos = rPos;
}

void pRect::setPos(float rx,float ry)
{
	pos = ofPoint(rx,ry); 
}

void pRect::setColor(ofPoint rgb)
{
	setColor(rgb.x,rgb.y,rgb.z,a);
}

void pRect::setColor(int rc,int gc,int bc)
{
	setColor(rc,gc,bc,a);
}

void pRect::setColor(int rc,int gc,int bc,int ac)
{
	r = rc;
	g = gc;
	b = bc;
	a = ac;
}

void pRect::setSize(ofPoint rSize)
{
	size = rSize;
}

void pRect::setSize(float rw,float rh)
{
	size = ofPoint(rw,rh);
}

ofPoint pRect::getPos()
{
	return pos;
}

float pRect::getPosX()
{
	return pos.x;
}

float pRect::getPosY()
{
	return pos.y;
}

ofPoint pRect::getColor()
{
	return ofPoint(r,g,b);
}

int pRect::getRed()
{
	return r;
}

int pRect::getGreen()
{
	return g;
}

int pRect::getBlue()
{
	return b;
}

int pRect::getAlpha()
{
	return a;
}

ofPoint pRect::getSize()
{
	return size;
}

float pRect::getWidth()
{
	return size.x;
}

float pRect::getHeight()
{
	return size.y;
}