#ifndef _TABLE
#define _TABLE

#include "ofMain.h"
#include "ball.h"

class table
{
private:
	int lscore;
	int rscore;
	char cons[8];
	char score[8];
	ofPoint scr;
	int key;
	ofPoint posDif;
	char posD[8];

public:
	table();	
	ofTrueTypeFont vfont;
	void draw();
	void update();
	void setScore(ofPoint score);
	void setMode(int inkey);
	void setPosd(ofPoint posD);
	~table();

	ball bont;

};

#endif