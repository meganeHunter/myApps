#ifndef _SMOKE_PARTICLE
#define _SMOKE_PARTICLE

#include "ofMain.h"

class sPart
{
public:
	vector<ofPoint> sLine;

	ofPoint speed;
	ofPoint pos;
	ofPoint windir;

	ofColor col;

	float weight;
	
	bool isGLMode;

	///---------------------------
	sPart();

	void update();
	void draw();

};



static float sqLength(ofPoint p1,ofPoint p2)
{
	ofPoint pp = p1 - p2;
	return (pp.x*pp.x + pp.y*pp.y + pp.z*pp.z);
}

#endif
