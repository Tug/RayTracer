#ifndef _H_RAYTRACING
#define _H_RAYTRACING

#include "RenderingMethod.h"
#include "Scene.h"
#include "Screen.h"
#include "CameraScreen.h"
#include "SceneRenderer.h"
#include "RGBColor.h"

class RayTracing: public RenderingMethod
{
public:
	RayTracing();
	virtual ~RayTracing();
	virtual void drawScene(SceneRenderer * sceneRenderer, Zone & renderingZone);
	bool intersectObject(std::vector<Object3D *> & objects, Ray & ray, Object3D ** closestObj, double * yMin);

protected:
	RGBColor throwRay(SceneRenderer * sceneRenderer, Ray & ray, int depth);
	int maxDepth;
};

#endif

