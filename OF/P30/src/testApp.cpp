#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	ofBackground(255,255,255);
	ofSetFrameRate(60.0);
	sC = new showChar;

	sC->setFont("automat.ttf",18);
	rT.setInputTxt("Elegy Written in a Country Churchyard.txt");
	rT.load();

	fw = ofGetWidth();
	fh = ofGetHeight();
	fPos = ofPoint(fw / 15,fh / 15);

	sG = ofPoint(0.0,0.8);

	rc = 240;
	rcdi = true;
	gc = 60;
	gcdi = true;
	bc = 0;
	bcdi = true;

	alp = 255;
}

//--------------------------------------------------------------
void testApp::update()
{
	if(!rcdi)
	{
		rc--;
		if(rc == 0)
		{
			rcdi = true;
		}
	}
	else
	{
		rc++;
		if(rc == cM)
		{
			rcdi = false;
		}
	}
	if(!gcdi)
	{
		gc--;
		if(gc == 0)
		{
			gcdi = true;
		}
	}
	else
	{
		gc++;
		if(gc == cM)
		{
			gcdi = false;
		}
	}
	if(!bcdi)
	{
		bc--;
		if(bc == 0)
		{
			bcdi = true;
		}
	}
	else
	{
		bc++;
		if(bc == cM)
		{
			bcdi = false;
		}
	}
	
	for(k=0;k<vsc.size();k++)
	{
		sPos = vsc[k]->getPos();
		if(sPos.y < fh - fPos.y)
		{
			vsc[k]->setPos(sPos + sG);
			vsc[k]->setColor(255-rc,255-gc,255-bc,alp-(int)(sPos.y/12));
		}
	}
	
}

//--------------------------------------------------------------
void testApp::draw()
{
	fRate = ofGetFrameRate();

	for(i=0;i<RN;i++)
	{
		for(j=0;j<CN;j++)
		{
			sC->setStr(rT.getChar(i,j));
			cRect = sC->getStrBBox();
			fPos.x = cRect.width / 2;
			fPos.y = cRect.height / 2;
			cPos.x = (cRect.width * j) - fPos.x;
			cPos.y = (cRect.height * i) - fPos.y;
			
			sC->setPos(cPos);
			sC->setColor(rc,gc,bc);
			sC->draw();
			
		}
	}
	
	
	for(k=0;k<vsc.size();k++)
	{
		vsc[k]->draw();
	}
	


	stat  = "StrBBox: ";
	stat += "w:" + ofToString(cRect.x,2) + " ";
	stat += "h:" + ofToString(cRect.y,2) + " Frame: ";
	stat += "w:" + ofToString(fw,2) + " ";
	stat += "h:" + ofToString(fh,2) + " fPos: ";
	stat += "x:" + ofToString(fPos.x,2) + " ";
	stat += "y:" + ofToString(fPos.y,2) + " ";
	stat += "FrameRate:" + ofToString(fRate,2);

	ofSetColor(38,38,12);	
	ofDrawBitmapString(stat,8.0,fh - 8.0);
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
	
	pChar = ofToString(key);

	showChar * sck = new showChar;
	sck->setPos(mouseX,mouseY);
	sck->setStr(pChar);
	sck->setColor(255-rc,255-gc,255-bc);
	sck->setFont("Cosmic Girl.ttf",12);
	vsc.push_back(sck);

}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{

}

void testApp::exit()
{
	delete sC;
}