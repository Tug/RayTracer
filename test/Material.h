#ifndef _H_MATERIAL
#define _H_MATERIAL

#define DEFAULT_REFLECTIVITY 0.6
#define DEFAULT_TRANSMITTANCE 0.0
#define DEFAULT_REFRACTIVE_INDEX 1.5

class Material
{
public:
	Material();
	Material(double reflectivity, double transmittance, double refractiveIndex);
	virtual ~Material();
	double getReflectivity();
	double getTransmittance();
	double getRefractiveIndex();
	void setReflectivity(double reflectivity);
	void setTransmittance(double transmittance);
	void setRefractiveIndex(double refractiveIndex);

private:
	double reflectivity;
	double transmittance;
	double refractiveIndex;
};

#endif