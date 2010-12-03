#ifndef _H_PARALLELEPIPED
#define _H_PARALLELEPIPED

#include "Object3D.h"
#include "Zone.h"
#include "P3.h"
#include "Plane.h"
#include "Ray.h"
#include "Polyhedron.h"
#include "Triangle.h"

class Parallelepiped: public Polyhedron
{
public:
	Parallelepiped(Parallelepiped * parallelepiped);
	Parallelepiped(P3 & A, P3 & B, P3 & C, P3 & D);
	virtual ~Parallelepiped();

protected:
	double lu;
	double lv;
	double lw;
};


#endif