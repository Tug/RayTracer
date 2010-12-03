#ifndef _H_RAY
#define _H_RAY

#include "P3.h"

class Ray
{
public:
	Ray(P3 & source, P3 & direction);
	Ray(P3 & source, P3 & direction, double mediumIndex);
	virtual ~Ray();
	P3 & getSource();
	P3 & getDirection();
	P3 get3DPoint(double distanceFromSource);
	Ray getReflectedRay(P3 & surfPoint, P3 & normal);
	Ray getTransmittedRay(P3 & surfPoint, P3 & normal, double n1On2);
	double getCurrentMediumIndex();
	void getCurrentMediumIndex(double newMediumIndex);

private:
	P3 source;
	P3 direction;
	double currentMediumIndex;
};

#endif

