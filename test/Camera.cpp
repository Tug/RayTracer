#include "stdafx.h"

#include "Camera.h"

Camera::Camera(P3 & position, P3 & direction) {
	this->position = position;
	this->direction = direction;
	direction.normalize();
	this->rotation = 0;
}

Camera::Camera(P3 & position, P3 & direction, double rotation) {
	this->position = position;
	this->direction = direction;
	direction.normalize();
	this->rotation = rotation;
}

Camera::Camera(Camera * camera) {
	this->position = camera->position;
	this->direction = camera->direction;
	this->rotation = camera->rotation;
}

void Camera::reinit() {
	direction.normalize();
}

Camera::~Camera() {
}

void Camera::move(P3 & deltaPos) {
	position = position + deltaPos;
	reinit();
}

void Camera::rotate(double u, double v) {
	P3S ps(direction);
	ps.u += u;
	ps.v += v;
	direction = direction + P3(ps);
	reinit();
}

P3 & Camera::getPosition() {
	return position;
}

P3 & Camera::getDirection() {
	return direction;
}

double Camera::getRotation() {
	return rotation;
}
