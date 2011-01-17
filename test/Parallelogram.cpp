#include "stdafx.h"

#include "Parallelogram.h"

Parallelogram::Parallelogram(P3 & A, P3 & B, P3 & C) : Plane(A, B, C) {
	this->AB = P3(A, B);
	this->AC = P3(A, C);
	this->normN = (AB ^ AC).norm();
	
}

Parallelogram::Parallelogram(Parallelogram * parallelogram) : Plane(parallelogram) {
	this->AB = parallelogram->AB;
	this->AC = parallelogram->AC;
	this->normN = normN;
}

Parallelogram::~Parallelogram() {
}

bool Parallelogram::intersect(Ray & ray, double * distFromSource) {
	P3 R0 = ray.getSource();
	P3 Rd = ray.getDirection();
	P3 distV = P3(R0, p);
	P3 N = normN * normal;
	double nr = N * Rd;
	if(fabs(nr) < 0.01) return false; // colineaire
	double ir = (N * distV) / nr;
	*distFromSource = ir;
	if (ir < 0.0) return false;
	double iu = -((distV ^ AC) * Rd) / nr;
	double iv = -((AB ^ distV) * Rd) / nr;
	*distFromSource = ir;
	return (ir >= 0 && iu >= 0 && iv >= 0 && iu <= 1 && iv <= 1);
	
}
