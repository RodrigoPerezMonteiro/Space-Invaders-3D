#ifndef ALIENTYPE4_H
#define ALIENTYPE4_H
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

#include "Alien.h"

class AlienType4:public Alien{
protected:
	float _x;
	float _y;
	float _z;
	bool _dead;


public:
	AlienType4(){};
	AlienType4(float x, float y, float z);
	void draw();
	void moveRight();
	void moveLeft();
	void moveDown();
	void roda();
	float getX();
	float getY();
	float getZ();

	void setDead(bool x);
	bool getDead();

	~AlienType4();
};

#endif