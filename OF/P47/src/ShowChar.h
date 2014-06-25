#ifndef _SHOW_CHAR
#define _SHOW_CHAR

#include <string>
#include "ofMain.h"
#include "broks.h"

class showChar
{
private:
	float fw,fh;
	float x,y;
	float deg;

	int r,g,b,a;
	int fSize;
	int inc;
	int k,j;
	int numq;

	int* numa;

	bool isDrawSBB;

	string fName;
	string s;

	char c;

	ofTTFCharacter* outLines;
	vector<ofTTFContour> oLine;
	vector<ofPoint> pos;

	brok tempbr;
	vector<brok> brk;
	brok* brs;

	vector<brokN> brkN;

	ofRectangle rect;

	ofTrueTypeFont *font; // +++
	
public:
	showChar(ofTrueTypeFont *font); // +++

	void draw(bool isDSBB = false);
	void drawB();
	void drawBA();
	void drawVN();

	void delPos();

	void setPos(ofPoint p);
	void setPos(float px,float py);
	void setPosV(vector<ofPoint>& posv);
	void setPosSV(vector<brok>& br);
	void setPosSA(brok* brsa);
	void setVN(vector<brokN>& brN);
	void setDeg(float degr);
	void setChar(char ch);
	void setCharS(string cs);
	void setInt(int num);
	void setStr(string str);
	void setColor(ofColor col);
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