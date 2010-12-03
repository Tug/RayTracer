
#ifndef _H_OBJECTMANAGER
#define _H_OBJECTMANAGER

#include <string>
#include <map>

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();
	void addObject(std::string objectName, void * obj);
	void * getObject(std::string objectName);
	void deleteObject(std::string objectName);
	void deleteAll();

protected:
	std::map<std::string, void* > objects;
};

#endif