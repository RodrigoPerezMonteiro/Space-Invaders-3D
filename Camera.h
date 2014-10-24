#ifndef CAMERA_H
#define CAMERA_H
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

class Camera{	

public:
	Camera();
	Camera(float x, float y, float z);
	Camera(std::string nome, float SpaceShipX, float size, float racio);
	void changePos(float SpaceShipX);
	void changeCam(std::string nome);
	void changeSize(float size);
	void changeRacio(float racio);
	void showCam();

	std::string _nome;
	float _SpaceShipX;
	float _size;
	float _racio;
	~Camera();
};

#endif