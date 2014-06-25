#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	ofBackground(255,255,255);
	ofSetFrameRate(60.0);

	sC.setFont("LiberationMono-Regular.ttf",24);
	rT.setInputTxt("Elegy Written in a Country Churchyard.txt");
	rT.load();

	fx = ofGetWidth();
	fy = ofGetHeight();
	fPos = ofPoint(fx / 8,fy / 8);

	rc = 240;
	rcdi = true;
	gc = 60;
	gcdi = true;
	bc = 0;
	bcdi = true;
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

	
}

//--------------------------------------------------------------
void testApp::draw()
{
	fRate = ofGetFrameRate();

	for(i=0;i<RN;i++)
	{
		for(j=0;j<CN;j++)
		{
			sC.setStr(rT.getChar(i,j));
			cRect = sC.getStrBBox();
			cPos.x = fPos.x + (cRect.width * j);
			cPos.y = fPos.y + (cRect.height * i);
			
			sC.setPos(cPos);
			sC.setColor(rc,gc,bc);
			sC.draw();
			
		}
	}
	
	
	stat =  "w:" + ofToString(cRect.x,2) + " ";
	stat += "h:" + ofToString(cRect.y,2) + " fPos: ";
	stat += "x:" + ofToString(fPos.x,2) + " ";
	stat += "y:" + ofToString(fPos.y,2) + " ";
	stat += "FrameRate:" + ofToString(fRate,2);

	ofSetColor(248,12,124);	
	ofDrawBitmapString(stat,8.0,fy - 8.0);
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{

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

