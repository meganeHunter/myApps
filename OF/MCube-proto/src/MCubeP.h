#ifndef MCUBE_P
#define MCUBE_P

#include "ofMain.h"
#include "timR.h"
#include "showChar.h"

#define NCLEARED 0
#define CLEARED  1

class MCubeP
{
public:
	MCubeP();
	
	//void setup(int cSizex,int cSizey,int xyS);
	void setup();
	void draw();
	void update();
	
	void setMode(int mo);
	
	int getMode();
	int getPoint();
	
private:
	int fw,fh;
	int k,j;
	int mode;
	int xySize;
	int ans;
	int ansCount;
	int point;
		
	bool isSetAns;
	bool isStart;
	
	string str;
	
	ofPoint img1Size,img2Size;
	ofPoint img1Pos;
	
	ofTrueTypeFont ttf1,ttf2;
	showChar* sC1;
	ofImage img1,img2;
	
	timR timerPn;
	
private:
	
};

#endif