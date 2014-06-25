#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	ofBackground(0,0,0);
	ofSetFrameRate(60);

	fw = ofGetWidth();
	fh = ofGetHeight();

	isContFDraw = false;
	isContPDraw = false;
	isSmokeDraw = false;

	ofSeedRandom();
	r = (int)ofRandom(124.0,255.0);
	g = (r * r) % 255;
	b = (g * g * g) % 255;


	font.loadFont("impact.ttf",64,true,false,true);
	sch = new showChar(&font);
	sch->setChar('A');
	
	sCol.r = r;
	sCol.g = g;
	sCol.b = b;
	
	
}

//--------------------------------------------------------------
void testApp::update()
{
	fps = ofGetFrameRate();

	smokeDir = ofPoint(mouseX,mouseY);

	if(isSmokeDraw)
	{
		smoke.update(smokeDir);
	}
}

//--------------------------------------------------------------
void testApp::draw()
{
	sch->setPos(fw / 2.0,fh / 2.0);
	sch->setColor(r,g,b);
	
	sch->draw();

	if(isContFDraw)
	{
		ofSetColor(248,12,99);
		//contourF = new vector<ofPoint>(&sch->getContour(0));

		
		/*
		for(j=0;j<(int)contourF.size();j++)
		{
			ofVertex(contourF[j].x,contourF[j].y);
		}
		*/
		
		for(k=0;k<(int)font.getCharacterAsPoints(sch->getChar()).contours.size();k++)
		{
			contourF = font.getCharacterAsPoints(sch->getChar()).contours[k].pts;
			ofBeginShape();

			for(j=0;j<(int)contourF.size();j++)
			{
				ofFill();
				ofCircle(contourF[j].x + (fw / 2.0),contourF[j].y + (fh / 2.0),2.8);

				contp = ofPoint(contourF[j].x + (fw / 2.0),contourF[j].y + (fh / 2.0));
				if((int)contourP.size() < 1201)
				{
					contourP.push_back(contp);
				}
				
				if(j > 1)
				{
					
					pdifx = (int)contourF[j].x - (int)contourF[j-1].x;
					if(abs(pdifx) < 2)
					{
						pmax.y = max(contourF[j].y,contourF[j-1].y);
						pmin.y = min(contourF[j].y,contourF[j-1].y);
						for(i=(int)pmin.y;i<=(int)pmax.y;i++)
						{
							ofCircle(contourF[j].x + (fw / 2.0),i + (fh / 2.0),2.8);

							contp = ofPoint(contourF[j].x + (fw / 2.0),i + (fh / 2.0));
							if((int)contourP.size() < 1201)
							{
								contourP.push_back(contp);
							}
						}
					}

					pdify = (int)contourF[j].y - (int)contourF[j-1].y;
					if(abs(pdify) < 2)
					{
						pmax.x = max(contourF[j].x,contourF[j-1].x);
						pmin.x = min(contourF[j].x,contourF[j-1].x);
						for(i=(int)pmin.x;i<=(int)pmax.x;i++)
						{
							ofCircle(i + (fw / 2.0),contourF[j].y + (fh / 2.0),2.8);

							contp = ofPoint(i + (fw / 2.0),contourF[j].y + (fh / 2.0));
							if((int)contourP.size() < 1201)
							{
								contourP.push_back(contp);
							}
						}
					}

					/*
					pdif = ofDist(contourF[j].x,contourF[j].y,contourF[j-1].x,contourF[j-1].y);
					if(8 < pdif && pdif < 100)
					{

						
						pdifx = contourF[j].x - contourF[j-1].x;
						pdify = contourF[j].y - contourF[j-1].y;

						for(i=(int)contourF[j-1].x;i<=(int)contourF[j].x;i++)
						{
							ofCircle(i + (fw / 2.0),i + (fh / 2.0),2.8);

							contp = ofPoint(i + (fw / 2.0),i + (fh / 2.0));
							contourP.push_back(contp);
						}
						
						

					}
					*/

				}

				ofNoFill();
				ofVertex(contourF[j].x + (fw / 2.0),contourF[j].y + (fh / 2.0));
			}

			ofEndShape(true);
		}


		if(isContPDraw)
		{
			ofSetColor(124,238,248);
			for(k=0;k<(int)contourP.size();k++)
			{
				ofFill();
				ofCircle(contourP[k].x + 168.0,contourP[k].y + 168.0,2.4);

				if((k < 12) && ((int)smokeSp.size() < 801))
				{
					smokeSp.push_back(contourP[k]);
				}

			}
		}
		else if(!contourP.empty())
		{
			contourP.clear();
		}
		

		//ofCircle(sch->getContour(0)[0].x,sch->getContour(0)[0].y,12.3);
		
		//for(j=0;j<(int)sch->getContour(0).size();j++)
		//{
			//ofVertex(sch->getContour(0)[j].x,sch->getContour(0)[j].y);
		//}
		

		if(isSmokeDraw)
		{
			smoke.init(smokeSp,sCol);
			smoke.draw();
		}

	}


	stat  = "fps : " + ofToString(fps,2) + " / ";
	stat += "color : ";
	stat += "r : " + ofToString(r,0) + " ";
	stat += "g : " + ofToString(g,0) + " ";
	stat += "b : " + ofToString(b,0) + " / ";
	stat += "size of smokeSp :" + ofToString((double)smokeSp.size(),0) + " / ";
	stat += "size of contourP :" + ofToString((double)contourP.size(),0) + " ";


	ofSetColor(255,255,255);
	ofDrawBitmapString(stat,20.0,fh - 20.0);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
	switch(key)
	{
	case OF_KEY_INSERT:
		isContFDraw = !isContFDraw;
		break;

	case OF_KEY_HOME:
		isContPDraw = !isContPDraw;
		break;

	case OF_KEY_END:
		isSmokeDraw = !isSmokeDraw;
		break;

	default:
		if(key != ' ')
		{
			if(!contourP.empty())
			{
				contourP.clear();
				
			}

			isSmokeDraw = false;

			if(!smokeSp.empty())
			{
				smokeSp.clear();
			}

			for(k=0;k<(int)contourP.size();k++)
			{
				if((k < 12) && ((int)smokeSp.size() < 801))
				{
					smokeSp.push_back(contourP[k]);
				}

			}

			ch = key;
			sch->setChar(ch);
		}
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

