#ifndef TIRO_H
#define TIRO_H
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

class Tiro{	
private:
	float _x;
	float _y;
	float _z;

public:
	Tiro();
	Tiro(float x, float y, float z);
	void draw();
	void movingUp();
	float getPositionY();
	~Tiro();
};

#endif