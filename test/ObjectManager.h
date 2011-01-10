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
	void add(std::string name, T obj, std::string type);
	T get(std::string name);
	std::string getType(T obj);
	void Delete(std::string name);
	void deleteAll();

protected:
	std::map<std::string, T> objects;
	std::map<T, std::string> types;
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
	types.clear();
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
void ObjectManager<T>::add(std::string name, T obj, std::string type) {
	this->add(name, obj);
	types[obj] = type;
}

template<typename T>
T ObjectManager<T>::get(std::string name) {
	if(objects.find(name) == objects.end())
		return NULL;
	else return objects[name];
}

template<typename T>
std::string ObjectManager<T>::getType(T obj) {
	return types[obj];
}

template<typename T> 
void ObjectManager<T>::Delete(std::string name) {
	T obj = objects[name];
	if(types.find(obj) != types.end()) {
		types.erase(obj);
	}
	objects.erase(name);

}


#endif