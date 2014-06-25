#include "ShowChar.h"


showChar::showChar(ofTrueTypeFont *font) // +++
{
	fw = ofGetWidth();
	fh = ofGetHeight();

	fSize = 12;
	r = g = b = 0;
	a = 255;
	charMov = true;

	this->font = font;
	rect = font->getStringBoundingBox(s,x,y);
	
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
	font->drawString(s,x,y);
}

void showChar::setPos(ofPoint p)
{
	setPos(p.x,p.y);
}

void showChar::setPos(float px,float py)
{
	x = px;
	y = py;
}

void showChar::setChar(char ch)
{
	s = ch;
}

void showChar::setCharS(string cs)
{
	//s = ((int)cs.size() < 2) ? (cs) : (cs[0]);
	if((int)cs.size() < 2)
	{
		s = cs;
	}
	else
	{
		s = cs[0];
	}
}

void showChar::setStr(string str)
{
	s = str;
}


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
	return s;
}

vector<ofPoint> showChar::getContour(int n)
{

	inc = c;
	//outLines = &font->getCharacterAsPoints(inc);
	//oLine = outLines->contours;

	return font->getCharacterAsPoints(inc).contours[n].pts;
}

char showChar::getChar()
{
	return *(s.c_str());
}