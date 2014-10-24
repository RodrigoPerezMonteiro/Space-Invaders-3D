#include "Alien.h"
#include "AlienType2.h"

void AlienType2::draw(){};
void AlienType2::roda(){};
void AlienType2::moveRight(){};
void AlienType2::moveLeft(){};
void AlienType2::moveDown(){};
float AlienType2::getX(){return _x;};
float AlienType2::getY(){return _y;};
float AlienType2::getZ(){return _z;};

AlienType2::AlienType2(float x, float y, float z): _x(x), _y(y), _z(z), _dead(false){};

void AlienType2::setDead(bool x)
{
	_dead = x;
}

bool AlienType2::getDead()
{
	return _dead;
}