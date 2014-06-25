//--------------------------------------------------------------

#include "testApp.h"

//--------------------------------------------------------------

void testApp::setup()
{	 
	ofBackground(0, 0, 0);	
	ofSetFrameRate(60);
	ofSetVerticalSync(true);

	fw = ofGetWidth();
	fh = ofGetHeight();
		
	size		= 24.0;
	pos			= ofxPoint2f(fw/2,fh/2);
	mov			= true;
	speed		= ofxPoint2f(12.0,12.0);
	color		= ofRGBA(12,12,248,35);

	minSpd		= ofxPoint2f(-24.0,-24.0);
	maxSpd		= ofxPoint2f(24.0,24.0);

	gui	= ofxGui::Instance(this);

	if(!gui->buildFromXml(OFXGUI_XML))
	{	
		ofxGuiPanel* panel = gui->addPanel(kParameter_Panel, "control", fw-170, fh-350, pBorder, pSpacing);
		panel->addXYPad(kParameter_Speed, "speed", 110, 110, minSpd, maxSpd, pos, kofxGui_Display_Int, 0);
		panel->addButton(kParameter_Move, "move", buttonH, buttonH, mov, kofxGui_Button_Switch);
		panel->addSlider(kParameter_Size, "size", 110, sliderH, 1.8, 120.4, size, kofxGui_Display_Float4, 0);
		panel->addColor(kParameter_Color, "color", 110, colorH, color, kofxGui_Color_RGBA);
		panel->addFiles(kParameter_File, "files", 110, filesH, "", "", "xml");
		panel->addButton(kParameter_SaveXml, "saveToXml", buttonH, buttonH, kofxGui_Button_Off, kofxGui_Button_Trigger);

		
		//	do update while inactive
		gui->forceUpdate(true);	
	}

}

//--------------------------------------------------------------

void testApp::update()
{
	pos += speed;
	
	if(pos.x < size)
	{
		pos.x = size;
	}
	if(pos.x > fw-size)
	{
		pos.x = fw-size;
	}
	if(pos.y < size)
	{
		pos.y = size;
	}
	if(pos.y > fh-size)
	{
		pos.y = fh-size;
	}

	
	
	if(!mov)
	{
		pos = cPos;
	}
	else
	{
		cPos = pos;
	}

}

//--------------------------------------------------------------

void testApp::draw()
{
	//Lets enable blending!
	//We are going to use a blend mode that adds
	//all the colors to white.
	ofEnableAlphaBlending();	
	glBlendFunc(GL_SRC_COLOR, GL_ONE);
	
		ofFill();
	
		glColor4f(color.r, color.g, color.b, color.a);
		ofRect(pos.x,pos.y,size,size);
	
	//Lets stop the blending!
	ofDisableAlphaBlending();	
		
	gui->draw();
}

//--------------------------------------------------------------

void testApp::keyPressed(int key)
{ 
	if(key == 'c') 
	{
		gui->activate(!gui->mIsActive);
	}
}

//--------------------------------------------------------------

void testApp::keyReleased(int key)
{ 
	
}

//--------------------------------------------------------------

void testApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------

void testApp::mouseDragged(int x, int y, int button)
{
	gui->mouseDragged(x, y, button);	
}

//--------------------------------------------------------------

void testApp::mousePressed(int x, int y, int button)
{
	gui->mousePressed(x, y, button);	
}

//--------------------------------------------------------------

void testApp::mouseReleased()
{
	gui->mouseReleased(mouseX, mouseY, 0);	
}

//--------------------------------------------------------------

void testApp::handleGui(int parameterId, int task, void* data, int length)
{
	switch(parameterId)
	{
		case kParameter_Panel:
			break;
			
		case kParameter_Size:
			if(task == kofxGui_Set_Float)
				size = *(float*)data;
			break;
			
		case kParameter_Color:
			if(task == kofxGui_Set_Color)
				color = *(ofRGBA*)data;
			break;

		case kParameter_File:
			if(task == kofxGui_Set_String)
			{
				string file = *(string*)data;
				gui->buildFromXml(file);
			}
			break;

		case kParameter_SaveXml:
			if(task == kofxGui_Set_Bool)
			{
				if(*(bool*)data)
					gui->saveToXml(OFXGUI_XML);
			}
			break;

		case kParameter_Speed:
			if(task == kofxGui_Set_Point)
				speed = *(ofxPoint2f*)data;
			break;

		case kParameter_Move:
			if(task == kofxGui_Set_Bool)
				mov = *(bool*)data;
			break;
	}
}

//--------------------------------------------------------------
