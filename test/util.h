#ifndef _H_BOITEAOUTILS
#define _H_BOITEAOUTILS

#define PI     3.14159265358979323846
#include "P3.h"
#include "Color.h"

void Invert_Coord_Spherique(P3 P, double r, double &u, double &v);
void SetPixel(int x, int y, Color & C);
extern int LARGEUR;
extern int HAUTEUR;

#endif