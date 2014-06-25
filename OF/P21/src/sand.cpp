#include "sand.h"

sand::sand()
{
	fx = ofGetWidth();
	fy = ofGetHeight();
	pos.x = ofRandom(0.0,fx);
	pos.y = 0.0;
	dim = 1.3;
	spd.x = 0.0;
	spd.y = ofRandom(0.0,5.0);

	g = dim * 1.3;
	
	p1 = ofPoint(fx * 2/6,fy * 2/5);
	p2 = ofPoint(fx * 3/6,fy * 4/5);
	p3 = ofPoint(fx * 4/6,fy * 2/5);
	
}

void sand::draw()
{
	ofFill();
	ofSetColor(220,12,120);
	ofCircle(pos.x,pos.y,dim);
}

void sand::update()
{
	pos += spd;
	pos.y += g;

	if(pos.x < dim || fx - dim < pos.x)
	{
		spd.x *= -1;
		spd.y *= 0.4;
	}
	if(pos.y < dim || fy - 12.0 < pos.y)
	{
		spd.y = 0.0;
		spd.x = 0.0;
		g = 0.0;
	}
	 
	ly1 = (12 * fy) / (5 * fx) * pos.x - fy * 2 / 5;
	
	if(p1.x < pos.x && pos.x < p2.x - 2.1)
	{
		if(pos.y > ly1 - 9)
		{
			spd.y = 0.0;
			spd.x = 0.0;
			g = 0.0;
		}
	}
	
	ly2 = -1 * (12 * fy) / (5 * fx) * pos.x + fy * 2;
	
	if(p2.x + 2.1 < pos.x && pos.x < p3.x)
	{
		if(pos.y > ly2 - 9)
		{
			spd.y = 0.0;
			spd.x = 0.0;
			g = 0.0;
		}
	}

}

ofPoint sand::getPos()
{
	return pos;
}

ofPoint sand::getSpd()
{
	return spd;
}

void sand::setSpd(ofPoint sSpd)
{
	spd = sSpd;
}