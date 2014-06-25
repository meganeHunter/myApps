#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxControlPanel.h"

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

		float fw,fh;
		float panelW,panelH;

		float rSize;
		ofPoint rPos,rrPos;
		ofPoint rSpeed;
		ofPoint rsMin,rsMax;
		int r,g,b;

		float r2Size;
		ofPoint r2Pos,rr2Pos;
		ofPoint r2Speed;
		int r2,g2,b2;

		ofxControlPanel gui;
		simpleColor bgC,txtC;

		ofTrueTypeFont font;
		ofPoint fPos;

};

#endif
