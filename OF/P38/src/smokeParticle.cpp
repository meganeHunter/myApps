#include "smokeParticle.h"

sPart::sPart()
{
	col.r = 0.0;
	col.g = 0.0;
	col.b = 0.0;
	col.a = 1.0;
	speed = ofPoint(0.0,0.0);
	weight = 1.0;

	isGLMode = true;
}


void sPart::update()
{

	if(sLine.empty() || sqLength(sLine.front(),pos) > 60)
	{
		sLine.push_back(pos);
	}
	
	if((int)sLine.size() > 500)
	{
		sLine.pop_back();
	}

}


void sPart::draw()
{
	if(isGLMode)
	{
		int i;
		glBegin(GL_LINE_STRIP);
		for (i=0;i<(int)sLine.size();i++)
		{
			float a = col.a - (float)i * 0.38 / (float)sLine.size();
			glColor4f(col.r,col.g,col.b,a * 0.3);
			glVertex3fv(sLine[i].v);
		}
		glEnd();
	}
	else
	{
		int j;
		ofBeginShape();
		for(j=0;j<(int)sLine.size();j++)
		{
			float a = col.a - (float)j * 0.38 / (float)sLine.size();
			ofSetColor(col.r,col.g,col.b,a * 0.4);
			ofCurveVertex(sLine[j].x,sLine[j].y);
		}
		ofEndShape(true);
	}
}