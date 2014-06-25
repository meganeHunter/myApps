#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	ofBackground(255,255,255);

	ofSetWindowTitle("INTRCHARTEST");
	ofSetWindowShape(1250,800);
	ofSetFrameRate(60.0);

	fw = ofGetWidth();
	fh = ofGetHeight();
	fPos.x = (14 * fw) / 15;
	fPos.y = (14 * fh) / 15;

	//avoidX = 0.0;

	sG = ofPoint(0.0,0.8);

	rc = 240;
	rcdi = true;
	gc = 60;
	gcdi = true;
	bc = 0;
	bcdi = true;

	alp = 255;

	colIns = false;

	//csnum = 0;
	colStr.clear();

	
	font.loadFont("automat.ttf", 16); // +++
	fontC.loadFont("impact.ttf",48);
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

		if(vsc[k]->charMov)
		{
			sPos = vsc[k]->getPos();
			cSize.x = font.stringWidth(vsc[k]->getStr());
			cSize.y = font.stringHeight(vsc[k]->getStr());
	//(vsc[k]->getSBBsize().x <= 0.0 || vsc[k]->getSBBsize().y <= 0.0) ? ofPoint(17.1,17.4) : vsc[k]->getSBBsize();

	
			if(sPos.y < fPos.y - cSize.y) //&& vsc[k]->charMov)
			{
				sPos += sG;
			}
			else
			{
				vsc[k]->charMov = false;
			}
	
	
			for(j=0;j<vsc.size();j++)
			{
				if(k != j) //&& vsc[k]->charMov)
				{
					vPos = vsc[j]->getPos();
			
					distX = (sPos.x > vPos.x) ? (sPos.x - vPos.x) : (vPos.x - sPos.x);
					distY = sPos.y - vPos.y;
				

					if(distX < 18.0)
					{
						//avoidX = cSize.x * ((sPos.x - vPos.x)/(unsigned)(sPos.x - vPos.x));

						//if(-4.0 * cSize.y < distY && distY < 4.0 * cSize.y)
						//{
							//strcpy(&colStr[csnum++],vsc[k]->getStr().c_str());
							//colStr += vsc[k]->getStr();

							if(-1.0 * cSize.y < distY && distY < cSize.y)
							{
								//sPos.x = vPos.x - cSize.x;
								sPos.y = vPos.y - cSize.y;
								vsc[k]->charMov = vsc[j]->charMov;
							}
						//}
					}
					else
					{
						//csnum = 0;
						//colStr = " ";
					}
					
				}

				vsc[j]->setPos(vPos);
			}
		
			vsc[k]->setPos(sPos);
		}
	}


	/*
	for(k=0;k<vsc.size();k++)
	{
		sPos = vsc[k]->getPos();

		for(j=0;j<vsc.size();j++)
		{
			vPos = vsc[j]->getPos();

			dist = ofDist(sPos.x,sPos.y,vPos.x,vPos.y);

			if(sPos.y < fh - fPos.y && vsc[k]->getAct())
			{
				vsc[k]->setPos(sPos + sG);
				vsc[k]->setColor(rc,gc,bc,alp-(int)(sPos.y/5.0));
			
	
				if(dist < 14.0 && j != k)
				{
					sPos.x += 14.0 * ((sPos.x - vPos.x)/(unsigned)(sPos.x - vPos.x));
					vPos.x -= 14.0 * ((sPos.x - vPos.x)/(unsigned)(sPos.x - vPos.x));
					vsc[k]->setPos(sPos);
					vsc[j]->setPos(vPos);
				}
			}
			else if(vPos.y > fh - fPos.y)
			{
				
				vsc[j]->setAct(false);
				
				psPos = sPos;
				pvPos = vPos;

				distX = (unsigned float)(sPos.x - vPos.x);

				if(dist < 14.0 && j != k)
				{
					if(sPos.y < vPos.y && distX < 14.0)
					{
						sPos = pvPos - ofPoint(0.0,4.0);
						
					}
					else
					{
						sPos = psPos;
					}

					vPos = pvPos;
					vsc[k]->setPos(sPos);
					vsc[j]->setPos(vPos);

				}
			}
		}
	}
	*/

	
}

