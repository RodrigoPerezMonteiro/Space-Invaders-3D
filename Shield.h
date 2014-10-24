#ifndef SHIELD_H
#define SHIELD_H
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

class Shield{	
private:
	float _x;
	float _y;
	float _z;
	int _Lives;

public:
	Shield(float x, float y, float z);
	void wasHit();
	void draw();
	~Shield();
};

#endif