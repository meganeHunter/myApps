#include "MCubeP.h"

//------------------------------------------------

//public:
MCubeP::MCubeP()
{
	fw = ofGetWidth();
	fh = ofGetHeight();
	
	str = " ";
	
	ofBackground(181,79,74);
	
	ttf1.loadFont("Futura Condensed.ttf",148);
	
	k = 0;
	j = 0;
	
	linePos = 0;
	
	ans = 0;
	ansCount = 0;
	mode = 0;
	gMode = 0;

}

//------------------------------------------------

void MCubeP::setup()
{
		
	sC1 = new showChar(&ttf1);
	
	setImgz(img1,"cube1-1.jpg");
	setImgz(img2,"cRoll.jpg");
	setImgz(img3,"nSelecta4.jpg");
	
}

void MCubeP::draw()
{
	ofSetupScreen();
	
	sC1->setColor(150,30,35);
	sC1->setPos(85,148);
		
	sC1->setStr(str);
	sC1->draw();
	
	if(gMode == 0)
	{
		ofSetColor(181,79,74);
		img1.img.draw(img1.pos.x,img1.pos.y,img1.size.x * 2,img1.size.y * 2);
		img2.img.draw(img2.pos.x,img2.pos.y,img2.size.x * 2,img2.size.y * 2);
		
		ofSetColor(180,30,35);
		ofSetLineWidth(8);
		ofLine(2,linePos,fw - 2,linePos);		
	}
	else if(gMode == 1)
	{
		ofSetColor(255,255,255);
		img3.img.draw(img3.pos.x,img3.pos.y,img3.size.x,img3.size.y);
	}
	
}

void MCubeP::update()
{
		
	if(gMode == 0)
	{
		switch(mode)
		{
			case 0:
				str = "test";
				
				img1.pos = ofPoint(331,431);
				img2.pos = ofPoint(621,427);
				
				img1.size = ofPoint(147,131);
				img2.size = ofPoint(194,95);
				
				linePos = 112;
				
				break;
				
			case 1:
				str = "mode: 1";
				
				break;
				
			case 2:
				str = "mode: 2";
				
				break;
				
			case 3:
				str = "mode: 3";
				
				break;
				
			case 4:
				str = "mode: 4";
				
				break;
				
			case 5:
				str = "mode: 5";
				
				break;
				
			case 35:
				str = "MATHCUBE";
				
				img1.pos = ofPoint(331,431);
				img2.pos = ofPoint(621,427);
				
				img1.size = ofPoint(147,131);
				img2.size = ofPoint(194,95);
				
				linePos = 112;
				
				break;
				
			default:
				break;
		}
		
	}
	else
	{
		switch(mode)
		{
			case 0:
				str = "test";
				
				img3.pos = ofPoint(331,431);
				img3.size = ofPoint(128,372);
				
				break;
				
			case 1:
				str = "mode: 1";
				
				break;
				
			case 2:
				str = "mode: 2";
				
				break;
				
			case 3:
				str = "mode: 3";
				
				break;
				
			default:
				break;
		}
	}
	
}

//------------------------------------------------

void MCubeP::setMode(int mo)
{
	mode = mo;
}

void MCubeP::setGMode(int gmo)
{
	gMode = gmo;
}

void MCubeP::setImgPos(ofPoint p,int iNum)
{
	switch(iNum)
	{
		case 1:
			img1.pos = p;
			break;
		
		case 2:
			img2.pos = p;
			break;
			
		case 3:
			img3.pos = p;
			
		default:
			break;
	}
}

void MCubeP::setImgSize(ofPoint s,int iNum)
{
	switch(iNum)
	{
		case 1:
			img1.size = s;
			break;
			
		case 2:
			img2.size = s;
			break;
			
		case 3:
			img3.size = s;
			
		default:
			break;
	}
}

void MCubeP::setLinePos(int lp)
{
	linePos = lp;
}

//------------------------------------------------

int MCubeP::getMode()
{
	return mode;
}

int MCubeP::getGMode()
{
	return gMode;
}

int MCubeP::getPoint()
{
	return point;
}

int MCubeP::getLinePos()
{
	return linePos;
}

ofPoint MCubeP::getImgPos(int iNum)
{
	switch(iNum)
	{
		case 1:
			return img1.pos;
			break;
			
		case 2:
			return img2.pos;
			break;
			
		case 3:
			return img3.pos;
			
		default:
			break;
	}
}

ofPoint MCubeP::getImgSize(int iNum)
{
	switch(iNum)
	{
		case 1:
			return img1.size;
			break;
			
		case 2:
			return img2.size;
			break;
			
		case 3:
			return img3.size;
			
		default:
			break;
	}
}


//------------------------------------------------

//private:

void MCubeP::setImgz(imgz im,string iName)
{
	im.img.loadImage(iName);
	im.size.x = im.img.getWidth();
	im.size.y = im.img.getHeight();
}
