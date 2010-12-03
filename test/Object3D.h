#ifndef _H_OBJECT3D
#define _H_OBJECT3D

class Model;

#include "P3S.h"
#include "Zone.h"
#include "Material.h"
#include "LightSource.h"
#include "Camera.h"
#include "Ray.h"

class Object3D
{
public:
	Object3D();
	virtual ~Object3D();
	//virtual Zone get2DBounds() = 0;
	virtual bool intersect(Ray & ray, double * distFromSource) = 0;
	virtual P3 getNormal(P3 & surfPoint) = 0;

protected:
	;
};

#endif