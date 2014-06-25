#ifndef _IMGZ_TST
#define _IMGZ_TST

#include "ofMain.h"

struct imgz
{
	ofImage img;
	ofPoint pos;
	ofPoint size;
};

	void setImgz(imgz im,string iName);
	void setImgzPos(imgz im,int xp,int yp);

	imgz setImgz2(string iName);
	
	void drawImgz(imgz im);

#endif