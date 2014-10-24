#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include "Alien.h"

void Alien::draw(){};
void Alien::roda(){};
void Alien::moveRight(){};
void Alien::moveLeft(){};
void Alien::moveDown(){};
float Alien::getX(){ return _x; };
float Alien::getY(){ return _y; };
float Alien::getZ(){ return _z; };

Alien::Alien(float x, float y, float z): _x(x), _y(y), _z(z), _dead(false) {};

void Alien::setCoords(float x, float y, float z)
{
	_x = x;
	_y = y;
	_z = z;
}

void Alien::setDead(bool x)
{
	_dead = x;
}

bool Alien::getDead()
{
	return _dead;
}