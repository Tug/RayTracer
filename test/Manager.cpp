#include "stdafx.h"

#include "Manager.h"

Manager::Manager() {
	objects3D = new ObjectManager<Object3D*>();
	polyhedra = new ObjectManager<Polyhedron*>();
	lights = new ObjectManager<LightSource*>();
	cameras = new ObjectManager<Camera*>();
	textures = new ObjectManager<Texture*>();
	models = new ObjectManager<Model*>();
}

Manager::~Manager() {
	delete objects3D;
	delete polyhedra;
	delete lights;
	delete cameras;
	delete textures;
	delete models;
}

void Manager::deleteAll() {
	objects3D->deleteAll();
	polyhedra->deleteAll();
	lights->deleteAll();
	cameras->deleteAll();
	textures->deleteAll();
	models->deleteAll();
}

ObjectManager<Object3D*> * Manager::getObjects3D() { return objects3D; }
ObjectManager<Polyhedron*> * Manager::getPolyhedra() { return polyhedra; }
ObjectManager<LightSource*> * Manager::getLightSources() { return lights; }
ObjectManager<Camera*> * Manager::getCameras() { return cameras; }
ObjectManager<Texture*> * Manager::getTextures() { return textures; }
ObjectManager<Model*> * Manager::getModels() { return models; }

