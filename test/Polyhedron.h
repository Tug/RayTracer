#ifndef _H_POLYHEDRON
#define _H_POLYHEDRON

#include "Zone.h"
#include "P3.h"
#include "Plane.h"
#include "Ray.h"
#include "Triangle.h"
#include <vector>

class Polyhedron
{
public:
	Polyhedron();
	Polyhedron(Polyhedron * polyhedron);
	Polyhedron(std::vector<Triangle *> & triangles);
	virtual ~Polyhedron();
	virtual bool intersect(Ray & ray, double * distFromSource);
	std::vector<Triangle *> & getTriangles();

protected:
	std::vector<Triangle *> triangles;
};


#endif