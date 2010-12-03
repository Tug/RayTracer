#include "stdafx.h"

#include "AmbientLightSource.h"

AmbientLightSource::AmbientLightSource(Color color, double diffuseCoef) : LightSource(color, diffuseCoef) {
}

AmbientLightSource::AmbientLightSource(Color color) : LightSource(color, AL_DEFAULT_DIFFUSE_COEF) {
}

AmbientLightSource::~AmbientLightSource() {
}

Color AmbientLightSource::getReflection(P3 & surfPoint, P3 & normalVec, P3 & observerPosition, Color & objectColor) {
	return diffuseCoef * (objectColor % color);
}
