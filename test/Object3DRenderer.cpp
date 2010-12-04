#include "stdafx.h"

#include "Object3DRenderer.h"


Object3DRenderer::Object3DRenderer(Object3D * object3D, Scene * scene, CameraScreen * cameraScreen) {
	this->object3D = object3D;
	this->scene = scene;
	this->cameraScreen = cameraScreen;
	this->observerPosition = cameraScreen->getPosition();
	this->visible = true;
}

Object3DRenderer::~Object3DRenderer() {
}

void Object3DRenderer::setModel(Model * newModel) {
	model = newModel;
}

Object3D * Object3DRenderer::getObject3D(){
	return object3D;
}

Model * Object3DRenderer::getModel(){
	return model;
}

Scene * Object3DRenderer::getScene(){
	return scene;
}

CameraScreen * Object3DRenderer::getCameraScreen() {
	return cameraScreen;
}

void Object3DRenderer::setVisible(bool visible) {
	this->visible = visible;
}

bool Object3DRenderer::isVisible() {
	return visible;
}
