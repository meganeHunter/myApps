#ifndef _SAND
#define _SAND

#include "ofMain.h"
#include "Triangle.h"

class sand
{
private:
	float fx,fy;
	ofPoint pos;
	ofPoint spd;
	float dim;
	float g;
	ofPoint rspd;
	bool ioSide;
	float ly1,ly2;
	ofPoint p1,p2,p3,p4,p5,p6;
	bool reach2tob;
	bool reach2m;

public:
	sand();
	void draw();
	void update();
	ofPoint getPos();
	ofPoint getSpd();
	void setSpd(ofPoint sSpd);
	
	triangle ta;
	
};

#endif
