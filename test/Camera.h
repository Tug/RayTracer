#ifndef _H_CAMERA
#define _H_CAMERA

#include "P3.H"
#include "P3S.h"
#include "Screen.h"

class Camera
{
public:
	Camera(P3 & position, P3 & direction);
	Camera(P3 & position, P3 & direction, double rotation);
	Camera(Camera * camera);
	virtual ~Camera();
	virtual void move(P3 & deltaPos);
	virtual void rotate(double u, double v);
	virtual P3 & getPosition();
	virtual P3 & getDirection();
	virtual double getRotation();

protected:
	virtual void reinit();
	P3 position;
	P3 direction;
	double rotation;
};

#endif