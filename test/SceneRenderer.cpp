#include "stdafx.h"

#include "SceneRenderer.h"

SceneRenderer::SceneRenderer(Screen * screen) {
	this->scene = new Scene();
	this->screen = screen;
	this->renderingMethod = NULL;
	this->camera = NULL;
	this->cameraScreen = NULL;
}

SceneRenderer::SceneRenderer(SceneRenderer * sceneRenderer) {
	this->scene = sceneRenderer->scene;
	this->screen = sceneRenderer->screen;
	this->camera = camera;
	this->cameraScreen = sceneRenderer->cameraScreen;
	this->renderingMethod = sceneRenderer->renderingMethod;
	this->renderersMap = sceneRenderer->renderersMap;
}

SceneRenderer::~SceneRenderer() {
	deleteObject3DRenderers();
	delete cameraScreen;
	delete scene;
}

void SceneRenderer::deleteObject3DRenderers() {
	for(std::map<Object3D*, Object3DRenderer*>::iterator it = renderersMap.begin(); it != renderersMap.end(); it++) {
		delete (*it).second;
	}
	renderersMap.clear();
}

void SceneRenderer::initObject3DRenderers() {
	std::vector<Object3D *> objects = scene->getObjects3D();
	for(std::vector<Object3D *>::iterator it = objects.begin(); it != objects.end(); it++) {
		Object3D * obj3D = *it;
		Object3DRenderer * objRenderer = new Object3DRenderer(obj3D, scene, cameraScreen);
		renderersMap[obj3D] = objRenderer;
	}
}

void SceneRenderer::render(Zone & rendereringZone) {
	cameraScreen->getScreen()->fillBackground(scene->getBackgroundColor());
	renderingMethod->drawScene(this, rendereringZone);
}

void SceneRenderer::render() {
	Zone zone;
	zone.x = 0;
	zone.y = 0;
	zone.width = screen->getWidth();
	zone.height = screen->getHeight();
	render(zone);
}

void SceneRenderer::moveCamera(double dx, double dy, double dz, double du, double dv) {
	if(dx != 0 || dy != 0 || dz != 0)
		cameraScreen->move(P3(dx,dy,dz));
	if(du != 0 || dv != 0)
		cameraScreen->rotate(P3S(du,dv,1));
}

Object3DRenderer * SceneRenderer::getObject3DRenderer(Object3D* object3D) {
	if(renderersMap.find(object3D) == renderersMap.end()) {
		Object3DRenderer * objRenderer = new Object3DRenderer(object3D, scene, cameraScreen);
		renderersMap[object3D] = objRenderer;
	};
	return renderersMap[object3D];
}


void SceneRenderer::reset() {
	scene->removeAll();
	if(this->renderingMethod != NULL)
		delete this->renderingMethod;
	if(this->cameraScreen != NULL)
		delete this->cameraScreen;
}

Scene * SceneRenderer::getScene() { return scene; }
double SceneRenderer::getCameraScreenDist() { return cameraScreenDist; }
RenderingMethod * SceneRenderer::getRenderingMethod() { return renderingMethod; }
Camera * SceneRenderer::getCamera() { return camera; }
void SceneRenderer::setCamera(Camera * camera) { this->camera = camera; }
CameraScreen * SceneRenderer::getCameraScreen() { return cameraScreen; }

void SceneRenderer::setScene(Scene * scene) {
	this->scene = scene;
	initObject3DRenderers();
}

void SceneRenderer::setCameraScreenDist(double dist) {
	this->cameraScreenDist = dist;
	this->cameraScreen = new CameraScreen(camera, screen, dist);
}

void SceneRenderer::setRenderingMethod(RenderingMethod * renderingMethod) {
	this->renderingMethod = renderingMethod;
}


