#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	ofBackground(0, 0, 0);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	ofEnableAlphaBlending();
	ofEnableSmoothing();
	
	fw = ofGetWidth();
	fh = ofGetHeight();

	ofSeedRandom();
	
	rarg = 0.0;
	rchange = ofRandom(0.018,0.08);

	isGLModeT = true;
	isDec = false;

	//sMode = GL_ONE_MINUS_SRC_ALPHA;	
	//dMode = GL_SRC_COLOR;

	for(i=0;i<240;i++)
	{
		penm = (i % 5 == 0)? 1.1 : (i % 5) * 4.6;

		sPart sP;

		sP.weight = ofRandom(0.1, 1.8);

		sP.windir.x = 0.003;	//penm * 0.023;
		sP.windir.y = ofRandom(-1.8,-1.9);

		sP.speed.x = (i % 2 == 0) ? -0.4 * penm : 0.4 * penm;		//ofRandom(-1.02,1.02) * 4.8 * penm;
		sP.speed.y = ofRandom(-0.1,0.1);
		sP.speed.z = ofRandom(-24.8,24.8);

		sP.pos.x = (fw + penm) / 1.8;		//ofRandom((fw + penm) / 1.8,(fw + penm) / 1.8);
		sP.pos.y = (fh / 1.3) + penm;		//ofRandom((fh / 1.3) + penm,(fh / 1.3) + penm);
		sP.pos.z = ofRandom(-23.5,23.5);
		
		sP.col.r = 1.0;
		sP.col.g = 1.0;
		sP.col.b = 1.0;
		sP.col.a = 0.019 * penm + ofRandom(0.014,0.248);

		sPar.push_back(sP);
	}
	
}

//--------------------------------------------------------------
void testApp::update()
{
	if(rarg == 0.0)
	{
		isDec = false;
	}
	if(rarg == TWO_PI)
	{
		isDec = true;
	}
	
	rchange = ofRandom(0.018,0.08);
	
	rarg = isDec ? (rarg - rchange) : (rarg + rchange);


	for(i=0;i<(int)sPar.size();i++)
	{
		//sPart &sp = sPar[i];
		
		
		/*
		for(k=0;k<(int)sPar.size();k++)
		{
			if(i == k)
			{
				continue;
			}

			//sPart &spp = sPar[k];
			
			sPar[i].speed += (sPar[k].pos - sPar[i].pos) / sPar[k].weight * 0.001;
		}
		*/
	
		//sPart &sp = sPar[i];
	
		//penm = (i % 5 == 0)? 0.1 : (i % 5) * 0.06;

		rchange += (i % 5) * 0.004;

		sPar[i].pos += sPar[i].speed * 0.1;
		//sPar[i].pos.x += 2.4 * sin(rarg);
		sPar[i].pos.y += 1.4 * sin(0.8 * rarg);
		sPar[i].pos += sPar[i].windir;

		sPar[i].update();
	}

	fps = ofGetFrameRate();
}

//--------------------------------------------------------------
void testApp::draw()
{
	//glBlendFunc(sMode,dMode);
	glEnable(GL_FOG);
	glFogi(GL_FOG_MODE,GL_LINEAR);
	glFogi(GL_FOG_START,1);
	glFogi(GL_FOG_END,2);

	for(i=0;i<(int)sPar.size();i++)
	{
		sPar[i].draw();
	}

	stat  = "Status : ";
	stat += " / FPS : " + ofToString(fps,2);
	stat += " / sPar.size : " + ofToString((double)sPar.size(),0);
	stat += " / drawMode : ";
	stat += isGLModeT ? "OpenGL " : "OF ";

	//stat += " / BlendMode : ";
	//stat += "sfactor : " + ofToString(sMode) + " , ";
	//stat += "dfactor : " + ofToString(dMode);

	//glBlendFunc(1,0);
	
	ofSetColor(255,255,255);
	ofDrawBitmapString(stat,20.0,fh - 20.0);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
	switch(key)
	{
	case OF_KEY_INSERT:
		for(i=0;i<(int)sPar.size();i++)
		{
			sPar[i].isGLMode = !sPar[i].isGLMode;
		}
		isGLModeT = !isGLModeT;
		break;

	case OF_KEY_END:
		//(sMode != GL_SRC_ALPHA_SATURATE) ? sMode++ : sMode = GL_SRC_COLOR;
		break;

	case OF_KEY_HOME:
		//(dMode != GL_SRC_ALPHA_SATURATE) ? dMode++ : dMode = GL_SRC_COLOR;
		break;
	
	case OF_KEY_UP:
		//(sMode != 0) ? sMode = 0 : sMode = 1;
		break;

	case OF_KEY_DOWN:
		//sMode = GL_ONE_MINUS_SRC_ALPHA;
		break;

	case OF_KEY_LEFT:
		//(dMode != 0) ? dMode = 0 : dMode = 1;
		break;

	case OF_KEY_RIGHT:
		//dMode = GL_ONE_MINUS_SRC_ALPHA;
		break;

	default:
		break;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{

}

