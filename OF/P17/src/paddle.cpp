#include "paddle.h"

paddle::paddle()
{
	table0 = ofPoint(ofGetWidth()*1/8,ofGetHeight()*1/8);
	tableF = ofPoint(ofGetWidth()*7/8,ofGetHeight()*5/8);

	ofSetRectMode(OF_RECTMODE_CENTER);

	width = 8;
	height = 58;
	pos1 = ofPoint(table0.x+35,ofGetHeight()/2);
	pos2 = ofPoint(tableF.x-35,ofGetHeight()/2);
	
	p1speed = 0.0;
}

void paddle::draw()
{
	ofFill();
	ofSetColor(255,255,255);
	ofRect(pos1.x,pos1.y,width,height);
	ofRect(pos2.x,pos2.y,width,height);

}

void paddle::update()
{
	pos1.y += p1speed;

	if(pos1.y < table0.y + height/2)
	{
		pos1.y = table0.y + height/2 - 24;
	}
	if(pos1.y > tableF.y + height/2)
	{
		pos1.y = tableF.y + height/2 + 3;
	}

	if(pos2.y < table0.y + height/2)
	{
		pos2.y = table0.y + height/2 - 24;
	}
	if(pos2.y > tableF.y + height/2)
	{
		pos2.y = tableF.y + height/2 + 3;
	}

}

ofPoint paddle::getPos1()
{
	return pos1;
}

void paddle::setPos1(ofPoint pPos1)
{
	pos1 = pPos1;
}

void paddle::setPos1r(ofPoint p1rPos)
{
	posDif = pos1 - p1rPos;
	
	if(posDif.x > -350)
	{
		if(0 < posDif.y && posDif.y < 12)
		{
			p1speed -= 1;
			if(posDif.y < 3)
			{
				p1speed *= 0.3;
			}
		}
		if(12 <= posDif.y)
		{
			p1speed -= 5;
		}
	
			
		if(-12 < posDif.y && posDif.y < 0)
		{
			p1speed += 1;
			if(posDif.y > -3)
			{
				p1speed *= 0.3;
			}
		}
		if(posDif.y <= -12)
		{
			p1speed += 5;
		}
		
	}
}

ofPoint paddle::getPos2()
{
	return pos2;
}

void paddle::setPos2(float pPos2)
{
	pos2.y = pPos2;
}

int paddle::getHeight()
{
	return height;
}

ofPoint paddle::getPosd()
{
	return posDif;
}
