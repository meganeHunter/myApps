//--------------------------------------------------------------

#ifndef _TEST_APP
#define _TEST_APP

//--------------------------------------------------------------

#define OF_ADDON_USING_OFXDIRLIST
#define OF_ADDON_USING_OFXVECTORMATH
#define OF_ADDON_USING_OFXXMLSETTINGS

#include "ofMain.h"
#include "ofAddons.h"

#include "ofxGui.h"
#include "ofxGuiTypes.h"

#define pBorder OFXGUI_PANEL_BORDER			//10
#define pSpacing OFXGUI_PANEL_SPACING		//10

#define buttonH OFXGUI_BUTTON_HEIGHT		//10
#define filesH OFXGUI_FILES_HEIGHT			//15
#define sliderH OFXGUI_SLIDER_HEIGHT		//10
#define colorH OFXGUI_COLOR_HEIGHT			//30
#define matrixS OFXGUI_MATRIX_SPACING		// 6


//--------------------------------------------------------------

const string dummy_Tags[] =
{
	"off",
	"vertical",
	"horizontal"
};

//--------------------------------------------------------------

class testApp : public ofSimpleApp, public ofxGuiListener	
{
	enum
	{
		kParameter_Panel,

		kParameter_Speed,
		kParameter_Move,
		kParameter_Size,
		kParameter_Color,
		kParameter_File,
		kParameter_SaveXml

	};

public:
		
	void		setup();
	void		update();
	void		draw();
	
	void		keyPressed(int key);
	void		keyReleased(int key);
	void		mouseMoved(int x, int y );
	void		mouseDragged(int x, int y, int button);
	void		mousePressed(int x, int y, int button);
	void		mouseReleased();
	
	void		handleGui(int parameterId, int task, void* data, int length);
		
	float		rotation;
	float		distance;
	float		size;
	ofxPoint2f	pos;
	bool		mov;
	ofxPoint2f	speed;
	ofRGBA		color;
	
	float		fw,fh;
	ofxPoint2f	minSpd,maxSpd;
	ofxPoint2f	cPos;

	ofxGui*		gui;
};

//--------------------------------------------------------------

#endif	

//--------------------------------------------------------------
