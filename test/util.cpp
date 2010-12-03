#include "stdafx.h"


#include "util.h"
#include <stdlib.h>




//CClientDC * Ecran;

//void CLS(COLORREF coul)
//{
 /* CPen    p(PS_SOLID,1,coul);
  CBrush  b(coul);
  Ecran->SelectObject(p);
  Ecran->SelectObject(b);
  Ecran->Rectangle(0,0,10000,10000);
  */
 // }


void Invert_Coord_Spherique(P3 P, double r, double &u, double &v)
{
	P = P / r;
	if ( P.z >= 1 )       {  u =  PI/2;  v = 0;  }
	else if ( P.z <= -1 ) {  u = -PI/2;  v = 0;  }
	else
	{		 v = asin(P.z); 
	         double  t = P.x/cos(v);
			 if      ( t <= -1 )  { u =  PI; }
			 else if ( t >=  1 )  { u =   0; }
			 else 
			 {    
				 if ( P.y < 0 )  u = 2*PI-acos(t);  
				 else		     u =      acos(t);	
			 }
	}
}

 