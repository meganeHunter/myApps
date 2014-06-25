#include "ReadTxt.h"

readTxt::readTxt()
{
	ifs.open("input.txt");
	ifs2.open("input2.txt");
	font.loadFont("LiberationMono-Regular.ttf",18);
	ofs.open("output.txt");
	ofs2.open("output2.txt");

	for(i=0;i<RN;i++)
	{
		for(j=0;j<CN;j++)
		{
			stext[i][j] = '\0';
		}
	}

	i = 0;

	while(ifs.getline(buf,sizeof buf))
	{
		ofs << setw(3) << i + 1 << ":" << buf << endl;
		for(j=0;j<CN;j++)
		{
			stext[i][j] = buf[j];
		}

		i++;
	}
	
	while(ifs2.getline(txt,sizeof txt))
	{
		ofs2 << setw(3) << i << ":" << txt << endl;
	}

	fx = ofGetWidth();
	fy = ofGetHeight();

	ofs2 << endl << "stext[] :" << endl;

	for(j=0;j<i;j++)
	{
		ofs2 << setw(3) << j << ":" << stext[j] << endl;
	}

	rc = 0;
	rcdi = true;
	gc = 120;
	gcdi = true;
	bc = 240;
	bcdi = true;

}

void readTxt::update()
{
	ofRectangle rect = font.getStringBoundingBox(stext[0],fx * 1/8,fy * 1/8);
	x = rect.x;
	y = rect.y;
	w = rect.width;
	h = rect.height;

	if(!rcdi)
	{
		rc--;
		if(rc == 0)
		{
			rcdi = true;
		}
	}
	else
	{
		rc++;
		if(rc == cM)
		{
			rcdi = false;
		}
	}
	if(!gcdi)
	{
		gc--;
		if(gc == 0)
		{
			gcdi = true;
		}
	}
	else
	{
		gc++;
		if(gc == cM)
		{
			gcdi = false;
		}
	}
	if(!bcdi)
	{
		bc--;
		if(bc == 0)
		{
			bcdi = true;
		}
	}
	else
	{
		bc++;
		if(bc == cM)
		{
			bcdi = false;
		}
	}

}


void readTxt::draw()
{
	for(j=0;j<i;j++)
	{
		ofSetColor(rc,gc,bc);
		font.drawString(stext[j],x,y + (h * j));
	}
}