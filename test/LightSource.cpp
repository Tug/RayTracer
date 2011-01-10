#include "stdafx.h"

#include "LightSource.h"

LightSource::LightSource(RGBColor color, double diffuseCoef) {
	this->color = color;
	this->diffuseCoef = diffuseCoef;
}

LightSource::LightSource(RGBColor color) {
	this->color = color;
	this->diffuseCoef = DEFAULT_DIFFUSE_COEF;
}

LightSource::LightSource() {
	this->color = RGBColor(1,1,1);
	this->diffuseCoef = DEFAULT_DIFFUSE_COEF;
}

LightSource::~LightSource() {
}

RGBColor & LightSource::getColor() {
	return color;
}

double LightSource::getDiffuseCoef() {
	return diffuseCoef;
}

void LightSource::setDiffuseCoef(double diffuseCoef) {
	this->diffuseCoef = diffuseCoef;
}

void LightSource::setColor(RGBColor& color) {
	this->color = color;
}