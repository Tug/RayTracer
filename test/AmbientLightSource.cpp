#include "stdafx.h"

#include "AmbientLightSource.h"

AmbientLightSource::AmbientLightSource(RGBColor color, double diffuseCoef) : LightSource(color, diffuseCoef) {
}

AmbientLightSource::AmbientLightSource(RGBColor color) : LightSource(color, AL_DEFAULT_DIFFUSE_COEF) {
}

AmbientLightSource::~AmbientLightSource() {
}

RGBColor AmbientLightSource::getReflection(P3 & surfPoint, P3 & normalVec, P3 & observerPosition, RGBColor & objectColor) {
	return diffuseCoef * (objectColor % color);
}
