#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxTUIO.h"
#include "ofxOpenCv.h"
#include "ofxOSC.h"


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

	
	private:
		int fw,fh;
		int a,alp;
		int k,j,p;
		int t;

		bool isRotate;

		string log;
		string stat,stat2;

		myTuioClient tuio;
		
		list<ofxTuioObject*> objectList;
		list<ofxTuioObject*>::iterator tobj;
		
		ofxTuioObject* blob;


};

#endif
