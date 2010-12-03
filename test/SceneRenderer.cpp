#include "stdafx.h"

#include "SceneRenderer.h"

SceneRenderer::SceneRenderer(Screen * screen) {
	this->scene = new Scene();
	this->screen = screen;
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
	for(std::map<Object3D*, Object3DRenderer*>::iterator it = renderersMap.begin(); it != renderersMap.end(); it++) {
		delete (*it).second;
	}
	delete cameraScreen;
	delete scene;
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
	System::Console::WriteLine("Start rendering...");
	renderingMethod->drawScene(this, rendereringZone);
	System::Console::WriteLine("Rendering finished!");
}

void SceneRenderer::render() {
	Zone zone;
	zone.x = 0;
	zone.y = 0;
	zone.width = screen->getWidth();
	zone.height = screen->getHeight();
	render(zone);
}

void SceneRenderer::moveCamera(int x, int y) {
	P3 deltaPos(x, 0, y);
	cameraScreen->move(deltaPos);
}

Object3DRenderer * SceneRenderer::getObject3DRenderer(Object3D* object3D) {
	if(renderersMap.find(object3D) == renderersMap.end()) {
		Object3DRenderer * objRenderer = new Object3DRenderer(object3D, scene, cameraScreen);
		renderersMap[object3D] = objRenderer;
	};
	return renderersMap[object3D];
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
	if(this->cameraScreen != NULL)
		delete this->cameraScreen;
	this->cameraScreen = new CameraScreen(camera, screen, dist);
}

void SceneRenderer::setRenderingMethod(RenderingMethod * renderingMethod) {
	if(this->renderingMethod != NULL)
		delete this->renderingMethod;
	this->renderingMethod = renderingMethod;
}


