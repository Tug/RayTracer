#ifndef _P3
#define _P3

#include "P3S.h"


class P3S;
// class handling points et vectors in 3D

class P3
{
  public :
  double x;				// vector coordinates
  double y;
  double z;

  double norm();		// return the norm of the vector
  double normSquare();     // return the norm of the vector squared
  void  normalize();	// normalize the vector
  P3();
  P3(const P3 & t);
  P3(const P3S & ps);
  P3(const P3 & src, const P3 & dst);
  P3 & operator = (const P3 & A);
  P3(double _x, double _y, double _z);
  P3(int _x, int _y, int _z);

  System::String^ toString();
};

P3 operator + (const P3 & a, const P3 & b);		// add 
P3 operator - (const P3 & a, const P3 & b);		// substract
P3 operator - (const P3 & b);					// unary minus
P3 operator ^ (const P3 & a, const P3 & b);		// cross product
P3 operator * (double a, const P3 & b);			// multiply with a float
P3 operator * (const P3 & b, double a);			// multiply with a float
P3 operator / (const P3 & b, double a);			// divide by a float

double operator * (const P3 & a, const P3 & b); // scalar product

#endif