//
//  altR1.cpp
//  altRaiiner1
//
//  Created by 吉森 圭太 on 2014/04/14.
//
//

#include "altR1.h"

altR1::altR1()
{
    ofBackground(0, 0, 0);
    
    fw = ofGetWindowSize().x;
    fh = ofGetWindowSize().y;
    
    k = 0;
    j = 0;

}

void altR1::setup()
{
    lineC.set(0, 0, 255, 255);
    linePos.set(1, 1);
    lineFrix = 0;
    lineDist = 1.0 / 24.0;
}

void altR1::update()
{
    /*
     nLinePos = linePos + lineSpeed;
     nLinePos.y += lineFrix;
     
     
     if(nLinePos.x > fw || nLinePos.x < 0)
     {
     lineSpeed.x *= -1;
     }
     if(nLinePos.y > fh || nLinePos.y < 0)
     {
     lineSpeed.y *= -1;
     }
     */
    
    
}

void altR1::draw()
{
    if(linePos.x < fw && linePos.x > 0)
    {
        for (k = 0; k < 124; k++)
        {
            ofSetColor(lineC);
            ofLine(linePos.x, 0,linePos.x + lineFrix, fh);
            linePos.x += k * lineDist;
        }
        
        //linePos.x += lineFrix;
        
    }
    else
    {
        linePos.x = 1;
    }
    
}

//---------------------------------------------------------

void altR1::setLColor(ofColor color)
{
    lineC = color;
}

void altR1::setLSpeed(ofPoint speed)
{
    lineSpeed = speed;
}

void altR1::setLFriction(int friction)
{
    lineFrix = friction;
}

void altR1::setLDistance(float distance)
{
    lineDist = distance;
}

//---------------------------------------------------------

ofPoint altR1::getLPos()
{
    return linePos;
}

ofPoint altR1::getLSpeed()
{
    return lineSpeed;
}

ofColor altR1::getLColor()
{
    return lineC;
}



