#ifndef _BALL
#define _BALL

#include "ofMain.h"

class ball
{
private:
	ofPoint pos;
	float dim;
	ofPoint speed;
	ofPoint rspeed;
	ofPoint table0;
	ofPoint tableF;
	int lscore;
	int rscore;
	ofPoint p1Pos;
	ofPoint p2Pos;
	int pHeight;
	int key;
	ofPoint mPos;
	float acs;
	bool mMode;

public:
	ball();
	
	void draw();
	void update();
	ofPoint getSpeed();
	void setSpeed(ofPoint spd);
	ofPoint getPos();
	void setPos(ofPoint bpos);
	ofPoint getScore();
	void setp1Pos(ofPoint pd1Pos);
	void setp2Pos(ofPoint pd2Pos);
	void setpHeight(int pdHeight);
	void setMode(int inKey);
	void setMpos(ofPoint dmPos);
	void setMmode(bool Mm);

};

#endif
