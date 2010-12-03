#include "stdafx.h"

#include "LightSource.h"

LightSource::LightSource(Color color, double diffuseCoef) {
	this->color = color;
	this->diffuseCoef = diffuseCoef;
}

LightSource::LightSource(Color color) {
	this->color = color;
	this->diffuseCoef = DEFAULT_DIFFUSE_COEF;
}

LightSource::~LightSource() {
}

Color & LightSource::getColor() {
	return color;
}

double LightSource::getDiffuseCoef() {
	return diffuseCoef;
}

void LightSource::setDiffuseCoef(double diffuseCoef) {
	this->diffuseCoef = diffuseCoef;
}