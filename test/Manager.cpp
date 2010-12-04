#include "stdafx.h"

#include "Manager.h"

Manager::Manager() {
	this->objManagers = new ObjectManager<void*>();
	this->objManagers->add("Object3D", new ObjectManager<Object3D*>());
	this->objManagers->add("Polyhedron", new ObjectManager<Polyhedron*>());
	this->objManagers->add("LightSource", new ObjectManager<LightSource*>());
	this->objManagers->add("Camera", new ObjectManager<Camera*>());
	this->objManagers->add("Texture", new ObjectManager<Texture*>());
	this->objManagers->add("Model", new ObjectManager<Model*>());
}

Manager::~Manager() {
	delete objManagers;
}

