#include "stdafx.h"

#include "ObjectManager.h"

ObjectManager::ObjectManager() {

}

ObjectManager::~ObjectManager() {
	for(std::map<std::string, void*>::iterator it = objects.begin(); it != objects.end(); it++) {
		void* obj = (*it).second;
		delete obj;
	}
}

void ObjectManager::addObject(std::string objectName, void * obj) {
	if(objects.find(objectName) != objects.end())
		delete objects[objectName];
	objects[objectName] = obj;
}

void ObjectManager::deleteObject(std::string objectName) {
	delete objects[objectName];
	objects.erase(objectName);
}

void * ObjectManager::getObject(std::string objectName) {
	if(objects.find(objectName) == objects.end())
		return NULL;
	else return objects[objectName];
}