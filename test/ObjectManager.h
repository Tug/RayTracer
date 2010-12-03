
#ifndef _H_OBJECTMANAGER
#define _H_OBJECTMANAGER

#include "Object3D.h"
#include "LightSource.h"
#include "Camera.h"
#include "Texture.h"
#include <string>
#include <map>

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	std::vector<std::string> getObjects3DNames();
	std::vector<std::string> getLightSourcesNames();
	std::vector<std::string> getCamerasNames();
	std::vector<std::string> getTexturesNames();
	std::vector<std::string> getOthersNames();
	
	void addObject3D(std::string objectName, Object3D * obj);
	void addLightSource(std::string lightName, LightSource * light);
	void addCamera(std::string camName, Camera * cam);
	void addTexture(std::string textureName, Texture * texture);
	void add(std::string name, void * obj);

	Object3D * getObject3D(std::string object3DName);
	LightSource * getLightSource(std::string lightName);
	Camera * getCamera(std::string camName);
	Texture * getTexture(std::string textureName);
	void * get(std::string name);

	void deleteObject3D(std::string objName);
	void deleteLight(std::string lightName);
	void deleteCamera(std::string camName);
	void deleteTexture(std::string textureName);
	void Delete(std::string name);

	void deleteAll();

protected:
	std::map<std::string, Object3D* > objects;
	std::map<std::string, LightSource* > lights;
	std::map<std::string, Camera* > cameras;
	std::map<std::string, Texture* > textures;
	std::map<std::string, void* > others;
};

#endif