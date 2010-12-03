#ifndef _H_TRIANGLE
#define _H_TRIANGLE

#include "Object3D.h"
#include "Zone.h"
#include "P3.h"
#include "Plane.h"
#include "Ray.h"

class Triangle: public Plane
{
public:
	Triangle(Triangle * triangle);
	Triangle(P3 & A, P3 & B, P3 & C);
	virtual ~Triangle();
	virtual bool intersect(Ray & ray, double * distFromSource);

protected:
	P3 AB;
	P3 AC;
	double normN;
};


#endif