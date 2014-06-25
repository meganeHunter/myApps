#include "ajeMain.h"

ajeMain::ajeMain()
{
	fw = ofGetWidth();
	fh = ofGetHeight();

	disp = 0;
	mode = 0;
		
	//font1.loadFont("BabyTria.ttf",128,true,false,false);
	//f1Rect = font1.getStringBoundingBox("0",fw / 2,fh / 2);

	//sch = new showChar(&font1);
	//sch->setColor(24,8,255,248);


	//font2.loadFont("BabyTria2.ttf",64,true,false,false);
	//f2Rect = font2.getStringBoundingBox("ALEA JACTA EST",fw / 2,fh / 2);

	//sch2 = new showChar(&font2);

	sCol.r = sCol.g = sCol.b = sCol.a = 255;
	sSize = (int)f1Rect.width;

	timere.setColor(255,255,255,128);
	timere.setPos(ofPoint(fw - 35.0,fh - 12.4));
	timere.setSize(24.8,8.5);
	timere.setLim(12);

	aje = "ALEA JACTA EST";
	ox = sqon = sign = num = eq = answ = "";
	

}

void ajeMain::update()
{
	switch(disp)
	{
	case 0:
		//sch2->setStr("ALEA JACTA EST");
		//sch2->setColor(255,255,255,255);
		//sch2->setPos((fw / 2) - (f2Rect.width / 2),fh / 2);

		aje = "ALEA JACTA EST";
		ox = sqon = sign = num = eq = answ = "";
	
		//switch(mode)
		//{
		//case 1:
		//	//sch2->setPos((fw / 2) - (f2Rect.width / 2),fh / 3);
		//	break;
		//
		//case 2:
		//	//sch2->setPos((fw / 2) - (f2Rect.width / 2),fh / 3);
		//	break;

		//default:
		//	break;
		//}

		break;

	case 1:
		//switch(mode)
		//{
		//case 0:
		//	break;

		//case 1:
		//	break;
		//
		//case 2:
		//	break;

		//default:
		//	break;
		//}

		aje = "";
		break;

	case 2:
		timere.update();
		
		checkAns();

		break;

	default:
		break;
	}
}

void ajeMain::draw()
{
	ofPushStyle();

	ofSetColor(255,255,255,255);
	
	switch(disp)
	{
	case 0:
		switch(mode)
		{
		case 0:
			//sch2->draw();
		
			ofDrawBitmapString(aje,fw / 4,fh / 2 + 100);
			break;

		case 1:
			drawSQON();
			ofDrawBitmapString(aje,fw / 4,fh / 2 + 100);
			break;

		case 2:
			drawOX();
			timere.reset();
			ofDrawBitmapString(ox,fw / 4,fh / 2 + 90);
			break;

		default:
			break;
		}

		break;

	case 1:
		switch(mode)
		{
		case 0:
			drawSQON();
			ofDrawBitmapString(sqon,fw / 4,fh / 2 + 80);
			break;

		case 1:
			drawSQON();
			drawSign(sin);
			ofDrawBitmapString(sqon,fw / 4,fh / 2 + 80);
			ofDrawBitmapString(sign,fw / 4,fh / 2 + 70);
			ofDrawBitmapString(num,fw / 4,fh / 2 + 60);
			ofDrawBitmapString(eq,fw / 4,fh / 2 + 50);
			break;

		case 2:
			drawSQON();
			drawSign(sin);
			drawEQ();
			ofDrawBitmapString(sqon,fw / 4,fh / 2 + 80);
			ofDrawBitmapString(sign,fw / 4,fh / 2 + 70);
			ofDrawBitmapString(num,fw / 4,fh / 2 + 60);
			ofDrawBitmapString(eq,fw / 4,fh / 2 + 50);
			break;

		default:
			break;
		}

		break;

	case 2:
		drawSQON();
		drawSign(sin);
		drawEQ();
		ofDrawBitmapString(sqon,fw / 4,fh / 2 + 80);
		ofDrawBitmapString(sign,fw / 4,fh / 2 + 70);
		ofDrawBitmapString(num,fw / 4,fh / 2 + 60);
		ofDrawBitmapString(eq,fw / 4,fh / 2 + 50);

		timere.draw();
		if(timere.getIsTimeOver())
		{
			ox = sqon = sign = num = eq = "";
			
		}

		break;

	default:
		break;
	}

	

	//ofDrawBitmapString(statA,fw * (1 / 4),fh / 2);
	

	ofPopStyle();

}

void ajeMain::drawSign(int si)
{
	//ofPushMatrix();
	//ofPushStyle();
	
	//ofSetColor(sCol.r,sCol.g,sCol.b,sCol.a);
	//ofTranslate(sPos.x,sPos.y);

	ofFill();

	switch(si)
	{
	case 0: // "+"

		//ofRect(0.0,sSize / 3,sSize,sSize / 3);
		//ofRect(sSize,0.0,sSize / 3,sSize);

		sign = "+";

		break;

	case 1: // "-"

		//ofRect(0.0,sSize / 3,sSize,sSize / 3);

		sign = "-";

		break;

	case 2: // "*"

		//ofTranslate(sPos.x + (sSize / 2),sPos.y + (sSize / 2));
		//ofSetRectMode(OF_RECTMODE_CENTER);
		
		//ofRect(0.0,sSize / 3,sSize,sSize / 3);
		//ofRect(sSize,0.0,sSize / 3,sSize);
		
		//ofRotate(45.0);

		//ofSetRectMode(OF_RECTMODE_CORNER);
		//ofTranslate(sPos.x,sPos.y);

		sign = "*";

		break;

	case 3: // "/"

		//ofRect(0.0,sSize / 3,sSize,sSize / 3);
		//ofCircle(sSize / 2,sSize / 6,sSize / 7);

		sign = "/";

		break;

	default:
		break;

	}

	//ofPopStyle();
	//ofPopMatrix();

}

