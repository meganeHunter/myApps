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
     
	fsnum = 0;

    log = "";

	fw = ofGetWidth();
	fh = ofGetHeight();

	isFrmNew = false;
	isLearnBG = false;
	isModeTuio = true;
	isDrawAll = true;
	isModeBG = false;
	isShowStat = false;
	isCursorFuz = false;

	a = 255;

	videoW = fw - 120;
	videoH = fh - 120;
	rangeW = 60;
	rangeH = 60;
	drawW = 0;
	drawH = 0;


	#ifdef _USE_LIVE_VIDEO
		vidGrabber = new ofVideoGrabber();
		vidGrabber->setVerbose(true);
		vidGrabber->listDevices();
		vidGrabber->setDeviceID(1);
		vidGrabber->initGrabber(videoW,videoH);
		
		colorImg.allocate(videoW,videoH);
		grayImage.allocate(videoW,videoH);
		grayBg.allocate(videoW,videoH);

	#else
        vidPlayer.loadMovie("fingers.mov");
        vidPlayer.play();
	#endif

	
	font.loadFont("automat.ttf",128,true,false,false);
	font2.loadFont("automat2.ttf",80,true,false,false);

	sch1 = new showChar(&font);
	sch2 = new showChar(&font);
	sch3 = new showChar(&font);

	schS = new showChar(&font2);
	
	sch1->setStr("R");
	sch2->setStr("G");
	sch3->setStr("B");

	schS->setStr("RGB");
	strs = "RGB";
	
	rect = font.getStringBoundingBox("8",fw / 2.0,fh / 2.0);
	rect2 = font2.getStringBoundingBox("358",fw / 2.0,fh / 2.0);

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
			if(f1Dat.size() > FIDTRAKNUM)
			{
				f1Dat.pop_front();
			}
			f1TempD.pos = ofPoint(blob->getPosition().getX() * fw,blob->getPosition().getY() * fh);
			f1TempD.deg = blob->getAngleDegrees();
			f1TempD.num = (int)(blob->getX() * fw) % 9;

			f1Dat.push_back(f1TempD);
		}

		if(blob->getFiducialId() == 2 || blob->getFiducialId() == 35)
		{
			
			if(f2Dat.size() > FIDTRAKNUM)
			{
				f2Dat.pop_front();
			}
			f2TempD.pos = ofPoint(blob->getPosition().getX() * fw,blob->getPosition().getY() * fh);
			f2TempD.deg = blob->getAngleDegrees();
			f2TempD.num = (int)(blob->getY() * fw) % 9;

			f2Dat.push_back(f2TempD);
			
		}

		if(blob->getFiducialId() == 3 || blob->getFiducialId() == 46)
		{
			if(f3Dat.size() > FIDTRAKNUM)
			{
				f3Dat.pop_front();
			}
			f3TempD.pos = ofPoint(blob->getPosition().getX() * fw,blob->getPosition().getY() * fh);
			f3TempD.deg = blob->getAngleDegrees();
			f3TempD.num = (int)((blob->getX() * fw) + (blob->getY() * fh)) % 9;

			f3Dat.push_back(f3TempD);

		}
    }

	if(ABS(f1TempD.pos.x - f2TempD.pos.x) < rect.width)
	{
		if(ABS(f1TempD.pos.y - f2TempD.pos.y) < 12.0)
		{
			if(f1TempD.num > f2TempD.num)
			{
				strs[0] = f1TempD.num + '0';
			}
			else if(f1TempD.num == f2TempD.num)
			{
				strs[0] = f1TempD.num + '0';
				strs[1] = f2TempD.num + '0';
			}
			else
			{
				strs[1] = f2TempD.num + '0';
			}
		}
	}
	else if(ABS(f1TempD.pos.y - f2TempD.pos.y) < rect.height)
	{
		if(ABS(f1TempD.pos.x - f2TempD.pos.x) < 12.0)
		{
			if(f1TempD.num > f2TempD.num)
			{
				strs[0] = f1TempD.num + '0';
			}
			else if(f1TempD.num == f2TempD.num)
			{
				strs[0] = f1TempD.num + '0';
				strs[1] = f2TempD.num + '0';
			}
			else
			{
				strs[1] = f2TempD.num + '0';
			}
		}
	}

	if(ABS(f2TempD.pos.x - f3TempD.pos.x) < rect.width)
	{
		if(ABS(f2TempD.pos.y - f3TempD.pos.y) < 12.0)
		{
			if(f2TempD.num > f3TempD.num)
			{
				strs[1] = f2TempD.num + '0';
			}
			else if(f2TempD.num == f3TempD.num)
			{
				strs[1] = f2TempD.num + '0';
				strs[2] = f3TempD.num + '0';
			}
			else
			{
				strs[2] = f3TempD.num + '0';
			}
		}
	}
	else if(ABS(f2TempD.pos.y - f3TempD.pos.y) < rect.height)
	{
		if(ABS(f2TempD.pos.x - f3TempD.pos.x) < 12.0)
		{
			if(f2TempD.num > f3TempD.num)
			{
				strs[1] = f2TempD.num + '0';
			}
			else if(f2TempD.num == f3TempD.num)
			{
				strs[1] = f2TempD.num + '0';
				strs[2] = f3TempD.num + '0';
			}
			else
			{
				strs[2] = f3TempD.num + '0';
			}
		}
	}

	if(ABS(f3TempD.pos.x - f1TempD.pos.x) < rect.width)
	{
		if(ABS(f3TempD.pos.y - f1TempD.pos.y) < 12.0)
		{
			if(f3TempD.num > f1TempD.num)
			{
				strs[2] = f3TempD.num + '0';
			}
			else if(f3TempD.num == f1TempD.num)
			{
				strs[2] = f3TempD.num + '0';
				strs[0] = f1TempD.num + '0';
			}
			else
			{
				strs[0] = f1TempD.num + '0';
			}
		}
	}
	else if(ABS(f3TempD.pos.y - f1TempD.pos.y) < rect.height)
	{
		if(ABS(f3TempD.pos.x - f1TempD.pos.x) < 12.0)
		{
			if(f3TempD.num > f1TempD.num)
			{
				strs[2] = f3TempD.num + '0';
			}
			else if(f3TempD.num == f1TempD.num)
			{
				strs[2] = f3TempD.num + '0';
				strs[0] = f1TempD.num + '0';
			}
			else
			{
				strs[0] = f1TempD.num + '0';
			}
		}
	}
	
	
	isFrmNew = false;

	
	#ifdef _USE_LIVE_VIDEO
		vidGrabber->grabFrame();
		isFrmNew = vidGrabber->isFrameNew();
	#else
		vidPlayer.isFrameNew();
    #endif


    if(isFrmNew)
    {
		#ifdef _USE_LIVE_VIDEO
			colorImg.setFromPixels(vidGrabber->getPixels(),videoW,videoH);
			grayImage = colorImg;

			if(isLearnBG)
			{
				grayBg = grayImage; 
				isLearnBG = false;
			}
		#else
			colorImg.setFromPixels(vidPlayer.getPixels(), 320,240);
		#endif
		
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
	stat += " / isModeBG : ";
	stat += isModeBG ? "true  ": "false ";

	stat2  = "        ";
	stat2 += " / ImageSize : ";
	stat2 += "w : " + ofToString(imageW) + ", ";
	stat2 += "h : " + ofToString(imageH);
	stat2 += " / FPS : " + ofToString(ofGetFrameRate(),2);
	stat2 += " / alpha : " + ofToString(a);
	stat2 += " / strs : " + strs;

	stat3  = "        ";

	stat4  = "        ";

	switch(fsnum)
	{
	case 1:
		stat3 += " / sch1 : ";
		stat3 += "x : " + ofToString(sch1->getPos().x,2) + ", ";
		stat3 += "y : " + ofToString(sch1->getPos().y,2) + ", ";
		stat3 += "deg : " + ofToString(sch1->getDeg(),2) + ", ";
		stat3 += "num : " + sch1->getStr() + "/ ";

		stat4 += " / fid1 : ";
		stat4 += "x : ";
		stat4 += f1Dat.empty() ? "-, " : ofToString(f1Dat.back().pos.x,0) + ", ";
		stat4 += "y : ";
		stat4 += f1Dat.empty() ? "-, " : ofToString(f1Dat.back().pos.y,0) + ", ";
		stat4 += "deg : ";
		stat4 += f1Dat.empty() ? "-, " : ofToString(f1Dat.back().deg,2) + ", ";
		stat4 += "num : ";
		stat4 += f1Dat.empty() ? "-, " : ofToString(f1Dat.back().num) + ", "; 
		break;

	case 2:
		stat3 += " / sch2 : ";
		stat3 += "x : " + ofToString(sch2->getPos().x,2) + ", ";
		stat3 += "y : " + ofToString(sch2->getPos().y,2) + ", ";
		stat3 += "deg : " + ofToString(sch2->getDeg(),2) + ", ";
		stat3 += "num : " + sch2->getStr() + "/ ";

		stat4 += " / fid2 : ";
		stat4 += "x : ";
		stat4 += f2Dat.empty() ? "-, " : ofToString(f2Dat.back().pos.x,0) + ", ";
		stat4 += "y : ";
		stat4 += f2Dat.empty() ? "-, " : ofToString(f2Dat.back().pos.y,0) + ", ";
		stat4 += "deg : ";
		stat4 += f2Dat.empty() ? "-, " : ofToString(f2Dat.back().deg,2) + ", ";
		stat4 += "num : ";
		stat4 += f2Dat.empty() ? "-, " : ofToString(f2Dat.back().num) + ", "; 
		break;
	
	case 3:
		stat3 += " / sch3 : ";
		stat3 += "x : " + ofToString(sch3->getPos().x,2) + ", ";
		stat3 += "y : " + ofToString(sch3->getPos().y,2) + ", ";
		stat3 += "deg : " + ofToString(sch3->getDeg(),2) + ", ";
		stat3 += "num : " + sch3->getStr() + "/ ";

		stat4 += " / fid3 : ";
		stat4 += "x : ";
		stat4 += f3Dat.empty() ? "-, " : ofToString(f3Dat.back().pos.x,0) + ", ";
		stat4 += "y : ";
		stat4 += f3Dat.empty() ? "-, " : ofToString(f3Dat.back().pos.y,0) + ", ";
		stat4 += "deg : ";
		stat4 += f3Dat.empty() ? "-, " : ofToString(f3Dat.back().deg,2) + ", ";
		stat4 += "num : ";
		stat4 += f3Dat.empty() ? "-, " : ofToString(f3Dat.back().num) + ", "; 
		break;

	default:
		stat3 += "PLEASE INPUT";
		stat4 += "NUMBER(1 OR 2 OR 3)";
		break;
	}
	
}

