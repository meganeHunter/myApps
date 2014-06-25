#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ball.h"
#include "table.h"
#include "paddle.h"
#include "ofxTuio.h"

#define HUMAN true
#define COMP false


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);


		///---------------------------------------------

		void objectAdded(ofxTuioObject& tuioObject);
		//���̂̍폜�����m
		void objectRemoved(ofxTuioObject& tuioObject);
		//���̂̏�Ԃ̍X�V�����m
		void objectUpdated(ofxTuioObject& tuioObject);
 
		//TUIO�̃J�[�\��(�^�b�`�|�C���g�Ȃ�)�Ɋ֌W����C�x���g
		//�J�[�\���̒ǉ������m
		void tuioAdded(ofxTuioCursor& tuioCursor);
		//�J�[�\���̍폜�����m
		void tuioRemoved(ofxTuioCursor& tuioCursor);
		//�J�[�\���̏�Ԃ̍X�V�����m
		void tuioUpdated(ofxTuioCursor& tuioCursor);
     
	private:
		int fw,fh;

		float pAng1,pAng2;

		bool is1Pmode;

		//���O�̏o�͗p
		string log;
		string stat;

		//TUIO�̃N���C�A���g�̃C���X�^���X��
		myTuioClient tuio;
		
		list<ofxTuioObject*> objectList;
		//���X�g����̂��߂̃C�e���[�^������
		list<ofxTuioObject*>::iterator tobj;
		
		ofxTuioObject* blob;
		


		ball sBall;
		table vTable;
		paddle vPaddle;


};

#endif
