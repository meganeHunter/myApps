#include "point2Smoke.h"


smokePart::smokePart()
{
	weight = 1.3;
	col.a = 3.5;
}

void smokePart::update()
{
	dist = (!smokeline.empty()) ? ofDist(smokeline[0].x,smokeline[0].y,pos.x,pos.y) : 12.0;
	if(smokeline.empty() || dist > 12.0 && (int)smokeline.size() < 840)
	{
		smokeline.push_back(pos);
	}

	col.a = abs(dist - (float)smokeline.size()) * 1.3 * ofGetFrameNum();
}

void smokePart::draw()
{
	ofSetColor(col.r,col.g,col.b,col.a);
	ofNoFill();
	ofBeginShape();
	for(j=0;j<(int)smokeline.size();j++)
	{
		alp = col.a * ((int)smokeline.size() - j);
		ofSetColor(col.r,col.g,col.b,alp);
		ofCurveVertex(smokeline[j].x,smokeline[j].y);
	}
	ofEndShape(true);
}


///-------------------------------------------------------------------

point2Smoke::point2Smoke()
{
	dist = 0.0;
}

void point2Smoke::init(vector<ofPoint>& startp,ofColor col)
{
	for(j=0;j<(int)startp.size();j++)
	{
		for(k=0;k<12;k++)
		{
			smokePart smoK;
			smoK.col = col;
			smoK.pos = startp[j];
			smp.push_back(smoK);

			this->col = col;
		}

		if(j<smp.size())
		{
			smp[j].weight = ofGetFrameNum() % 3 * 2.3;
		}

	}

}

void point2Smoke::update(ofPoint dir)
{
	for(j=0;j<(int)smp.size();j++)
	{

		dist = ofDist(smp[j].pos.x,smp[j].pos.y,dir.x,dir.y);
		if(dist > 14.8)
		{
			smp[j].pos.x += (dir.x - smp[j].pos.x) / dist + (ofGetFrameNum() % 12);
			smp[j].pos.y += (dir.y - smp[j].pos.y) / dist + smp[j].weight;	
		}

		smp[j].update();

	}
}

void point2Smoke::draw()
{
	for(j=0;j<(int)smp.size();j++)
	{
		smp[j].draw();
	}

	stat  = "p2Smoke:loaded. / ";
	stat += "Color : ";
	stat += "r : " + ofToString(col.r,2) + " ";
	stat += "g : " + ofToString(col.g,2) + " ";
	stat += "b : " + ofToString(col.b,2) + " ";
	stat += "a : " + ofToString(col.a,2) + " / ";
	stat += "smokePartsize : " + ofToString((double)smp.size(),0) + " ";

	ofSetColor(255,255,255);
	ofDrawBitmapString(stat,20.0,20.0);
}