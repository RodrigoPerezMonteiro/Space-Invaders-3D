#ifndef TIROALIEN_H
#define TIROALIEN_H
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

class TiroAlien{	
private:
	float _x;
	float _y;
	float _z;

public:
	TiroAlien(float x, float y, float z);
	void draw();
	void movingDown();
	float getPosY();
	~TiroAlien();
};

#endif