void ajeMain::drawSQ(int start,int end)
{
	ofPushMatrix();
	ofPushStyle();

	ofNoFill();
	ofSetColor(sCol.r,sCol.g,sCol.b,sCol.a);

	for(k = start; k < end + 1; k++)
	{
		ofRect(f1Rect.width * (k + 1),fh / 2,f1Rect.width,f1Rect.width);
	}

	ofPopStyle();
	ofPopMatrix();
}

void ajeMain::drawSQR(bool* sorn)
{
	ofPushMatrix();
	ofPushStyle();

	ofNoFill();
	ofSetColor(sCol.r,sCol.g,sCol.b,sCol.a);

	for(k = 0; k < 3; k++)
	{
		if(sorn[k])
		{
			ofRect(f1Rect.width * (k + 1),fh / 2,f1Rect.width,f1Rect.width);
		}
	}

	ofPopStyle();
	ofPopMatrix();
}

void ajeMain::drawSQON()
{
	//sch->setVN(bN);
	//sch->drawVN();

	//ofPushMatrix();
	//ofPushStyle();

	//ofNoFill();
	//ofSetColor(sCol.r,sCol.g,sCol.b,sCol.a);

	for(k = 0; k < bN.size(); k++)
	{
		if((sqon.size() < 3) && !bN[k].isShow)
		{
			//ofRect(f1Rect.width * (k + 1),fh / 2,f1Rect.width,f1Rect.width);

			sqon += "#";
		}
		else if(num.size() < 3) 
		{
			num += ofToString(bN[k].var);
		}
	}

	//ofPopStyle();
	//ofPopMatrix();

}

void ajeMain::drawOX()
{
	//ofPushMatrix();
	//ofPushStyle();

	//ofSetColor(sCol.r,sCol.g,sCol.b,sCol.a);

	if(isCorr)
	{
		//ofFill();
		//ofCircle(fw / 2,fh / 2,fh / 4);
		
		//ofPushStyle();
			
		//ofSetColor(0,0,0);
		//ofCircle(fw / 2,fh / 2,(fh / 4) - 24);

		//ofPopStyle();

		ox = "O";
	}
	else
	{
		//ofTranslate(fw / 2,fh / 2);
		//ofSetRectMode(OF_RECTMODE_CENTER);
		
		//ofRect(0.0,0.0,fh / 4,fh / 12);
		//ofRect(0.0,0.0,fh / 12,fh / 4);
		
		//ofRotate(45.0);

		//ofSetRectMode(OF_RECTMODE_CORNER);

		ox = "X";
	}

	//ofPopStyle();
	//ofPopMatrix();
}

void ajeMain::drawNum(int *numar)
{
	ofPushMatrix();
	ofPushStyle();

	ofNoFill();
	ofSetColor(sCol.r,sCol.g,sCol.b,sCol.a);

	for(k = 0; k < 3; k++)
	{
		if(numar[k])
		{
			//sch->drawBA();
		}
	}

	ofPopStyle();
	ofPopMatrix();
}



void ajeMain::drawEQ()
{
	if(isDrawEQ)
	{
		//ofPushMatrix();
		//ofPushStyle();
	
		//ofSetColor(sCol.r,sCol.g,sCol.b,sCol.a);
		//ofTranslate(sPos.x + (f1Rect.width * 2),sPos.y);

		//ofFill();

		//ofRect(0.0,sSize / 4,sSize,sSize / 3);
		//ofRect(0.0,sSize * (3 / 4),sSize,sSize / 3);

		//ofPopStyle();
		//ofPopMatrix();

		eq = "=";

	}
}

void ajeMain::drawAns()
{
	if(ans != 10)
	{
		answ = ofToString(ans);
	}
	else
	{
		answ = "";
	}
}

///----------------------------------------------

void ajeMain::checkAns()
{
	switch(sin)
	{
	case 0: // "+"
		isCorr = (ans == (int)(bN[0].var + bN[2].var));

		break;

	case 1: // "-"
		isCorr = (ans == (int)(bN[0].var - bN[2].var));

		break;

	case 2: // "*"
		isCorr = (ans == (int)(bN[0].var * bN[2].var));

		break;

	case 3: // "/"
		isCorr = (ans == (int)(bN[0].var / bN[2].var));

		break;

	default:
		break;

	}
}

///----------------------------------------------

void ajeMain::setNumVar(brok* bras)
{
	
}

void ajeMain::setDisp(int dsp)
{
	disp = dsp;
}

void ajeMain::setSignPos(ofPoint sinp)
{
	
}

void ajeMain::setSignSize(int ssiz)
{
	
}

void ajeMain::setSignColor(ofColor scol)
{
	sCol = scol;
}

void ajeMain::setSignType(int sint)
{
	sin = sint;
}

void ajeMain::setSorn(bool* sorn)
{
	
}

void ajeMain::setMode(int mo)
{
	mode = mo;
}

void ajeMain::setBroN(vector<brokN>& broN)
{
	bN = broN;
}

void ajeMain::setIsDrawEQ(bool isD)
{
	isDrawEQ = isD;
}

void ajeMain::setAns(int answer)
{
	ans = answer;
}

///----------------------------------------------

int ajeMain::getDisp()
{
	return disp;
}

int ajeMain::getMode()
{
	return mode;
}

int ajeMain::getTime()
{
	return timere.getTime();
}

bool ajeMain::getIsTimeOver()
{
	return timere.getIsTimeOver();
}