#include "table.h"

table::table()
{
	vfont.loadFont("Xephei.ttf",58);
	scr = bont.getScore();
	key = '\0';
}
	
	
	
void table::draw()
{
	ofSetColor(255,255,255,120);
	vfont.drawString("PINGPONG",ofGetWidth()*2/8-35,ofGetHeight()*1/3);
	
	sprintf(score,"%d  -  %d",lscore,rscore);
	
	vfont.drawString(score,ofGetWidth()*2/8+12,ofGetHeight()*1/2);
	
	if(lscore > 14 )
	{
		vfont.drawString("PLAYER 1 WON",ofGetWidth()*1/8-24,ofGetHeight()*1/5);
	}
	if(rscore > 14 )
	{
		vfont.drawString("PLAYER 2 WON",ofGetWidth()*1/8-24,ofGetHeight()*1/5);
	}

	if(key =='p')
	{
		vfont.drawString("-PAUSE-",ofGetWidth()*2/8+12,ofGetHeight()*1/5);

	}
	if(key == 'c')
	{
		key = '\0';
	}
	
	//sprintf(posD,"X:%2.1f , Y:%2.1f",posDif.x,posDif.y);
	//vfont.drawString(posD,ofGetWidth()*1/8-58,ofGetHeight()*7/8);
}

void table::update()
{
	
	lscore = scr.x;
	rscore = scr.y;

}

void table::setScore(ofPoint score)
{
	scr = score;
}

void table::setMode(int inKey)
{
	key = inKey;
}

void table::setPosd(ofPoint posd)
{
	posDif = posd;
}

table::~table()
{

	vfont.drawString("THE END",ofGetWidth()*1/8-58,ofGetHeight()*7/8);
}