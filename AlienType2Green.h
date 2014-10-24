#ifndef ALIENTYPE2GREEN_H
#define ALIENTYPE2GREEN_H
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

#include "Alien.h"
#include "AlienType2.h"

class AlienType2Green:public AlienType2{
private:
	float _x;
	float _y;
	float _z;
	bool _dead;

public:
	AlienType2Green(float x, float y, float z);
	void draw();
	void roda();

	void setDead(bool x);
	bool getDead();

	~AlienType2Green();
};

#endif
