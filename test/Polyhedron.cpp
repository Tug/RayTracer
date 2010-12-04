#include "stdafx.h"

#include "Polyhedron.h"

Polyhedron::Polyhedron() : Object3D() {
}

Polyhedron::Polyhedron(Polyhedron * polyhedron) : Object3D() {
	this->triangles = std::vector<Triangle *>(polyhedron->triangles);
}

Polyhedron::Polyhedron(std::vector<Triangle *> & triangles) : Object3D() {
	this->triangles = triangles;
}

Polyhedron::~Polyhedron() {
	triangles.clear();
}

std::vector<Triangle *> & Polyhedron::getTriangles() {
	return triangles;
}

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


