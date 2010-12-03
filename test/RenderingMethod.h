#ifndef _H_RENDERINGMETHOD
#define _H_RENDERINGMETHOD

#include "Scene.h"
#include "Screen.h"
#include "CameraScreen.h"
#include "SceneRenderer.h"

class SceneRenderer;

class RenderingMethod
{
public:
	RenderingMethod() { }
	virtual ~RenderingMethod() { }
	virtual void drawScene(SceneRenderer * sceneRenderer, Zone & renderingZone) = 0;

};

#endif

