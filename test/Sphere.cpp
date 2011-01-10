#include "stdafx.h"

#include "Sphere.h"

Sphere::Sphere() : Object3D()
{
	this->center = P3(0,0,0);
	this->radius = 1;
	this->radiusSquared = 1;
}

Sphere::Sphere(Sphere * sphere) : Object3D()
{
	this->center = sphere->center;
	this->radius = sphere->radius;
	this->radiusSquared = sphere->radiusSquared;
}

Sphere::Sphere(double x, double y, double z, double radius) : Object3D()
{
	this->center = P3(x,y,z);
	this->radius = radius;
	this->radiusSquared = radius*radius;
}

Sphere::Sphere(P3 & center, double radius) : Object3D()
{
	this->center = center;
	this->radius = radius;
	this->radiusSquared = radius*radius;
}


Sphere::~Sphere() {
}

/*
Zone Sphere::get2DBounds(Camera * camera) {
	double centerX = coordinates->x;
	double centerY = coordinates->y;
	double centerZ = coordinates->z;
	Zone zone;
	zone.x = (int)(centerX - (radius));
	zone.y = (int)(centerZ - (radius));
	zone.width = (int)(centerX + (radius) - zone.x);
	zone.height = (int)(centerZ + (radius) - zone.y);
	return zone;
}
*/


bool Sphere::intersect(Ray & ray, double * distFromSource) {
	P3 R0 = ray.getSource();
	P3 Rd = ray.getDirection();
	P3 distV = P3(R0, center);
	double d = (Rd * distV)/Rd.norm();
	if(d < 0) return false; // Object in the oposite direction
	double minDistFromCenter2 = distV.normSquare() - d*d;
	if((sqrt(minDistFromCenter2) < radius)) {
		if(distV.norm() < radius + 0.1) // if ray starts from inside the object
			*distFromSource = d + sqrt(radiusSquared - minDistFromCenter2);
		else
			*distFromSource = d - sqrt(radiusSquared - minDistFromCenter2);
		return true;
	}
	return false;
}

P3 Sphere::getNormal(P3 & surfPoint) {
	P3 normal(center, surfPoint);
	normal.normalize();
	return normal;
}

P3 & Sphere::getCenter() {
	return center;
}

double Sphere::getRadius() {
	return radius;
}

void Sphere::setCenter(P3 & center) {
	this->center = center;
}

void Sphere::setRadius(double radius) {
	this->radius = radius;
	this->radiusSquared = radius*radius;
}