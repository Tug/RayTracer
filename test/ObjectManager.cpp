#include "stdafx.h"

#include "ObjectManager.h"

ObjectManager::ObjectManager() {
}

ObjectManager::~ObjectManager() {
	deleteAll();
}

void ObjectManager::deleteAll() {
	objects.clear();
	lights.clear();
	cameras.clear();
	textures.clear();
	others.clear();
}


std::vector<std::string> ObjectManager::getObjects3DNames() {
	std::vector<std::string> keys;
	for(std::map<std::string, Object3D* >::iterator it = objects.begin(); it != objects.end(); it++) {
	  keys.push_back(it->first);
	}
	return keys;
}

std::vector<std::string> ObjectManager::getLightSourcesNames() {
	std::vector<std::string> keys;
	for(std::map<std::string, LightSource* >::iterator it = lights.begin(); it != lights.end(); it++) {
	  keys.push_back(it->first);
	}
	return keys;
}

std::vector<std::string> ObjectManager::getCamerasNames() {
	std::vector<std::string> keys;
	for(std::map<std::string, Camera* >::iterator it = cameras.begin(); it != cameras.end(); it++) {
	  keys.push_back(it->first);
	}
	return keys;
}

std::vector<std::string> ObjectManager::getTexturesNames() {
	std::vector<std::string> keys;
	for(std::map<std::string, Texture* >::iterator it = textures.begin(); it != textures.end(); it++) {
	  keys.push_back(it->first);
	}
	return keys;
}

std::vector<std::string> ObjectManager::getOthersNames() {
	std::vector<std::string> keys;
	for(std::map<std::string, void* >::iterator it = others.begin(); it != others.end(); it++) {
	  keys.push_back(it->first);
	}
	return keys;
}



void ObjectManager::addObject3D(std::string objectName, Object3D * obj) {
	if(objects.find(objectName) != objects.end())
		delete objects[objectName];
	objects[objectName] = obj;
}

void ObjectManager::addLightSource(std::string lightName, LightSource * light) {
	if(lights.find(lightName) != lights.end())
		delete lights[lightName];
	lights[lightName] = light;
}

void ObjectManager::addCamera(std::string camName, Camera * cam) {
	if(cameras.find(camName) != cameras.end())
		delete cameras[camName];
	cameras[camName] = cam;
}

void ObjectManager::addTexture(std::string textureName, Texture * texture) {
	if(textures.find(textureName) != textures.end())
		delete textures[textureName];
	textures[textureName] = texture;
}

void ObjectManager::add(std::string name, void * obj) {
	if(others.find(name) != others.end())
		delete others[name];
	others[name] = obj;
}


Object3D * ObjectManager::getObject3D(std::string object3DName) {
	if(objects.find(object3DName) == objects.end())
		return NULL;
	else return objects[object3DName];
}

LightSource * ObjectManager::getLightSource(std::string lightName) {
	if(lights.find(lightName) == lights.end())
		return NULL;
	else return lights[lightName];
}

Camera * ObjectManager::getCamera(std::string camName) {
	if(cameras.find(camName) == cameras.end())
		return NULL;
	else return cameras[camName];
}

Texture * ObjectManager::getTexture(std::string textureName) {
	if(textures.find(textureName) == textures.end())
		return NULL;
	else return textures[textureName];
}

void * ObjectManager::get(std::string name) {
	if(others.find(name) == others.end())
		return NULL;
	else return others[name];
}


void ObjectManager::deleteObject3D(std::string objectName) {
	objects.erase(objectName);
}

void ObjectManager::deleteLight(std::string lightName) {
	lights.erase(lightName);
}

void ObjectManager::deleteCamera(std::string camName) {
	cameras.erase(camName);
}

void ObjectManager::deleteTexture(std::string textureName) {
	textures.erase(textureName);
}

void ObjectManager::Delete(std::string name){
	others.erase(name);
}
