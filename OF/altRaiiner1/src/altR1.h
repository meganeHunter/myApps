//
//  altR1.h
//  altRaiiner1
//
//  Created by 吉森 圭太 on 2014/04/14.
//
//

#ifndef __altRaiiner1__altR1__
#define __altRaiiner1__altR1__

#include <iostream>
#include "ofMain.h"

class altR1
{
public:
    altR1();
    
    void setup();
    void update();
    void draw();
    
    void setLColor(ofColor color);
    void setLSpeed(ofPoint speed);
    void setLFriction(int friction);
    void setLDistance(float distance);
    
    ofPoint getLPos();
    ofPoint getLSpeed();
    ofColor getLColor();
    
private:
    int fw,fh;
    int k,j;
    
    int lineFrix;
    float lineDist;
    
    ofColor lineC;
    ofPoint lineSpeed;
    ofPoint linePos,nLinePos;
    
};

#endif /* defined(__altRaiiner1__altR1__) */
