#include "stdafx.h"

#include "P3S.h"

P3S::P3S()
{
}

P3S::P3S(const P3S & t) : u(t.u), v(t.v), r(t.r)
{
}

P3S & P3S::operator = (const P3S & A)
{ 
	u = A.u;
	v = A.v;
	r = A.r;
	return * this;
}


P3S::P3S(double _u, double _v, double _r)
{
	u = double(_u);
	v = double(_v);
	r = double(_r);
}

P3S::P3S(const P3 & p)
{
	r = sqrt(p.x*p.x + p.y*p.y + p.z*p.z);
	v = asin(p.z/r); // v = 0 ie p.z = 0
	u = -atan2(p.y, p.x);
	//if(p.y > 0) u += 2*M_PI;
}

double P3S::norm()
{
	return r; 
}

void  P3S::normalize()
{
	r = 1;
}


P3S P3S::fromCartesian(double x, double y, double z) {
	return P3S(P3(x,y,z));
}