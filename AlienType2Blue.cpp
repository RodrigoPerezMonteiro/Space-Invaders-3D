#include "Alien.h"
#include "AlienType2.h"
#include "AlienType2Blue.h"

AlienType2Blue::AlienType2Blue(float x, float y, float z): _x(x), _y(y), _z(z), _dead(false){};

void AlienType2Blue::draw(){
	
	 glPushMatrix();
	 glTranslatef(_x, _y, _z);
	 
	   //Cabeça
	   glPushMatrix();
	     GLfloat amb2[] = { 0.12, 0.56, 1, 1.0 };
  GLfloat diff2[] = { 0.12, 0.56, 1, 1.0 };
  GLfloat spec2[] = { 0.0, 0.0, 0.0, 1.0 };
  glMaterialfv(GL_FRONT, GL_AMBIENT, amb2);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff2);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec2);
	  // glColor3f (0.12, 0.56, 1);
	   glScalef(1, 1, 1);
	   glutSolidCube(1.0f);
	   glPopMatrix();
	   
	   //Perna Esquerda
	   glPushMatrix();
	   glMaterialfv(GL_FRONT, GL_AMBIENT, amb2);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff2);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec2);
	  // glColor3f (0.12, 0.56, 1);
	   glTranslatef(-0.2, -0.9, 0);
	   glScalef(0.2, 0.8, 0.2);
	   glutSolidCube(1.0f);
	   glPopMatrix();

	   //Pé Esquerdo
	   glPushMatrix();
	   glMaterialfv(GL_FRONT, GL_AMBIENT, amb2);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff2);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec2);
	   //glColor3f (0.12, 0.56, 1);
	   glTranslatef(-0.35, -1.2, 0);
	   glScalef(0.2, 0.2, 0.2);
	   glutSolidCube(1.0f);
	   glPopMatrix();

	   //Perna Direita
	   glPushMatrix();
	   glMaterialfv(GL_FRONT, GL_AMBIENT, amb2);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff2);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec2);
	  // glColor3f (0.12, 0.56, 1);
	   glTranslatef(0.2, -0.9, 0);
	   glScalef(0.2, 0.8, 0.2);
	   glutSolidCube(1.0f);
	   glPopMatrix();

	   //Pé Direito
	   glPushMatrix();
	   glMaterialfv(GL_FRONT, GL_AMBIENT, amb2);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff2);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec2);
	  // glColor3f (0.12, 0.56, 1);
	   glTranslatef(0.35, -1.2, 0);
	   glScalef(0.2, 0.2, 0.2);
	   glutSolidCube(1.0f);
	   glPopMatrix();

	   //Olho Direito
	   glPushMatrix();
	   GLfloat amb1[] = { 0,0,0, 1.0 };
  GLfloat diff1[] = { 0,0,0, 1.0 };
  GLfloat spec1[] = { 0.0, 0.0, 0.0, 1.0 };
  glMaterialfv(GL_FRONT, GL_AMBIENT, amb1);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff1);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec1);
	 //  glColor3f (0,0,0);
	   glTranslatef(0.2, 0, 0.55);
	   glScalef(0.2, 0.2, 0.1);
	   glutSolidCube(1.0f);
	   glPopMatrix();

	   //Olho Esquerdo
	   glPushMatrix();
	     glMaterialfv(GL_FRONT, GL_AMBIENT, amb1);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff1);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec1);
	  //glColor3f (0,0,0);
	   glTranslatef(-0.2, 0, 0.55);
	   glScalef(0.2, 0.2, 0.1);
	   glutSolidCube(1.0f);
	   glPopMatrix();

	   //Boca
	   glPushMatrix();
	     glMaterialfv(GL_FRONT, GL_AMBIENT, amb1);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff1);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec1);
	  // glColor3f (0,0,0);
	   glTranslatef(0, -0.3, 0.55);
	   glScalef(0.4, 0.2, 0.1);
	   glutSolidCube(1.0f);
	   glPopMatrix();
	   
	 glPopMatrix();
}

void AlienType2Blue::roda(){

	glPushMatrix();
	glTranslatef(_x, _y, _z);
	glRotatef(90, 1, 0, 0);
	glTranslatef(-_x, -_y, -_z);
	draw();
	glPopMatrix();

}


void AlienType2Blue::moveRight(){

	_x+=.2;

}

void AlienType2Blue::moveLeft(){

	_x-=.2;

}

void AlienType2Blue::moveDown(){

	_y-=.2/50;

}

float AlienType2Blue::getX(){

	return _x;

}

float AlienType2Blue::getY(){

	return _y;

}

float AlienType2Blue::getZ(){

	return _z;

}

void AlienType2Blue::setDead(bool x)
{
	_dead = x;
}

bool AlienType2Blue::getDead()
{
	return _dead;
}