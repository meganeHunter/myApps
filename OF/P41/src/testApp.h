#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxTuio.h"
#include "ShowChar.h"

#define HUMAN true
#define COMP false

#define BRUSHSIZE 4800
#define D_RANGE 48

#define _USE_LIVE_VIDEO


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


		///---------------------------------------------

		void objectAdded(ofxTuioObject& tuioObject);
		
		void objectRemoved(ofxTuioObject& tuioObject);
		
		void objectUpdated(ofxTuioObject& tuioObject);
 
		
		void tuioAdded(ofxTuioCursor& tuioCursor);
		
		void tuioRemoved(ofxTuioCursor& tuioCursor);
		
		void tuioUpdated(ofxTuioCursor& tuioCursor);

		
		///--------------------------------------------

		void drawRectsR(int k,int j);
		void drawRectsG(int k,int j);
		void drawRectsB(int k,int j);

		void drawRects(int k,int j);

     
	private:
		
		int threshold;
		int fw,fh;
		int a;
		int k,j,t;
		int imageW,imageH;
		int videoW,videoH;
		int rangeW,rangeH;
		int rr,gr,br;
		int fid1X,fid1Y;
		int fid2X,fid2Y;
		int fid3X,fid3Y;
		int rangef1,rangef2,rangef3;

		float fps;
		float angf1,angf2,angf3;

		unsigned char r,g,b;

		bool isFrmNew;
		bool isLearnBG;
		bool isModeTuio;
		bool isDrawAll;
		bool isPaintByMouse;
		bool isInRangeX,isInRangeY;
		bool isInRangeXf1,isInRangeYf1;
		bool isInRangeXf2,isInRangeYf2;
		bool isInRangeXf3,isInRangeYf3;
		bool isDrawRectsR,isDrawRectsG,isDrawRectsB;
		bool isShowStat;
		bool isCursorFuz;

		
		string log;
		string stat,stat2,stat3;

		
		myTuioClient tuio;
		
		list<ofxTuioObject*> objectList;
		
		list<ofxTuioObject*>::iterator tobj;
		
		ofxTuioObject* blob;
		
		vector<ofxTuioPoint> brush;

		vector<ofPoint> mBrush;

		#ifdef _USE_LIVE_VIDEO
		  ofVideoGrabber vidGrabber;
		#else
		  ofVideoPlayer vidPlayer;
		#endif

        ofxCvColorImage colorImg;

        ofxCvGrayscaleImage grayImage;
		ofxCvGrayscaleImage grayBg;

		ofTrueTypeFont font;
		
		showChar* sch1,* sch2,* sch3;

};

#endif
