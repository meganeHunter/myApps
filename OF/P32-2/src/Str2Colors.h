#ifndef _STR_TO_COLORS
#define _STR_TO_COLORS

#include <string>
#include "ofMain.h"
#include "ShowChar.h"

#define COLS 8

using namespace std;


class str2c
{
private:
	string cstr;
	string* colors;
	string statest;
	
	int j,k;
	int count;
	int slcol;

	float fw,fh;
	float scWidth,scHeight;

	showChar* sch;

	void setupRed(ofTrueTypeFont* font);
	void setupOrange();
	void setupYellow();
	void setupGreen();
	void setupBlue(ofTrueTypeFont* font);
	void setupIvory();
	void setupViolet();
	void setupWhite();

	void drawRed();
	void drawOrange();
	void drawYellow();
	void drawGreen();
	void drawBlue();
	void drawIvory();
	void drawViolet();
	void drawWhite();

public:
	str2c();
	//str2c(ofTrueTypeFont* font);
	//str2c(showChar* sc);

	void setup(ofTrueTypeFont* font);
	void draw();
	void update();

	void setStr(string str);

};


#endif
