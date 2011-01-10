#ifndef _H_SPHEREMODEL
#define _H_SPHEREMODEL

#include "Model.h"
#include "P3.h"
#include "Object3D.h"
#include "RGBColor.h"
#include "Sphere.h"

class SphereModel : public Model
{
public:
	SphereModel();
	~SphereModel();
	virtual void surfaceColorAndBump(Object3D * object3D, P3 & surfPoint, RGBColor * color, P3 * bumpedNormal);
};



#endif