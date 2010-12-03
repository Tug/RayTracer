#include "stdafx.h"

#include "Polyhedron.h"

Polyhedron::Polyhedron() {
}

Polyhedron::Polyhedron(Polyhedron * polyhedron) {
	this->triangles = std::vector<Triangle *>(polyhedron->triangles);
}

Polyhedron::Polyhedron(std::vector<Triangle *> & triangles) {
	this->triangles = triangles;
}

Polyhedron::~Polyhedron() {
	for(std::vector<Triangle*>::iterator it = triangles.begin(); it != triangles.end(); it++) {
		delete (*it);
	}
}

std::vector<Triangle *> & Polyhedron::getTriangles() {
	return triangles;
}

/*
bool Polyhedron::intersect(Ray & ray, double * distFromSource) {
	double yMin = DBL_MAX;
	bool intersec = false;
	for(std::vector<Triangle*>::iterator it = triangles.begin(); it != triangles.end(); it++) {
		double y;
		if((*it)->intersect(ray, &y) && y < yMin) {
			yMin = y;
			intersec = true;
		}
	}
	*distFromSource = yMin;
	return intersec;
}

P3 Cube::getNormal(P3 & surfPoint) {
	return lastIntersecTriangle->getNormal(surfPoint);
}
*/
