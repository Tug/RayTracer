#ifndef _H_SCENERENDERER
#define _H_SCENERENDERER

#include "Screen.h"
#include "Texture.h"
#include "Sphere.h"
#include "WinScreen.h"
#include "LightSource.h"
#include "AmbientLightSource.h"
#include "PointLightSource.h"
#include "Camera.h"
#include "CameraScreen.h"
#include "Scene.h"
#include "RenderingMethod.h"
#include "Object3DRenderer.h"
#include <stdio.h>
#include <map>

class RenderingMethod;

class SceneRenderer
{
public:
	SceneRenderer(SceneRenderer * sceneRenderer);
	SceneRenderer(Screen * screen);
	~SceneRenderer();
	void render();
	void render(Zone & renderingZone);
	void moveCamera(double dx, double dy, double dz, double du, double dv);
	Object3DRenderer * getObject3DRenderer(Object3D* object3D);
	void initObject3DRenderers();
	void deleteObject3DRenderers();
	void reset();

	Scene * getScene();
	void setScene(Scene * scene);
	Camera * getCamera();
	void setCamera(Camera * camera);
	double getCameraScreenDist();
	void setCameraScreenDist(double dist);
	CameraScreen * getCameraScreen();
	RenderingMethod * getRenderingMethod();
	void setRenderingMethod(RenderingMethod * renderingMethod);

private:
	Scene * scene;
	Screen * screen;
	Camera * camera;
	double cameraScreenDist;
	std::map<Object3D*, Object3DRenderer*> renderersMap;
	CameraScreen * cameraScreen;
	RenderingMethod * renderingMethod;
};

#endif