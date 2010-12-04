#ifndef _H_OBJECTMANAGER
#define _H_OBJECTMANAGER

#include <vector>
#include <string>
#include <map>

template<typename T> class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	std::vector<std::string> getNames();
	void add(std::string name, T obj);
	T get(std::string name);
	void Delete(std::string name);
	void deleteAll();

protected:
	std::map<std::string, T > objects;
};



template<typename T>
ObjectManager<T>::ObjectManager() {
}

template<typename T>
ObjectManager<T>::~ObjectManager() {
	deleteAll();
}

template<typename T> 
void ObjectManager<T>::deleteAll() {
	objects.clear();
}

template<typename T>
std::vector<std::string> ObjectManager<T>::getNames() {
	std::vector<std::string> keys;
	for(std::map<std::string, T>::iterator it = objects.begin(); it != objects.end(); it++) {
	  keys.push_back(it->first);
	}
	return keys;
}

template<typename T> 
void ObjectManager<T>::add(std::string name, T obj) {
	if(objects.find(name) != objects.end())
		delete objects[name];
	objects[name] = obj;
}

template<typename T>
T ObjectManager<T>::get(std::string name) {
	if(objects.find(name) == objects.end())
		return NULL;
	else return objects[name];
}

template<typename T> 
void ObjectManager<T>::Delete(std::string name) { 
	objects.erase(name);
}


#endif