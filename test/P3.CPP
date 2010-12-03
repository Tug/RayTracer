#include "stdafx.h"

#include "P3.h"

double P3::norm()
{ 
	return double(sqrt(x*x+y*y+z*z)); 
}

double P3::normSquare()
{ 
	return double(x*x+y*y+z*z); 
}

void  P3::normalize()
{
	double n = norm();
	if (n==0) return;
	x /= n;
	y /= n;
	z /= n;
}

P3::P3()
{
}

P3::P3(const P3 & t) : x(t.x), y(t.y), z(t.z)
{
}

P3::P3(const P3S & ps)
{
	double v = M_PI/2 - ps.v;
	double u = - ps.u;
	double cosv = cos(v);
	double sinv = sin(v);
	double cosu = cos(u);
	double sinu = sin(u);
	x = ps.r * sinv * cosu;
	y = ps.r * sinv * sinu;
	z = ps.r * cosv;
}

P3 & P3::operator = (const P3 & A)
{ 
	x = A.x;
	y = A.y;
	z = A.z;
	return * this;
}

 

P3::P3(double _x, double _y, double _z)
{ 
	x = double(_x);
	y = double(_y);
	z = double(_z);
}

P3::P3(int _x, int _y, int _z)
{ 
	x = double(_x);
	y = double(_y);
	z = double(_z);
}

P3::P3(const P3 & src, const P3 & dst)
{ 
	x = dst.x - src.x;
	y = dst.y - src.y;
	z = dst.z - src.z;
}

P3 operator + (const P3 & a, const P3 & b)
{
  P3 t;
  t.x = a.x+b.x;
  t.y=a.y+b.y;
  t.z=a.z+b.z;
  return t;
}

P3 operator - (const P3 & a, const P3 & b)
{
  P3 t;
  t.x = a.x-b.x;
  t.y = a.y-b.y;
  t.z = a.z-b.z;
  return t;
}

P3 operator % (const P3 & a, const P3 & b)
{
  P3 t;
  t.x = a.x*b.x;
  t.y = a.y*b.y;
  t.z = a.z*b.z;
  return t;
}

P3 operator - (const P3 & b)
{
  P3 t;
  t.x = -b.x;
  t.y = -b.y;
  t.z = -b.z;
  return t;
}

P3 operator ^ (const P3 & a, const P3 & b)
{
  P3 t;
  t.x = a.y*b.z-a.z*b.y;
  t.y = a.z*b.x-a.x*b.z;
  t.z=  a.x*b.y-a.y*b.x;
  return t;
}

double operator * (const P3 & a, const P3 & b)
{
  return a.x*b.x+a.y*b.y+a.z*b.z;
}

P3 operator * (double a, const P3 & b)
{
  P3 t;
  t.x = b.x*a;
  t.y = b.y*a;
  t.z=  b.z*a;
  return t;
}

P3 operator * (const P3 & b, double a)
{
  P3 t;
  t.x = b.x*a;
  t.y = b.y*a;
  t.z=  b.z*a;
  return t;
}

P3 operator / (const P3 & b, double a)
{
  P3 t;
  t.x = b.x/a;
  t.y = b.y/a;
  t.z=  b.z/a;
  return t;
}


System::String^ P3::toString() {
	return "{ x="+x+", y="+y+" z="+z+" }";
}

