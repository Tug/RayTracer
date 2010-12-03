#ifndef _H_AMBIENTLIGHTSOURCE
#define _H_AMBIENTLIGHTSOURCE

#include "LightSource.h"
#include "P3.h"
#include "Scene.h"

#define AL_DEFAULT_DIFFUSE_COEF 0.3

class AmbientLightSource : public LightSource
{
public:
	AmbientLightSource(Color color, double diffuseCoef);
	AmbientLightSource(Color color);
	virtual ~AmbientLightSource();
	Color getReflection(P3 & surfPoint, P3 & normalVec, P3 & observerPosition, Color & objectColor);
};

#endif