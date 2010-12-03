#include "stdafx.h"

#include "WinBufferedScreen.h"


WinBufferedScreen::WinBufferedScreen(gcroot<System::Windows::Forms::PictureBox^> & pictureBox, int width, int height) : Screen(width, height) {
	this->pictureBox = pictureBox;
	image = gcnew System::Drawing::Bitmap(width, height);
}

WinBufferedScreen::~WinBufferedScreen() {

}

void WinBufferedScreen::setPixel(int x, int y, Color & c) {
	if ( (x>=0) && (x<width) ) {
		if ( (y>=0) && (y<height) ) {
			int R = int((c.m_R)*255);
			int G = int((c.m_G)*255);
			int B = int((c.m_B)*255);
			image->SetPixel(x, y, System::Drawing::Color::FromArgb(R,G,B));
		}
	}
}

void WinBufferedScreen::repaint() {
	pictureBox->Image = image;
}
