#ifndef _H_WINSCREEN
#define _H_WINSCREEN

#include <vcclr.h>
#include <gcroot.h>
#include "Screen.h"


class WinScreen : public Screen
{
public:
	//WinScreen(gcroot<System::Windows::Forms::PictureBox^> & pictureBox, int width, int height);
	WinScreen(gcroot<System::Drawing::Graphics^> & g, int width, int height);
	~WinScreen();
	void setPixel(int px, int py, RGBColor & c);
	void repaint();
	virtual void fillBackground(RGBColor & c);

private:
	gcroot<System::Drawing::Graphics^> g;
};

#endif
