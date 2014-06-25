#ifndef _SHOW_CHAR
#define _SHOW_CHAR

#include <string>
#include "ofMain.h"

class showChar
{
private:
	float fx,fy;
	float x,y;
	int r,g,b;
	int fSize;
	string fName;
	string str;

	ofRectangle rect;
	ofTrueTypeFont font;
	
public:
	showChar();
	void draw();
	void setPos(ofPoint p);
	void setStr(string s);
	void setFont(string fontName,int fontSize);
	void setColor(int rc,int gc,int bc);
	ofRectangle getStrBBox();
	ofPoint getSBBsize();

};

#endif