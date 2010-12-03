#include "stdafx.h"

#include "OrthographicProjection.h"

OrthographicProjection::OrthographicProjection() : Rasterization() {

}

OrthographicProjection::~OrthographicProjection() {

}

void OrthographicProjection::drawObject(Object3DRenderer * object3DRenderer, Zone & renderingZone)
{
	Object3D * object3D = object3DRenderer->getObject3D();
	CameraScreen * cameraScreen = object3DRenderer->getCameraScreen();
	Screen * screen = cameraScreen->getScreen();
	P3 camPos = cameraScreen->getPosition();
	P3 camDir = cameraScreen->getDirection();
	Model * model = object3DRenderer->getModel();
	std::vector<LightSource *> lights = object3DRenderer->getScene()->getLightSources();
	//Zone zone = object3D->get2DBounds(scene->getCamera());
	Zone zone;
	int width = screen->getWidth();
	int height = screen->getHeight();
	zone.x = 0; zone.y = 0; zone.width = width; zone.height = height;
	// invert y
	//zone.y = pzCenter - zone.y;
	Zone pixzone = zone;//sceneToScreenZone(zone);
	for(int i=0; i<pixzone.height; i++) {
		int py = i + pixzone.y;
		int z3d = height - py;
		for(int j=0; j<pixzone.width; j++) {
			int px = j + pixzone.x;
			P3 screenPoint3d = cameraScreen->get3DPoint(px, py);
			Ray ray(screenPoint3d, camDir);
			double depth;
			if(object3D->intersect(ray, &depth) && zbuffer->getZ(py,px) > depth) {
				zbuffer->setZ(py, px, depth);
				P3 pSurf = screenPoint3d + (camDir*depth);
				Color objectColor;
				P3 bumpedNormal;
				model->surfaceColorAndBump(object3D, pSurf, &objectColor, &bumpedNormal);
				Color res(0,0,0);
				for(std::vector<LightSource *>::iterator it = lights.begin(); it != lights.end(); it++) {
					Color lightContrib = (*it)->getReflection(pSurf, bumpedNormal, camPos, objectColor);
					res = res + lightContrib;
				}
				res.checkBounds();
				screen->setPixel(px, py, res);
			}
		}
	}
}


/*
Zone Screen::sceneToScreenZone(Zone zone) {
	Zone pixelzone;
	
	// if zone outside the pixel zone
	if( zone.x > width ||
		zone.x + zone.width < 0 ||
		zone.y > height ||
		zone.y + zone.height < 0 ) {
			pixelzone.x = 0;
			pixelzone.width = 0;
			pixelzone.y = 0;
			pixelzone.height = 0;
			return pixelzone;
	}

	if(zone.x < 0) { pixelzone.x = 0; pixelzone.width = zone.width - zone.x; }
	else pixelzone.x = zone.x;

	if(zone.y < 0) { pixelzone.y = 0; pixelzone.height = zone.height - zone.y; }
	else pixelzone.y = zone.y;

	if(zone.x + zone.width > width) pixelzone.width = width - zone.x;
	else pixelzone.width = zone.width;

	if(zone.y + zone.height > height) pixelzone.height = height - zone.y;
	else pixelzone.height = zone.height;

	return pixelzone;
}
*/