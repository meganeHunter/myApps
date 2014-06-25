#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	ofBackground(255,255,255);
	
	fw = ofGetWidth();
	fh = ofGetHeight();
	
	a = 0;

	vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(fw,fh);

	colorImg.allocate(fw,fh);
	grayImage.allocate(fw,fh );
	grayBg.allocate(fw,fh);
	grayDiff.allocate(fw,fh);

	isLearnBG = true;
	isConpDraw = false;

	threshold = 80;

}

//--------------------------------------------------------------
void testApp::update()
{
	isFrmNew = false;

	vidGrabber.grabFrame();
	isFrmNew = vidGrabber.isFrameNew();

	if (isFrmNew)
	{
		colorImg.setFromPixels(vidGrabber.getPixels(),fw,fh);

        grayImage = colorImg;


		if (isLearnBG)
		{
			grayBg = grayImage; 
			isLearnBG = false;
		}

		grayDiff.absDiff(grayBg, grayImage);
		grayDiff.threshold(threshold);

		contourFinder.findContours(grayDiff, 20, (fw * fh) / 3, 10, true);
	}


}

//--------------------------------------------------------------
void testApp::draw()
{
	ofSetColor(255,255,255);
	colorImg.draw(0,0);

	ofFill();
	ofSetColor(255,255,255,a);
	ofRect(0,0,fw,fh);

	fps = ofGetFrameRate();

	unsigned char* pix = vidGrabber.getPixels();


	if(isConpDraw)
	{
		for(k=0;k<contourFinder.nBlobs;k++)
		{
			for(j=0;j<contourFinder.blobs[k].nPts;j++)
			{
				conp = contourFinder.blobs[k].pts[j];

				/*
				r = pix[((int)conp.x + (int)conp.y) * 3];
				g = pix[((int)conp.x + (int)conp.y) * 3 + 1];
				b = pix[((int)conp.x + (int)conp.y) * 3 + 2];

				ofSetColor(255,0,0,100);
				ofCircle(conp.x,conp.y,(float)r / 255.0);
				ofSetColor(0,255,0,100);
				ofCircle(conp.x,conp.y,(float)g / 255.0);
				ofSetColor(0,0,255,100);
				ofCircle(conp.x,conp.y ,(float)b / 255.0);
				*/

				ofSetColor(0,0,0,255);
				ofCircle(conp.x,conp.y,(float)pix[(int)conp.x + (int)conp.y * 3] / 255.0);

			}	
		}
	}

	stat  = "status : ";
	stat += " / FPS : " + ofToString(fps,2) + " ";
	stat += " / threshold : " + ofToString(threshold) + " ";
	stat += " / alpha : " + ofToString(a);
	stat += " / isFrmNew : ";
	stat += isFrmNew ? "true " : "false ";
	stat += " / isLearnBG : ";
	stat += isLearnBG ? "true " : "false ";
	stat += " / isConpDraw : ";
	stat += isConpDraw ? "true " : "false ";

	ofSetColor(0,0,0);
	ofDrawBitmapString(stat,20.0,fh - 20.0);

	ofSetColor(255,255,255);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
	switch (key)
	{

	case ' ':
		isLearnBG = true;
		break;

	case '+':
		(threshold > 255) ? threshold = 255 : threshold++;
		break;

	case '-':
		(threshold < 0) ? threshold = 0 : threshold--;
		break;

	case OF_KEY_UP:
		(255 < a) ? a = 255 : a++;
		break;

	case OF_KEY_DOWN:
		(a < 0) ? a = 0 : a--;
		break;

	case OF_KEY_HOME:
		(a == 255) ? a = 0 : a = 255;

	case OF_KEY_INSERT:
		isConpDraw = !isConpDraw;
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

