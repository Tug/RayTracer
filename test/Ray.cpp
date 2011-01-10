#include "stdafx.h"

#include "Ray.h"

Ray::Ray(P3 & source, P3 & direction) {
	this->source = source;
	direction.normalize();
	this->direction = direction;
	this->currentMediumIndex = 1.0;
}

Ray::Ray(P3 & source, P3 & direction, double mediumIndex) {
	this->source = source;
	this->direction = direction;
	this->direction.normalize();
	this->currentMediumIndex = mediumIndex;
}

Ray::~Ray() {
}

P3 & Ray::getSource() {
	return source;
}

P3 & Ray::getDirection() {
	return direction;
}

P3 Ray::get3DPoint(double distFromSource) {
	return source + (direction * distFromSource);
}

Ray Ray::getReflectedRay(P3 & surfPoint, P3 & normal) {
	P3 newDirection = direction - 2 * ( normal * direction ) * normal;
	return Ray(surfPoint, newDirection);
}

Ray Ray::getTransmittedRay(P3 & surfPoint, P3 & normal, double n2) {
	P3 N = normal;
	double cosi =  - direction * N;
	if(cosi < 0) { //inside the object
		cosi = -cosi;
		N = -N;
	}
	double n1On2 = currentMediumIndex/n2;
	P3 newDirection = (n1On2*cosi - sqrt(1-n1On2*n1On2*(1-cosi*cosi))) * N + n1On2 * direction;
	return Ray(surfPoint, newDirection, n2);
}

double Ray::getCurrentMediumIndex() {
	return currentMediumIndex;
}

void Ray::getCurrentMediumIndex(double newMediumIndex) {
	this->currentMediumIndex = newMediumIndex;
}