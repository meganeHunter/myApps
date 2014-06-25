#ifndef ALEA_JACTA_EST
#define ALEA_JACTA_EST

#include "ofMain.h"
#include "showChar.h"
#include "broks.h"
#include "timR.h"

#define BRS 3

class ajeMain
{
public:
	ajeMain();

	void update();
	void draw();

	void drawSign(int si);
	void drawSQ(int start,int end);
	void drawSQR(bool* sorn);
	void drawSQON();
	void drawOX();
	void drawNum(int* numar);
	void drawEQ();
	void drawAns();

	void checkAns();

	void setNumVar(brok* bras);
	void setDisp(int dsp);
	void setSignPos(ofPoint sinp);
	void setSignSize(int ssiz);
	void setSignColor(ofColor scol);
	void setSignType(int sint);
	void setSorn(bool* sorn);
	void setMode(int mo);
	void setIsDrawEQ(bool isD);
	void setAns(int answer);

	void setBroN(vector<brokN>& broN);
	//void setSign(vector<brokS>* broS);

	int getDisp();
	int getMode();
	int getTime();
	bool getIsTimeOver();

private:
	int k,j,p;
	int fw,fh;
	int disp,mode;
	int sSize;
	int sin;
	int ans;

	bool isCorr;
	bool son[3];
	bool isDrawEQ;

	string aje,ox,sqon,sign,num,eq,answ;

	vector<brokN> bN;
	vector<brokS> bS;

	ofPoint sPos;

	ofTrueTypeFont font1,font2;

	ofRectangle f1Rect,f2Rect;

	showChar* sch;
	showChar* sch2;

	ofColor sCol;

	timR timere;

	brok tempb;
	brok brks[BRS];
};


#endif