#ifndef _H_MODEL
#define _H_MODEL

#include "Screen.h"
#include "RGBColor.h"
#include "Material.h"
#include "Texture.h"
#include "P3.h"
#include "P3S.h"
#include "Object3D.h"

class Model
{
public:
	Model();
	virtual ~Model();
	RGBColor getColor(double x, double y);
	P3 bumpNormal(double x, double y, P3 & normal);
	virtual void surfaceColorAndBump(Object3D * object3D, P3 & surfPoint, RGBColor * color, P3 * bumpedNormal) = 0;
	Texture * getTexture();
	Texture * getBump();
	Material & getMaterial();
	RGBColor & getColor();
	double getTextureScale();
	void setTexture(Texture * texture);
	void setColor(RGBColor & c);
	void setBump(Texture * bump);
	void setMaterial(Material & material);
	void setTextureScale(double textureScale);

private:
	RGBColor c;
	Texture * texture;
	Texture * bump;
	Material material;
	double textureScale;
};


#endif