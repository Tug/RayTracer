#ifndef _H_ZBUFFER
#define _H_ZBUFFER

#include <limits>

class ZBuffer
{
private:
	double * zbuff;
	int width, height;

public:
	ZBuffer(int width, int height);
	~ZBuffer();
	void setZ(int i, int j, double zValue);
	double getZ(int i, int j);
	void reset();
};


#endif