#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	ofBackground(0,0,0);
	fw = ofGetWidth();
	fh = ofGetHeight();

	font.loadFont("automat.ttf",48);

	bgC.setColor(12,56,240,6);
	txtC.setColor(255,255,255,255);
	gui.setBackgroundColor(bgC);
	gui.setTextColor(txtC);
	panelW = 284.0;
	panelH = fh - 20.0;

	rSize = 14.6;
	rPos = ofPoint(fw/2,fh/2);
	rSpeed = ofPoint(0.0,0.0);
	rsMin = ofPoint(-24.0,-24.0);
	rsMax = ofPoint(24.0,24,0);
	r = 128;
	g = 128;
	b = 128;
	
	r2Size = rSize + ofRandom(0.0,35.0);
	r2Pos = ofPoint(fw/2,fh/3);
	r2Speed = ofPoint(0.0,0.0);
	r2 = 128;
	g2 = 128;
	b2 = 128;

	gui.loadFont("MONACO.TTF",8);
	gui.setup("MoveRectControl",fw-panelW,fh-panelH,panelW,panelH);
	gui.addPanel("Control",1,false);

	gui.setWhichColumn(0);
	gui.addToggle("Show2ndRect","SHOW2NDRECT",false);
	gui.addSlider("RectSize","RECTSIZE",rSize,8.0,135.8,false);
	gui.addSlider2D("RectSpeed","RECTSPEED",rSpeed.x,rSpeed.y,rsMin.x,rsMax.x,rsMin.y,rsMax.y,false);
	gui.addToggle("RectMovable","RECTMOVABLE",true);
	gui.addSlider("RectColorR","RECTCOLORR",r,0,255,true);
	gui.addSlider("RectColorG","RECTCOLORG",g,0,255,true);
	gui.addSlider("RectColorB","RECTCOLORB",b,0,255,true);

	gui.setupEvents();
	gui.enableEvents();
}

//--------------------------------------------------------------
void testApp::update()
{
	gui.update();
	rSize = gui.getValueF("RECTSIZE");
	rSpeed.x = gui.getValueF("RECTSPEED",0);
	rSpeed.y = gui.getValueF("RECTSPEED",1);
	r = gui.getValueI("RECTCOLORR");
	g = gui.getValueI("RECTCOLORG");
	b = gui.getValueI("RECTCOLORB");

	r2Size = 135.8 - rSize;
	r2Speed.x = rSpeed.y;
	r2Speed.y = rSpeed.x;
	r2 = 255 - r;
	g2 = 255 - g;
	b2 = 255 - b;
	
	rrPos = rPos;
	rr2Pos = r2Pos;

	if(!gui.getValueB("RECTMOVABLE"))
	{
		rPos = rrPos;
		r2Pos = rr2Pos;
	}
	else
	{
		rPos += rSpeed;
		r2Pos += r2Speed;
	}

	if(rPos.x < rSize/2 || fw - (rSize/2) < rPos.x)
	{
		rPos.x = rrPos.x;
	}
	if(rPos.y < rSize/2 || fh - (rSize/2) < rPos.y)
	{
		rPos.y = rrPos.y;
	}

	if(r2Pos.x < r2Size/2 || fw - (r2Size/2) < r2Pos.x)
	{
		r2Pos.x = rr2Pos.x;
	}
	if(r2Pos.y < r2Size/2 || fh - (r2Size/2) < r2Pos.y)
	{
		r2Pos.y = rr2Pos.y;
	}

	if(ofDist(rPos.x,rPos.y,r2Pos.x,r2Pos.y) < (rSize + r2Size) / 2 + 10.6)
	{
		rPos = rrPos;
		r2Pos = rr2Pos;
	}

	ofRectangle rect = font.getStringBoundingBox("2",r2Pos.x,r2Pos.y);
	fPos = ofPoint(r2Pos.x - (rect.width/2),r2Pos.y - (rect.height/2));

}

//--------------------------------------------------------------
void testApp::draw()
{
	ofSetRectMode(OF_RECTMODE_CENTER);

	ofSetColor(r,g,b);
	ofRect(rPos.x,rPos.y,rSize,rSize);
	
	if(gui.getValueB("SHOW2NDRECT"))
	{
		ofSetColor(r2,g2,b2);
		ofRect(r2Pos.x,r2Pos.y,r2Size,r2Size);
		ofSetColor(r,g,b);
		
		font.drawString("2",fPos.x,fPos.y);
	}
	
	ofSetRectMode(OF_RECTMODE_CORNER);


	ofSetColor(255,255,255);
	gui.draw();

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
	gui.mouseDragged(x,y,button);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{
	gui.mousePressed(x,y,button);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{
	gui.mouseReleased();
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{

}

