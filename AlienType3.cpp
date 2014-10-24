#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include "Alien.h"
#include "AlienType3.h"

AlienType3::AlienType3(float x, float y, float z) : _x(x), _y(y), _z(z), _dead(false)  {}

void AlienType3::draw()
{
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
	//  glColor3f (1, 0, 0);
	   glScalef(0.65, 0.75, 0.6);
	   glutSolidSphere(1.f, 100.f, 100.f);
	   glPopMatrix();


	   //Antenas do Alien
	   //Antena Esquerda
	   glPushMatrix();
	     glMaterialfv(GL_FRONT, GL_AMBIENT, amb1);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff1);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec1);
	  // glColor3f (1.0, 0.0, 0.0);
	   glTranslatef(-0.2, 0.8, 0);
	   glRotatef(90, 1, 0, 0);
	   glScalef(0.15, 0.15, 0.2);
	   glutSolidCube(1.0f);
	   glPopMatrix();

	   //Antena Direita
	   glPushMatrix();
	     glMaterialfv(GL_FRONT, GL_AMBIENT, amb1);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff1);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec1);
	  // glColor3f (1.0, 0.0, 0.0);
	   glTranslatef(0.2, 0.8, 0);
	   glRotatef(90, -1, 0, 0);
	   glScalef(0.15, 0.15, 0.2);
	   glutSolidCube(1.0f);
	   glPopMatrix();



	   //Braços do Alien
	   //Ombro Esquerdo
	   glPushMatrix();
	     glMaterialfv(GL_FRONT, GL_AMBIENT, amb1);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff1);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec1);
	  // glColor3f (1.0, 0.0, 0.0);
	   glTranslatef(-0.8, 0, 0);
	   glScalef(0.3, 0.2, 0.2);
	   glutSolidCube(1.0f);
	   glPopMatrix();

	   //Ombro Direito
	   glPushMatrix();
	     glMaterialfv(GL_FRONT, GL_AMBIENT, amb1);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff1);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec1);
	  // glColor3f (1.0, 0.0, 0.0);
	   glTranslatef(0.8, 0, 0);
	   glScalef(0.3, 0.2, 0.2);
	   glutSolidCube(1.0f);
	   glPopMatrix();

	

	   //Braço Esquerdo
	   glPushMatrix();
	     glMaterialfv(GL_FRONT, GL_AMBIENT, amb1);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff1);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec1);
	 //  glColor3f (1.0, 0.0, 0.0);
	   glTranslatef(-0.85, -0.4, 0);
	   glScalef(0.2, 0.6, 0.2);
	   glutSolidCube(1.0f);
	   glPopMatrix();

	   //Braço Direito
	   glPushMatrix();
	     glMaterialfv(GL_FRONT, GL_AMBIENT, amb1);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff1);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec1);
	  // glColor3f (1.0, 0.0, 0.0);
	   glTranslatef(0.85, -0.4, 0);
	   glScalef(0.2, 0.6, 0.2);
	   glutSolidCube(1.0f);
	   glPopMatrix();

	   //Mão Esquerda
	   glPushMatrix();
	     glMaterialfv(GL_FRONT, GL_AMBIENT, amb1);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff1);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec1);
	 //  glColor3f (1.0, 0.0, 0.0);
	   glTranslatef(-0.85, -0.8, 0);
	   glScalef(0.16, 0.16, 0.16);
	   glutSolidSphere(1.0f, 100, 100);
	   glPopMatrix();

	   //Mão Direita
	   glPushMatrix();
	     glMaterialfv(GL_FRONT, GL_AMBIENT, amb1);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff1);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec1);
	  // glColor3f (1.0, 0.0, 0.0);
	   glTranslatef(0.85, -0.8, 0);
	   glScalef(0.16, 0.16, 0.16);
	   glutSolidSphere(1.0f, 100, 100);
	   glPopMatrix();

	   //Faixa Ombro Esquerdo
	   glPushMatrix();
	    GLfloat amb2[] = { 1, 1, 0.0, 1.0 };
  GLfloat diff2[] = { 1, 1, 0.0, 1.0 };
  GLfloat spec2[] = { 0.0, 0.0, 0.0, 1.0 };
  glMaterialfv(GL_FRONT, GL_AMBIENT, amb2);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff2);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec2);
	  // glColor3f (1.0, 1.0, 0.0);
	   glTranslatef(-0.8, 0.1, 0);
	   glScalef(0.3, 0.05, 0.15);
	   glutSolidCube(1.0f);
	   glPopMatrix();

	   //Faixa Ombro Direito
	   glPushMatrix();
	     glMaterialfv(GL_FRONT, GL_AMBIENT, amb2);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff2);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec2);
	 //  glColor3f (1.0, 1.0, 0.0);
	   glTranslatef(0.8, 0.1, 0);
	   glScalef(0.3, 0.05, 0.15);
	   glutSolidCube(1.0f);
	   glPopMatrix();

	   //Olho do Alien
	   glPushMatrix();
	   GLfloat amb3[] = { 1, 1, 1, 1.0 };
  GLfloat diff3[] = { 1, 1, 1, 1.0 };
  GLfloat spec3[] = { 0.0, 0.0, 0.0, 1.0 };
  glMaterialfv(GL_FRONT, GL_AMBIENT, amb3);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff3);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec3);
	 //  glColor3f (1.0, 1.0, 1.0);
	   glTranslatef(-0.0, 0.2, 0.5);
	   glScalef(0.3, 0.35, 0.15);
	   glutSolidSphere(1.0f, 100, 100);
	   glPopMatrix();

	   //Iris do olho Alien
	   glPushMatrix();
	   GLfloat amb4[] = { 0,0, 1, 1.0 };
  GLfloat diff4[] = { 0,0, 1, 1.0 };
  GLfloat spec4[] = { 0.0, 0.0, 0.0, 1.0 };
  glMaterialfv(GL_FRONT, GL_AMBIENT, amb4);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff4);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec4);
	 //  glColor3f (0.0, 0.0, 1.0);
	   glTranslatef(-0.0, 0.2, 0.55);
	   glScalef(0.08, 0.08, 0.045);
	   glutSolidSphere(1.0f, 100, 100);
	   glPopMatrix();



	   //Pernas do Alien
	   //Perna Esquerda
	   glPushMatrix();
	   GLfloat amb5[] = { 1,0, 0, 1.0 };
  GLfloat diff5[] = { 1,0, 0, 1.0 };
  GLfloat spec5[] = { 0.0, 0.0, 0.0, 1.0 };
  glMaterialfv(GL_FRONT, GL_AMBIENT, amb5);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff5);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec5);
	//   glColor3f (1.0, 0.0, 0.0);
	   glTranslatef(-0.2, -0.9, 0);
	   glScalef(0.2, 0.8, 0.2);
	   glutSolidCube(1.0f);
	   glPopMatrix();

	   //Pé Esquerdo
	   glPushMatrix();
	   glMaterialfv(GL_FRONT, GL_AMBIENT, amb1);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff1);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec1);
	 //  glColor3f (1.0, 0.0, 0.0);
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
	  // glColor3f (1.0, 0.0, 0.0);
	   glTranslatef(0.35, -1.2, 0);
	   glScalef(0.2, 0.2, 0.2);
	   glutSolidCube(1.0f);
	   glPopMatrix();
	   
	 glPopMatrix();
	 
}

void AlienType3::roda(){

	glPushMatrix();
	glTranslatef(_x, _y, _z);
	glRotatef(90, 1, 0, 0);
	glTranslatef(-_x, -_y, -_z);
	draw();
	glPopMatrix();

}

void AlienType3::moveRight(){

	_x+=.2;

}

void AlienType3::moveLeft(){

	_x-=.2;

}

void AlienType3::moveDown(){

	_y-=.2/50;

}

float AlienType3::getX(){

	return _x;

}

float AlienType3::getY(){

	return _y;

}

float AlienType3::getZ(){

	return _z;

}

void AlienType3::setDead(bool x)
{
	_dead = x;
}

bool AlienType3::getDead()
{
	return _dead;
}