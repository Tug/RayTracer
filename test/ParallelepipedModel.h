#ifndef _H_PARALLELEPIPEDEMODEL
#define _H_PARALLELEPIPEDEMODEL

#include "Model.h"
#include "P3.h"
#include "Object3D.h"
#include "PolyhedronModel.h"
#include "Polyhedron.h"

class ParallelepipedModel : public PolyhedronModel
{
public:
	ParallelepipedModel(Polyhedron * polyhedron);
	~ParallelepipedModel();
	virtual void surfaceColorAndBump(Object3D * object3D, P3 & surfPoint, Color * color, P3 * bumpedNormal);
};



#endif