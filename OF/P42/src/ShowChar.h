#ifndef _SHOW_CHAR
#define _SHOW_CHAR

#include <string>
#include "ofMain.h"

class showChar
{
private:
	float fw,fh;
	float x,y;
	float deg;

	int r,g,b,a;
	int fSize;
	int inc;

	bool isDrawSBB;

	string fName;
	string s;

	char c;

	ofTTFCharacter* outLines;
	vector<ofTTFContour> oLine;
	vector<ofPoint> cont;

	ofRectangle rect;

	ofTrueTypeFont *font; // +++
	
public:
	showChar(ofTrueTypeFont *font); // +++

	void draw(bool isDSBB = false);

	void setPos(ofPoint p);
	void setPos(float px,float py);
	void setDeg(float degr);
	void setChar(char ch);
	void setCharS(string cs);
	void setInt(int num);
	void setStr(string str);
	void setColor(int rc,int gc,int bc);
	void setColor(int rc,int gc,int bc,int alp);
	
	
	ofPoint getPos();
	float getDeg();
	ofRectangle getStrBBox();
	ofPoint getSBBsize();
	string getStr();
	vector<ofPoint> getContour(int n);
	char getChar();

};

#endif