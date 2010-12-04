#include "stdafx.h"

#include "ObjectManager.h"

ObjectManager::ObjectManager() {
}

ObjectManager::~ObjectManager() {
	deleteAll();
}

void ObjectManager::deleteAll() {
	objects.clear();
}

std::vector<std::string> ObjectManager::getNames() {
	std::vector<std::string> keys;
	for(std::map<std::string, T >::iterator it = objects.begin(); it != objects.end(); it++) {
	  keys.push_back(it->first);
	}
	return keys;
}

void ObjectManager::add(std::string name, T obj) {
	if(objects.find(objectName) != objects.end())
		delete objects[objectName];
	objects[objectName] = obj;
}

T ObjectManager::get(std::string name) {
	if(objects.find(name) == objects.end())
		return NULL;
	else return objects[name];
}

void ObjectManager::Delete(std::string name) { 
	objects.erase(name);
}

