#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

class Spaceship{	
private:
	float _x;
	float _y;
	float _z;
	bool _lightON;
	int _Lives;

public:
	Spaceship();
	Spaceship(float x, float y, float z);
	int getLives();
	void wasHit();
	void draw();
	void actualizaPos(float x);
	void disable();
	void enable();
	bool getLightsStatus(); // devolve o estado do spotlight
	float getX();
	float getY();
	float getZ();
	~Spaceship();
};
#endif