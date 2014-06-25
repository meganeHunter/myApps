#include "Str2Colors.h"

str2c::str2c()
{
	fw = ofGetWidth();
	fh = ofGetHeight();

	slcol = COLS;

	colors = new string[COLS];
	colors[0] = "red";
	colors[1] = "orange";
	colors[2] = "yellow";
	colors[3] = "green";
	colors[4] = "blue";
	colors[5] = "ivory";
	colors[6] = "violet";
	colors[7] = "white";

}

/*
str2c::str2c(ofTrueTypeFont* font)
{
	fw = ofGetWidth();
	fh = ofGetHeight();

	slcol = COLS;

	colors = new string[COLS];
	colors[0] = "red";
	colors[1] = "orange";
	colors[2] = "yellow";
	colors[3] = "green";
	colors[4] = "blue";
	colors[5] = "ivory";
	colors[6] = "violet";
	colors[7] = "white";

	this->font = font; 

}
*/

//

/*
str2c::str2c(showChar* sc)
{
	fw = ofGetWidth();
	fh = ofGetHeight();

	slcol = COLS;

	colors = new string[COLS];
	colors[0] = "red";
	colors[1] = "orange";
	colors[2] = "yellow";
	colors[3] = "green";
	colors[4] = "blue";
	colors[5] = "ivory";
	colors[6] = "violet";
	colors[7] = "white";

	sch = sc;

}
*/





void str2c::setup(ofTrueTypeFont* font)
{
	switch(slcol)
	{
	case 0:
		setupRed(font);
		break;

	case 1:
		setupOrange();
		break;

	case 2:
		setupYellow();
		break;

	case 3:
		setupGreen();
		break;

	case 4:
		setupBlue(font);
		break;

	case 5:
		setupIvory();
		break;

	case 6:
		setupViolet();
		break;

	case 7:
		setupWhite();
		break;

	default:
		break;

	}
}

void str2c::draw()
{
	switch(slcol)
	{
	case 0:
		drawRed();
		break;

	case 1:
		drawOrange();
		break;

	case 2:
		drawYellow();
		break;

	case 3:
		drawGreen();
		break;

	case 4:
		drawBlue();
		break;

	case 5:
		drawIvory();
		break;

	case 6:
		drawViolet();
		break;

	case 7:
		drawWhite();
		break;

	default:
		break;

	}
}

void str2c::update()
{
	
}

void str2c::setStr(string str)
{	
	for(j=0;j<COLS;j++)
	{
		if(str == colors[j])
		{
			slcol = j;
			return;
		}
		else
		{
			slcol = 8;
		}
	}
}

void str2c::setupRed(ofTrueTypeFont* font)
{
	//ofTrueTypeFont fontR;
	//fontR.loadFont("LILIPUT.ttf",12);

	sch = new showChar(font);
	

	scWidth = font->stringWidth("W");
	scHeight = font->stringHeight("W");
}


void str2c::drawRed()
{
	sch->setColor(248,21,24);
	count = 0;
	for(j=0;j<(int)fh;j+=(int)scHeight)
	{
		for(k=0;k<(int)fw;k+=(int)scWidth)
		{
			switch(count % 4)
			{
			case 0:
				k += (int)scWidth;
				break;

			case 1:
				sch->setStr("R");
				break;

			case 2:
				sch->setStr("E");
				break;

			case 3:
				sch->setStr("D");
				break;

			default:
				break;

			}

			sch->setPos(k,j);
			sch->draw();

			count++;

		}
	}
}

void str2c::setupOrange()
{

}

void str2c::drawOrange()
{

}

void str2c::setupYellow()
{

}

void str2c::drawYellow()
{

}

void str2c::setupGreen()
{
	
}

void str2c::drawGreen()
{

}

void str2c::setupBlue(ofTrueTypeFont* font)
{
	sch = new showChar(font);
	
}

void str2c::drawBlue()
{
	sch->setColor(12,124,248,128);
	sch->setStr("BLUE");
	sch->setPos(fw/2.0,fh/2.0);
	sch->draw();

	ofSetColor(0,0,0);
	statest  = "Btest / strPos : ";
	statest += "x: " + ofToString(sch->getPos().x,2) + " ,";
	statest += "y: " + ofToString(sch->getPos().y,2) + "  ";
	statest += "slcol: " + ofToString(slcol,0) + "  ";
	ofDrawBitmapString(statest,20.0,fh - 30.0);
}

void str2c::setupIvory()
{

}

void str2c::drawIvory()
{

}

void str2c::setupViolet()
{

}

void str2c::drawViolet()
{

}

void str2c::setupWhite()
{

}

void str2c::drawWhite()
{

}