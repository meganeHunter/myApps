#include "ShowChar.h"


showChar::showChar(ofTrueTypeFont *font) // +++
{
	fw = ofGetWidth();
	fh = ofGetHeight();

	fSize = 12;
	r = g = b = 0;
	a = 255;
	deg = 0.0;

	isDrawSBB = false;

	s = " ";

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

	tempbr.fig = 0;
	tempbr.id = 0;
	tempbr.pos = ofPoint(x,y);

	brk.push_back(tempbr);
	
}

void showChar::draw(bool isDSBB)
{
	isDrawSBB = isDSBB;

	for(k = 0; k < pos.size(); k++)
	{
		ofPushMatrix();
	
		ofSetColor(r,g,b,a);
		ofTranslate(pos[k].x + (rect.width / 2.0),pos[k].y + (rect.height / 2.0));
		ofRotateZ(deg);
	
		font->drawString(s,-(rect.width / 2.0),-(rect.height / 2.0));

		ofPopMatrix();
	}
 
	//isDrawSBB ? ofRect(x - (rect.width / 2.0),y - (rect.height / 2.0),rect.width,rect.height) : 0;
	
	
}

void showChar::drawB()
{
	for(k = 0; k < brk.size(); k++)
	{
		ofPushMatrix();
	
		ofSetColor(brk[k].col.r,brk[k].col.g,brk[k].col.b,brk[k].col.a);
		ofTranslate(brk[k].pos.x + (rect.width / 2.0),brk[k].pos.y + (rect.height / 2.0));
		ofRotateZ(deg);
	
		if(brk[k].fig == 1001)
		{
			s = brk[k].ch;
			font->drawString(s,-(rect.width / 2.0),-(rect.height / 2.0));
		}
		else
		{
			font->drawString(ofToString(brk[k].fig),-(rect.width / 2.0),-(rect.height / 2.0));
		}

		ofPopMatrix();
	}
}

void showChar::drawBA()
{
	for(k = 0; brs; k++)
	{
		ofPushMatrix();
	
		ofSetColor(brs[k].col.r,brs[k].col.g,brs[k].col.b,brs[k].col.a);
		ofTranslate(brs[k].pos.x + (rect.width / 2.0),brs[k].pos.y + (rect.height / 2.0));
		ofRotateZ(deg);
	
		if(brk[k].fig == 1001)
		{
			s = brs[k].ch;
			font->drawString(s,-(rect.width / 2.0),-(rect.height / 2.0));
		}
		else
		{
			font->drawString(ofToString(brs[k].fig),-(rect.width / 2.0),-(rect.height / 2.0));
		}

		ofPopMatrix();
	}
}

void showChar::drawVN()
{
	ofPushMatrix();
	ofPushStyle();

	for(k = 0; k < brkN.size(); k++)
	{
		if(brkN[k].isShow)
		{
			ofSetColor(brkN[k].col.r,brkN[k].col.g,brkN[k].col.b,brkN[k].col.a);
			
			ofTranslate(rect.width * (k + 1),fh / 2);
			font->drawString(ofToString(brkN[k].var),-(rect.width / 2.0),-(rect.height / 2.0));
		}
	}

	ofPopStyle();
	ofPopMatrix();
}

void showChar::delPos()
{
	if(!pos.empty())
	{
		pos.pop_back();
	}
}

void showChar::setPos(ofPoint p)
{
	pos.push_back(p);

}

void showChar::setPos(float px,float py)
{
	setPos(ofPoint(px,py));
}

void showChar::setPosV(vector<ofPoint>& posv)
{
	pos = posv;
}

void showChar::setPosSV(vector<brok>& br)
{
	brk = br;
}

void showChar::setPosSA(brok* brsa)
{
	if(brsa)
	{
		brs = brsa;
	}
}

void showChar::setVN(vector<brokN>& brN)
{
	brkN = brN;
}

void showChar::setDeg(float degr)
{
	deg = degr;
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

void showChar::setInt(int num)
{
	s = ofToString(num);
}


void showChar::setStr(string str)
{
	s = str;
}

void showChar::setColor(ofColor col)
{
	setColor(col.r,col.g,col.b,col.a);
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

float showChar::getDeg()
{
	return deg;
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