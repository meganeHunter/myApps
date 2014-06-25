#ifndef _SAND
#define _SAND

#include "ofMain.h"

class sand
{
private:
 float fx,fy;
 ofPoint pos;
 ofPoint spd;
 float dim;
 float g;

public:
	sand();
	void draw();
	void update();
	ofPoint getPos();
	ofPoint getSpd();
	void setSpd(ofPoint sSpd);
	
	float ly1,ly2;
	ofPoint p1,p2,p3;
};

#endif
