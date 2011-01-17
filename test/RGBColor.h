#ifndef _H_RGBCOLOR
#define _H_RGBCOLOR

#include <string>

// class handling color

class RGBColor
{
	public:
		double m_R,m_G,m_B;						// R,G,B components between 0 and 1
		RGBColor();
		RGBColor(double R,double G,double B);
		double GreyLevel();						// utilise pour le Bump Map
		RGBColor(const RGBColor &color);
		~RGBColor();
		
		void checkBounds();

		RGBColor & operator = (const RGBColor& color);

		static const RGBColor RED;
		static const RGBColor GREEN;
		static const RGBColor BLUE;
		static const RGBColor YELLOW;
		static const RGBColor MAGENTA;
		static const RGBColor CYAN;
		static const RGBColor WHITE;
		static const RGBColor BLACK;
		static const RGBColor GREY;
		static RGBColor commonColor(std::string & colorName);
};

RGBColor operator + (const RGBColor & a, const RGBColor & b);	// add 2 colors
RGBColor operator - (const RGBColor & a, const RGBColor & b);	
RGBColor operator - (const RGBColor & b);					
RGBColor operator * (double a, const RGBColor & b);			// multiply by a float
RGBColor operator * (const RGBColor & b, double a);
RGBColor operator % (const RGBColor & a,const RGBColor & b);   // multiply on each channel RGB
RGBColor operator / (const RGBColor & b, double a);			// divide by a float

#endif