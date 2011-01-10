#ifndef _H_POINTLIGHTSOURCE
#define _H_POINTLIGHTSOURCE

#include "LightSource.h"
#include "P3.h"
#include "Scene.h"

#define DEFAULT_SPECULAR_COEF 0.6
#define DEFAULT_SPECULAR_EXP 50

class PointLightSource : public LightSource
{
public:
	PointLightSource(P3 position, RGBColor color, double diffuseCoef, double specularCoef, double specularExponent);
	PointLightSource(P3 position, RGBColor color);
	PointLightSource();
	~PointLightSource();
	P3 & getPosition();
	double getSpecularCoef();
	double getSpecularExponent();
	void setSpecularCoef(double specularCoef);
	void setSpecularExponent(double specularExponent);
	void setPosition(P3 & newPosition);
	RGBColor getReflection(P3 & surfPoint, P3 & normalVec, P3 & observerPosition, RGBColor & objectColor);

private:
	P3 position;
	double specularCoef;
	double specularExponent;
};

#endif