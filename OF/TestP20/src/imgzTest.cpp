
#include "imgzTest.h"

void setImgz(imgz im,string iName)
{
	im.img.loadImage(iName);
	im.size.x = im.img.getWidth();
	im.size.y = im.img.getHeight();
}

void setImgzPos(imgz im,int xp,int yp)
{
	im.pos.x = xp;
	im.pos.y = yp;
}

imgz setImgz2(string iName)
{
	imgz im;
	
	im.img.loadImage(iName);
	im.size.x = im.img.getWidth();
	im.size.y = im.img.getHeight();
	
	return im;
}

void drawImgz(imgz im)
{
	im.img.draw(im.pos.x,im.pos.y,im.size.x,im.size.y);
}