#ifndef _H_ORTHOGRAPHICPROJECTION
#define _H_ORTHOGRAPHICPROJECTION

#include "Rasterization.h"
#include "Scene.h"
#include "Screen.h"
#include "ZBuffer.h"
#include "CameraScreen.h"
#include "Object3DRenderer.h"

class OrthographicProjection: public Rasterization
{
public:
	OrthographicProjection();
	virtual ~OrthographicProjection();

protected:
	virtual void drawObject(Object3DRenderer * object3DRenderer, Zone & renderingZone);
	RGBColor getColor(Object3DRenderer * object3DRenderer, P3 & surfPoint);
	//Zone sceneToScreenZone(Zone zone);
};

#endif
