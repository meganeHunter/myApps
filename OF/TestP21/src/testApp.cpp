#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	
	ofSetWindowPosition(0,0);
	ofBackground(0,0,0);
	ofSetFrameRate(60.0);

	fw = ofGetWidth();
	fh = ofGetHeight();
	fPos = ofPoint(fw / 15,fh / 15);

	sPos = ofPoint(0,0);
	fsPos = ofPoint(0,0);
	fcPos = ofPoint(0,0); 
	sG = ofPoint(0.0,0.8);
	sBBs = ofPoint(0,0);
	
	dif = 0;
	fcNum = 0;
	
	rPos = fPos + ofPoint(fw - 248,58);
	
	font.loadFont("automat.ttf",48); // +++
	font2.loadFont("automat.ttf",24);
	font3.loadFont("Cosmic Girl.ttf",24);
		
	isSTReady = false;
	isST2Ready = false;
	
	isDifOver = false;
	isDifUnder = false;
	isDifU2 = false;
	
	stat = " ";
	stat2 = " ";
	
}

//--------------------------------------------------------------
void testApp::update()
{
	fRate = ofGetFrameRate();
	
	stat  = " Frame: ";
	stat += "w:" + ofToString(fw,0) + " ";
	stat += "h:" + ofToString(fh,0) + " / mousePos: ";
	stat += "x:" + ofToString(mouseX,0) + " ";
	stat += "y:" + ofToString(mouseY,0);
	stat += " / sPos:";
	stat += "x:" + ofToString(sPos.x,0) + " ";
	stat += "y:" + ofToString(sPos.y,0);
	stat += " / dif:" + ofToString(dif,0);
	stat += " / VscSize: " + ofToString(vsc.size(),0);
	stat += " / pChar: " + pChar;
	stat += " / sBBs: ";
	stat += "w: " + ofToString(sBBs.x,0) + " ";
	stat += "h: " + ofToString(sBBs.y,0);
 	
	stat2 = " FrmRate: " + ofToString(fRate,0);
	stat2 += " / FontLoaded: ";
	stat2 += (font.bLoadedOk) ? "y" : "n";
	stat2 += " / Font2Loaded: ";
	stat2 += (font2.bLoadedOk) ? "y" : "n";
	stat2 += " / fsPos:";
	stat2 += "x:" + ofToString(fsPos.x,0) + " ";
	stat2 += "y:" + ofToString(fsPos.y,0);		
	stat2 += " / STReady: ";
	stat2 += (isSTReady) ? "y" : "n";
	stat2 += " / ST2Ready: ";
	stat2 += (isST2Ready) ? "y" : "n";
	stat2 += " / DifUnder: ";
	stat2 += (isDifUnder) ? "y" : "n";


	for(k = 0; k < vsc.size(); k++)
	{
		sPos = vsc[k]->getPos();
		sBBs = vsc[k]->getSBBsize();
			
		if(k > 0)
		{
			fsPos = vsc[k-1]->getPos();
						
			dif = fsPos.y - sPos.y;
			
			
			/*
			if((dif < 56) && (fsPos.y > 67))
			{
				if((sPos.y - 58) > rPos.y)
				{
					vsc[k]->setPos(sPos - ofPoint(0,58));
					sPos = vsc[k]->getPos();
					isDifOver = true;
				}
			}
			else
			{
				isDifOver = false;
			}
			*/
		}
		
		if(vPos.size() > 0)
		{
			for(j = 0; j < (k - 1); j++)
			{
				vPos[j] = vsc[j]->getPos(); 
				
				isDifU2 = (vPos[j].y - rPos.y) < 85;				
			}
			
			if(isDifU2)
			{
				vsc[k]->setPos(rPos);
			}
			
			if(sPos.y < (rPos.y + 248))
			{
				vsc[k]->setPos(sPos + sG);
			}
			else
			{
				vsc[k]->setPos(rPos);
			}
			
		}
	}
	
}
//--------------------------------------------------------------
void testApp::draw()
{
	
	for(k = 0; k < vsc.size(); k++)
	{
		sdPos = vsc[k]->getPos();
		
		vsc[k]->draw();
		ofDrawBitmapString(vNum[k],sdPos.x + 48,sdPos.y + 24);
	}
	
	if(isSTReady)
	{
		sT->draw();
	}
	if(isST2Ready)
	{
		sT2->draw();
	}
	
	
	ofSetColor(255,255,255);	
	ofDrawBitmapString(stat,12.0,fh - 68.0);
	ofDrawBitmapString(stat2,12.0,fh - 58.0);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
	pC2 = key;
	pChar = pC2; 
	
	if(key == OF_KEY_HOME)
	{
		showChar * scTest = new showChar(&font2);
				
		scTest->setPos((fw / 2) - 24,(fh / 2) - 48);
		scTest->setStr("TEST");
		scTest->setColor(255,255,255,255);		
		
		sT = scTest;
		
		isSTReady = true;
	}
	else if(key == OF_KEY_END)
	{
		showChar * scT2 = new showChar(&font3);
		
		scT2->setPos((fw / 2) - 24,(fh / 2) + 48);
		scT2->setStr("TE2T");
		scT2->setColor(255,255,255,255);		
		
		sT2 = scT2;
		
		isST2Ready = true;
	}
	else if(key == OF_KEY_UP)
	{
		isSTReady = false;
	}
	else if(key == OF_KEY_DOWN)
	{
		isST2Ready = false;
	}
	else if(vsc.size() < 12)
	{
		if(vsc.size() > 1)
		{
			fcNum = vsc.size() - 2;
			//fcPos = vsc[fcNum]->getPos();
		
			if(vPos.size() > 1)
			{				
				for(l = 0; l < vPos.size(); l++)
				{
					isDifUnder = (vPos[l].y - rPos.y) < 124;
				}
			}
			
			if(!isDifUnder)
			{
				showChar * sck = new showChar(&font); // +++
				sck->setPos(rPos);
				sck->setStr(pChar);
				sck->setColor(255,255,255,255);
				//sck->setFont("Cosmic Girl.ttf",12);
				vsc.push_back(sck);
				vNum.push_back(ofToString(fcNum + 3,0));
				vPos.push_back(rPos);
			}
			
		}
		else
		{
			fcNum = vsc.size();
			
			showChar * sck = new showChar(&font); // +++
			sck->setPos(rPos);
			sck->setStr(pChar);
			sck->setColor(255,255,255,255);
			//sck->setFont("Cosmic Girl.ttf",12);
			vsc.push_back(sck);
			vNum.push_back(ofToString(fcNum + 1,0));
			vPos.push_back(rPos);
		}
		
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

//--------------------------------------------------------------
void testApp::exit()
{
	
}