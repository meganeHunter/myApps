#ifndef _TEST_APP
#define _TEST_APP

#include <string>
#include "ofMain.h"
#include "ShowChar.h"
#include "ReadTxt.h"

#define RN 101
#define CN 124
#define cM 255

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

		showChar sC;
		readTxt rT;

		float fx,fy;
		int i,j;
		int rc,gc,bc;
		bool rcdi,gcdi,bcdi;
		float fRate;

		ofRectangle cRect;
		ofPoint cPos,fPos;
		ofPoint posp;
		ofPoint SBBSize;

		string stat,curStr;

};

#endif
