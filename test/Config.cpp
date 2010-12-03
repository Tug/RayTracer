#include "stdafx.h"

#include "Config.h"


Config::Config(std::string fileName) {
	this->fileName = fileName;
}

Config::~Config() {
}

void Config::load(SceneRenderer * sceneRenderer, ObjectManager * objectManager) {
    Json::Value root;   // will contains the root value after parsing.
	Json::Reader reader;

	std::ifstream file;
	file.open(fileName);
    bool parsingSuccessful = reader.parse(file, root, false);
	file.close();
	if(!parsingSuccessful) {
		// report to the user the failure and their locations in the document.
		System::Console::WriteLine("Failed to parse configuration\n");
		System::Console::WriteLine(gcnew System::String(reader.getFormatedErrorMessages().c_str()));
		throw std::runtime_error("Failed to parse configuration file: "+fileName);
	}

	Json::Value sceneJSON = root.get("scene", NULL);
	Scene * scene = sceneRenderer->getScene();
	Json::Value bgColorJSON = sceneJSON.get("backgroundColor", NULL);
	if(bgColorJSON != NULL) {
		scene->setBackgroundColor(jsonToColor(bgColorJSON));
	}

	Json::Value lightsJSON = sceneJSON.get("lights", NULL);
	if(lightsJSON != NULL) {
		Json::Value::Members lightsName = lightsJSON.getMemberNames();
		for(std::vector<std::string>::iterator it = lightsName.begin(); it != lightsName.end(); it++) {
			std::string lightName = *it;
			Json::Value lightJSON = lightsJSON[lightName];
			Color lightColor = jsonToColor(lightJSON["color"]);
			LightSource * light;
			if(lightJSON["type"].asString() == "AmbientLightSource") {
				light = new AmbientLightSource(lightColor);
			} else if(lightJSON["type"].asString() == "PointLightSource") {
				light = new PointLightSource(jsonToP3(lightJSON["position"]), lightColor);
				Json::Value specularCoefJSON = lightJSON.get("specularCoef", NULL);
				PointLightSource * pLight = static_cast<PointLightSource*>(light);
				if(specularCoefJSON != NULL) {
					pLight->setSpecularCoef(specularCoefJSON.asDouble());
				}
				Json::Value specularExpJSON = lightJSON.get("specularExponent", NULL);
				if(specularExpJSON != NULL) {
					pLight->setSpecularExponent(specularExpJSON.asDouble());
				}
			}
			Json::Value diffuseCoefJSON = lightJSON.get("diffuseCoef", NULL);
			if(diffuseCoefJSON != NULL) {
				light->setDiffuseCoef(diffuseCoefJSON.asDouble());
			}
			scene->addLightSource(light);
			objectManager->addLightSource(lightName, light);
		}
	}

	Json::Value objectsJSON = sceneJSON.get("objects", NULL);
	if(objectsJSON != NULL) {
		Json::Value::Members objectsName = objectsJSON.getMemberNames();
		for(std::vector<std::string>::iterator it = objectsName.begin(); it != objectsName.end(); it++) {
			std::string objectName = *it;
			Json::Value object3DJSON = objectsJSON[objectName];
			Object3D * object3D;
			std::string oject3DTypeStr = object3DJSON["type"].asString();
			if(oject3DTypeStr == "Sphere") {
				object3D = new Sphere(jsonToP3(object3DJSON["center"]),
									  object3DJSON["radius"].asDouble());
			} else if(oject3DTypeStr == "Plane") {
				
				if(object3DJSON.get("u", NULL) != NULL) {
					object3D = new Plane(jsonToP3(object3DJSON["p"]),
									 jsonToP3(object3DJSON["u"]),
									 jsonToP3(object3DJSON["v"]));
				} else {
					object3D = new Plane(jsonToP3(object3DJSON["p"]),
										 jsonToP3(object3DJSON["normal"]));
				}
			} else if(oject3DTypeStr == "Triangle") {
				object3D = new Triangle(jsonToP3(object3DJSON["A"]),
									    jsonToP3(object3DJSON["B"]),
										jsonToP3(object3DJSON["C"]));
			}
			scene->addObject3D(object3D);
			objectManager->addObject3D(objectName, object3D);
		}
	}

	Json::Value polyhedraJSON = sceneJSON.get("polyhedra", NULL);
	if(polyhedraJSON != NULL) {
		Json::Value::Members polyhedraName = polyhedraJSON.getMemberNames();
		for(std::vector<std::string>::iterator it = polyhedraName.begin(); it != polyhedraName.end(); it++) {
			std::string objectName = *it;
			Json::Value polyhedronJSON = polyhedraJSON[objectName];
			Polyhedron * polyhedron;
			std::string polyhedronTypeStr = polyhedronJSON["type"].asString();
			if(polyhedronTypeStr == "Parallelepiped") {
				polyhedron = new Parallelepiped(jsonToP3(polyhedronJSON["A"]),
												jsonToP3(polyhedronJSON["B"]),
												jsonToP3(polyhedronJSON["C"]),
												jsonToP3(polyhedronJSON["D"]));
			} else if(polyhedronTypeStr == "Maya") {
				std::vector<Triangle*> triangles;
				std::string filename = polyhedronJSON["FileName"].asString();
				Json::Value pJSON = polyhedronJSON.get("p", NULL);
				P3 centerObj(0,0,0);
				if(pJSON != NULL) centerObj = jsonToP3(polyhedronJSON["p"]);
				Json::Value scaleJSON = polyhedronJSON.get("scale", NULL);
				double scale = 1.0;
				if(scaleJSON != NULL) scale = scaleJSON.asDouble();
				parseObjFile(filename, &triangles, centerObj, scale);
				polyhedron = new Polyhedron(triangles);
			} else continue;
			std::vector<Triangle*> triangles = polyhedron->getTriangles();
			for(std::vector<Triangle*>::iterator it = triangles.begin(); it != triangles.end(); it++) {
				scene->addObject3D(*it);
			}
			objectManager->addObject3D(objectName, polyhedron);
		}
	}

	Json::Value texturesJSON = root.get("textures", NULL);
	if(texturesJSON != NULL) {
		Json::Value::Members texturesName = texturesJSON.getMemberNames();
		for(std::vector<std::string>::iterator it = texturesName.begin(); it != texturesName.end(); it++) {
			std::string textureName = *it;
			Json::Value textureJSON = texturesJSON[textureName];
			Texture * texture = new Texture(textureJSON["FileName"].asString().c_str());
			objectManager->addTexture(textureName, texture);
		}
	}

	Json::Value sceneRendererJSON = root.get("sceneRenderer", NULL);
	if(sceneRendererJSON == NULL) 
		throw std::runtime_error("sceneRenderer not defined in "+fileName);
	Json::Value cameraJSON = sceneRendererJSON["camera"];
	Camera * camera = new Camera(jsonToP3(cameraJSON["position"]),
								 jsonToP3(cameraJSON["direction"]),
								 cameraJSON.get("rotation", 0).asDouble());
	sceneRenderer->setCamera(camera);
	sceneRenderer->setCameraScreenDist(sceneRendererJSON.get("cameraScreenDist", 200).asDouble());
	objectManager->addCamera("camera1", camera);

	std::string methodType = sceneRendererJSON["method"].get("type", "OrthographicProjection").asString();
	RenderingMethod * renderingMethod;
	if(methodType == "OrthographicProjection") {
		renderingMethod = new OrthographicProjection();
	} else if(methodType == "RayCasting") {
		renderingMethod = new RayCasting();
	} else if(methodType == "RayTracing") {
		renderingMethod = new RayTracing();
	} else throw std::runtime_error("renderingMethod not defined in "+fileName);
	sceneRenderer->setRenderingMethod(renderingMethod);
	Json::Value modelsJSON = sceneRendererJSON.get("models", NULL);
	if(modelsJSON != NULL) {
		Json::Value::Members objectsName = modelsJSON.getMemberNames();
		for(std::vector<std::string>::iterator it = objectsName.begin(); it != objectsName.end(); it++) {
			std::string objectName = *it;
			Json::Value modelJSON = modelsJSON[objectName];
			Json::Value modelTypeJSON = modelJSON.get("type", NULL);
			if(modelTypeJSON != NULL) {
				std::string modelTypeStr = modelTypeJSON.asString();
				Object3D * object3D = objectManager->getObject3D(objectName);
				if(object3D == NULL) continue;
				Model * model;
				if( modelTypeStr == "SphereModel" 
				 || modelTypeStr == "PlaneModel"
				 || modelTypeStr == "TriangleModel") {
					if(modelTypeStr == "SphereModel") {
						model = new SphereModel();
					} else {
						model = new PlaneModel();
					}
					sceneRenderer->getObject3DRenderer(object3D)->setModel(model);
				} else if(modelTypeStr == "PolyhedronModel"
					   || modelTypeStr == "ParallelepipedModel"
					   || modelTypeStr == "MayaModel") {
					Polyhedron * polyhedron = static_cast<Polyhedron*>(object3D);
					if(modelTypeStr == "PolyhedronModel") {
						model = new PolyhedronModel(polyhedron);
					} else {

					}
					std::vector<Triangle*> triangles = polyhedron->getTriangles();
					for(std::vector<Triangle*>::iterator it = triangles.begin(); it != triangles.end(); it++) {
						sceneRenderer->getObject3DRenderer(*it)->setModel(model);
					}
				}
				Json::Value textureJSON = modelJSON.get("texture", NULL);
				if(textureJSON != NULL) {
					model->setTexture(objectManager->getTexture(textureJSON.asString()));
				}
				Json::Value colorJSON = modelJSON.get("color", NULL);
				if(colorJSON != NULL) {
					model->setColor(jsonToColor(colorJSON));
				}
				Json::Value bumpJSON = modelJSON.get("bump", NULL);
				if(bumpJSON != NULL) {
					model->setBump(objectManager->getTexture(bumpJSON.asString()));
				}
				Json::Value materialJSON = modelJSON.get("material", NULL);
				if(materialJSON != NULL) {
					model->setMaterial(jsonToMaterial(materialJSON));
				}
				Json::Value textureScaleJSON = modelJSON.get("textureScale", NULL);
				if(textureScaleJSON != NULL) {
					model->setTextureScale(textureScaleJSON.asDouble());
				}
				objectManager->add(objectName+"Model", model);
			}
		}
	}
}

