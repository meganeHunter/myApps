#ifndef _POINT_2_SMOKE
#define _POINT_2_SMOKE

#include "ofMain.h"

class smokePart
{
private:
	int j,k;

public:
	float weight;
	float alp;
	float dist;

	ofColor col;

	ofPoint pos;
	ofPoint speed;

	vector<ofPoint> smokeline;

	
	smokePart();

	void update();
	void draw();

};

///---------------------------------------------------------

class point2Smoke
{
private:
	int j,k;

	float dist;

	ofColor col;

	string stat;

public:
	vector<smokePart> smp;
	
	point2Smoke();
	
	void init(vector<ofPoint>& startp,ofColor col);

	void update(ofPoint dir);
	void draw();

};


#endif
