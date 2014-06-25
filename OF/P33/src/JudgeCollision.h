#ifndef _JUDGE_COLLISION
#define _JUDGE_COLLISION

#include "ofMain.h"
#include "polyRect.h"

class JudgeC
{
private:
	float fw,fh;
	float fRate;
	float dist,distX,distY;
	float sRectW,sRectH;
	float vRectW,vRectH;
	float sWidth;

	int k,j;

	ofPoint cPos,fPos;
	ofPoint posp;
	ofPoint sPos,vPos;
	ofPoint psPos,pvPos;
	ofPoint sG;

	pRect ** mRect;

public:
	JudgeC(pRect ** pR);
	void judge();

};

#endif
