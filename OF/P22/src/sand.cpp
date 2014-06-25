#include "sand.h"

sand::sand()
{
	p1 = ta.getP1();
	p2 = ta.getP2();
	p3 = ta.getP3();
	p4 = ta.getP4();
	p5 = ta.getP5();
	p6 = ta.getP6();

	fx = ofGetWidth();
	fy = ofGetHeight();
	pos.x = ofRandom(p1.x,p3.x);
	pos.y = 0.0;
	dim = 1.3;
	spd.x = 0.0;
	spd.y = ofRandom(0.0,5.0);

	rspd = ofPoint(0.0,0.0);
	g = dim * 1.3;
	
	ioSide = false; 
	reach2tob = false;
	reach2m = false;
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
	 
	ly1 =((2 * fy / fx) + (72 / fx)) * pos.x - fy * 3 / 6 - 24;
	
	if(p1.x < pos.x && pos.x < p2.x - 4.1)
	{
		if(pos.y > ly1 - 5)
		{
			rspd = spd;
			//rspd.x += ofRandom(0.3,0.8);
			spd.y = 0.1;
			spd.x = 0.1;
			pos.x += 0.1;
			pos.y = ly1 - 5 - ofRandom(0.1,0.8);
			g = 0.0;
			ioSide = true; 
		}
	}
	else if(ioSide)
	{
		spd = rspd;
		g = dim * 1.3;
		ioSide = false;
	}
	
	ly2 = -1 * ((2 * fy / fx) + (72 / fx)) * pos.x + fy * 3 / 2 + 48;
	
	if(p2.x + 4.1 < pos.x && pos.x < p3.x)
	{
		if(pos.y > ly2 - 5)
		{
			rspd = spd;
			//rspd.x -= ofRandom(0.3,0.8);
			spd.y = 0.1;
			spd.x = - 0.1;
			pos.x -= 0.1;
			pos.y = ly2 - 5 - ofRandom(0.1,0.8) ;
			g = 0.0;
			ioSide = true;
		}
	}
	else if(ioSide)
	{
		spd = rspd;
		rspd = ofPoint(0.0,0.0);
		g = dim * 1.3;
		ioSide = false;
	}

	if(p5.y -31 <= pos.y && pos.y <= p5.y -24)
	{
		if(spd.x == 0.0)
		{
			reach2m = true;
		}
	}
	else if(reach2m)
	{
		spd.x += ofRandom(-0.4,0.4);
		reach2m = false;
	}

	if(pos.y > p4.y - 12.8)
	{
		rspd = spd;
		spd = ofPoint(0.0,0.0);
		g = 0.0;
		reach2tob = true;
	}
	else if(reach2tob)
	{
		spd = rspd;
		rspd = ofPoint(0.0,0.0);
		reach2tob = false;
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