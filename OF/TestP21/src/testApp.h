#ifndef _TEST_APP
#define _TEST_APP

#include <string>
#include "ofMain.h"
#include "ShowChar.h"

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
		void exit();
		
		vector <showChar * > vsc;
		
		showChar * sT;
		showChar * sT2;
		
		float fw,fh;
		float fRate;
		
		int j,k,l;
		int alp;
		int dif;
		int fcNum;
				
		bool isSTReady,isST2Ready;
		bool isDifOver,isDifUnder,isDifU2;

		string pChar;
		unsigned char pC2;

		ofPoint cPos,fPos;
		ofPoint rPos;
		ofPoint sPos,fsPos,fcPos,sdPos;
		ofPoint sG;
		ofPoint sBBs;

		vector <ofPoint> vPos;
		
		string stat,stat2;
		
		vector <string> vNum;
	
		ofTrueTypeFont font; // +++
		ofTrueTypeFont font2;
		ofTrueTypeFont font3;
};

#endif
