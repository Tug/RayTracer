#ifndef _H_PLANE
#define _H_PLANE

#include "Object3D.h"
#include "Zone.h"
#include "P3.h"
#include "Ray.h"

class Plane: public Object3D
{
public:
	Plane();
	Plane(Plane * plane);
	Plane(P3 & p, P3 & normal);
	Plane(P3 & A, P3 & B, P3 & C);
	virtual ~Plane();
	//Zone get2DBounds();
	P3 getP();
	virtual bool intersect(Ray & ray, double * distFromSource);
	virtual P3 getNormal(P3 & surfPoint);
	void computeUV();
	P3 getU();
	P3 getV();

protected:
	P3 p;
	P3 normal;
	P3 u, v;
};


#endif