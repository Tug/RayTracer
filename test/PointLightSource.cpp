#include "stdafx.h"

#include "PointLightSource.h"

PointLightSource::PointLightSource(P3 position, RGBColor color, double diffuseCoef, double specularCoef, double specularExponent) : LightSource(color, diffuseCoef) {
	this->position = position;
	this->specularCoef = specularCoef;
	this->specularExponent = specularExponent;
}

PointLightSource::PointLightSource(P3 position, RGBColor color) : LightSource(color) {
	this->position = position;
	this->specularCoef = DEFAULT_SPECULAR_COEF;
	this->specularExponent = DEFAULT_SPECULAR_EXP;
}

PointLightSource::PointLightSource() : LightSource() {
	this->position = P3(0,0,0);
	this->specularCoef = DEFAULT_SPECULAR_COEF;
	this->specularExponent = DEFAULT_SPECULAR_EXP;
}

PointLightSource::~PointLightSource() {
}

RGBColor PointLightSource::getReflection(P3 & surfPoint, P3 & normalVec, P3 & observerPosition, RGBColor & objectColor) {
	// ensure normal vec is normalized
	normalVec.normalize();
	// diffuse
	P3 lightVector(surfPoint, position);
	double dist = lightVector.norm();
	lightVector.normalize();
	double costheta = fabs(lightVector * normalVec);
	RGBColor cDiff = diffuseCoef * (objectColor % color) * costheta;
	// specular
	P3 obsVec(surfPoint, observerPosition);
	obsVec.normalize();
	P3 v = (normalVec - lightVector);
	P3 sym = 2*normalVec * (lightVector * normalVec) - lightVector;
	sym.normalize();
	double coskSO = pow(fabs(sym * obsVec), specularExponent);
	RGBColor cSpec = specularCoef * color * coskSO;
	return cDiff + cSpec;
}

/*
RGBColor PointLightSource::getReflection(P3 & surfPoint, P3 & normalVec, P3 & observerPosition, RGBColor & objectColor, Scene * scene) {
	std::vector<Object3D *> objects = scene->getObjects3D();
	std::vector<Object3D *>::iterator itobjs;
	Ray ray(surfPoint, P3(surfPoint, *position));
	double y;
	bool oculted = false;
	for(itobjs = objects.begin(); itobjs != objects.end(); itobjs++) {
		if((*itobjs)->intersect(ray, &y)) {
			oculted = true;
		}
	}
	if(!oculted) {
		return getReflection(surfPoint, normalVec, observerPosition, objectColor);
	}
	return RGBColor(0,0,0);
}
*/

double PointLightSource::getSpecularCoef() {
	return specularCoef;
}

double PointLightSource::getSpecularExponent() {
	return specularExponent;
}

P3 & PointLightSource::getPosition() {
	return position;
}

void PointLightSource::setSpecularCoef(double specularCoef) {
	this->specularCoef = specularCoef;
}

void PointLightSource::setSpecularExponent(double specularExponent) {
	this->specularExponent = specularExponent;
}

void PointLightSource::setPosition(P3 & newPosition) {
	this->position = newPosition;
}