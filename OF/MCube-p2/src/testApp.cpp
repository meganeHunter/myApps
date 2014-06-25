#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	
	ofSetWindowPosition(0,0);
	
	k = 0;
	j = 0;
	
	lineP = 0;
	
	qmo = 0;
	gmo = 0;
	
	fw = ofGetWidth();
	fh = ofGetHeight();
	
	//ofBackground(181,79,74);
	//ttf1.loadFont("Futura.dfont",24);
	
	MQP.setup();
		
	}

//--------------------------------------------------------------
void testApp::update()
{
	MQP.setMode(qmo);
	MQP.setGMode(gmo);
	
	if(gmo == 0)
	{
		if(qmo == 0 || qmo == 35)
		{
			img1p = MQP.getImgPos(1);
			img2p = MQP.getImgPos(2);
			
			img1s = MQP.getImgSize(1);
			img2s = MQP.getImgSize(2);
			
			lineP = MQP.getLinePos();
		}
		
		MQP.setImgPos(img1p,1);
		MQP.setImgSize(img1s,1);
		
		MQP.setImgPos(img2p,2);
		MQP.setImgSize(img2s,2);

	}
	else if(gmo == 1)
	{
		if(qmo == 0 || qmo == 35)
		{
			img3p = MQP.getImgPos(3);
			img3s = MQP.getImgSize(3);
			
			img4p = MQP.getImgPos(4);
			img4s = MQP.getImgSize(4);
			
			img5p = MQP.getImgPos(5);
			img5s = MQP.getImgSize(5);
					
			//lineP = MQP.getLinePos();
		}
		
		MQP.setImgPos(img3p,3);
		MQP.setImgSize(img3s,3);
		
		MQP.setImgPos(img4p,4);
		MQP.setImgSize(img4s,4);
		
		MQP.setImgPos(img5p,5);
		MQP.setImgSize(img5s,5);
		
	}
		
	MQP.setLinePos(lineP);
	MQP.update();
	
	stat  = "/";
	if(gmo == 0)
	{
		stat += "img1Pos: ";
		stat += ofToString(img1p.x,0) + ", " + ofToString(img1p.y,0) + "/ ";
		stat += "img1Size: ";
		stat += ofToString(img1s.x,0) + ", " + ofToString(img1s.y,0) + "/ ";
		stat += "img2Pos: ";
		stat += ofToString(img2p.x,0) + ", " + ofToString(img2p.y,0) + "/ ";
		stat += "img2Size: ";
		stat += ofToString(img2s.x,0) + ", " + ofToString(img2s.y,0) + "/ ";		
	}
	else if(gmo == 1)
	{
		stat += "img3Pos: ";
		stat += ofToString(img3p.x,0) + ", " + ofToString(img3p.y,0) + "/ ";
		stat += "img3Size: ";
		stat += ofToString(img3s.x,0) + ", " + ofToString(img3s.y,0) + "/ ";
		stat += "img4Pos: ";
		stat += ofToString(img4p.x,0) + ", " + ofToString(img4p.y,0) + "/ ";
		stat += "img4Size: ";
		stat += ofToString(img4s.x,0) + ", " + ofToString(img4s.y,0) + "/ ";
		stat += "img5Pos: ";
		stat += ofToString(img5p.x,0) + ", " + ofToString(img5p.y,0) + "/ ";
		stat += "img5Size: ";
		stat += ofToString(img5s.x,0) + ", " + ofToString(img5s.y,0) + "/ ";
	}
	stat += "linePos: ";
	stat += ofToString(lineP) + "/ ";
	stat += "gMode: "; 
	stat += ofToString(gmo) + "/ ";
	stat += "qMode: ";
	stat += ofToString(qmo) + "/ ";
	stat += " ";
	
}

