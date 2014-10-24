#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include "ALL.h"
#include <string>

Camera::Camera(){}

Camera::Camera(std::string nome, float SpaceShipX, float size, float racio){

	_nome = nome;
	_SpaceShipX = SpaceShipX;
	_size = size;
	_racio = racio;
}

void Camera::changePos(float SpaceShipX){
	_SpaceShipX = SpaceShipX;
}

void Camera::changeRacio(float racio){
	_racio = racio;
}

void Camera::changeSize(float size){
	_size = size;
}

void Camera::showCam(){

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	if(_nome.compare("Vista Ortogonal") == 0)
	{
		if(_racio<1)
		{
			glOrtho(-_size, _size, -_size/_racio, _size/_racio, -_size, _size);
		}

		else
		{
			glOrtho(-_size*_racio, _size*_racio, -_size, _size, -_size, _size);
		}
	}

	else 
	{
		gluPerspective(90, _racio, 1, 50);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		if(_nome.compare("Camara Retaguarda") == 0)
		{
			gluLookAt(_SpaceShipX, -12.5f, 6.f, _SpaceShipX, 0.f, 0.f, 0.f, 0.f, 1.f);
		}

		if(_nome.compare("Camera Primeira Pessoa") == 0)
		{
			gluLookAt(_SpaceShipX, -6.5f, 0.f, _SpaceShipX, 0.f, 0.f, 0.f, 0.f, 1.f);
		}
	}
}

void Camera::changeCam(std::string nome){}