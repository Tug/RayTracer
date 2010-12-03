#include "stdafx.h"

#include "RayCasting.h"

RayCasting::RayCasting() : RenderingMethod() {

}

RayCasting::~RayCasting() {

}

inline bool RayCasting::intersectObject(std::vector<Object3D *> & objects, Ray & ray, Object3D ** closestObj, double * yMin) {
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

void RayCasting::drawScene(SceneRenderer * sceneRenderer, Zone & renderingZone) {
	CameraScreen * cameraScreen = sceneRenderer->getCameraScreen();
	P3 cameraPos = cameraScreen->getPosition();
	Screen * screen = cameraScreen->getScreen();
	int width = screen->getWidth();
	int height = screen->getHeight();
	Color backGround = sceneRenderer->getScene()->getBackgroundColor();
	std::vector<Object3D *> objects = sceneRenderer->getScene()->getObjects3D();
	std::vector<LightSource *> lights = sceneRenderer->getScene()->getLightSources();
	std::vector<Object3D *>::iterator itobjs;
	std::vector<LightSource *>::iterator itlights;
	for(int y=renderingZone.y; y<renderingZone.height; y++) {
		for(int x=renderingZone.x; x<renderingZone.width; x++) {
			P3 R1 = cameraScreen->get3DPoint(x, y);
			P3 Rd(cameraPos, R1);
			Ray ray(cameraPos, Rd);
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
						if(intersectObject(objects, toLight, &closestObj, &yMin)) continue;
					}
					pixCol = pixCol + light->getReflection(surfPoint, bumpedNormal, cameraPos, objectColor);
				}
			}
			pixCol.checkBounds();
			screen->setPixel(x, y, pixCol);
		}
	}
}
