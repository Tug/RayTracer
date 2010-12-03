#ifndef _H_SCREEN
#define _H_SCREEN

class Scene;

#include "Color.h"
#include "ZBuffer.h"
#include "Object3D.h"
#include "Scene.h"
#include "Zone.h"
#include "P3.h"

class Screen
{
public:
	Screen(int width, int height);
	virtual ~Screen();
	virtual void setPixel(int px, int py, Color & c) = 0;
	virtual void repaint() = 0;
	int getWidth();
	int getHeight();
	ZBuffer * getZBuffer();
	void drawScene(Scene * scene);
	void drawObject(Object3D * object3D, Scene * scene);
	virtual void fillBackground(Color & c);

protected:
	int width, height;
//	ZBuffer * zbuffer;

private:
	Zone sceneToScreenZone(Zone zone);
};

#endif

