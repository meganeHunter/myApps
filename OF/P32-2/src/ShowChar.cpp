#include "ShowChar.h"


showChar::showChar(ofTrueTypeFont *font) // +++
{
	fw = ofGetWidth();
	fh = ofGetHeight();

	/*
	fName = "LILLIPUT.TTF";
	str = "a";
	 */

	fSize = 12;
	r = g = b = 0;
	a = 0;
	charMov = true;

	// font.loadFont(fName,fSize); // ---

	this->font = font;
	rect = font->getStringBoundingBox(str,x,y);
	
	if(0.0 < rect.x && rect.x < fw)
	{
		if(0.0 < rect.y && rect.y < fh)
		{
			x = rect.x;
			y = rect.y;
		}
	}
	else
	{
		x = fw / 2.0;
		y = fh / 2.0;
	}
	
}

void showChar::draw()
{
	ofSetColor(r,g,b,a);
	font->drawString(str,x,y);
}

void showChar::setPos(ofPoint p)
{
	setPos(p.x,p.y);
}

void showChar::setPos(float px,float py)
{
	/*
	if(0.0 < px && px < fw)
	{
		x = px;
	}	
	else
	{
		x = (px < 0.0) ? 0.0 : fw;
	}

	if(0.0 < py && py < fh)
	{
		y = py;
	}
	else
	{
		y = (py < 0.0) ? 0.0 : fh;
	}
	*/

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
	setColor(rc,gc,bc,a);
}

void showChar::setColor(int rc,int gc,int bc,int alp)
{
	if((unsigned)rc < 256 && (unsigned)gc < 256 && (unsigned)bc < 256)
	{
		r = rc;
		g = gc;
		b = bc;
		a = alp;
	}
	else
	{
		r = (unsigned)rc / 256;
		g = (unsigned)gc / 256;
		b = (unsigned)bc / 256;
		a = alp;
	}
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

string showChar::getStr()
{
	return str;
}