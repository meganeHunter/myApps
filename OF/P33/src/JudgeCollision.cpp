#include "JudgeCollision.h"


JudgeC::JudgeC(pRect ** pR)
{
	mRect = pR;

	fw = ofGetWidth();
	fh = ofGetHeight();
	fPos.x = (14 * fw) / 15;
	fPos.y = (14 * fh) / 15;

	sG = ofPoint(0.0,1.8);
}

void JudgeC::judge(){


	for(k=0;k<mRect->size();k++)
	{
		sPos = mRect[k]->getPos();
		sRectW = mRect[k]->rectW;
		sRectH = mRect[k]->rectH;
		if(sPos.y < fPos.y - sRectH && mRect[k]->rectMov)
		{
			sPos += sG;
		}
		else
		{
			mRect[k]->rectMov = false;
		}


		for(j=0;j<mRect->size();j++)
		{
			
			vPos = mRect[j]->getPos();
			vRectW = mRect[j]->rectW;
			vRectH = mRect[j]->rectH;

			distX = (sPos.x > vPos.x) ? (sPos.x - vPos.x) : (vPos.x - sPos.x);
			distY = sPos.y - vPos.y;

			sWidth = (sRectW < vRectW) ? sRectW : vRectW;

			if(k != j && mRect[k]->rectMov)
			{
				
				if(distX < sWidth)
				{
	
					if(-1.0 * sRectH < distY && distY < 0.0)
					{
						sPos.y = vPos.y - sRectH;
						mRect[k]->rectMov = mRect[j]->rectMov;
					}
				}	
			}

			
			mRect[j]->setPos(vPos);
		}
		
		mRect[k]->setPos(sPos);
	}

}