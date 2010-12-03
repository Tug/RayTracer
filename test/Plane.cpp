#include "stdafx.h"

#include "Plane.h"

Plane::Plane() {
}

Plane::Plane(Plane * plane) : Object3D() {
	this->p = plane->p;
	this->normal = plane->normal;
	this->u = plane->u;
	this->v = plane->v;
}

Plane::Plane(P3 & p, P3 & normal) : Object3D() {
	this->p = p;
	this->normal = normal;
	normal.normalize();
	computeUV();
}

Plane::Plane(P3 & A, P3 & B, P3 & C) : Object3D() {
	this->p = A;
	P3 AB(A,B);
	P3 AC(A,C);
	AB.normalize();
	AC.normalize();
	this->normal = AB ^ AC;
	computeUV();
}

void Plane::computeUV() {
	P3S us(normal);
	us.u += M_PI/2;
	this->u = P3(us);
	u.normalize();
	this->v = u ^ normal;
}

Plane::~Plane() {
}

/*
Zone Sphere::get2DBounds(Camera * camera) {

}
*/

bool Plane::intersect(Ray & ray, double * distFromSource) {
	P3 R0 = ray.getSource();
	P3 Rd = ray.getDirection();
	P3 distV = P3(R0, p);
	double nr = normal * Rd;
	if(fabs(nr) < 0.1) return false;
	double ir = (normal * distV) / nr;
	if(ir <= 0.1) return false;
	//double iu = - (distV ^ v) * Rd / nr;
	//double iv = - (u ^ distV) * Rd / nr;
	*distFromSource = ir;
	return true;
}

P3 Plane::getNormal(P3 & surfPoint) {
	return normal;
}

P3 Plane::getP() {
	return p;
}

P3 Plane::getU() {
	return u;
}

P3 Plane::getV() {
	return v;
}
