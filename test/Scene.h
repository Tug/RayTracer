#ifndef _H_SCENE
#define _H_SCENE

class Object3D;
class LightSource;

#include "Camera.h"
#include "LightSource.h"
#include "Object3D.h"
#include <math.h>
#include <vector>

class Scene
{
public:
	Scene();
	~Scene();
	void addLightSource(LightSource * lightSource);
	void addObject3D(Object3D * object3D);
	void addObjects3D(std::vector<Object3D *> & objects3D);
	void addLightSources(std::vector<LightSource *> & lightsources);
	std::vector<LightSource *> & getLightSources();
	std::vector<Object3D *> & getObjects3D();
	void removeAllObjects3D();
	void removeAllLightSources();
	void removeAll();
	Color & getBackgroundColor();
	void setBackgroundColor(Color & color);

private:
	std::vector<LightSource *> lights;
	std::vector<Object3D *> objects;
	Color backgroundColor;
};


#endif