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
	imgz setImgz2(string iName);
	
	void rollNum(int top,int bottom,int yPos);

private:
	int fw,fh;
	int k,j,l;
	int randNum;
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
	string rNum;
	
	ofTrueTypeFont ttf1,ttf2;
	showChar* sC1;
	
	vector <showChar * > numRoll;
	vector <showChar * >::iterator it;
	
	imgz img1,img2,img3,img4,img5;
	imgz img6;
	timR timerPn;
	
	
};

#endif