#ifndef _H_CAMERASCREEN
#define _H_CAMERASCREEN

#include "P3.H"
#include "P3S.h"
#include "Camera.h"
#include "Screen.h"

class CameraScreen: public Camera
{
public:
	CameraScreen(P3 & position, P3 & direction, double rotation, Screen * screen, double screenDist);
	CameraScreen(Camera * camera, Screen * screen, double screenDist);
	CameraScreen(Screen * screen, double screenDist);
	virtual ~CameraScreen();
	P3 get3DPoint(int px, int py);
	P3 & getCenterScreen();
	P3 & getTopLeftCornerScreen();
	P3 & getDx();
	P3 & getDy();
	Screen * getScreen();
	Camera * getCamera();
	double getScreenDist();

protected:
	virtual void reinit();
	Camera * camera;
	Screen * screen;
	double screenDist;
	P3 centerScreen;
	P3 topLeftCornerScreen;
	P3 dx;
	P3 dy;
};

#endif