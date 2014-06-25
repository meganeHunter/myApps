#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	ofSetWindowPosition(0,0);
	ofBackground(181,79,74);
	
	fw = ofGetWidth();
	fh = ofGetHeight();
	
	stat = " ";
	stat2 = " ";
	
	img1.loadImage("cube1.jpg");
	img1Size.x = img1.getWidth();
	img1Size.y = img1.getHeight();
	img1Pos.x = 50;
	img1Pos.y = 50;
	
	img2.loadImage("cRoll.jpg");
	img2Size.x = img2.getWidth();
	img2Size.y = img2.getHeight();
	img2Pos.x = img1Pos.x + img1Size.x + 50;
	img2Pos.y = img1Pos.y;
	
	img3.loadImage("nSelecta.jpg");
	img3Size.x = img3.getWidth();
	img3Size.y = img3.getHeight();
	img3Pos.x = img2Pos.x + img2Size.x + 50;
	img3Pos.y = img2Pos.y;
	
	imz1.img.loadImage("cube1-1.jpg");
	imz1.size.x = imz1.img.getWidth();
	imz1.size.y = imz1.img.getHeight();
	imz1.pos.x = 50;
	imz1.pos.y = img1Pos.y + img1Size.y + 50;

	setImgz(imz2,"cRoll-2.jpg");
	imz2.pos.x = imz1.pos.x + imz1.size.x + 50;
	imz2.pos.y = imz1.pos.y;
	
	imz3 = setImgz2("nSelecta2.jpg");
	imz3.pos = ofPoint(imz2.pos.x + imz2.pos.x + 50,imz1.pos.y);

}

//--------------------------------------------------------------
void testApp::update()
{
	stat  = "frameSize: ";
	stat += ofToString(fw,0) + "," + ofToString(fh,0) + " /";
	stat += "img1Pos: ";
	stat += ofToString(img1Pos.x,0) + ","+ ofToString(img1Pos.y,0) + " /";
	stat += "img2Pos: ";
	stat += ofToString(img2Pos.x,0) + "," + ofToString(img2Pos.y,0) + " /";
	stat += "img3Pos: ";
	stat += ofToString(img3Pos.x,0) + "," + ofToString(img3Pos.y,0) + " /";
	
	stat2  = "imz1Pos: ";
	stat2 += ofToString(imz1.pos.x,0) + "," + ofToString(imz1.pos.y,0) + " /";
	stat2 += "imz2Pos: ";
	stat2 += ofToString(imz2.pos.x,0) + "," + ofToString(imz2.pos.y,0) + " /";
	stat2 += "imz3Pos: ";
	stat2 += ofToString(imz3.pos.x,0) + "," + ofToString(imz3.pos.y,0) + " /"; 
}

//--------------------------------------------------------------
void testApp::draw()
{
	img1.draw(img1Pos.x,img1Pos.y);
	
	ofSetColor(181,79,74);
	img2.draw(img2Pos.x,img2Pos.y);
	
	ofSetColor(255,255,255);
	img3.draw(img3Pos.x,img3Pos.y);
	
	ofSetColor(181,79,74);
	imz1.img.draw(imz1.pos.x,imz1.pos.y);
	
	ofSetColor(181,79,74);
	drawImgz(imz2);
	drawImgz(imz3);

	ofSetColor(255,255,255,255);
	ofDrawBitmapString(stat,20,fh - 50);
	ofDrawBitmapString(stat2,20,fh - 85);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{

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

