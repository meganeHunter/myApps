#include "ReadTxt.h"

readTxt::readTxt()
{

	for(i=0;i<RN;i++)
	{
		for(j=0;j<CN;j++)
		{
			stext[i][j] = '\0';
		}
	}

	//fileN = "Input.txt";
}

void readTxt::load()
{
	ifs.open(fileN);

	i = 0;
	
	while(ifs.getline(buf,sizeof buf))
	{
		for(j=0;j<CN;j++)
		{
			stext[i][j] = '\0';
			stext[i][j] = buf[j];
			buf[j] = '\0';
		}

		i++;
	}

}

string readTxt::getChar(int r,int c)
{
	chr = stext[r][c];
	return chr;
}

void readTxt::setInputTxt(char * inputFn)
{
	fileN = inputFn;
}

