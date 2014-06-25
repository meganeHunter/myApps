#ifndef _TRIANGLE
#define _TRIANGLE

#include "ofMain.h"

class triangle
{
private:
	ofPoint p1,p2,p3,p4,p5,p6;
	float fx,fy;

public:
	triangle();
	void draw();
	ofPoint getP1();
	ofPoint getP2();
	ofPoint getP3();
	ofPoint getP4();
	ofPoint getP5();
	ofPoint getP6();

};

#endif
