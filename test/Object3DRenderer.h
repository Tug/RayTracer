#ifndef _H_OBJECT3DRENDERER
#define _H_OBJECT3DRENDERER

#include "Model.h"
#include "P3.h"
#include "Object3D.h"
#include "Scene.h"
#include "CameraScreen.h"

class Object3DRenderer
{
public:
	Object3DRenderer(Object3D * object3D, Scene * scene, CameraScreen * cameraScreen);
	virtual ~Object3DRenderer();
	void setModel(Model * model);
	Object3D * getObject3D();
	Model * getModel();
	Scene * getScene();
	CameraScreen * getCameraScreen();

protected:
	Object3D * object3D;
	Model * model;
	Scene * scene;
	CameraScreen * cameraScreen;
	P3 observerPosition;
};


#endif