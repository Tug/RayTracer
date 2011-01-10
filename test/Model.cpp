#include "stdafx.h"

#include "Model.h"

Model::Model() {
	this->c = RGBColor::GREY;
	this->texture = 0;
	this->material = Material();
	this->bump = 0;
	this->textureScale = 1;
}

Model::~Model() {
}

RGBColor & Model::getColor() {
	return c;
}

RGBColor Model::getColor(double x, double y) {
	if(texture) {
		return texture->relativePixelColor(x/textureScale, y/textureScale);
	}
	return c;
}

P3 Model::bumpNormal(double x, double y, P3 & normal) {
	if(bump) {
		P3S ns(normal);
		P3S sdu(P3(1,0,0));
		sdu.u += ns.u + M_PI/2;
		P3 dMdu(sdu);
		P3 dMdv = normal ^ dMdu;
		double dhdu, dhdv;
		bump->Bump(x/textureScale, y/textureScale, dhdu, dhdv);
		normal = normal + (dMdv * dhdv) + (dMdu * dhdu);
	}
	return normal;
}

Texture * Model::getTexture() {
	return texture;
}

Texture * Model::getBump() {
	return bump;
}

Material & Model::getMaterial() {
	return material;
}

double Model::getTextureScale() {
	return textureScale;
}

void Model::setTexture(Texture * texture) {
	this->texture = texture;
}

void Model::setColor(RGBColor & c) {
	this->c = c;
}

void Model::setBump(Texture * bump) {
	this->bump = bump;
}

void Model::setMaterial(Material & material) {
	this->material = material;
}

void Model::setTextureScale(double textureScale) {
	this->textureScale = textureScale;
}