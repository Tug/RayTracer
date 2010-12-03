#include "stdafx.h"

#include "PlaneModel.h"

PlaneModel::PlaneModel() : Model() {

}

PlaneModel::~PlaneModel() {
}


void PlaneModel::surfaceColorAndBump(Object3D * object3D, P3 & surfPoint, Color * color, P3 * bumpedNormal) {
	Plane * plane = (Plane *)object3D;
	P3 relativePoint(plane->getP(), surfPoint);
	double x = (relativePoint * plane->getU())/100;
	double y = (relativePoint * plane->getV())/100;
	*color = getColor(x, y);
	*bumpedNormal = plane->getNormal(surfPoint);//bumpNormal(x, y, plane->getNormal(surfPoint));
}
