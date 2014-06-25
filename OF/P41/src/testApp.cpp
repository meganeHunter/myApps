#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
    ofAddListener(tuio.objectAdded,this,&testApp::objectAdded);
    ofAddListener(tuio.objectRemoved,this,&testApp::objectRemoved);
    ofAddListener(tuio.objectUpdated,this,&testApp::objectUpdated);
    ofAddListener(tuio.cursorAdded,this,&testApp::tuioAdded);
    ofAddListener(tuio.cursorRemoved,this,&testApp::tuioRemoved);
    ofAddListener(tuio.cursorUpdated,this,&testApp::tuioUpdated);
     
    
    ofSetFrameRate(60);
    
    ofBackground(0,0,0);
     
	ofEnableAlphaBlending();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE);

   
    tuio.start(3333);
     

    log = "";

	fw = ofGetWidth();
	fh = ofGetHeight();

	isFrmNew = false;
	isLearnBG = false;
	isModeTuio = true;
	isDrawAll = false;
	isPaintByMouse = false;
	isInRangeX = isInRangeY = false;
	isDrawRectsR = isDrawRectsG = isDrawRectsB = false;
	isShowStat = false;
	isCursorFuz = false;

	a = 255;

	videoW = fw - 120;
	videoH = fh - 120;
	rangeW = 60;
	rangeH = 60;

	rangef1 = rangef2 = rangef3 = D_RANGE;
	angf1 = angf2 = angf3 = 180;

	
	#ifdef _USE_LIVE_VIDEO
		vidGrabber.setVerbose(true);
		vidGrabber.listDevices();
		vidGrabber.setDeviceID(1);
		vidGrabber.initGrabber(videoW,videoH);
	#else
        vidPlayer.loadMovie("fingers.mov");
        vidPlayer.play();
	#endif

	colorImg.allocate(videoW,videoH);
	grayImage.allocate(videoW,videoH);
	grayBg.allocate(videoW,videoH);

	font.loadFont("automat.ttf",48,true,false,false);
	sch1 = new showChar(&font);
	sch2 = new showChar(&font);
	sch3 = new showChar(&font);
	
	sch1->setStr("RED");
	sch2->setStr("GREEN");
	sch3->setStr("BLUE");

}

