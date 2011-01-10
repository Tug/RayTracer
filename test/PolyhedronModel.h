#ifndef _H_POLYHEDRONMODEL
#define _H_POLYHEDRONMODEL

#include "PlaneModel.h"
#include "P3.h"
#include "Object3D.h"
#include "RGBColor.h"
#include "Polyhedron.h"

class PolyhedronModel : public PlaneModel
{
public:
	PolyhedronModel();
	~PolyhedronModel();
	virtual void surfaceColorAndBump(Object3D * object3D, P3 & surfPoint, RGBColor * color, P3 * bumpedNormal);
};



#endif