#ifndef _TEST_APP
#define _TEST_APP

/*	
GL_SRC_COLOR	
GL_ONE_MINUS_SRC_COLOR
GL_SRC_ALPHA
GL_ONE_MINUS_SRC_ALPHA	
GL_DST_ALPHA
GL_ONE_MINUS_DST_ALPHA			
GL_DST_COLOR	
GL_ONE_MINUS_DST_COLOR	
GL_SRC_ALPHA_SATURATE	
*/

#include "ofMain.h"
#include "smokeParticle.h"

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

		int i,k,j;
		int sMode,dMode;
		
		float fw,fh;
		float fps;
		float rarg;
		float rchange;
		float penm;

		bool isGLModeT;
		bool isDec;

		string stat;

		vector<sPart> sPar;

};

#endif