//--------------------------------------------------------------
void testApp::update()
{
	tuio.getMessage();

	
    objectList = tuio.getTuioObjects();
   
    
    for (tobj = objectList.begin();tobj != objectList.end();tobj++) 
	{
        
        blob = (*tobj);

		if(blob->getFiducialId() == 1 || blob->getFiducialId() == 24)
		{
			if(isCursorFuz)
			{
				fid1X = (blob->getPosition().getX() * fw) + (int)ofRandom(-3,3);
				fid1Y = (blob->getPosition().getY() * fh) + (int)ofRandom(-4,4);
			}
			else
			{
				fid1X = blob->getPosition().getX() * fw;
				fid1Y = blob->getPosition().getY() * fh;
			}

			if(abs(blob->getAngleDegrees() - angf1) > 24.0)
			{
				if(rangef1 + (int)(blob->getAngleDegrees() - angf1) > 0)
				{
					rangef1 += (int)(blob->getAngleDegrees() - angf1);
				}

				angf1 = blob->getAngleDegrees();
			}
		}

		if(blob->getFiducialId() == 2 || blob->getFiducialId() == 35)
		{
			if(isCursorFuz)
			{
				fid2X = (blob->getPosition().getX() * fw) + (int)ofRandom(-5,3);
				fid2Y = (blob->getPosition().getY() * fh) + (int)ofRandom(-4,6);
			}
			else
			{
				fid2X = blob->getPosition().getX() * fw;
				fid2Y = blob->getPosition().getY() * fh;
			}

			if(abs(blob->getAngleDegrees() - angf2) > 35.0)
			{
				if(rangef2 + (int)(blob->getAngleDegrees() - angf2) > 0)
				{
					rangef2 += (int)(blob->getAngleDegrees() - angf2);
				}

				angf2 = blob->getAngleDegrees();
			}
		}

		if(blob->getFiducialId() == 3 || blob->getFiducialId() == 46)
		{
			if(isCursorFuz)
			{
				fid3X = (blob->getPosition().getX() * fw) + (int)ofRandom(-2,4);
				fid3Y = (blob->getPosition().getY() * fh) + (int)ofRandom(-4,8);
			}
			else
			{
				fid3X = blob->getPosition().getX() * fw;
				fid3Y = blob->getPosition().getY() * fh;
			}

			if(abs(blob->getAngleDegrees() - angf3) > 46.2)
			{
				if(rangef3 + (int)(blob->getAngleDegrees() - angf3) > 0)
				{
					rangef3 += (int)(blob->getAngleDegrees() - angf3);
				}
				angf3 = blob->getAngleDegrees();
			}
		}
    }
	
	
	isFrmNew = false;

	
	#ifdef _USE_LIVE_VIDEO
		vidGrabber.grabFrame();
		isFrmNew = vidGrabber.isFrameNew();
	#else
		vidPlayer.isFrameNew();
    #endif

	if(isFrmNew)
	{
		#ifdef _USE_LIVE_VIDEO
            colorImg.setFromPixels(vidGrabber.getPixels(),videoW,videoH);
	    #else
            colorImg.setFromPixels(vidPlayer.getPixels(), 320,240);
        #endif
			
		grayImage = colorImg;

		if (isLearnBG)
		{
			grayBg = grayImage; 
			isLearnBG = false;
		}

	}


	stat  = "status :";
	stat += " / isFrmNew : ";
	stat += isFrmNew ? "true  " : "false ";
	stat += " / isLearnBG : ";
	stat += isLearnBG ? "true  " : "false ";
	stat += " / isModeTuio : ";
	stat += isModeTuio ? "true  " : "false ";
	stat += " / isDrawAll : ";
	stat += isDrawAll ? "true  ": "false ";
	stat += " / isPaintByMouse : ";
	stat += isPaintByMouse ? "true  ": "false ";

	stat2  = "        ";
	stat2 += " / BrushSize : ";
	stat2 += isModeTuio ? ofToString((int)brush.size()) : ofToString((int)mBrush.size());
	stat2 += " / ImageSize : ";
	stat2 += "w : " + ofToString(imageW) + ", ";
	stat2 += "h : " + ofToString(imageH);
	stat2 += " / FPS : " + ofToString(ofGetFrameRate(),2);
	stat2 += " / alpha : " + ofToString(a);

	stat3  = "        ";
	stat3 += " / fid1 : ";
	stat3 += "x : " + ofToString(fid1X) + ", ";
	stat3 += "y : " + ofToString(fid1Y) + ", ";
	stat3 += "range : " + ofToString(rangef1); 
	stat3 += " / fid2 : ";
	stat3 += "x : " + ofToString(fid2X) + ", ";
	stat3 += "y : " + ofToString(fid2Y) + ", ";
	stat3 += "range : " + ofToString(rangef2);
	stat3 += " / fid3 : ";
	stat3 += "x : " + ofToString(fid3X) + ", ";
	stat3 += "y : " + ofToString(fid3Y) + ", ";
	stat3 += "range : " + ofToString(rangef3); 

}

