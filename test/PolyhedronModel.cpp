#include "stdafx.h"

#include "PolyhedronModel.h"

PolyhedronModel::PolyhedronModel() : PlaneModel() {

}

PolyhedronModel::~PolyhedronModel() {
}

void PolyhedronModel::surfaceColorAndBump(Object3D * object3D, P3 & surfPoint, RGBColor * color, P3 * bumpedNormal) {
	//P3 normal = object3D->getNormal(surfPoint);
	//Triangle * triangle = static_cast<Triangle *>(object3D);
	PlaneModel::surfaceColorAndBump(object3D, surfPoint, color, bumpedNormal);
}
