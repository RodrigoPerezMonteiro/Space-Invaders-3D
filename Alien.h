#ifndef ALIEN_H
#define ALIEN_H
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

class Alien{	
private:
	float _x;
	float _y;
	float _z;
	bool _dead;

public:
	Alien(){};		
	Alien(float x, float y, float z);
	virtual void draw();
	virtual void roda();
	virtual void moveRight();
	virtual void moveLeft();
	virtual void moveDown();
	virtual float getX();
	virtual float getY();
	virtual float getZ();
	void setCoords(float x, float y, float z);

	void setDead(bool x);
	bool getDead();

	~Alien();
};

#endif