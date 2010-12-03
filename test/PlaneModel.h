#ifndef _H_PLANEMODEL
#define _H_PLANEMODEL

#include "Model.h"
#include "P3.h"
#include "Object3D.h"
#include "Color.h"
#include "Plane.h"

class PlaneModel : public Model
{
public:
	PlaneModel();
	virtual ~PlaneModel();
	virtual void surfaceColorAndBump(Object3D * object3D, P3 & surfPoint, Color * color, P3 * bumpedNormal);
};



#endif