//--------------------------------------------------------------
void testApp::draw()
{
	fps = ofGetFrameRate();
	ofSetColor(255,255,255);

	#ifdef _USE_LIVE_VIDEO
		//unsigned char* pix = vidGrabber->getPixels();
		//vidGrabber->draw(rangeW,rangeH);
		colorImg.draw(rangeW,rangeH);
	
		imageW = (int)vidGrabber->getWidth();
		imageH = (int)vidGrabber->getHeight();
	#else
		unsigned char* pix = vidPlayer.getPixels();
	
		imageW = (int)vidPlayer.getWidth();
		imageH = (int)vidPlayer.getHeight();
	#endif

	
	//for(k = 0;k < imageW; k += 3)
	//{
	//	for(j = 0;j < imageH;j += 3)
	//	{
	//		//r = pix[(j * imageW + k) * 3];
	//		//g = pix[(j * imageW + k) * 3 + 1];
	//		//b = pix[(j * imageW + k) * 3 + 2];

	//		
	//		if(isDrawAll)
	//		{
	//			/*drawW = k + rangeW;
	//			drawH = j + rangeH;
	//			drawRects(drawW,drawH);*/
	//			//drawRects(k + rangeW,j + rangeH);
	//		}

	//	}
	//}
	
	if(!f1Dat.empty())
	{
		drawTrakR(f1Dat,0);
	}
	if(!f2Dat.empty())
	{
		drawTrakG(f2Dat,0);
	}
	if(!f3Dat.empty())
	{
		drawTrakB(f3Dat,0);
	}

	schS->setStr(strs);
	schS->setColor(255,255,0);
	schS->setPos(fw - rangeW - rect2.width,fh - rangeH - rect2.height);
	schS->draw();

	if(isShowStat)
	{
		ofSetColor(0xffffff);
		ofDrawBitmapString(log,20.0,20.0);
		ofDrawBitmapString(stat,20.0,fh - 44.0);
		ofDrawBitmapString(stat2,20.0,fh - 32.0);
		ofDrawBitmapString(stat3,20.0,fh - 20.0);
		ofDrawBitmapString(stat4,20.0,fh - 8.0);
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
		isDrawRectsR = true;
		break;

	case 'g':
		isDrawRectsG = true;
		break;

	case 'b':
		isDrawRectsB = true;
		break; 

	case '1':
		fsnum = 1;
		break;

	case '2':
		fsnum = 2;
		break;

	case '3':
		fsnum = 3;
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
		isModeBG = !isModeBG;
		break;

	case OF_KEY_BACKSPACE:
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

void testApp::drawRects(int& k,int& j)
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

///-------------------------------------------------------------

void testApp::drawTrakR(deque<fidData>& dat,int al)
{
	alp = al;

	for(k = 0;k < dat.size();k++)
	{
		alp = (alp > 255) ? 255 : alp + 8;
		alp = (k == dat.size() - 1) ? 255 : alp;

		sch1->setPos(dat[k].pos);
		sch1->setDeg(dat[k].deg);
		sch1->setInt(dat[k].num);
		sch1->setColor(255,0,0,alp);
		sch1->draw(true);
	}
}

///-------------------------------------------------------------

void testApp::drawTrakG(deque<fidData>& dat,int al)
{
	alp = al;

	for(k = 0;k < dat.size();k++)
	{
		alp = (alp > 255) ? 255 : alp + 8;
		alp = (k == dat.size() - 1) ? 255 : alp;

		sch2->setPos(dat[k].pos);
		sch2->setDeg(dat[k].deg);
		sch2->setInt(dat[k].num);
		sch2->setColor(0,255,0,alp);
		sch2->draw();
	}
}

///-------------------------------------------------------------

void testApp::drawTrakB(deque<fidData>& dat,int al)
{
	alp = al;

	for(k = 0;k < dat.size();k++)
	{
		alp = (alp > 255) ? 255 : alp + 8;
		alp = (k == dat.size() - 1) ? 255 : alp;

		sch3->setPos(dat[k].pos);
		sch3->setDeg(dat[k].deg);
		sch3->setInt(dat[k].num);
		sch3->setColor(0,0,255,alp);
		sch3->draw();
	}
}

///-------------------------------------------------------------

void testApp::drawTrakR(deque<fidData*>& dat,int al)
{
	alp = al;

	for(k = 0;k < dat.size();k++)
	{
		alp = (alp > 255) ? 255 : alp + 8;
		alp = (k == dat.size() - 1) ? 255 : alp;

		sch1->setPos(dat[k]->pos);
		sch1->setDeg(dat[k]->deg);
		sch1->setInt(dat[k]->num);
		sch1->setColor(255,0,0,alp);
		sch1->draw();
	}
}

///-------------------------------------------------------------

void testApp::drawTrakG(deque<fidData*>& dat,int al)
{
	alp = al;

	for(k = 0;k < dat.size();k++)
	{
		alp = (alp > 255) ? 255 : alp + 8;
		alp = (k == dat.size() - 1) ? 255 : alp;

		sch2->setPos(dat[k]->pos);
		sch2->setDeg(dat[k]->deg);
		sch2->setInt(dat[k]->num);
		sch2->setColor(0,255,0,alp);
		sch2->draw();
	}
}

///-------------------------------------------------------------

void testApp::drawTrakB(deque<fidData*>& dat,int al)
{
	alp = al;

	for(k = 0;k < dat.size();k++)
	{
		alp = (alp > 255) ? 255 : alp + 8;
		alp = (k == dat.size() - 1) ? 255 : alp;

		sch3->setPos(dat[k]->pos);
		sch3->setDeg(dat[k]->deg);
		sch3->setInt(dat[k]->num);
		sch3->setColor(0,0,255,alp);
		sch3->draw();
	}
}