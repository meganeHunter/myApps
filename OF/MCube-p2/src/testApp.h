#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "MCubeP.h"
#include "showChar.h"

class testApp : public ofBaseApp
{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		
	private:
		MCubeP MQP;
		//ofTrueTypeFont ttf1,ttf2;
		//showChar* sC1;
		
		int k,j;
		int curs;
		int xcurs,ycurs;
		int fw,fh;
		int xyCellsSize;
		int point;
		int lineP;
		int qmo;
		int gmo;
		
		bool isCursInc;
		bool isCursDec;
					
		string stat;
		
		ofPoint img1p,img2p,img3p,img4p,img5p;
		ofPoint img6p;
		
		ofPoint img1s,img2s,img3s,img4s,img5s;
		ofPoint img6s;

};

#endif
