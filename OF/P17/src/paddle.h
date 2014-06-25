#ifndef _PADDLE
#define _PADDLE

#include "ofMain.h"

class paddle
{
private:
	ofPoint table0;
	ofPoint tableF;

	ofPoint pos1;
	ofPoint pos2;
	int width;
	int height;
	float p1speed;
	ofPoint posDif;

public:
	paddle();
	
	void draw();
	void update();
	ofPoint getPos1();
	void setPos1(ofPoint pPos1);
	void setPos1r(ofPoint p1rPos);
	ofPoint getPos2();
	void setPos2(float pPos2);
	int getHeight();
	ofPoint getPosd();
};

#endif
