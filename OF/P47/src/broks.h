#ifndef BROK_S
#define BROK_S

#include "ofMain.h"

struct brok
{
	int id;
	int fig;

	char ch;

	ofPoint pos;

	ofColor col;

};

struct brokN
{
	int var;

	bool isShow;

	ofPoint pos;

	ofColor col;
};

struct brokS
{
	int type;
	int size;

	bool isShow;

	ofPoint pos;
	
	ofColor col;

};

#endif