//--------------------------------------------------------------
void testApp::draw()
{
	fps = ofGetFrameRate();

	#ifdef _USE_LIVE_VIDEO
		unsigned char* pix = vidGrabber.getPixels();
	
		imageW = (int)vidGrabber.getWidth();
		imageH = (int)vidGrabber.getHeight();
	#else
		unsigned char* pix = vidPlayer.getPixels();
	
		imageW = (int)vidPlayer.getWidth();
		imageH = (int)vidPlayer.getHeight();
	#endif
	

	t = 0;

	sch1->setPos(fid1X - rangef1,fid1Y - rangef1);
	sch1->setColor(255,0,0);
	sch1->draw();
	
	sch2->setPos(fid2X - rangef2,fid2Y - rangef2);
	sch2->setColor(0,255,0);
	sch2->draw();

	sch3->setPos(fid3X - rangef3,fid3Y - rangef3);
	sch3->setColor(0,0,255);
	sch3->draw();
	
	for(k = 0;k < imageW; k += 3)
	{
		for(j = 0;j < imageH;j += 3)
		{
			r = pix[(j * imageW + k) * 3];
			g = pix[(j * imageW + k) * 3 + 1];
			b = pix[(j * imageW + k) * 3 + 2];

			if(isModeTuio)
			{
				isDrawAll = false;

				isInRangeXf1 = (k + rangeW - rangef1 < fid1X 
								&& fid1X < k + rangeW + rangef1);
				isInRangeYf1 = (j + rangeH - rangef1 < fid1Y 
								&& fid1Y < j + rangeH + rangef1);

				if(isInRangeXf1 && isInRangeYf1)
				{
					drawRectsR(k + rangeW,j + rangeH);
				}

				isInRangeXf2 = (k + rangeW - rangef2 < fid2X 
								&& fid2X < k + rangeW + rangef2);
				isInRangeYf2 = (j + rangeH - rangef2 < fid2Y 
								&& fid2Y < j + rangeH + rangef2);

				if(isInRangeXf2 && isInRangeYf2)
				{
					drawRectsG(k + rangeW,j + rangeH);
				}

				isInRangeXf3 = (k + rangeW - rangef3 < fid3X 
								&& fid3X < k + rangeW + rangef3);
				isInRangeYf3 = (j + rangeH - rangef3 < fid3Y 
								&& fid3Y < j + rangeH + rangef3);

				if(isInRangeXf3 && isInRangeYf3)
				{
					drawRectsB(k + rangeW,j + rangeH);
				}
			}

			if(!isDrawAll)
			{
				/*
				if(++t < mBrush.size())
				{	
					isInRangeX = (k + rangeW - D_RANGE < (int)mBrush[t].x 
								&& (int)mBrush[t].x < k + rangeW + D_RANGE);
					isInRangeY = (j + rangeH - D_RANGE < (int)mBrush[t].y 
								&& (int)mBrush[t].y < j + rangeH + D_RANGE);

					if(isInRangeX && isInRangeY)
					{
						drawRects(k + rangeW,j + rangeH);
						//drawRects((int)mBrush[t].x,(int)mBrush[t].y);
					}
				}
				*/

				//vidGrabber.draw(rangeW,rangeH);
			
			}
			else 
			{
				drawRects(k + rangeW,j + rangeH);
			}

			///*
			if(isPaintByMouse)
			{
				
				isInRangeX = (k + rangeW - D_RANGE < mouseX 
								&& mouseX < k + rangeW + D_RANGE);
				isInRangeY = (j + rangeH - D_RANGE < mouseY 
								&& mouseY < j + rangeH + D_RANGE);

				if(isInRangeX && isInRangeY)
				{
					//drawRects(mouseX,mouseY);
					//drawRects(k + rangeW,j + rangeH);

					if(isDrawRectsR)
					{
						drawRectsR(k + rangeW,j + rangeH);
					}
					if(isDrawRectsG)
					{
						drawRectsG(k + rangeW,j + rangeH);
					}
					if(isDrawRectsB)
					{
						drawRectsB(k + rangeW,j + rangeH);
					}
				}
			}
			//*/

		}
	}

	if(isShowStat)
	{
		ofSetColor(0xffffff);
		ofDrawBitmapString(log,20.0,20.0);
		ofDrawBitmapString(stat,20.0,fh - 44.0);
		ofDrawBitmapString(stat2,20.0,fh - 32.0);
		ofDrawBitmapString(stat3,20.0,fh - 20.0);
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
	switch(key)
	{
	case ' ':
		isLearnBG = !isLearnBG;
		break;

	case 'r':
		isDrawRectsR = !isDrawAll;
		break;

	case 'g':
		isDrawRectsG = !isDrawAll;
		break;

	case 'b':
		isDrawRectsB = !isDrawAll;
		break; 

	case OF_KEY_INSERT:
		isModeTuio = !isModeTuio;
		break;

	case OF_KEY_HOME:
		isDrawAll = !isDrawAll;
		break;

	case OF_KEY_DEL:
		isShowStat = !isShowStat;
		break;

	case OF_KEY_END:
		isCursorFuz = !isCursorFuz;
		break;

	case OF_KEY_BACKSPACE:
		if(!mBrush.empty())
		{
			mBrush.clear();
		}
		break;

	default:
		break;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{
	switch(key)
	{
	case 'r':
		isDrawRectsR = false;
		break;

	case 'g':
		isDrawRectsG = false;
		break;

	case 'b':
		isDrawRectsB = false;
		break; 
	}
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{
	/*
	if(mBrush.size() < BRUSHSIZE)
	{
		isPaintByMouse = false;
		for(k = mouseX - 3;k < mouseX + 3;k++)
		{
			for(j = mouseY - 3;j < mouseY + 3;j++)
			{
				mBrush.push_back(ofPoint(mouseX + k,mouseY + j));
			}
		}
	}
	*/

	
	if(!isDrawAll)
	{
		isPaintByMouse = true;
	}
	//*/
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{
	isPaintByMouse = false;
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{

}


///-------------------------------------------------------------

void testApp::objectAdded(ofxTuioObject& tuioObject)
{
    log  = " new object: ";
	log += ofToString(tuioObject.getFiducialId());
	log += " X: " + ofToString(tuioObject.getX());
	log += " Y: " + ofToString(tuioObject.getY());
	log += " angle: " + ofToString(tuioObject.getAngleDegrees());
}

///-------------------------------------------------------------

void testApp::objectRemoved(ofxTuioObject& tuioObject)
{
    log  = " object removed: ";
	log += ofToString(tuioObject.getFiducialId());
	log += " X: " + ofToString(tuioObject.getX());
	log += " Y: " + ofToString(tuioObject.getY());
	log += " angle: " + ofToString(tuioObject.getAngleDegrees());
}

///-------------------------------------------------------------

void testApp::objectUpdated(ofxTuioObject& tuioObject)
{
    log  = " object updated: ";
	log += ofToString(tuioObject.getFiducialId());
	log += " X: " + ofToString(tuioObject.getX());
	log += " Y: " + ofToString(tuioObject.getY());
	log += " angle: " + ofToString(tuioObject.getAngleDegrees());
}

///-------------------------------------------------------------

void testApp::tuioAdded(ofxTuioCursor& tuioCursor)
{
    log  = " new cursor: ";
	log += ofToString(tuioCursor.getFingerId());
	log += " X: " + ofToString(tuioCursor.getX());
	log += " Y: " + ofToString(tuioCursor.getY());
}

///-------------------------------------------------------------

void testApp::tuioRemoved(ofxTuioCursor& tuioCursor)
{
    log  =  " cursor removed: ";
	log += ofToString(tuioCursor.getFingerId());
	log += " X: " + ofToString(tuioCursor.getX());
	log += " Y: " + ofToString(tuioCursor.getY());
}

///-------------------------------------------------------------

void testApp::tuioUpdated(ofxTuioCursor& tuioCursor)
{
    log =  " cursor updated: ";
	log += ofToString(tuioCursor.getFingerId());
	log += " X: " + ofToString(tuioCursor.getX());
	log += " Y: " + ofToString(tuioCursor.getY());
}


///-------------------------------------------------------------

void testApp::drawRectsR(int k,int j)
{
	ofSetRectMode(OF_RECTMODE_CENTER);
						
	ofSetColor(255,0,0,a);
	rr = 8.0 * r / 255.0;
	ofRect(k,j,rr,rr);

	ofSetRectMode(OF_RECTMODE_CORNER);
}

///-------------------------------------------------------------

void testApp::drawRectsG(int k,int j)
{
	ofSetRectMode(OF_RECTMODE_CENTER);

	ofSetColor(0,255,0,a);
	gr = 8.0 * g / 255.0;
	ofRect(k,j,gr,gr);

	ofSetRectMode(OF_RECTMODE_CORNER);
}

///-------------------------------------------------------------

void testApp::drawRectsB(int k,int j)
{
	ofSetRectMode(OF_RECTMODE_CENTER);

	ofSetColor(0,0,255,a);
	br = 8.0 * b / 255.0;
	ofRect(k,j,br,br);

	ofSetRectMode(OF_RECTMODE_CORNER);
}

///-------------------------------------------------------------

void testApp::drawRects(int k,int j)
{
	ofSetRectMode(OF_RECTMODE_CENTER);
						
	ofSetColor(255,0,0,a);
	rr = 8.0 * r / 255.0;
	ofRect(k,j,rr,rr);

	ofSetColor(0,255,0,a);
	gr = 8.0 * g / 255.0;
	ofRect(k,j,gr,gr);

	ofSetColor(0,0,255,a);
	br = 8.0 * b / 255.0;
	ofRect(k,j,br,br);

	ofSetRectMode(OF_RECTMODE_CORNER);
}