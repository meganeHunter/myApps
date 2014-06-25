#ifndef _SHOW_CHAR
#define _SHOW_CHAR

#include <string>
#include "ofMain.h"

class showChar
{
private:
	float fx,fy;
	float x,y;
	int r,g,b,a;
	int fSize;
	string fName;
	string str;

	ofRectangle rect;
	ofTrueTypeFont *font; // +++
	
public:
	showChar(ofTrueTypeFont *font); // +++
	void draw();
	void setPos(ofPoint p);
	void setPos(float px,float py);
	void setStr(string s);
	// void setFont(string fontName,int fontSize);
	void setColor(int rc,int gc,int bc);
	void setColor(int rc,int gc,int bc,int alp);
	ofPoint getPos();
	ofRectangle getStrBBox();
	ofPoint getSBBsize();

};

#endif