P3 Config::jsonToP3(Json::Value & p3JSON) {
	return P3(p3JSON["x"].asDouble(),
			  p3JSON["y"].asDouble(),
			  p3JSON["z"].asDouble());
}

Color Config::jsonToColor(Json::Value & colorJSON) {
	if(colorJSON.isString()) {
		return Color::commonColor(colorJSON.asString());
	}
	return Color(colorJSON["m_R"].asDouble(),
			     colorJSON["m_G"].asDouble(),
			     colorJSON["m_B"].asDouble());
}

Material Config::jsonToMaterial(Json::Value & materialJSON) {
	return Material(materialJSON["reflectivity"].asDouble(),
					materialJSON["transmittance"].asDouble(),
					materialJSON["refractiveIndex"].asDouble());
}

struct Face {
	int V1;
	int V2;
	int V3;
};

bool Config::parseObjFile(std::string & filename, std::vector<Triangle*> * triangles, P3 & centerObj, double scale)
{
	std::vector<P3> vertices;
	std::vector<struct Face> faces;
	std::ifstream ifstream(filename.c_str());
	std::string line;

	// inspired by libobj
	while (!ifstream.eof() && std::getline(ifstream, line)) {
		std::istringstream stringstream(line);
		stringstream.unsetf(std::ios_base::skipws);
		std::string keyword;
		stringstream >> keyword;

		// vertices
		if (keyword == "v") {
			double x, y, z;
			char whitespace_v_x, whitespace_x_y, whitespace_y_z;
			stringstream >> whitespace_v_x >> std::ws >> x >> whitespace_x_y >> std::ws >> y >> whitespace_y_z >> std::ws >> z >> std::ws;
			vertices.push_back(P3(centerObj.x+scale*x,centerObj.y+scale*y,centerObj.z+scale*z));
		}
		// faces
		else if (keyword == "f") {
			struct Face face;
			char whitespace_f_v1;
			stringstream >> whitespace_f_v1 >> std::ws >> face.V1;
			if(stringstream.peek() == ' ') {
			  // f v
			  char whitespace_v1_v2, whitespace_v2_v3;
			  stringstream >> whitespace_v1_v2 >> std::ws >> face.V2 >> whitespace_v2_v3 >> std::ws >> face.V3;
			  char whitespace_v3_v4 = ' ';
			  if (!stringstream.eof()) {
				stringstream >> whitespace_v3_v4 >> std::ws;
			  }
			} else {
				char slash_v1_vt1;
				stringstream >> slash_v1_vt1;
				if(stringstream.peek() != '/') {
					int vt1;
					stringstream >> vt1;
					if(stringstream.peek() == ' ') {
						// f v/vt
						int vt2, vt3;
						char whitespace_vt1_v2, slash_v2_vt2, whitespace_vt2_v3, slash_v3_vt3;
						stringstream >> whitespace_vt1_v2 >> std::ws >> face.V2 >> slash_v2_vt2 >> vt2 >> whitespace_vt2_v3 >> std::ws >> face.V3 >> slash_v3_vt3 >> vt3;
						char whitespace_vt3_v4 = ' ';
						if (!stringstream.eof()) {
							stringstream >> whitespace_vt3_v4 >> std::ws;
						}
					} else {
						// f v/vt/vn
						int vn1, vt2, vn2, vt3, vn3;
						char slash_vt1_vn1, whitespace_vn1_v2, slash_v2_vt2, slash_vt2_vn2, whitespace_vn2_v3, slash_v3_vt3, slash_vt3_vn3;
						stringstream >> slash_vt1_vn1 >> vn1 >> whitespace_vn1_v2 >> std::ws >> face.V2 >> slash_v2_vt2 >> vt2 >> slash_vt2_vn2 >> vn2 >> whitespace_vn2_v3 >> std::ws >> face.V3 >> slash_v3_vt3 >> vt3 >> slash_vt3_vn3 >> vn3;
						char whitespace_vn3_v4 = ' ';
						if (!stringstream.eof()) {
							stringstream >> whitespace_vn3_v4 >> std::ws;
						}
					}
				} else {
					// f v//vn
					int vn1, vn2, vn3;
					char slash_vt1_vn1, whitespace_vn1_v2, slash_v2_vt2, slash_vt2_vn2, whitespace_vn2_v3, slash_v3_vt3, slash_vt3_vn3;
					stringstream >> slash_vt1_vn1 >> vn1 >> whitespace_vn1_v2 >> std::ws >> face.V2 >> slash_v2_vt2 >> slash_vt2_vn2 >> vn2 >> whitespace_vn2_v3 >> std::ws >> face.V3 >> slash_v3_vt3 >> slash_vt3_vn3 >> vn3;
					char whitespace_vn3_v4 = ' ';
					if (!stringstream.eof()) {
					  stringstream >> whitespace_vn3_v4 >> std::ws;
					}
				}
			}
			if(stringstream.eof()) {
				faces.push_back(face);
			}
		} 
	}
	for(std::vector<struct Face>::iterator it = faces.begin(); it != faces.end(); it++) {
		struct Face face = *it;
		triangles->push_back(new Triangle(vertices[face.V1-1], vertices[face.V2-1], vertices[face.V3-1]));
	}
	return true;
}
