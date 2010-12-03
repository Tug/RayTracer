#include "stdafx.h"

#include "Texture.h"
#include "Sphere.h"
#include "WinScreen.h"
#include "LightSource.h"
#include "AmbientLightSource.h"
#include "PointLightSource.h"
#include "Camera.h"
#include "SceneRenderer.h"
#include "OrthographicProjection.h"
#include "RayCasting.h"
#include "RayTracing.h"
#include "ObjectManager.h"
#include "Config.h"
#include <stdio.h>

// LAB STARTS HERE

void myProject(Screen * screen)
{
	ObjectManager * manager = new ObjectManager();
	Config config("config/default.txt");
	System::Console::WriteLine("Loading config...");
	SceneRenderer * sceneRenderer = new SceneRenderer(screen);
	config.load(sceneRenderer, manager);
	System::Console::WriteLine("Finished!");
	sceneRenderer->render();
	delete sceneRenderer;
	delete manager;

	/*
	float rayon = 100;
	System::Console::WriteLine("Starting...");
	Sphere * sphere1 = new Sphere(250,300,200,rayon);
	Sphere * sphere2 = new Sphere(470,300,200,rayon);
	Sphere * sphere3 = new Sphere(200,730,220,rayon/2);
	System::Console::WriteLine("Creating scene...");
	LightSource * ambientLight = new AmbientLightSource(Color(1,1,1));
	LightSource * pointLight = new PointLightSource(P3(600,0,200), Color(1,1,1));
	LightSource * pointLight2 = new PointLightSource(P3(0,720,200), Color(1,1,1));
	Scene * scene = new Scene();
	scene->addLightSource(ambientLight);
	scene->addLightSource(pointLight);
	scene->addLightSource(pointLight2);
	scene->addObject3D(sphere1);
	scene->addObject3D(sphere2);
	scene->addObject3D(sphere3);
	CameraScreen * cameraScreen = new CameraScreen(P3(350,0,200), P3(0,1,0), 0, screen, 400);
	SceneRenderer * sceneRenderer = new SceneRenderer(scene, cameraScreen, new RayTracing());//new OrthographicProjection());
	Texture * goldTex = new Texture("textures//gold.jpg");
	Texture * goldBump = new Texture("textures//gold_Bump.jpg");
	Texture * leadTex = new Texture("textures//lead.jpg");
	Texture * leadBump = new Texture("textures//lead_Bump.jpg");
	Model * goldSphere = new SphereModel();
	goldSphere->setTexture(goldTex);
	goldSphere->setBump(goldBump);
	goldSphere->setMaterial(Material(0.9,0.98,1.5));
	Model * leadSphere = new SphereModel();
	leadSphere->setTexture(leadTex);
	leadSphere->setBump(leadBump);
	Model * sphere3Model = new SphereModel();
	sphere3Model->setColor(Color::RED);
	sceneRenderer->getObject3DRenderer(sphere1)->setModel(goldSphere);
	sceneRenderer->getObject3DRenderer(sphere2)->setModel(leadSphere);
	sceneRenderer->getObject3DRenderer(sphere3)->setModel(sphere3Model);
	System::Console::WriteLine("Rendering objects...");
	sceneRenderer->render();
	delete sceneRenderer;
	delete goldTex;
	delete goldBump;
	delete leadTex;
	delete leadBump;
	delete scene; // must delete Objects3D and LightSources
	*/
}
