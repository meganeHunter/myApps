#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	ofBackground(0,0,0);
	
	ofSetWindowTitle("RECTSTACKTEST");
	ofSetWindowShape(1250,800);
	ofSetFrameRate(60.0);

	fw = ofGetWidth();
	fh = ofGetHeight();
	fPos.x = (14 * fw) / 15;
	fPos.y = (14 * fh) / 15;

	sG = ofPoint(0.0,1.8);

	rc = 0;
	rcdi = true;
	gc = 60;
	gcdi = true;
	bc = 255;

	alp = 255;

	fillRect = true;
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


	fRate = ofGetFrameRate();

	

	for(k=0;k<mRect.size();k++)
	{
		sPos = *mRect[k]->getPos();
		sRectW = mRect[k]->rectW;
		sRectH = mRect[k]->rectH;
		if(sPos.y< fPos.y - sRectH && mRect[k]->rectMov)
		{
			sPos += sG;

			bHeight = 0.0;
			for(j=(int)sPos.x;j<(int)sPos.x + (int)sRectW;j++)
			{
				bHeight += bottom[j];
			}
			if(sPos.y + sRectH > fh - bHeight)
			{
				sPos.y = fh - (bHeight + sRectH);
				mRect[k]->rectMov = false;
			}

		}
		else
		{
			mRect[k]->rectMov = false;
			if(0.0 < sPos.x && sPos.x < fw)
			{
				if(sPos.x + sRectW > 0.0)
				{
					bottom[(int)sPos.x + (int)sRectW] += sRectH;
				}
			}
		}



		/*
		for(j=0;j<mRect.size();j++)
		{
			
			vPos = *mRect[j]->getPos();
			vRectW = &mRect[j]->rectW;
			vRectH = &mRect[j]->rectH;


			distX = (sPos.x > vPos.x) ? (sPos.x - vPos.x) : (vPos.x - sPos.x);
			distY = (sPos.y - vPos.y);

			sWidth = (*sRectW < *vRectW) ? sRectW : vRectW;

			if(k != j && mRect[k]->rectMov)
			{
				

				if(distX < *sWidth)
				{
	
					if(-1.0 * (*sRectH) < distY && distY < 0.0)
					{
						sPos.y= vPos.y - *sRectH;
						mRect[k]->rectMov = mRect[j]->rectMov;
					}
				}
				
			}
			
			mRect[j]->setPos(&vPos);
		}
		*/

		
		mRect[k]->setPos(&sPos);
	}

}

//--------------------------------------------------------------
void testApp::draw()
{
	fillRect ? ofFill() : ofNoFill();

	for(k=0;k<mRect.size();k++)
	{
		mRect[k]->setColor(rc,gc,bc);
		mRect[k]->draw();
	}

	if(!mRect.empty())
	{
		ofSetColor(255,255,255);
		ofLine(mRect[mRect.size() - 1]->getPosX(),mRect[mRect.size() - 1]->getPosY(),mouseX,mouseY);
	}

	stat  = " Frame: ";
	stat += "w:" + ofToString(fw,2) + " ";
	stat += "h:" + ofToString(fh,2);
	stat += " / mousePos: ";
	stat += "x:" + ofToString(mouseX,2) + " ";
	stat += "y:" + ofToString(mouseY,2);
	stat += " / fPos: ";
	stat += "x:" + ofToString(fPos.x,2) + " ";
	stat += "y:" + ofToString(fPos.y,2);
	stat += " / VecSize: ";
	stat += ofToString(mRect.size(),2);
	stat += " / Color: ";
	stat += "r:" + ofToString(rc,2) + " ";
	stat += "g:" + ofToString(gc,2) + " ";
	stat += "b:" + ofToString(bc,2);
	stat += " / FrameRate:";
	stat += ofToString(fRate,2);

	if(!mRect.empty())
	{
		stat2  = " sRectSize: ";
		stat2 += "w: " + ofToString(sRectW,2) + " ";
		stat2 += "h: " + ofToString(sRectH,2) + " / ";
		stat2 += "distX: " + ofToString(distX,2) + " ";
		stat2 += "distY: " + ofToString(distY,2) + " / ";
		stat2 += "vPos: ";
		stat2 += "x: " + ofToString(vPos.x,2) + " ";
		stat2 += "y: " + ofToString(vPos.y,2) + " / ";
		stat2 += "sPos:";
		stat2 += "x: " + ofToString(sPos.x,2) + " ";
		stat2 += "y: " + ofToString(sPos.y,2) + " ";
	}
	else
	{
		stat2 = " Test Started";
	}


	ofSetColor(38,138,12);	
	ofDrawBitmapString(stat,8.0,fh - 8.0);
	ofDrawBitmapString(stat2,8.0,fh - 20.0);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
	if(key == OF_KEY_BACKSPACE && !mRect.empty()) 
	{
		mRect.pop_back();
	}
	if(key == OF_KEY_INSERT)
	{
		fillRect = !fillRect;
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
	randW = ofRandom(5.8,24.8);
	randH = ofRandom(5.8,24.8);

	ofRectangle paramrect(x,y,randW,randH);
	pRect * mr = new pRect(&paramrect);
	mr->setPos(x,y);
	mr->setColor(rc,gc,bc);
	mr->rectW = randW;
	mr->rectH = randH;
	mRect.push_back(mr);

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{

}

