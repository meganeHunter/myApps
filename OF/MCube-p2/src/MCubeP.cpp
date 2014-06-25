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
	ttf2.loadFont("Princetown LET Plain1.0.ttf",148);
	

	k = 0;
	j = 0;
	l = 0;
	
	randNum = 0;
	
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
	
	img1 = setImgz2("cube1-1.jpg");
	img2 = setImgz2("cRoll.jpg");
	
	img3 = setImgz2("nSelecta2.jpg");
	img4 = setImgz2("nCube3.jpg");
	img5 = setImgz2("nCube4.jpg");
	img6 = setImgz2("nCube5.jpg");
	
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
		ofSetColor(184,79,74,0);
		
		img3.img.draw(img3.pos.x,img3.pos.y,img3.size.x,img3.size.y);
		img4.img.draw(img4.pos.x,img4.pos.y,img4.size.x,img4.size.y);
		img5.img.draw(img5.pos.x,img5.pos.y,img5.size.x,img5.size.y);
		img6.img.draw(img6.pos.x,img6.pos.y,img6.size.x,img6.size.y);
	}
	else if(gMode == 2)
	{
		ofSetColor(184,79,74,0);
		
		img3.img.draw(img3.pos.x,img3.pos.y,img3.size.x,img3.size.y);
		img4.img.draw(img4.pos.x,img4.pos.y,img4.size.x,img4.size.y);
		img5.img.draw(img5.pos.x,img5.pos.y,img5.size.x,img5.size.y);
		img6.img.draw(img6.pos.x,img6.pos.y,img6.size.x,img6.size.y);
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
	else if(gMode == 1)
	{
		switch(mode)
		{
			case 0:
				str = "test";
				
				img3.pos = ofPoint(783,153);
								
				img4.pos = ofPoint(58,193);
				
				img5.pos = ofPoint(410,193);
				
				img6.pos = ofPoint(798,193);
				
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
				
			
				
			default:
				break;
		}
		
	}
	else if(gMode == 2)
	{
		switch(mode)
		{
			case 0:
				str = "test";
					
				img3.pos = ofPoint(783,153);
					
				img4.pos = ofPoint(58,193);
					
				img5.pos = ofPoint(410,193);
					
				img6.pos = ofPoint(798,193);
					
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
			break;
			
		case 4:
			img4.pos = p;
			break;
			
		case 5:
			img5.pos = p;
			break;
			
		case 6:
			img6.pos = p;
			break;
			
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
			break;
			
		case 4:
			img4.size = s;
			break;
			
		case 5:
			img5.size = s;
			break;
			
		case 6:
			img6.size = s;
			break;
			
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
			break;
		
		case 4:
			return img4.pos;
			break;
			
		case 5:
			return img5.pos;
			break;
			
		case 6:
			return img6.pos;
			break;
			
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
			break;
			
		case 4:
			return img4.size;
			break;
			
		case 5:
			return img5.size;
			break;
			
		case 6:
			return img6.size;
			break;
		
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

imgz MCubeP::setImgz2(string iName)
{
	imgz im;
	
	im.img.loadImage(iName);
	im.size.x = im.img.getWidth();
	im.size.y = im.img.getHeight();
	
	return im;	
}

void MCubeP::rollNum(int top,int bottom,int yPos)
{
	for(l = 0; l < 10; l++)
	{
		randNum = (int)rand() % 10;
		rNum = ofToString(randNum,0);
		
		showChar * sc = new showChar;
		sc->setPos(top + (l * 35),yPos);
		sc->setStr(rNum);
		sc->setColor(237,123,123);
		numRoll.push_back(sc);
	}
}

