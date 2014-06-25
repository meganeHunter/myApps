#ifndef _TEST_APP
#define _TEST_APP

#include <string>
#include "ofMain.h"
#include "ShowChar.h"
#include "Str2Colors.h"

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

		void drawRectR(const ofRectangle* rect);
		void exit();
		
///--------------------------------------------------
		
		float fw,fh;
		float fRate;
		float dist,distX,distY;
		//float avoidX;

		int k,j,csnum;
		int rc,gc,bc;
		int alp;
		
		bool rcdi,gcdi,bcdi;
		bool colIns;
		

		string pChar;
		unsigned char pC2;
		string colStr;

		ofPoint fPos;
		ofPoint sPos,vPos;
		ofPoint sG;
		ofPoint cSize;
		ofPoint linr;

		string stat,stat2;
		
		vector <showChar * > vsc;
		vector <showChar * >::iterator it;

	
		ofTrueTypeFont font; // +++
		ofTrueTypeFont fontC;

		str2c s2c;

};

#endif
