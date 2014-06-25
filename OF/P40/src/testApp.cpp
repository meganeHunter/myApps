#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
    ofAddListener(tuio.objectAdded,this,&testApp::objectAdded);
    ofAddListener(tuio.objectRemoved,this,&testApp::objectRemoved);
    ofAddListener(tuio.objectUpdated,this,&testApp::objectUpdated);
    ofAddListener(tuio.cursorAdded,this,&testApp::tuioAdded);
    ofAddListener(tuio.cursorRemoved,this,&testApp::tuioRemoved);
    ofAddListener(tuio.cursorUpdated,this,&testApp::tuioUpdated);
     
    //�t���[�����[�g�ݒ�
    ofSetFrameRate(60);
    //�w�i������
    ofBackground(0,0,0);
     
    //�|�[�g�ԍ�3333�ŁATUIO�̒ʐM�J�n
    tuio.start(3333);
     
    //���O�̃e�L�X�g�����
    log = "";

	fw = ofGetWidth();
	fh = ofGetHeight();

	pAng1 = 0.0;
	pAng2 = 0.0;

	is1Pmode = COMP;
}

//--------------------------------------------------------------
void testApp::update()
{
	tuio.getMessage();

	//�I�u�W�F�N�g�̃��X�g���擾
    objectList = tuio.getTuioObjects();
	
	pAng1 = 0.0;
	pAng2 = 0.0;
   
    //�S�ẴI�u�W�F�N�g���C�e���[�^�ő���
    for (tobj = objectList.begin();tobj != objectList.end();tobj++) 
	{
        //���̂��擾
        blob = (*tobj);

		if(blob->getFiducialId() == 1)
		{
			pAng1  = (180.0 - blob->getAngleDegrees()) / 8.4;
		}

		if(blob->getFiducialId() == 2)
		{
			pAng2  = (180.0 - blob->getAngleDegrees()) / 8.4;
			//pAng2 *= blob->getMotionSpeed();
		}
       
    }
	
	
	vTable.setPosd(vPaddle.getPosd());
	vTable.setScore(sBall.getScore());
	vTable.update();

	is1Pmode ? vPaddle.setPos1(vPaddle.getPos1().y + (pAng1 / 4.6)) : vPaddle.setPos1r(sBall.getPos());
	vPaddle.setPos2(vPaddle.getPos2().y + (pAng2 / 4.6));
	vPaddle.update();

	sBall.setpHeight(vPaddle.getHeight());
	sBall.setp1Pos(vPaddle.getPos1());
	sBall.setp2Pos(vPaddle.getPos2());
	sBall.update();


	stat  = "status :";
	stat += "  pAng1 : " + ofToString(pAng1,2);
	stat += " /pAng2 : " + ofToString(pAng2,2);
	stat += " /p1Pos.y : " + ofToString(vPaddle.getPos1().y,2);
	stat += " /p2Pos.y : " + ofToString(vPaddle.getPos2().y,2); 
	stat += " /FPS : " + ofToString(ofGetFrameRate(),2);
	stat += " /is1Pmode : ";
	stat += is1Pmode ? "HUMAN" : "COMP";

}

//--------------------------------------------------------------
void testApp::draw()
{
	/*
    //�J�[�\���̏�Ԃ�\��
    tuio.drawCursors();
    //�I�u�W�F�N�g�̏�Ԃ�\��
    tuio.drawObjects();
	*/

	ofSetColor(255,255,255);
	ofNoFill();
	ofRect(fw*1/8,fh*1/8,fw*6/8,fh*5/8);

	ofFill();
	sBall.draw();
	vTable.draw();
	vPaddle.draw();

	ofSetColor(255,255,255);
	ofNoFill();
	ofSetRectMode(OF_RECTMODE_CORNER);

    //���O��\��
    ofSetColor(0xffffff);
    ofDrawBitmapString(log,20.0,20.0);
	ofDrawBitmapString(stat,20.0,fh - 20.0);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
	sBall.setMode(key);
	vTable.setMode(key);

	switch(key)
	{
	case OF_KEY_INSERT:
		is1Pmode = !is1Pmode;
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


///-------------------------------------------------------------

void testApp::objectAdded(ofxTuioObject& tuioObject)
{
    //�}�[�J�[�ǉ�
    log  = " new object: ";
	log += ofToString(tuioObject.getFiducialId());
	log += " X: " + ofToString(tuioObject.getX());
	log += " Y: " + ofToString(tuioObject.getY());
	log += " angle: " + ofToString(tuioObject.getAngleDegrees());
}

///-------------------------------------------------------------

void testApp::objectRemoved(ofxTuioObject& tuioObject)
{
    //�}�[�J�[�폜
    log  = " object removed: ";
	log += ofToString(tuioObject.getFiducialId());
	log += " X: " + ofToString(tuioObject.getX());
	log += " Y: " + ofToString(tuioObject.getY());
	log += " angle: " + ofToString(tuioObject.getAngleDegrees());
}

///-------------------------------------------------------------

void testApp::objectUpdated(ofxTuioObject& tuioObject)
{
    //�}�[�J�[�̏�ԍX�V
    log  = " object updated: ";
	log += ofToString(tuioObject.getFiducialId());
	log += " X: " + ofToString(tuioObject.getX());
	log += " Y: " + ofToString(tuioObject.getY());
	log += " angle: " + ofToString(tuioObject.getAngleDegrees());
}

///-------------------------------------------------------------

void testApp::tuioAdded(ofxTuioCursor& tuioCursor)
{
    //�J�[�\���ǉ�
    log  = " new cursor: ";
	log += ofToString(tuioCursor.getFingerId());
	log += " X: " + ofToString(tuioCursor.getX());
	log += " Y: " + ofToString(tuioCursor.getY());
}

///-------------------------------------------------------------

void testApp::tuioRemoved(ofxTuioCursor& tuioCursor)
{
    //�J�[�\���폜
    log  =  " cursor removed: ";
	log += ofToString(tuioCursor.getFingerId());
	log += " X: " + ofToString(tuioCursor.getX());
	log += " Y: " + ofToString(tuioCursor.getY());
}

///-------------------------------------------------------------

void testApp::tuioUpdated(ofxTuioCursor& tuioCursor)
{
    //�J�[�\����ԍX�V
    log =  " cursor updated: ";
	log += ofToString(tuioCursor.getFingerId());
	log += " X: " + ofToString(tuioCursor.getX());
	log += " Y: " + ofToString(tuioCursor.getY());
}

