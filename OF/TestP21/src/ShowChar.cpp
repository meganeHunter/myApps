#include "ShowChar.h"


showChar::showChar(ofTrueTypeFont *font) // +++
{
	fx = ofGetWidth();
	fy = ofGetHeight();
	x = fx * 1/8;
	y = fy * 1/8;
	
	/*
	fName = "LILLIPUT.TTF";
	str = "a";
	 */
	fSize = 12;
	r = g = b = 0;
	a = 0;

	// font.loadFont(fName,fSize); // ---
	this->font = font;
	rect = font->getStringBoundingBox(str,x,y);
}

void showChar::draw()
{
	ofSetColor(r,g,b,a);
	font->drawString(str,x,y);
}

void showChar::setPos(ofPoint p)
{
	x = p.x;
	y = p.y;
}

void showChar::setPos(float px,float py)
{
	x = px;
	y = py;
}

void showChar::setStr(string s)
{
	str = s;
}

/*
void showChar::setFont(string fontName,int fontSize)
{
	fName = fontName;
	fSize = fontSize;
	font.loadFont(fName,fSize);
	rect = font->getStringBoundingBox(str,x,y);
}
 */

void showChar::setColor(int rc,int gc,int bc)
{
	r = rc;
	g = gc;
	b = bc;
}

void showChar::setColor(int rc,int gc,int bc,int alp)
{
	r = rc;
	g = gc;
	b = bc;
	a = alp;
}

ofPoint showChar::getPos()
{
	return ofPoint(x,y);
}

ofRectangle showChar::getStrBBox()
{
	return rect;
}

ofPoint showChar::getSBBsize()
{
	return ofPoint(rect.width,rect.height);
}
