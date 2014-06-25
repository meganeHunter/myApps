#ifndef TIM_R
#define TIM_R

#include "ofMain.h"

class timR
{
public:
	timR();
	void update();
	void draw();
	void reset();

	void setColor(ofColor& col);
	void setColor(int red,int green,int blue,int alp);
	void setPos(ofPoint& p);
	void setSize(float wiz,float hyt);
	void setLim(int limo);

	int getTime();
	bool getIsTimeOver();


private:
	int fw,fh;
	int tm;
	int lim;
	int j,k,p;
	int r,g,b,a;
	int rh;
	int frmn;

	float w,h;

	bool isTimeOver;

	ofPoint pos;

	string stat;
};

#endif