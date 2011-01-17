#ifndef _H_PARALLELOGRAM
#define _H_PARALLELOGRAM

#include "Object3D.h"
#include "Zone.h"
#include "P3.h"
#include "Plane.h"
#include "Ray.h"

class Parallelogram: public Plane
{
public:
	Parallelogram(Parallelogram * parallelogram);
	Parallelogram(P3 & A, P3 & B, P3 & C);
	virtual ~Parallelogram();
	virtual bool intersect(Ray & ray, double * distFromSource);

protected:
	P3 AB;
	P3 AC;
	double normN;
};


#endif