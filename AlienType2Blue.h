#ifndef ALIENTYPE2BLUE_H
#define ALIENTYPE2BLUE_H
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

#include "Alien.h"
#include "AlienType2.h"

class AlienType2Blue:public AlienType2{
private:
	float _x;
	float _y;
	float _z;
	bool _dead;

public:
	AlienType2Blue(float x, float y, float z);
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

	~AlienType2Blue();
};

#endif
