#ifndef _H_OBJECTMANAGER
#define _H_OBJECTMANAGER

#include <vector>
#include <string>
#include <map>

template < typename T > class ObjectManager
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

#endif