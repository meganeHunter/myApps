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
		vector <showChar * >::iterator it;

		float fw,fh;
		int j,k;
		int rc,gc,bc;
		bool rcdi,gcdi,bcdi;
		int alp;
		float fRate;
		float dist;

		string pChar;
		unsigned char pC2;

		ofPoint cPos,fPos;
		ofPoint posp;
		ofPoint sPos,vPos;
		ofPoint tsPos,tvPos;
		ofPoint sG;

		string stat;

};

#endif