//--------------------------------------------------------------
void testApp::draw()
{	
	ofPushStyle();
	
	MQP.draw();
	
	if(qmo != 35)
	{
		ofSetColor(255,255,255,255);
		ofDrawBitmapString(stat,20,fh - 60);
	}
	
	ofPopStyle();
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
	switch(key)
	{
	case OF_KEY_UP:
		if(gmo == 0)
		{
			if(qmo == 1)
			{
				img1p.y--;
			}
			else if(qmo == 2)
			{
				img2p.y--;
			}
			else if(qmo == 3)
			{
				img1s.y++;
			}
			else if(qmo == 4)
			{
				img2s.y++;
			}		
			else if(qmo == 5)
			{
				lineP--;
			}
			
		}
		else if(gmo == 1)
		{
			if(qmo == 1)
			{
				img3p.y--;
			}
			else if(qmo == 2)
			{
				img4p.y--;
			}
			else if(qmo == 3)
			{
				img3s.y++;
			}
			else if(qmo == 4)
			{
				img4s.y++;
			}		
			else if(qmo == 5)
			{
				img5p.y--;
			}
			
		}
		break;
		
	case OF_KEY_RIGHT:
		if(gmo == 0)
		{
			if(qmo == 1)
			{
				img1p.x++;
			}
			else if(qmo == 2)
			{
				img2p.x++;
			}
			else if(qmo == 3)
			{
				img1s.x--;
			}
			else if(qmo == 4)
			{
				img2s.x--;
			}		
			
		}
		else if(gmo == 1)
		{
			if(qmo == 1)
			{
				img3p.x++;
			}
			else if(qmo == 2)
			{
				img4p.x++;
			}
			else if(qmo == 3)
			{
				img3s.x--;
			}
			else if(qmo == 4)
			{
				img4s.x--;
			}
			else if(qmo == 5)
			{
				img5p.x++;
			}
			
		}
		break;

	case OF_KEY_LEFT:
		if(gmo == 0)
		{
			if(qmo == 1)
			{
				img1p.x--;
			}
			else if(qmo == 2)
			{
				img2p.x--;
			}
			else if(qmo == 3)
			{
				img1s.x++;
			}
			else if(qmo == 4)
			{
				img2s.x++;
			}
			
		}
		else if(gmo == 1)
		{
			if(qmo == 1)
			{
				img3p.x--;
			}
			else if(qmo == 2)
			{
				img4p.x--;
			}
			else if(qmo == 3)
			{
				img3s.x++;
			}
			else if(qmo == 4)
			{
				img4s.x++;
			}
			else if(qmo == 5)
			{
				img5p.x--;
			}
		}
		
		break;
		
	case OF_KEY_DOWN:
		if(gmo == 0)
		{
			if(qmo == 1)
			{
				img1p.y++;
			}
			else if(qmo == 2)
			{
				img2p.y++;
			}
			else if(qmo == 3)
			{
				img1s.y--;
			}
			else if(qmo == 4)
			{
				img2s.y--;
			}
			else if(qmo == 5)
			{
				lineP++;
			}
			
		}
		else if(gmo == 1)
		{
			if(qmo == 1)
			{
				img3p.y++;
			}
			else if(qmo == 2)
			{
				img4p.y++;
			}
			else if(qmo == 3)
			{
				img3s.y--;
			}
			else if(qmo == 4)
			{
				img4s.y--;
			}
			else if(qmo == 5)
			{
				img5p.y++;
			}
			
		}
		break;
		
	case OF_KEY_F1:
		qmo = 1; 
		
		break;
						
	case OF_KEY_F2:
		qmo = 2;
		
		break;
		
	case OF_KEY_F3:
		qmo = 3;
		
		break;
		
	case OF_KEY_F4:
		qmo = 4;
		
		break;
		
	case OF_KEY_F5:
		qmo = 5;
		
		break;
		
	case OF_KEY_HOME:
		qmo = 35;
		
		break;
		
	case OF_KEY_END:
		qmo = 0;
		
		break;
		
	case 'o':
		gmo++;
		
		break;
		
	case 'p':
		gmo--;
		
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

