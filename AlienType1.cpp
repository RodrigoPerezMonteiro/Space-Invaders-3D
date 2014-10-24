#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include "Alien.h"
#include "AlienType1.h"

AlienType1::AlienType1(float x, float y, float z) : _x(x), _y(y), _z(z), _dead(false) {}

void AlienType1::draw(){
	 glPushMatrix();
	 glTranslatef(_x, _y, _z);
	 
	   //Corpo do Alien
	   glPushMatrix();
	   GLfloat amb1[] = { 1, 0.0, 0.0, 1.0 };
	   GLfloat diff1[] = { 1, 0.0, 0.0, 1.0 };
	   GLfloat spec1[] = { 0.0, 0.0, 0.0, 1.0 };
	   glMaterialfv(GL_FRONT, GL_AMBIENT, amb1);
	   glMaterialfv(GL_FRONT, GL_DIFFUSE, diff1);
	   glMaterialfv(GL_FRONT, GL_SPECULAR, spec1);
	   //glColor3f (1,0,0);
	   glScalef(1, 1, 1);
	   glutSolidCube(1.0f);
	   glPopMatrix();

	   //Olhos do Alien
	   glPushMatrix();
	   GLfloat amb2[] = { 0.0, 0.0, 0.0, 1.0 };
	   GLfloat diff2[] = { 0.0, 0.0, 0.0, 1.0 };
	   GLfloat spec2[] = { 0.0, 0.0, 0.0, 1.0 };
	   glMaterialfv(GL_FRONT, GL_AMBIENT, amb2);
	   glMaterialfv(GL_FRONT, GL_DIFFUSE, diff2);
	   glMaterialfv(GL_FRONT, GL_SPECULAR, spec2);

	   //glColor3f (0.0, 0.0, 0.0);
	   glTranslatef(-0.2, 0, 0.55);
	   glScalef(0.2, 0.2, 0.1);
	   glutSolidCube(1.0f);
	   glPopMatrix();

	   glPushMatrix();
	   glMaterialfv(GL_FRONT, GL_AMBIENT, amb2);
	   glMaterialfv(GL_FRONT, GL_DIFFUSE, diff2);
	   glMaterialfv(GL_FRONT, GL_SPECULAR, spec2);
	  // glColor3f (0.0, 0.0, 0.0);
	   glTranslatef(0.2, 0, 0.55);
	   glScalef(0.2, 0.2, 0.1);
	   glutSolidCube(1.0f);
	   glPopMatrix();

	   //Antenas do Alien
	   //Antena Esquerda
	   glPushMatrix();
	   GLfloat amb3[] = { 0.0, 0.0, 1, 1.0 };
	   GLfloat diff3[] = { 0.0, 0.0, 1, 1.0 };
	   GLfloat spec3[] = { 0.0, 0.0, 0.0, 1.0 };
	   glMaterialfv(GL_FRONT, GL_AMBIENT, amb3);
	   glMaterialfv(GL_FRONT, GL_DIFFUSE, diff3);
	   glMaterialfv(GL_FRONT, GL_SPECULAR, spec3);
	   //glColor3f (0.0, 0.0, 1.0);
	   glTranslatef(-0.2, 0.75, 0);
	   glRotatef(90, 1, 0, 0);
	   glScalef(0.15, 0.15, 0.5);
	   glutSolidCube(1.0f);
	   glPopMatrix();

	   //Antena Direita
	   glPushMatrix();
	   glMaterialfv(GL_FRONT, GL_AMBIENT, amb3);
	   glMaterialfv(GL_FRONT, GL_DIFFUSE, diff3);
	   glMaterialfv(GL_FRONT, GL_SPECULAR, spec3);
	 //  glColor3f (0.0, 0.0, 1.0);
	   glTranslatef(0.2, 0.75, 0);
	   glRotatef(90, -1, 0, 0);
	   glScalef(0.15, 0.15, 0.5);
	   glutSolidCube(1.0f);
	   glPopMatrix();

	   //Pernas do Alien
	   //Perna Esquerda
	   glPushMatrix();
	   glMaterialfv(GL_FRONT, GL_AMBIENT, amb1);
	   glMaterialfv(GL_FRONT, GL_DIFFUSE, diff1);
	   glMaterialfv(GL_FRONT, GL_SPECULAR, spec1);
	  // glColor3f (1.0, 0.0, 0.0);
	   glTranslatef(-0.2, -0.9, 0);
	   glScalef(0.2, 0.8, 0.2);
	   glutSolidCube(1.0f);
	   glPopMatrix();

	   //Pé Esquerdo
	   glPushMatrix();
	   glMaterialfv(GL_FRONT, GL_AMBIENT, amb1);
	   glMaterialfv(GL_FRONT, GL_DIFFUSE, diff1);
	   glMaterialfv(GL_FRONT, GL_SPECULAR, spec1);
	  // glColor3f (1.0, 0.0, 0.0);
	   glTranslatef(-0.35, -1.2, 0);
	   glScalef(0.2, 0.2, 0.2);
	   glutSolidCube(1.0f);
	   glPopMatrix();

	   //Perna Direita
	   glPushMatrix();
	   glMaterialfv(GL_FRONT, GL_AMBIENT, amb1);
	   glMaterialfv(GL_FRONT, GL_DIFFUSE, diff1);
	   glMaterialfv(GL_FRONT, GL_SPECULAR, spec1);
	  // glColor3f (1.0, 0.0, 0.0);
	   glTranslatef(0.2, -0.9, 0);
	   glScalef(0.2, 0.8, 0.2);
	   glutSolidCube(1.0f);
	   glPopMatrix();

	   //Pé Direito
	   glPushMatrix();
	   glMaterialfv(GL_FRONT, GL_AMBIENT, amb1);
	   glMaterialfv(GL_FRONT, GL_DIFFUSE, diff1);
	   glMaterialfv(GL_FRONT, GL_SPECULAR, spec1);
	   //glColor3f (1.0, 0.0, 0.0);
	   glTranslatef(0.35, -1.2, 0);
	   glScalef(0.2, 0.2, 0.2);
	   glutSolidCube(1.0f);
	   glPopMatrix();
	   
	 glPopMatrix();
	 
}

void AlienType1::roda(){

	glPushMatrix();
	glTranslatef(_x, _y, _z);
	glRotatef(90, 1, 0, 0);
	glTranslatef(-_x, -_y, -_z);
	draw();
	glPopMatrix();

}

void AlienType1::moveRight(){

	_x+=.2;

}

void AlienType1::moveLeft(){

	_x-=.2;

}

void AlienType1::moveDown(){

	_y-=.2/50;

}

float AlienType1::getX(){

	return _x;

}

float AlienType1::getY(){

	return _y;

}

float AlienType1::getZ(){

	return _z;

}

void AlienType1::setDead(bool x)
{
	_dead = x;
}

bool AlienType1::getDead()
{
	return _dead;
}