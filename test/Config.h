#ifndef _H_CONFIG
#define _H_CONFIG

#include "jsoncpp/json.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Scene.h"
#include "LightSource.h"
#include "AmbientLightSource.h"
#include "PointLightSource.h"
#include "SceneRenderer.h"
#include "Model.h"
#include "SphereModel.h"
#include "PlaneModel.h"
#include "CameraScreen.h"
#include "RenderingMethod.h"
#include "OrthographicProjection.h"
#include "RayCasting.h"
#include "RayTracing.h"
#include "Screen.h"
#include "Object3DRenderer.h"
#include "Manager.h"
#include "RGBColor.h"
#include "Object3D.h"
#include "Sphere.h"
#include "Plane.h"
#include "Polyhedron.h"
#include "Parallelepiped.h"
#include "PolyhedronModel.h"
#include "ParallelepipedModel.h"
#include "Triangle.h"

class Config
{
public:
	Config(std::string fileName);
	~Config();
	void load(SceneRenderer * sceneRenderer, Manager * objectManager);
	
private:
	std::string fileName;
	P3 jsonToP3(Json::Value & p3JSON);
	RGBColor jsonToColor(Json::Value & colorJSON);
	Material jsonToMaterial(Json::Value & materialJSON);
	bool parseObjFile(std::string & filename, std::vector<Triangle*> * triangles, P3 & centerObj, double scale);
};

#endif