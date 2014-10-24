#ifndef LIGHTS_H
#define LIGHTS_H
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

class Lights{	
private:
	float _x;
	float _y;
	float _z;

public:
	Lights();
	void lighter(const float x, const float y, const float z, const float amb1, const float amb2, const float amb3, const float diff1, const float diff2, const float diff3, const float spec1, const float spec2, const float spec3);
	~Lights();
};

#endif