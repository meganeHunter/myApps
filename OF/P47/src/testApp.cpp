#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	ofSetFrameRate(60);
    
    ofBackground(0,0,0);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE);


	for(k = 0; k < 3; k++)
	{
		tempb.col.r = 255;
		tempb.col.g = 255;
		tempb.col.b = 255;
		tempb.col.a = 255;

		tempb.isShow = false;
		tempb.pos = ofPoint(0.0,0.0);
		tempb.var = 1000;

		bro.push_back(tempb);
	}

	for(j = 0; j < 10; j++)
	{
		gnum.push_back((int)ofRandom(0,10));
	}

	disp = 0;
	mode = 0;

	p = 0;
	ans = 10;

	fw = ofGetWidth();
	fh = ofGetHeight();

	ofAddListener(tuio.objectAdded,this,&testApp::objectAdded);
    ofAddListener(tuio.objectRemoved,this,&testApp::objectRemoved);
    ofAddListener(tuio.objectUpdated,this,&testApp::objectUpdated);
    ofAddListener(tuio.cursorAdded,this,&testApp::tuioAdded);
    ofAddListener(tuio.cursorRemoved,this,&testApp::tuioRemoved);
    ofAddListener(tuio.cursorUpdated,this,&testApp::tuioUpdated);
	
    tuio.start(3333);

    log = "";

	rans = (int)ofRandom(3,817);
}

//--------------------------------------------------------------
void testApp::update()
{
	rs = rans % 4;

	tuio.getMessage();

	
    objectList = tuio.getTuioObjects();
   
    
    for(tobj = objectList.begin();tobj != objectList.end();tobj++) 
	{
        
        blob = (*tobj);

		t = blob->getFiducialId();
		if(mode == 0 && disp == 1)
		{
			
		}

		

		isRotate = blob->getRotationSpeed() > 0.0;

		switch(disp)
		{
		case 0: //disp 0
			switch(mode)
			{
			case 0:
				if(blob->getRotationSpeed() > 0.0)
				{
					mode = 1;
				}
				break;

			case 1:
				if(blob->getMotionSpeed() > 3.0)
				{
					disp = 1;
					mode = 0;
				}

				break;

			case 2:
				if(blob->getRotationSpeed() > 0.0)
				{
					mode = 1;
				}
				break;

			default:
				break;
			}

			break;

		case 1: //disp 1
			switch(mode)
			{
			case 0:
				if(blob->getRotationSpeed() > 0.0)
				{
					if(t / 10 == 3 && t < 100)
					{
						if(t == 1 && bro.size() > 1)
						{
							bro[t].isShow = false;
							sign = t % 4;
						}
						else if(bro[t % 3].var == 1000)
						{
							bro[t % 3].var = gnum[t];
						}
					}
				}
				break;

			case 1:
				mode = 2;
				break;

			case 2:
				aMain.setIsDrawEQ(true);
				disp = 2;
				mode = 0;
				break;
			}

			break;

		case 2: //disp 2
			if(aMain.getIsTimeOver())
			{
				disp = 0;
				mode = 0;
				ans = 10;

				for(k = 0; k < bro.size(); k++)
				{
					bro[k].var = 1000;
				}
			}
			else
			{
				if((int)blob->getRotationSpeed() > 3 && ans != 9)
				{
					ans++;
				}
				else if((int)blob->getRotationSpeed() < -3 && ans != 0)
				{
					ans--;
				}
			}
			break;

		default:
			break;
		}
    }
	
	aMain.setBroN(bro);
	aMain.setDisp(disp);
	aMain.setMode(mode);
	aMain.setSignType(sign);
	aMain.setAns(ans);

	aMain.update();

	stat  = " bro.size: " + ofToString((int)bro.size()) + " /";
	stat += " gnum.size: " + ofToString((int)gnum.size()) + " /";
	stat += " tempb.pos: x: " + ofToString(tempb.pos.x,2) + " y: " + ofToString(tempb.pos.y,2) + " /";
	stat += " framenum: " + ofToString(ofGetFrameNum()) + " /";
	stat += " framerate: " + ofToString(ofGetFrameRate(),2) + " /"; 

	stat2  = " disp: " + ofToString(aMain.getDisp()) + ", " + ofToString(disp) + " /";
	stat2 += " mode: " + ofToString(aMain.getMode()) + ", " + ofToString(mode) + " /";
	stat2 += " rotate: " + isRotate ? " true /" : " false /" ;
	
}

//--------------------------------------------------------------
void testApp::draw()
{
	aMain.draw();

	ofSetColor(0xffffff);
	ofDrawBitmapString(log,20.0,20.0);
	ofDrawBitmapString(stat,20.0,fh - 20.0);
	ofDrawBitmapString(stat2,20.0,fh - 30.0);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
	switch(key)
	{
	case OF_KEY_INSERT:
		
		break;

	default:
		break;
	}
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
