#ifndef _H_MANAGER
#define _H_MANAGER

#include "ObjectManager.h"
#include "Object3D.h"
#include "Polyhedron.h"
#include "LightSource.h"
#include "Camera.h"
#include "Texture.h"
#include "Model.h"

class Manager : public ObjectManager<void*>
{
public:
	Manager() {
		add("Object3D", new ObjectManager<Object3D*>());
		add("Polyhedron", new ObjectManager<Polyhedron*>());
		add("LightSource", new ObjectManager<LightSource*>());
		add("Camera", new ObjectManager<Camera*>());
		add("Texture", new ObjectManager<Texture*>());
		add("Model", new ObjectManager<Model*>());
	}

};

#endif