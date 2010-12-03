#include "stdafx.h"

#include "RayTracing.h"

RayTracing::RayTracing() : RenderingMethod() {
	this->maxDepth = 1;
}

RayTracing::~RayTracing() {

}

inline bool RayTracing::intersectObject(std::vector<Object3D *> & objects, Ray & ray, Object3D ** closestObj, double * yMin) {
	*yMin = DBL_MAX;
	bool intersec = false;
	for(std::vector<Object3D *>::iterator itobjs = objects.begin(); itobjs != objects.end(); itobjs++) {
		double y;
		if((*itobjs)->intersect(ray, &y) && y < *yMin) {
			*yMin = y;
			*closestObj = *itobjs;
			intersec = true;
		}
	}
	return intersec;
}

void RayTracing::drawScene(SceneRenderer * sceneRenderer, Zone & renderingZone) {
	CameraScreen * cameraScreen = sceneRenderer->getCameraScreen();
	Scene * scene = sceneRenderer->getScene();
	P3 cameraPos = cameraScreen->getPosition();
	Screen * screen = cameraScreen->getScreen();
	Color backGround = sceneRenderer->getScene()->getBackgroundColor();
	for(int y=renderingZone.y; y<renderingZone.height; y++) {
		for(int x=renderingZone.x; x<renderingZone.width; x++) {
			P3 R1 = cameraScreen->get3DPoint(x, y);
			P3 Rd(cameraPos, R1);
			Ray ray(cameraPos, Rd);
			screen->setPixel(x, y, throwRay(sceneRenderer, ray, maxDepth));
		}
	}
}

Color RayTracing::throwRay(SceneRenderer * sceneRenderer, Ray & ray, int depth) {
	CameraScreen * cameraScreen = sceneRenderer->getCameraScreen();
	P3 cameraPos = cameraScreen->getPosition();
	Color backGround = sceneRenderer->getScene()->getBackgroundColor();
	Scene * scene = sceneRenderer->getScene();
	std::vector<Object3D *> objects = scene->getObjects3D();
	std::vector<LightSource *> lights = scene->getLightSources();
	std::vector<LightSource *>::iterator itlights;
	double yMin;
	Object3D * closestObj = NULL;
	Color pixCol(0,0,0);
	if(!intersectObject(objects, ray, &closestObj, &yMin)) {
		pixCol = backGround;
	} else {
		Object3DRenderer * closestObjRenderer = sceneRenderer->getObject3DRenderer(closestObj);
		Model * model = closestObjRenderer->getModel();
		P3 surfPoint = ray.get3DPoint(yMin);
		Color objectColor;
		P3 bumpedNormal;
		model->surfaceColorAndBump(closestObj, surfPoint, &objectColor, &bumpedNormal);
		for(itlights = lights.begin(); itlights != lights.end(); itlights++) {
			LightSource * light = *itlights;
			PointLightSource * pLight = dynamic_cast<PointLightSource*>(light);
			if(pLight != 0) {
				Ray toLight(surfPoint, P3(surfPoint, pLight->getPosition()));
				if(intersectObject(objects, toLight, &closestObj, &yMin)) continue; // if object between this point and the light
			}
			pixCol = pixCol + light->getReflection(surfPoint, bumpedNormal, cameraPos, objectColor);
		}
		Material material = model->getMaterial();
		double reflectivity = material.getReflectivity();
		double transmittance = material.getTransmittance();
		pixCol = (1-transmittance) * pixCol;
		if(depth > 0) {
			// reflected ray
			if(reflectivity > 0.0) {
				Ray reflectedRay = ray.getReflectedRay(surfPoint, bumpedNormal);
				pixCol = pixCol + reflectivity * throwRay(sceneRenderer, reflectedRay, depth-1);
			}
			// tramsmited ray
			if(transmittance > 0.0) {
				double refractiveIndex = material.getRefractiveIndex();
				Ray transmitteddRay = ray.getTransmittedRay(surfPoint, bumpedNormal, refractiveIndex);
				pixCol = pixCol + transmittance * throwRay(sceneRenderer, transmitteddRay, depth-1);
			}
		}
	}
	pixCol.checkBounds();
	return pixCol;
}