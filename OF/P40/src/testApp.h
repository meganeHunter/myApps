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
		//物体の削除を検知
		void objectRemoved(ofxTuioObject& tuioObject);
		//物体の状態の更新を検知
		void objectUpdated(ofxTuioObject& tuioObject);
 
		//TUIOのカーソル(タッチポイントなど)に関係するイベント
		//カーソルの追加を検知
		void tuioAdded(ofxTuioCursor& tuioCursor);
		//カーソルの削除を検知
		void tuioRemoved(ofxTuioCursor& tuioCursor);
		//カーソルの状態の更新を検知
		void tuioUpdated(ofxTuioCursor& tuioCursor);
     
	private:
		int fw,fh;

		float pAng1,pAng2;

		bool is1Pmode;

		//ログの出力用
		string log;
		string stat;

		//TUIOのクライアントのインスタンス化
		myTuioClient tuio;
		
		list<ofxTuioObject*> objectList;
		//リスト操作のためのイテレータを準備
		list<ofxTuioObject*>::iterator tobj;
		
		ofxTuioObject* blob;
		


		ball sBall;
		table vTable;
		paddle vPaddle;


};

#endif
