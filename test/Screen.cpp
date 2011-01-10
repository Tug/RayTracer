#include "stdafx.h"

#include "Screen.h"

Screen::Screen(int width, int height) {
	this->width = width;
	this->height = height;
}

Screen::~Screen() {
}

int Screen::getWidth() {
	return width;
}

int Screen::getHeight() {
	return height;
}

void Screen::fillBackground(RGBColor & c) {
	for(int y=0; y<height; y++) {
		for(int x=0; x<width; x++) {
			setPixel(x, y, c);
		}
	}
}
