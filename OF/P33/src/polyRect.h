#ifndef _POLY_RECT
#define _POLY_RECT

#include "ofMain.h"

class pRect
{
private:
	int r,g,b,a;

	float fw,fh;

	ofPoint size;
	ofPoint pos;

	
public:
	pRect();
	pRect(ofRectangle * rect);
	void draw();

	void setPos(ofPoint rPos);
	void setPos(float rx,float ry);
	void setColor(ofPoint rgb);
	void setColor(int rc,int gc,int bc);
	void setColor(int rc,int gc,int bc,int ac);
	void setSize(ofPoint rSize);
	void setSize(float rw,float rh);

	ofPoint getPos();
	float getPosX();
	float getPosY();
	ofPoint getColor();
	int getRed();
	int getGreen();
	int getBlue();
	int getAlpha();
	ofPoint getSize();
	float getWidth();
	float getHeight();

	bool rectMov,nearX;
	float rectW,rectH;

};

#endif
