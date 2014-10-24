#ifndef ALIENTYPE3_H
#define ALIENTYPE3_H
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

#include "Alien.h"

class AlienType3:public Alien{
protected:
	float _x;
	float _y;
	float _z;
	bool _dead;

public:
	AlienType3(){};
	AlienType3(float x, float y, float z);
	void draw();
	void roda();
	void moveRight();
	void moveLeft();
	void moveDown();
	float getX();
	float getY();
	float getZ();

	void setDead(bool x);
	bool getDead();

	~AlienType3();
};

#endif