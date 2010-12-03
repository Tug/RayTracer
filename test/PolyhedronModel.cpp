#include "stdafx.h"

#include "PolyhedronModel.h"

PolyhedronModel::PolyhedronModel(Polyhedron * polyhedron) : PlaneModel() {
	this->polyhedron = polyhedron;
}

PolyhedronModel::~PolyhedronModel() {
}

void PolyhedronModel::surfaceColorAndBump(Object3D * object3D, P3 & surfPoint, Color * color, P3 * bumpedNormal) {
	//P3 normal = object3D->getNormal(surfPoint);
	//Triangle * triangle = static_cast<Triangle *>(object3D);
	PlaneModel::surfaceColorAndBump(object3D, surfPoint, color, bumpedNormal);
}
