#ifndef _H_RAYCASTING
#define _H_RAYCASTING

#include "RenderingMethod.h"
#include "Scene.h"
#include "Screen.h"
#include "CameraScreen.h"
#include "SceneRenderer.h"

class RayCasting: public RenderingMethod
{
public:
	RayCasting();
	virtual ~RayCasting();
	virtual void drawScene(SceneRenderer * sceneRenderer, Zone & renderingZone);
	bool intersectObject(std::vector<Object3D *> & objects, Ray & ray, Object3D ** closestObj, double * yMin);
};

#endif