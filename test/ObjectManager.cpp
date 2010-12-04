#include "stdafx.h"

#include "ObjectManager.h"

template<class T>
ObjectManager<T>::ObjectManager() {
}

template<class T>
ObjectManager<T>::~ObjectManager() {
	deleteAll();
}

template<class T> 
void ObjectManager<T>::deleteAll() {
	objects.clear();
}

template<class T>
std::vector<std::string> ObjectManager<T>::getNames() {
	std::vector<std::string> keys;
	for(std::map<std::string, T >::iterator it = objects.begin(); it != objects.end(); it++) {
	  keys.push_back(it->first);
	}
	return keys;
}

template<class T> 
void ObjectManager<T>::add(std::string name, T obj) {
	if(objects.find(objectName) != objects.end())
		delete objects[objectName];
	objects[objectName] = obj;
}

template<class T>
T ObjectManager<T>::get(std::string name) {
	if(objects.find(name) == objects.end())
		return NULL;
	else return objects[name];
}

template<class T> 
void ObjectManager<T>::Delete(std::string name) { 
	objects.erase(name);
}

