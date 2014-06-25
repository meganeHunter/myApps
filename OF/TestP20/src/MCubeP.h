#ifndef MCUBE_P
#define MCUBE_P

#include "ofMain.h"
#include "timR.h"
#include "showChar.h"

#define NCLEARED 0
#define CLEARED  1

struct imgz
{
	ofImage img;
	ofPoint pos;
	ofPoint size;
};

class MCubeP
{
public:
	MCubeP();
	
	//void setup(int cSizex,int cSizey,int xyS);
	void setup();
	void draw();
	void update();
	
	void setMode(int mo);
	void setGMode(int gmo);
	void setImgPos(ofPoint p,int iNum);
	void setImgSize(ofPoint s,int iNum); 
	void setLinePos(int lp);
	
	int getMode();
	int getGMode();
	int getPoint();
	int getLinePos();
	ofPoint getImgPos(int iNum);
	ofPoint getImgSize(int iNum);
	
private:
	void setImgz(imgz im,string iName);

private:
	int fw,fh;
	int k,j;
	int mode;
	int gMode;
	int xySize;
	int ans;
	int ansCount;
	int point;
	int linePos;
		
	bool isSetAns;
	bool isStart;
	
	string str;
	
	ofTrueTypeFont ttf1,ttf2;
	showChar* sC1;
	imgz img1,img2,img3;	
	timR timerPn;
	
	
};

#endif