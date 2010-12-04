#ifndef _H_Texture
#define _H_Texture

#include "P3.h"
#include "Color.h"
#include <string>

// classe handling textures

class Texture
{
	protected:
		Color *m_pColorMap;
		int	m_wWidth,m_wHeight;
		Color Interpol(double x,double y) const;
		Color GetColor(int x,int y) const;

    public:
		Texture(std::string fileName);
		void load();
		~Texture();
				
		// les paramètres u et v sont independants de la résolution de la texture
		// qui peut etre 64x64 ou 512x512. Par convention ils varient entre 0 et 1
		// une valeur hors de la plage [0,1] est tronquée pour la ramener dans cette plage
		// ainsi (2.3,4.5) => (0.3,0.5)

		Color	relativePixelColor(double u,double v) const; 
		void	Bump (double u,double v,double &dhdu,double &dhdv) const;  // pour le bump map

	private:
		std::string fileName;
		bool loaded;
};

#endif
