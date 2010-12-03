#ifndef _H_P3S
#define _H_P3S

class P3;

#include "P3.h"

// classe gérant les points et vecteurs en 3D coordonnees spheriques

class P3S
{
public :
  double u;				// coordonnées du vecteur
  double v;
  double r;

  double norm();		// retourne la norme du vecteur
  void  normalize();	// normalise le vecteur
  P3S();
  P3S(const P3S & t);
  P3S(const P3 & t);
  P3S & operator = (const P3S & A);
  P3S(double _u, double _v, double _r);

  static P3S fromCartesian(double x, double y, double z);
};

#endif