#include "triangle.h"

triangle::triangle()
{
	fx = ofGetWidth();
	fy = ofGetHeight();

	p1 = ofPoint(fx * 2/6,fy * 1/6);
	p2 = ofPoint(fx * 3/6,fy * 3/6 + 12);
	p3 = ofPoint(fx * 4/6,fy * 1/6);

	p4 = ofPoint(fx * 2/6,fy * 5/6);
	p5 = ofPoint(fx * 3/6,fy * 3/6 - 12);
	p6 = ofPoint(fx * 4/6,fy * 5/6);
}

void triangle::draw()
{
	ofNoFill();
	ofSetColor(248,12,56);
	ofTriangle(p1.x,p1.y,p2.x,p2.y,p3.x,p3.y);
	ofTriangle(p4.x,p4.y,p5.x,p5.y,p6.x,p6.y);
}

ofPoint triangle::getP1()
{
	return p1;
}

ofPoint triangle::getP2()
{
	return p2;
}

ofPoint triangle::getP3()
{
	return p3;
}

ofPoint triangle::getP4()
{
	return p4;
}

ofPoint triangle::getP5()
{
	return p5;
}

ofPoint triangle::getP6()
{
	return p6;
}

