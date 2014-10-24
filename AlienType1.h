#ifndef ALIENTYPE1_H
#define ALIENTYPE1_H
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

#include "Alien.h"

class AlienType1:public Alien{
protected:
	float _x;
	float _y;
	float _z;
	bool _dead;

public:
	AlienType1(){};
	AlienType1(float x, float y, float z);
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

	~AlienType1();
};

#endif
