#include "stdafx.h"

#include "Rasterization.h"

Rasterization::Rasterization() : RenderingMethod() {

}

Rasterization::~Rasterization() {

}

void Rasterization::drawScene(SceneRenderer * sceneRenderer, Zone & renderingZone) {
	CameraScreen * cameraScreen = sceneRenderer->getCameraScreen();
	Screen * screen = cameraScreen->getScreen();
	this->zbuffer = new ZBuffer(screen->getWidth(), screen->getHeight());
	std::vector<Object3D *> objects = sceneRenderer->getScene()->getObjects3D();
	for(std::vector<Object3D *>::iterator it = objects.begin(); it != objects.end(); it++) {
		drawObject(sceneRenderer->getObject3DRenderer(*it), renderingZone);
	}
	delete zbuffer;
}

