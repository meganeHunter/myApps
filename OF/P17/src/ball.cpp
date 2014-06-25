#include "ball.h"

ball::ball()
{
	pos = ofPoint(ofGetWidth()*1/2,ofGetHeight()*1/2);
	dim = 24.0;
	speed = ofPoint(ofRandom(-8,8),ofRandom(-8,8));
	table0 = ofPoint(ofGetWidth()*1/8,ofGetHeight()*1/8);
	tableF = ofPoint(ofGetWidth()*7/8,ofGetHeight()*5/8 + 46);
	
	
	lscore = 0;
	rscore = 0;
	rspeed = 0.0;
	acs = 0.0;
	key = '\0';
	mPos = ofPoint(0,0);
	mMode = false;

}

void ball::draw()
{
	ofSetColor(255,255,255,240);
	ofCircle(pos.x,pos.y,dim);
	
}

void ball::update()
{
	
	pos += speed;
	if(0 < speed.x && speed.x < 3)
	{
		speed.x *= 1.8;
	}
	if(-3 < speed.x && speed.x < 0)
	{
		speed.x *= 1.8;
	}
	if(0 < speed.y && speed.y < 3)
	{
		speed.y *= 1.1;
	}
	if(-3 < speed.y && speed.y < 0)
	{
		speed.y *= 1.1;
	}	

	if(pos.y < table0.y + dim)
	{
		speed.y *= -1;
	}
	if(pos.y > tableF.y + dim)
	{
		speed.y *= -1;
	}

	if(pos.x-dim <= p1Pos.x)
	{
		if(p1Pos.y-(pHeight/2) < pos.y && pos.y < p1Pos.y+(pHeight/2))
		{
			pos.x = p1Pos.x + dim;
			speed.x *= -1;
		}
	}
	if(pos.x+dim >= p2Pos.x)
	{
		if(p2Pos.y-(pHeight/2) < pos.y && pos.y < p2Pos.y+(pHeight/2))
		{
			pos.x = p2Pos.x - dim;
			speed.x *= -1;
			speed.y += acs;
			acs = 0.0;
			//mPos = ofPoint(0,0);
		}
	}

	if(pos.x < table0.x + dim)
	{
				
		speed = 0.0;
		
		rscore++;
		
		pos = ofPoint(ofGetWidth()*1/2,ofGetHeight()*1/2);
		speed = ofPoint(ofRandom(-8,8),ofRandom(-8,8));
	}
	if(pos.x > tableF.x - dim)
	{
		speed = 0.0;
		
		lscore++;		
		
		pos = ofPoint(ofGetWidth()*1/2,ofGetHeight()*1/2);
		speed = ofPoint(ofRandom(-8,8),ofRandom(-8,8));
	}

	if(lscore > 14)
	{
		speed = 0.0;
		pos = ofPoint(ofGetWidth()*1/2,tableF.y);
	}
	if(rscore > 14)
	{
		speed = 0.0;
		pos = ofPoint(ofGetWidth()*1/2,tableF.y);
	}
	
	if(key == 'p' && speed != 0.0)
	{
		rspeed = speed;
		speed = 0.0;
	}
	if(key == 'c' && rspeed != 0.0)
	{
		speed = rspeed;
		key = '\0';
	}

	if(pos.x+dim >= p2Pos.x - 24)
	{
		if(mMode == true)
		{
			acs += 1.4 * speed.y;
			mMode = false;
		}
	}
	else
	{
		if(mMode == true)
		{
			acs = 0.0;
			mMode = false;
		}
	}
	
	
}

ofPoint ball::getSpeed()
{
	return speed;
}

void ball::setSpeed(ofPoint spd)
{
	speed = spd;
}
ofPoint ball::getPos()
{
	return pos;
}

void ball::setPos(ofPoint bpos)
{
	pos = bpos;
}

ofPoint ball::getScore()
{
	return ofPoint(lscore,rscore);
}

void ball::setp1Pos(ofPoint pd1Pos)
{
	p1Pos = pd1Pos;
}

void ball::setp2Pos(ofPoint pd2Pos)
{
	p2Pos = pd2Pos;
}

void ball::setpHeight(int pdHeight)
{
	pHeight = pdHeight;
}

void ball::setMode(int inKey)
{
	key = inKey;
}

void ball::setMpos(ofPoint dmPos)
{
	mPos = dmPos;
}


void ball::setMmode(bool Mm)
{
	mMode = Mm;
}

