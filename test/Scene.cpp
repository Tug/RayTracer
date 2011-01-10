#include "stdafx.h"

#include "Scene.h"

Scene::Scene() {
	this->backgroundColor = RGBColor(0,0,0);
}

Scene::~Scene() {
	removeAll();
}

void Scene::addLightSource(LightSource * lightSource) {
	lights.push_back(lightSource);
}


void Scene::addObject3D(Object3D * object3D) {
	objects.push_back(object3D);
}

void Scene::addObjects3D(std::vector<Object3D *> & objects3D) {
	for(std::vector<Object3D *>::iterator it = objects3D.begin(); it != objects3D.end(); it++) {
		addObject3D(*it);
	}
}

void Scene::addLightSources(std::vector<LightSource *> & lightsources) {
	for(std::vector<LightSource *>::iterator it = lightsources.begin(); it != lightsources.end(); it++) {
		addLightSource(*it);
	}
}

std::vector<LightSource *> & Scene::getLightSources() {
	return lights;
}

std::vector<Object3D *> & Scene::getObjects3D() {
	return objects;
}

void Scene::removeAllObjects3D() {
	objects.clear();
}

void Scene::removeAllLightSources() {
	lights.clear();
}

void Scene::removeAll() {
	removeAllObjects3D();
	removeAllLightSources();
}


RGBColor & Scene::getBackgroundColor() {
	return backgroundColor;
}

void Scene::setBackgroundColor(RGBColor & color) {
	this->backgroundColor = color;
}

