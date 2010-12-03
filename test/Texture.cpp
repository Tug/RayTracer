#include "stdafx.h"
#include "Texture.h"

//using namespace System::Windows::Forms;
//using namespace System::Drawing;
//using namespace System;

Texture::Texture(const char * name)
{
	System::String ^systemstring = gcnew System::String(name);
	System::Drawing::Bitmap Bmp(systemstring);
    m_wWidth  = Bmp.Width;
	m_wHeight = Bmp.Height;
	m_pColorMap = new Color[m_wWidth*m_wHeight];
	for (int x = 0 ; x < m_wWidth ; x++)
	for (int y = 0 ; y < m_wHeight ; y++)
	{
		System::Drawing::Color p = Bmp.GetPixel(x,y);
		double R = double(p.R/255.0);
		double V = double(p.G/255.0);
		double B = double(p.B/255.0);
	    int pos = x + y*m_wWidth;
		m_pColorMap[pos] = Color(R,V,B);
	}
	delete systemstring;
}
 	
Texture::~Texture()
{
	delete [] m_pColorMap;
}

 
Color Texture::Interpol(double x,double y) const
{
	int xx,yy;
	double cx,cy;
	double ccx,ccy;
	while ( x < 0 ) x += m_wWidth;
	while ( y < 0 ) y += m_wHeight;
	while ( x >= m_wWidth ) x -= m_wWidth;
	while ( y >= m_wHeight ) y -= m_wHeight;
	xx = int(x);
	yy = int(y);

	cx=x-xx;
	cy=y-yy;

	ccx=cx*cx;
	ccy=cy*cy;

	return      GetColor(xx  ,yy  ) * (1-ccx)*(1-ccy)
			+	GetColor(xx+1,yy  ) * ccx*(1-ccy)
			+	GetColor(xx  ,yy+1) * (1-ccx)*ccy
			+	GetColor(xx+1,yy+1) * ccx*ccy;
}

Color Texture::relativePixelColor(double u,double v) const
{
  return Interpol(u*m_wWidth,v*m_wHeight);
}

void Texture::Bump(double u,double v,double &dhdu,double &dhdv) const
{
	double x = u*m_wWidth;
	double y = v*m_wHeight;

	double vv  = Interpol(x,y).GreyLevel();
    double vx  = Interpol(x+1,y).GreyLevel();
    double vy  = Interpol(x,y+1).GreyLevel();

	dhdu = vx-vv;
	dhdv = vy-vv;
}


Color Texture::GetColor(int x,int y) const
{
	while ( x < 0) x+= m_wWidth;
	while ( y < 0) y+= m_wHeight;
	x = x % m_wWidth; 
	y = y % m_wHeight;
	if(m_pColorMap)
		return m_pColorMap[ x + y * m_wWidth ];

	return Color();
}