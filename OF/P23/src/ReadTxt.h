#ifndef _READ_TXT
#define _READ_TXT

#include "ofMain.h"
#include <iostream>
#include <fstream>
#include <string>

#define RN 101
#define CN 124
#define cM 255


using namespace std;

class readTxt{
private:
	char buf[CN];
	char txt[CN];
	char stext[RN][CN];
	ofTrueTypeFont font;
	float fx,fy;
	ifstream ifs;
	ifstream ifs2;
	ofstream ofs;
	ofstream ofs2;
	int i,j,k;
	float x,y,w,h;

	int rc,gc,bc;
	bool rcdi,gcdi,bcdi;
	
public:
	readTxt();
	void draw();
	void update();

};

#endif