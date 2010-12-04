#ifndef _H_MANAGER
#define _H_MANAGER

#include "ObjectManager.h"
#include "Object3D.h"
#include "Polyhedron.h"
#include "LightSource.h"
#include "Camera.h"
#include "Texture.h"
#include "Model.h"

class Manager
{
public:
	Manager();
	~Manager();
	void deleteAll();

	ObjectManager<Object3D*> * getObjects3D();
	ObjectManager<Polyhedron*> * getPolyhedra();
	ObjectManager<LightSource*> * getLightSources();
	ObjectManager<Camera*> * getCameras();
	ObjectManager<Texture*> * getTextures();
	ObjectManager<Model*> * getModels();

private:
	ObjectManager<Object3D*> * objects3D;
	ObjectManager<Polyhedron*> * polyhedra;
	ObjectManager<LightSource*> * lights;
	ObjectManager<Camera*> * cameras;
	ObjectManager<Texture*> * textures;
	ObjectManager<Model*> * models;
};

#endif