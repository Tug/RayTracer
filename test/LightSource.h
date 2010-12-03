#ifndef _H_LIGHTSOURCE
#define _H_LIGHTSOURCE

#include "Color.h"
#include "P3.h"
#include "Scene.h"

#define DEFAULT_DIFFUSE_COEF 0.6

class LightSource
{
public:
	LightSource(Color color, double diffuseCoef);
	LightSource(Color color);
	virtual ~LightSource();
	virtual Color & getColor();
	double getDiffuseCoef();
	void setDiffuseCoef(double diffuseCoef);
	virtual Color getReflection(P3 & surfPoint, P3 & normalVec, P3 & observerPosition, Color & objectColor) = 0;

protected:
	Color color;
	double diffuseCoef;
};

#endif