//--------------------------------------------------------------
void testApp::draw()
{
	fRate = ofGetFrameRate();
	
	if(colIns)
	{
		s2c.draw();
	}
	else
	{
		for(k=0;k<vsc.size();k++)
		{
			vsc[k]->setColor(rc,gc,bc,alp);
			vsc[k]->draw();
		}
	}
	
	stat  = "FrameSize: ";
	stat += "w:" + ofToString(fw,2) + " ";
	stat += "h:" + ofToString(fh,2);
	stat += " / FrameRate:" + ofToString(fRate,2);
	stat += " / mousePos: ";
	stat += "x:" + ofToString(mouseX,2) + " ";
	stat += "y:" + ofToString(mouseY,2) ;
	stat += " / VscSize: ";
	stat += ofToString(vsc.size(),0);
	stat +=  " / Color: ";
	stat += "r:" + ofToString(rc,0) + " ";
	stat += "g:" + ofToString(gc,0) + " ";
	stat += "b:" + ofToString(bc,0) + " / ";
	stat += "key: " + ofToString(pC2,0) + " / ";
	stat += "colStr: " + colStr + " ";

	if(!vsc.empty())
	{
		if(!colIns)
		{
			ofSetColor(38,38,48);
			linr = vsc[(int)vsc.size() - 1]->getPos();
			ofLine(linr.x,linr.y - 12.8,mouseX,mouseY);
			dist = ofDist(linr.x,linr.y,mouseX,mouseY);
			drawRectR(&ofRectangle(linr.x,linr.y - 12.8,cSize.x,cSize.y));	
			//&vsc[(int)vsc.size() - 1]->getStrBBox());

		}

		/*
		if(ofDist(linr.x,linr.y - 12.8,mouseX,mouseY) < 5.8)
		{
			colStr += vsc[(int)vsc.size() - 1]->getStr();

		}
		else
		{
			colStr = " ";
		}
		*/


		stat2  = "cSize: ";
		stat2 += "w: " + ofToString(cSize.x,2) + " ";
		stat2 += "h: " + ofToString(cSize.y,2) + " / ";
		stat2 += "this->font: ";
		stat2 += "width: "  + ofToString(font.stringWidth("x"),2)  + " ";
		stat2 += "height: " + ofToString(font.stringHeight("x"),2) + " / ";
		stat2 += "distX: " + ofToString(distX,2) + " ";
		stat2 += "distY: " + ofToString(distY,2) + " / ";
		stat2 += "fPos: ";
		stat2 += "x: " + ofToString(fPos.x,2) + " ";
		stat2 += "y: " + ofToString(fPos.y,2) + " / ";
		stat2 += "sPos:";
		stat2 += "x: " + ofToString(sPos.x,2) + " ";
		stat2 += "y: " + ofToString(sPos.y,2) + " / ";
	}
	else
	{
		stat2 = "Test Started";
	}

	ofSetColor(38,38,12);	
	ofDrawBitmapString(stat,8.0,fh - 8.0);
	ofDrawBitmapString(stat2,8.0,fh - 20.0);
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
	
	if(key == OF_KEY_BACKSPACE)
	{
		/*
		it = vsc.begin();
	
		if(it != vsc.end())
		{
			it = vsc.erase(it);
		}
		*/
		if(!colStr.empty())
		{
			colStr.erase(colStr.begin());
		}

		if(!vsc.empty())
		{
			vsc.pop_back();
		}

	}
	else if(key == OF_KEY_DEL)
	{
		if(!colStr.empty())
		{
			colStr.clear();
		}
	}
	else if(key == OF_KEY_RETURN)
	{
		s2c.setStr(colStr);
		s2c.setup(&fontC);
		colIns = true;
	}
	else if(key != ' ')
	{
		if((int)vsc.size() > 499)
		{
			it = vsc.begin();
	
			if(it != vsc.end())
			{
				it = vsc.erase(it);
			}
		}

		pC2 = key;
		pChar = pC2; 
	
		showChar * sck = new showChar(&font); // +++
		sck->setPos(mouseX,mouseY);
		sck->setStr(pChar);
		sck->setColor(rc,gc,bc);
		// sck->setFont("Cosmic Girl.ttf",12);

		//cSize = sck->getSBBsize();
		vsc.push_back(sck);

		linr = vsc[(int)vsc.size() - 1]->getPos();
		
		if(-108.0 < dist && dist < 108.0)
		{
			colStr += pChar;
		}
		else if(colStr.empty())
		{
			colStr = pChar;
		}

		colIns = false;
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
void testApp::drawRectR(const ofRectangle* rect)
{
	ofNoFill();
	ofRect(rect->x,rect->y,rect->width,rect->height);
}
///-------------------------------------------------------------
void testApp::exit()
{
	
}