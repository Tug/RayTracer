#ifndef _H_COLOR
#define _H_COLOR

#include <string>

// class handling color

class Color
{
	public:
		double m_R,m_G,m_B;						// R,G,B components between 0 and 1
		Color();
		Color(double R,double G,double B);
		double GreyLevel();						// utilise pour le Bump Map
		Color(const Color &color);
		~Color();
		
		void checkBounds();

		Color & operator = (const Color& color);

		static const Color RED;
		static const Color GREEN;
		static const Color BLUE;
		static const Color YELLOW;
		static const Color MAGENTA;
		static const Color CYAN;
		static const Color WHITE;
		static const Color BLACK;
		static const Color GREY;
		static Color commonColor(std::string & colorName);
};

Color operator + (const Color & a, const Color & b);	// add 2 colors
Color operator - (const Color & a, const Color & b);	
Color operator - (const Color & b);					
Color operator * (double a, const Color & b);			// multiply by a float
Color operator * (const Color & b, double a);
Color operator % (const Color & a,const Color & b);   // multiply on each channel RGB
Color operator / (const Color & b, double a);			// divide by a float

#endif