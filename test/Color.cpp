#include "stdafx.h"
#include "Color.h"


const Color Color::RED(1,0,0);
const Color Color::GREEN(0,1,0);
const Color Color::BLUE(0,0,1);
const Color Color::YELLOW(1,1,0);
const Color Color::MAGENTA(1,0,1);
const Color Color::CYAN(0,1,1);
const Color Color::WHITE(1,1,1);
const Color Color::BLACK(0,0,0);
const Color Color::GREY(0.5,0.5,0.5);

Color::Color():
m_R(0),
m_G(0),
m_B(0)
{
}

Color::Color(double R,double G,double B)
:
m_R(R),
m_G(G),
m_B(B)
{
}

Color::Color(const Color &color):
m_R(color.m_R),
m_G(color.m_G),
m_B(color.m_B)
{
}

Color::~Color()
{
}

void Color::checkBounds() {
	if(m_R < 0) m_R = 0;
	else if(m_R>1) m_R = 1;
	if(m_G < 0) m_G = 0;
	else if(m_G>1) m_G = 1;
	if(m_B < 0) m_B = 0;
	else if(m_B>1) m_B = 1;
}

Color & Color::operator=(const Color& color)
{
	m_R=color.m_R;
	m_G=color.m_G;
	m_B=color.m_B;

	return *this;
}

double Color::GreyLevel()
{
	return (m_R+m_G+m_B)/3;
}

Color Color::commonColor(std::string & colorName)
{
	if(colorName == "RED") {
		return Color::RED;
	} else if(colorName == "GREEN") {
		return Color::GREEN;
	} else if(colorName == "YELLOW") {
		return Color::YELLOW;
	} else if(colorName == "MAGENTA") {
		return Color::MAGENTA;
	} else if(colorName == "CYAN") {
		return Color::CYAN;
	} else if(colorName == "WHITE") {
		return Color::WHITE;
	} else if(colorName == "BLACK") {
		return Color::BLACK;
	} else if(colorName == "GREY") {
		return Color::GREY;
	}
	return Color::BLACK;
}

//////////////////////////////////////////////////////////////////////

Color operator + (const Color & a, const Color & b)
{
  Color t;
  t.m_R = a.m_R + b.m_R;
  t.m_G = a.m_G + b.m_G;
  t.m_B = a.m_B + b.m_B;
  return t;
}


Color operator - (const Color & a, const Color & b)
{
  Color t;
  t.m_R = a.m_R - b.m_R;
  t.m_G = a.m_G - b.m_G;
  t.m_B = a.m_B - b.m_B;
  return t;
}

Color operator - (const Color & b)
{
  Color t;
  t.m_R = - b.m_R;
  t.m_G = - b.m_G;
  t.m_B = - b.m_B;
  return t;
}

Color operator * (double a, const Color & b)
{
  Color t;
  t.m_R = a * b.m_R;
  t.m_G = a * b.m_G;
  t.m_B = a * b.m_B;
  return t;
}

Color operator * (const Color & b, double a)
{
  Color t;
  t.m_R = b.m_R * a;
  t.m_G = b.m_G * a;
  t.m_B = b.m_B * a;
  return t;
}

Color operator % (const Color & a,const Color & b)
{
  Color t;
  t.m_R = a.m_R * b.m_R;
  t.m_G = a.m_G * b.m_G;
  t.m_B = a.m_B * b.m_B;
  return t;
}


Color operator / (const Color & b, double a)
{
  Color t;
  t.m_R = b.m_R / a;
  t.m_G = b.m_G / a;
  t.m_B = b.m_B / a;
  return t;
}
