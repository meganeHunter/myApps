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
#define FIDTRAKNUM 12

#define _USE_LIVE_VIDEO

struct fidData
{
	ofPoint pos;
	float deg;
	int num;
};


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

		void drawRects(int& k,int& j);
		void drawRects(int k,int j);


		///--------------------------------------------

		void drawTrakR(deque<fidData>& dat,int al);
		void drawTrakG(deque<fidData>& dat,int al);
		void drawTrakB(deque<fidData>& dat,int al);

		void drawTrakR(deque<fidData*>& dat,int al);
		void drawTrakG(deque<fidData*>& dat,int al);
		void drawTrakB(deque<fidData*>& dat,int al);


     
	private:
		int threshold;
		int fw,fh;
		int a,alp;
		int k,j,t;
		int imageW,imageH;
		int videoW,videoH;
		int rangeW,rangeH;
		int drawW,drawH;
		int rr,gr,br;
		int fid1X,fid1Y;
		int fid2X,fid2Y;
		int fid3X,fid3Y;
		int rangef1,rangef2,rangef3;
		int f1Tcount,f2Tcount,f3Tcount;
		int fsnum;

		float fps;
		
		unsigned char r,g,b;

		bool isFrmNew;
		bool isLearnBG;
		bool isModeTuio;
		bool isDrawAll;
		bool isPaintByMouse;
		bool isModeBG;
		bool isDrawRectsR,isDrawRectsG,isDrawRectsB;
		bool isShowStat;
		bool isCursorFuz;

		string log;
		string stat,stat2,stat3,stat4;

		string strs;

		ofRectangle rect,rect2;

		fidData f1TempD, f2TempD, f3TempD;

		deque<fidData> f1Dat,f2Dat,f3Dat;
		

		myTuioClient tuio;
		
		list<ofxTuioObject*> objectList;
		
		list<ofxTuioObject*>::iterator tobj;
		
		ofxTuioObject* blob;

		#ifdef _USE_LIVE_VIDEO
		  ofVideoGrabber* vidGrabber;
		  ofxCvColorImage colorImg;

          ofxCvGrayscaleImage grayImage;
		  ofxCvGrayscaleImage grayBg;
		#else
		  ofVideoPlayer vidPlayer;
		#endif

		ofTrueTypeFont font,font2;
		
		showChar* sch1,* sch2,* sch3;
		showChar* schS;

};

#endif
