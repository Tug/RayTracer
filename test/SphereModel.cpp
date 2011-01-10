#include "stdafx.h"

#include "SphereModel.h"

SphereModel::SphereModel() : Model() {
}

SphereModel::~SphereModel() {
}

void SphereModel::surfaceColorAndBump(Object3D * object3D, P3 & surfPoint, RGBColor * color, P3 * bumpedNormal) {
	P3 normal = object3D->getNormal(surfPoint);
	P3S ns(normal);
	double x = -ns.u/(2*M_PI) + 0.5;
	double y = -ns.v/M_PI + 0.5;
	*color = getColor(x, y);
	*bumpedNormal = bumpNormal(x, y, normal);
}
