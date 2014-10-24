#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

#include "Alien.h"
#include "AlienType1.h"	
#include "AlienType2.h"
#include "AlienType2Green.h"
#include "AlienType2Blue.h"
#include "Shield.h"
#include "Spaceship.h"
#include "Camera.h"
#include "Tiro.h"
#include "TiroAlien.h"
#include "Texture.h"

#include <vector>

class GameManager{	
private:
	std::vector<Alien*> _Aliens;
	std::vector<Shield*> _Shields;
	std::vector<Camera*> _Cameras;

	Camera* Cam;
	Tiro* _Tiro;
	TiroAlien* _TiroAlien;
	Spaceship* _Spaceship;
	Alien* alien;
	Shield* _shield;

	bool LeftToRight;
	bool RightToLeft;
	bool onlyOnce;
	bool _Restart;
	bool _GameOver;

	int _Aliens1, _Aliens2, _Aliens3, _Aliens4, _NShields, _totalAliens;
	int _background;
	int _currentCam;
	int _Score;

	float _Size;
	float _Racio;
	float _SpaceshipX, _SpaceshipY, _SpaceshipZ, _AlienX, _AlienY, _AlienZ;

	Texture _texture;

public:
	GameManager(){};

	void init(int Aliens1, int Aliens2, int Aliens3, int Aliens4, float SpaceshipX, float SpaceshipY, float SpaceshipZ, float AlienX, float AlienY, float AlienZ, int Shields, float size, float racio);
	void setup();
	void draw();
	void actualizaNave(float pos);
	void showCam();
	void alienMoving(float WinSize);
	void disparoAliens();
	void dispAlien();
	void setTiroAlienFalse();
	void moveRight();
	void moveLeft();
	void moveDown();
	void disparar();
	void moveTiro();
	void desenhaTiro();
	void desenhaTiroAlien();
	void moveTiroAlien();
	void setTiroFalse();
	void destroiTiro();
	void changeCamera(std::string nome, float racio, float size);
	void setSpotlightON();
	void setSpotlightOFF();
	void drawBackground();
	void setupBackground();
	void setRestart(bool boolean);
	void HUD(GLfloat x, GLfloat y, std::string s);

	int randomnumber();
	int getCurrentCam();
	int getLives();
	int getPoints();

	float getTiroAlienY();
	float getTiroY();
	float getSpaceshipX();
	float getSpaceshipY();
	float getSpaceshipZ();

	bool getExisteTiro();
	bool podeDisparar(int n);
	bool getSpaceshipLightsStatus();
	bool getGameOver();
	bool getRestart();
};

#endif