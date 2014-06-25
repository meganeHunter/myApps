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
	char stext[RN][CN];

	ifstream ifs;

	int i,j,k;
	char * fileN;
	string chr;
	
public:
	readTxt();
	void load();
	string getChar(int r,int c);
	void setInputTxt(char * inputFn);

};

#endif