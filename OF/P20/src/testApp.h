#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"

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

		ofPoint pos;
		ofPoint speed;
		float width;
		float height;

		ofPoint pos2;
		ofPoint speed2;
		float phase;
		ofPoint cPos;
		float dim;
		bool swc;
		int swc2;

};

#endif
