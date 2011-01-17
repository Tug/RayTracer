#include "stdafx.h"
#include "RGBColor.h"


const RGBColor RGBColor::RED(1,0,0);
const RGBColor RGBColor::GREEN(0,1,0);
const RGBColor RGBColor::BLUE(0,0,1);
const RGBColor RGBColor::YELLOW(1,1,0);
const RGBColor RGBColor::MAGENTA(1,0,1);
const RGBColor RGBColor::CYAN(0,1,1);
const RGBColor RGBColor::WHITE(1,1,1);
const RGBColor RGBColor::BLACK(0,0,0);
const RGBColor RGBColor::GREY(0.5,0.5,0.5);

RGBColor::RGBColor():
m_R(0),
m_G(0),
m_B(0)
{
}

RGBColor::RGBColor(double R,double G,double B)
:
m_R(R),
m_G(G),
m_B(B)
{
}

RGBColor::RGBColor(const RGBColor &color):
m_R(color.m_R),
m_G(color.m_G),
m_B(color.m_B)
{
}

RGBColor::~RGBColor()
{
}

void RGBColor::checkBounds() {
	if(m_R < 0) m_R = 0;
	else if(m_R>1) m_R = 1;
	if(m_G < 0) m_G = 0;
	else if(m_G>1) m_G = 1;
	if(m_B < 0) m_B = 0;
	else if(m_B>1) m_B = 1;
}

RGBColor & RGBColor::operator=(const RGBColor& color)
{
	m_R=color.m_R;
	m_G=color.m_G;
	m_B=color.m_B;

	return *this;
}

double RGBColor::GreyLevel()
{
	return (m_R+m_G+m_B)/3;
}

RGBColor RGBColor::commonColor(std::string & colorName)
{
	if(colorName == "RED") {
		return RGBColor::RED;
	} else if(colorName == "GREEN") {
		return RGBColor::GREEN;
	} else if(colorName == "BLUE") {
		return RGBColor::BLUE;
	} else if(colorName == "YELLOW") {
		return RGBColor::YELLOW;
	} else if(colorName == "MAGENTA") {
		return RGBColor::MAGENTA;
	} else if(colorName == "CYAN") {
		return RGBColor::CYAN;
	} else if(colorName == "WHITE") {
		return RGBColor::WHITE;
	} else if(colorName == "BLACK") {
		return RGBColor::BLACK;
	} else if(colorName == "GREY") {
		return RGBColor::GREY;
	}
	return RGBColor::BLACK;
}

//////////////////////////////////////////////////////////////////////

RGBColor operator + (const RGBColor & a, const RGBColor & b)
{
  RGBColor t;
  t.m_R = a.m_R + b.m_R;
  t.m_G = a.m_G + b.m_G;
  t.m_B = a.m_B + b.m_B;
  return t;
}


RGBColor operator - (const RGBColor & a, const RGBColor & b)
{
  RGBColor t;
  t.m_R = a.m_R - b.m_R;
  t.m_G = a.m_G - b.m_G;
  t.m_B = a.m_B - b.m_B;
  return t;
}

RGBColor operator - (const RGBColor & b)
{
  RGBColor t;
  t.m_R = - b.m_R;
  t.m_G = - b.m_G;
  t.m_B = - b.m_B;
  return t;
}

RGBColor operator * (double a, const RGBColor & b)
{
  RGBColor t;
  t.m_R = a * b.m_R;
  t.m_G = a * b.m_G;
  t.m_B = a * b.m_B;
  return t;
}

RGBColor operator * (const RGBColor & b, double a)
{
  RGBColor t;
  t.m_R = b.m_R * a;
  t.m_G = b.m_G * a;
  t.m_B = b.m_B * a;
  return t;
}

RGBColor operator % (const RGBColor & a,const RGBColor & b)
{
  RGBColor t;
  t.m_R = a.m_R * b.m_R;
  t.m_G = a.m_G * b.m_G;
  t.m_B = a.m_B * b.m_B;
  return t;
}


RGBColor operator / (const RGBColor & b, double a)
{
  RGBColor t;
  t.m_R = b.m_R / a;
  t.m_G = b.m_G / a;
  t.m_B = b.m_B / a;
  return t;
}
