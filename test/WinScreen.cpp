#include "stdafx.h"

#include "WinScreen.h"


WinScreen::WinScreen(gcroot<System::Drawing::Graphics^> & g, int width, int height) : Screen(width, height) {
	this->g = g;
}

WinScreen::~WinScreen() {
}

void WinScreen::setPixel(int x, int y, RGBColor & c) {
	if ( (x>=0) && (x<width) ) {
		if ( (y>=0) && (y<height) ) {
			int R = int((c.m_R)*255);
			int G = int((c.m_G)*255);
			int B = int((c.m_B)*255);
			System::Drawing::SolidBrush S(System::Drawing::Color::FromArgb(R,G,B));
			g->FillRectangle(%S,x,y,1,1);
		}
	}
}

void WinScreen::repaint() {

	// nothing to do
}

void WinScreen::fillBackground(RGBColor & c) {
	int R = int((c.m_R)*255);
	int G = int((c.m_G)*255);
	int B = int((c.m_B)*255);
	System::Drawing::SolidBrush S(System::Drawing::Color::FromArgb(R,G,B));
	g->FillRectangle(%S,0,0,width,height);
}