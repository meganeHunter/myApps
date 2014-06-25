#include "MCubeP.h"

//public:
MCubeP::MCubeP()
{
	fw = ofGetWidth();
	fh = ofGetHeight();
	
	str = " ";
	
	ofBackground(181,79,74);
	
	//ttf1.loadFont("Futura.dfont",48);
	ttf1.loadFont("Futura Condensed.ttf",148);
	
	
	k = 0;
	j = 0;
	
}

void MCubeP::setup()
{
	ans = 0;
	ansCount = 0;
	mode = 0;
	
	sC1 = new showChar(&ttf1);
	
	img1.loadImage("cube1-1.jpg");
	//img1.setImageType(OF_IMAGE_COLOR_ALPHA);
	//img1.setUseTexture(1);
	img1Size.x = img1.getWidth();
	img1Size.y = img1.getHeight();
	
	img2.loadImage("cRoll.jpg");
	img2Size.x = img2.getWidth();
	img2Size.x = img2.getHeight();

}

void MCubeP::draw()
{
	sC1->setColor(150,30,35);
	sC1->setPos(146,148);
		
	sC1->setStr(str);
	sC1->draw();
	
	ofSetColor(181,79,74);
	img1.draw(img1Pos.x,img1Pos.y,img1Size.x * 2,img1Size.y * 2);
	
	img2.draw(img1Pos.x - img1Size.x,img1Pos.y,img2Size.x * 2,img2Size.y * 2);
}

void MCubeP::update()
{
	img1Pos.x = (fw / 2) - img1Size.x;
	img1Pos.y = (fh / 2);
	
	switch(mode)
	{
		case 0:
			str = "test";
			break;
			
		case 1:
			str = "mode: 1";
			break;
			
		case 2:
			str = "mode: 2";
			
		default:
			break;
	}

}

void MCubeP::setMode(int mo)
{
	mode = mo;
}

int MCubeP::getMode()
{
	return mode;
}

int MCubeP::getPoint()
{
	return point;
}


//------------------------------------------------

//private:

