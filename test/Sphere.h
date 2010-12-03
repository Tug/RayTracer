#ifndef _H_SPHERE
#define _H_SPHERE

#include "Object3D.h"
#include "Zone.h"
#include "P3.h"
#include "Ray.h"

class Sphere: public Object3D
{
public:
	Sphere();
	Sphere(Sphere * sphere);
	Sphere(double x, double y, double z, double radius);
	Sphere(P3 & center, double radius);
	virtual ~Sphere();
	//Zone get2DBounds();
	virtual bool intersect(Ray & ray, double * distFromSource);
	virtual P3 getNormal(P3 & surfPoint);
	P3 & getCenter();
	double getRadius();
	void setCenter(P3 & center);
	void setRadius(double radius);

protected:
	P3 center;
	double radius;
	double radiusSquared;
};

#endif