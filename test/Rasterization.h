#ifndef _H_RASTERIZATION
#define _H_RASTERIZATION

#include "RenderingMethod.h"
#include "Scene.h"
#include "Screen.h"
#include "CameraScreen.h"
#include "SceneRenderer.h"

class Rasterization: public RenderingMethod
{
public:
	Rasterization();
	virtual ~Rasterization();
	virtual void drawScene(SceneRenderer * sceneRenderer, Zone & renderingZone);

protected:
	virtual void drawObject(Object3DRenderer * object3DRenderer, Zone & rendereringZone) = 0;
	ZBuffer * zbuffer;
};

#endif
