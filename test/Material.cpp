#include "stdafx.h"

#include "Material.h"

Material::Material() {
	this->reflectivity = DEFAULT_REFLECTIVITY;
	this->transmittance = DEFAULT_TRANSMITTANCE;
	this->refractiveIndex = DEFAULT_REFRACTIVE_INDEX;
}

Material::Material(double reflectivity, double transmittance, double refractiveIndex) {
	this->reflectivity = reflectivity;
	this->transmittance = transmittance;
	this->refractiveIndex = refractiveIndex;
}

Material::~Material() {
}

double Material::getReflectivity() {
	return reflectivity;
}

double Material::getTransmittance() {
	return transmittance;
}

double Material::getRefractiveIndex() {
	return refractiveIndex;
}

void Material::setReflectivity(double reflectivity) {
	this->reflectivity = reflectivity;
}

void Material::setTransmittance(double transmittance) {
	this->transmittance = transmittance;
}

void Material::setRefractiveIndex(double refractiveIndex) {
	this->refractiveIndex = refractiveIndex;
}
