#ifndef _H_LIGHTSOURCE
#define _H_LIGHTSOURCE

#include "RGBColor.h"
#include "P3.h"
#include "Scene.h"

#define DEFAULT_DIFFUSE_COEF 0.6

class LightSource
{
public:
	LightSource(RGBColor color, double diffuseCoef);
	LightSource(RGBColor color);
	LightSource();
	virtual ~LightSource();
	virtual RGBColor & getColor();
	double getDiffuseCoef();
	void setDiffuseCoef(double diffuseCoef);
	void setColor(RGBColor& color);
	virtual RGBColor getReflection(P3 & surfPoint, P3 & normalVec, P3 & observerPosition, RGBColor & objectColor) = 0;

protected:
	RGBColor color;
	double diffuseCoef;
};

#endif