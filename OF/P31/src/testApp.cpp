#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	ofBackground(255,255,255);
	ofSetFrameRate(60.0);

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

			for(j=0;j<vsc.size();j++)
			{
				vPos = vsc[j]->getPos();

				dist = ofDist(sPos.x,sPos.y,vPos.x,vPos.y);
				if(dist < 14.0 && j != k)
				{
					sPos.x += 14.0 * ((sPos.x - vPos.x)/(unsigned)(sPos.x - vPos.x));
					vPos.x -= 14.0 * ((sPos.x - vPos.x)/(unsigned)(sPos.x - vPos.x));
					vsc[k]->setPos(sPos);
					vsc[j]->setPos(vPos);
				}
			}

			vsc[k]->setColor(rc,gc,bc,alp-(int)(sPos.y/5.0));
		}
		else
		{
			for(j=0;j<vsc.size();j++)
			{
				vPos = vsc[j]->getPos();
				tsPos = sPos;
				tvPos = vPos;

				dist = ofDist(sPos.x,sPos.y,vPos.x,vPos.y);
				if(dist < 14.0 && j != k)
				{
					sPos = tsPos;
					vPos = tvPos;
					vsc[k]->setPos(sPos);
					vsc[j]->setPos(vPos);
				}
			}
		}
	}
	
}

//--------------------------------------------------------------
void testApp::draw()
{
	fRate = ofGetFrameRate();
	
	
	for(k=0;k<vsc.size();k++)
	{
		vsc[k]->draw();
	}
	
	stat  = " Frame: ";
	stat += "w:" + ofToString(fw,2) + " ";
	stat += "h:" + ofToString(fh,2) + " / mousePos: ";
	stat += "x:" + ofToString(mouseX,2) + " ";
	stat += "y:" + ofToString(mouseY,2) ;
	stat += " / VscSize: " + ofToString(vsc.size(),2) + " / Color: ";
	stat += "r:" + ofToString(rc,2) + " ";
	stat += "g:" + ofToString(gc,2) + " ";
	stat += "b:" + ofToString(bc,2) + " ";
	stat += "a:" + ofToString(alp,2) + " / ";
	stat += "FrameRate:" + ofToString(fRate,2);

	ofSetColor(38,38,12);	
	ofDrawBitmapString(stat,8.0,fh - 8.0);
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
	
	if(key == OF_KEY_BACKSPACE)
	{
		/*it = vsc.begin();
		while(vsc.empty())
		{
			it++;
		}
		if(it != vsc.end())
		{
			it = vsc.erase(it);
		}*/

		if(!vsc.empty())
		{
			vsc.pop_back();
		}
	}
	else if(key != ' ')
	{
		pC2 = key;
		pChar = pC2; 

		showChar * sck = new showChar;
		sck->setPos(mouseX,mouseY);
		sck->setStr(pChar);
		sck->setColor(rc,gc,bc);
		sck->setFont("Cosmic Girl.ttf",12);
		vsc.push_back(sck);
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

void testApp::exit()
{
	
}