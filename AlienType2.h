#ifndef ALIENTYPE2_H
#define ALIENTYPE2_H
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

#include "Alien.h"

class AlienType2:public Alien{
private:
	float _x;
	float _y;
	float _z;
	bool _dead;

public:
	AlienType2(){};
	AlienType2(float x, float y, float z);
	virtual void draw();
	virtual void roda();
	virtual void moveRight();
	virtual void moveLeft();
	virtual void moveDown();
	virtual float getX();
	virtual float getY();
	virtual float getZ();

	void setDead(bool x);
	bool getDead();

	~AlienType2();
};

#endif
