#include "timR.h"

timR::timR()
{
	fw = ofGetWidth();
	fh = ofGetHeight();

	tm = 0;
	rh = 0.0;
	lim = 0;

	pos.x = fw / 2;
	pos.y = fh / 2;

	r = g = b = a = 255;
	w = 24.0;
	h = w / 2.0;
	
	p = 0;

	isTimeOver = false;
}

void timR::update()
{
	p++;

	if(p > (int)ofGetFrameRate())
	{
		p = 0;
		isTimeOver = false;
	}

	if(!isTimeOver)
	{
		if(rh < lim)
		{
			rh += p / (int)ofGetFrameRate();
		}
		else
		{
			isTimeOver = true;
			rh = 0;
		}
	}

}

void timR::draw()
{
	ofPushMatrix();

	ofSetColor(r,g,b,a);

	j = ((h / 4.0) > 1.0) ? (-5.0 * h / 4.0) : -5.0;

	for(k = 0; k < rh; k++)
	{
		ofRect(pos.x,pos.y + (j * k),w,h);
	}

	ofPopMatrix();

}

void timR::reset()
{
	rh = 0.0;
	p = 0;
	
	if(isTimeOver)
	{
		isTimeOver = false;
	}
}

void timR::setColor(ofColor &col)
{
	setColor(col.r,col.g,col.b,col.a);
}

void timR::setColor(int red, int green, int blue, int alp)
{
	r = red;
	g = green;
	b = blue;
	a = alp;
}

void timR::setPos(ofPoint &p)
{
	pos = p;
}

void timR::setSize(float wiz, float hyt)
{
	w = wiz;
	h = hyt;
}

void timR::setLim(int limo)
{
	lim = limo;
}

int timR::getTime()
{
	return rh;
}

bool timR::getIsTimeOver()
{
	return isTimeOver;
}