#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ShowChar.h"
#include "point2Smoke.h"


class testApp : public ofBaseApp{

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

		int j,k,i;
		
		int pdifx,pdify;
		int r,g,b;

		float fw,fh;
		float fps;
		float pdif;

		char ch;

		bool isContFDraw,isContPDraw,isSmokeDraw;

		ofPoint pmax,pmin;
		ofPoint contp;
		ofPoint smokeDir;
		
		ofColor sCol;

		string stat;

		vector<ofPoint> contourF;
		vector<ofPoint> contourP;
		vector<ofPoint> smokeSp;

		ofTrueTypeFont font;

		showChar* sch;

		point2Smoke smoke;

};

#endif
