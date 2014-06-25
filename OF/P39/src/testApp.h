#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxOpenCv.h"

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


		///-----------------------------------------------------

		int threshold;
		int fw,fh;
		int a;
		int k,j;

		float fps;

		bool isLearnBG;
		bool isFrmNew;
		bool isConpDraw;

		unsigned char r,g,b;

		string stat;

		ofPoint conp;

		

		ofVideoGrabber vidGrabber;

        ofxCvColorImage colorImg;

        ofxCvGrayscaleImage grayImage;
		ofxCvGrayscaleImage grayBg;
		ofxCvGrayscaleImage grayDiff;

        ofxCvContourFinder contourFinder;

		

};

#endif
