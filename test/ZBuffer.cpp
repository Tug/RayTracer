#include "stdafx.h"
#include "ZBuffer.h"

ZBuffer::ZBuffer(int width, int height)
{
	this->width = width;
	this->height = height;
	this->zbuff = new double[width*height];
	reset();
}

ZBuffer::~ZBuffer() {
	delete[] zbuff;
}

void ZBuffer::reset() {
	int len = width*height;
	double maxDouble = std::numeric_limits<double>::max();
	for(int i=0; i<len; i++) {
		zbuff[i] = maxDouble;
	}
}

void ZBuffer::setZ(int i, int j, double zValue)
{
	zbuff[i*width+j] = zValue;
}

double ZBuffer::getZ(int i, int j)
{
	return zbuff[i*width+j];
}