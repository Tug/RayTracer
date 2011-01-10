#include "stdafx.h"

#include "CameraScreen.h"

CameraScreen::CameraScreen(P3 & position, P3 & direction, double rotation,
							Screen * screen, double screenDist): Camera(position, direction, rotation) {
	this->screen = screen;
	this->screenDist = screenDist;
	reinit();
}

CameraScreen::CameraScreen(Camera * camera, Screen * screen, double screenDist): Camera(camera) {
	this->screen = screen;
	this->screenDist = screenDist;
	reinit();
}

CameraScreen::CameraScreen(Screen * screen, double screenDist) 
		: Camera(P3(screen->getWidth()/2, 0, screen->getHeight()/2), P3(0, 1, 0), 0) {
	this->screen = screen;
	this->screenDist = screenDist;
	reinit();
}

void CameraScreen::reinit() {
	Camera::reinit();
	// find the position of the center of the screen in 3D space
	this->centerScreen = position + (screenDist * direction);
	double cosrot = cos(rotation);
	double sinrot = sin(rotation);
	// compute the directions of the u and v vector along the screen
	P3S sDir(direction);
	P3S sdu(P3(cosrot,0.0,sinrot));
	P3S sdv(P3(sinrot,0.0,cosrot));
	sdu.u += sDir.u + M_PI/2;
	sdv.v += sDir.v;
	P3 du(sdu);
	P3 dv(sdv);
	du.normalize();
	dv.normalize();
	// deduce dx and dy
	this->dx = du;
	this->dy = - dv;
	// precompute the top left corner of the screen
	int width = screen->getWidth();
	int height = screen->getHeight();
	this->topLeftCornerScreen = centerScreen - ((width/2)*dx) - ((height/2)*dy);
}

CameraScreen::~CameraScreen() {
}

P3 CameraScreen::get3DPoint(int px, int py) {
	return topLeftCornerScreen + (px * dx)+ (py * dy);
}

Screen * CameraScreen::getScreen() {
	return screen;
}

double CameraScreen::getScreenDist() {
	return screenDist;
}

P3 & CameraScreen::getCenterScreen() {
	return centerScreen;
}

P3 & CameraScreen::getTopLeftCornerScreen() {
	return topLeftCornerScreen;
}

P3 & CameraScreen::getDx() {
	return dx;
}

P3 & CameraScreen::getDy() {
	return dy;
}
