#ifndef _H_WINBUFFEREDSCREEN
#define _H_WINBUFFEREDSCREEN

#include <vcclr.h>
#include <gcroot.h>
#include "Screen.h"

// test a faster drawing implementation ? (drawing once)

class WinBufferedScreen : public Screen
{
public:
	WinBufferedScreen(gcroot<System::Windows::Forms::PictureBox^> & pictureBox, int width, int height);
	~WinBufferedScreen();
	void setPixel(int px, int py, RGBColor & c);
	void repaint();

private:
	gcroot<System::Windows::Forms::PictureBox^> pictureBox;
	gcroot<System::Drawing::Bitmap^> image;
};

#endif
