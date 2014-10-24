#include "Spaceship.h"

Spaceship::Spaceship(float x, float y, float z):_Lives(3), _x(x), _y(y),_z(z), _lightON(false){};
Spaceship::Spaceship(){};

void Spaceship::draw(){

	glPushMatrix();

	if(_lightON)
	{
		GLfloat ambient1[] = { 0.7, 0.7, 0.7, 1.0};
		GLfloat diffuse1[] = { 1.0, 1.0, 1.0, 1.0};
		GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
		GLfloat light_position[] = {getX(), getY()-2, -.5, 1.0};
		GLfloat spotDir[] = {0, 1.0, 0.0, 0.0};

		glLightfv(GL_LIGHT1, GL_AMBIENT, ambient1);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1);
		glLightfv(GL_LIGHT1, GL_SPECULAR, mat_specular);
		glLightfv(GL_LIGHT1, GL_POSITION, light_position);
		glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotDir);
		glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 25.0);
		glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 50.0);
	}
	 
	// MATERIAL

	GLfloat amb[] = {0.19225, 0.19225, 0.19225, 1.0 };
	GLfloat dif[] = {0.50754, 0.50754, 0.50754, 1.0};
	GLfloat spec[] = {0.508273, 0.508273, 0.508273, 1.0};
	GLfloat shine[] = {128*.4};
	glMaterialfv(GL_FRONT, GL_AMBIENT, amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
	glMaterialfv(GL_FRONT,GL_SHININESS, shine);

	glPushMatrix();

	// SHIP DRAW

	glBegin(GL_QUADS);//face de frente
	glNormal3f(0, 0, 1);
	glVertex3f(_x-0.7, _y+0.25, _z+0.25);
	glVertex3f(_x+0.7, _y+0.25, _z+0.25);
	glVertex3f(_x+0.7, _y-0.25, _z+0.25);
	glVertex3f(_x-0.7, _y-0.25, _z+0.25);
	glEnd();

	glBegin(GL_QUADS); //face de tras
	glNormal3f(0, 0, -1);
	glVertex3f(_x-0.7, _y+0.25, _z-0.25);
	glVertex3f(_x+0.7, _y+0.25, _z-0.25);
	glVertex3f(_x+0.7, _y-0.25, _z-0.25);
	glVertex3f(_x-0.7, _y-0.25, _z-0.25);
	glEnd();

	glBegin(GL_QUADS);//face lateral direita
	glNormal3f(1, 0, 0);
	glVertex3f(_x+0.7, _y+0.25, _z+0.25);
	glVertex3f(_x+0.7, _y+0.25, _z-0.25);
	glVertex3f(_x+0.7, _y-0.25, _z-0.25);
	glVertex3f(_x+0.7, _y-0.25, _z+0.25);
	glEnd();

	glBegin(GL_QUADS);//face lateral esquerda
	glNormal3f(-1, 0, 0);
	glVertex3f(_x-0.7, _y+0.25, _z+0.25);
	glVertex3f(_x-0.7, _y+0.25, _z-0.25);
	glVertex3f(_x-0.7, _y-0.25, _z-0.25);
	glVertex3f(_x-0.7, _y-0.25, _z+0.25);
	glEnd();

	glBegin(GL_QUADS);//face de cima
	glNormal3f(0, 1, 0);
	glVertex3f(_x-0.7, _y+0.25, _z+0.25);
	glVertex3f(_x+0.7, _y+0.25, _z+0.25);
	glVertex3f(_x+0.7, _y-0.25, _z+0.25);
	glVertex3f(_x-0.7, _y-0.25, _z+0.25);
	glEnd();

	glBegin(GL_QUADS);//face de baixo
	glNormal3f(0, -1, 0);
	glVertex3f(_x-0.7, _y-0.25, _z+0.25);
	glVertex3f(_x+0.7, _y-0.25, _z+0.25);
	glVertex3f(_x+0.7, _y-0.25, _z-0.25);
	glVertex3f(_x-0.7, _y-0.25, _z-0.25);
	glEnd();

	//paralelipipedo do centro
	glBegin(GL_QUADS);//face de frente
	glNormal3f(0, 0, 1);
	glVertex3f(_x-0.13, _y+0.25, _z+0.25);
	glVertex3f(_x+0.13, _y+0.25, _z+0.25);
	glVertex3f(_x+0.13, _y+0.7, _z+0.25);
	glVertex3f(_x-0.13, _y+0.7, _z+0.25);
	glEnd();

	glBegin(GL_QUADS);//face de tras
	glNormal3f(0, 0, -1);
	glVertex3f(_x-0.13, _y+0.25, _z-0.25);
	glVertex3f(_x+0.13, _y+0.25, _z-0.25);
	glVertex3f(_x+0.13, _y+0.7, _z-0.25);
	glVertex3f(_x-0.13, _y+0.7, _z-0.25);
	glEnd();

	glBegin(GL_QUADS);//face lateral direita
	glNormal3f(1, 0, 0);
	glVertex3f(_x+0.13, _y+0.25, _z+0.25);
	glVertex3f(_x+0.13, _y+0.25, _z-0.25);
	glVertex3f(_x+0.13, _y+0.7, _z-0.25);
	glVertex3f(_x+0.13, _y+0.7, _z+0.25);
	glEnd();

	glBegin(GL_QUADS);//face lateral esquerda
	glNormal3f(-1, 0, 0);
	glVertex3f(_x-0.13, _y+0.25, _z+0.25);
	glVertex3f(_x-0.13, _y+0.25, _z-0.25);
	glVertex3f(_x-0.13, _y+0.7, _z-0.25);
	glVertex3f(_x-0.13, _y+0.7, _z+0.25);
	glEnd();

	glBegin(GL_QUADS);//face de cima
	glNormal3f(0, 1, 0);
	glVertex3f(_x-0.13, _y+0.7, _z-0.25);
	glVertex3f(_x+0.13, _y+0.7, _z-0.25);
	glVertex3f(_x+0.13, _y+0.7, _z+0.25);
	glVertex3f(_x-0.13, _y+0.7, _z+0.25);
	glEnd();

	glBegin(GL_QUADS);//face de baixo
	glNormal3f(0, -1, 0);
	glVertex3f(_x-0.13, _y+0.25, _z+0.25);
	glVertex3f(_x+0.13, _y+0.25, _z+0.25);
	glVertex3f(_x+0.13, _y+0.25, _z-0.25);
	glVertex3f(_x-0.13, _y+0.25, _z-0.25);
	glEnd();

	//paralelepipedo esquerdo
	glBegin(GL_QUADS);//face de frente
	glNormal3f(0, 0, 1);
	glVertex3f(_x-0.83, _y-0.4, _z+0.25);
	glVertex3f(_x-0.57, _y-0.4, _z+0.25);
	glVertex3f(_x-0.57, _y+0.4, _z+0.25);
	glVertex3f(_x-0.83, _y+0.4, _z+0.25);
	glEnd();

	glBegin(GL_QUADS);//face de tras
	glNormal3f(0, 0, -1);
	glVertex3f(_x-0.83, _y-0.4, _z-0.25);
	glVertex3f(_x-0.57, _y-0.4, _z-0.25);
	glVertex3f(_x-0.57, _y+0.4, _z-0.25);
	glVertex3f(_x-0.83, _y+0.4, _z-0.25);
	glEnd();

	glBegin(GL_QUADS);//face lateral direita
	glNormal3f(1, 0, 0);
	glVertex3f(_x-0.57, _y-0.4, _z+0.25);
	glVertex3f(_x-0.57, _y-0.4, _z-0.25);
	glVertex3f(_x-0.57, _y+0.4, _z-0.25);
	glVertex3f(_x-0.57, _y+0.4, _z+0.25);
	glEnd();

	glBegin(GL_QUADS);//face lateral esquerda
	glNormal3f(-1, 0, 0);
	glVertex3f(_x-0.83, _y-0.4, _z+0.25);
	glVertex3f(_x-0.83, _y-0.4, _z-0.25);
	glVertex3f(_x-0.83, _y+0.4, _z-0.25);
	glVertex3f(_x-0.83, _y+0.4, _z+0.25);
	glEnd();

	glBegin(GL_QUADS);//face de cima
	glNormal3f(0, 1, 0);
	glVertex3f(_x-0.83, _y+0.4, _z-0.25);
	glVertex3f(_x-0.57, _y+0.4, _z-0.25);
	glVertex3f(_x-0.57, _y+0.4, _z+0.25);
	glVertex3f(_x-0.83, _y+0.4, _z+0.25);
	glEnd();
	glBegin(GL_QUADS);//face de baixo
	glNormal3f(0, -1, 0);
	glVertex3f(_x-0.83, _y+0.4, _z-0.25);
	glVertex3f(_x-0.57, _y+0.4, _z-0.25);
	glVertex3f(_x-0.57, _y+0.4, _z+0.25);
	glVertex3f(_x-0.83, _y+0.4, _z+0.25);
	glEnd();

	//paralelepipedo direito
	glBegin(GL_QUADS);//face de frente
	glNormal3f(0, 0, 1);
	glVertex3f(_x+0.83, _y-0.4, _z+0.25);
	glVertex3f(_x+0.57, _y-0.4, _z+0.25);
	glVertex3f(_x+0.57, _y+0.4, _z+0.25);
	glVertex3f(_x+0.83, _y+0.4, _z+0.25);
	glEnd();

	glBegin(GL_QUADS);//face de tras
	glNormal3f(0, 0, -1);
	glVertex3f(_x+0.83, _y-0.4, _z-0.25);
	glVertex3f(_x+0.57, _y-0.4, _z-0.25);
	glVertex3f(_x+0.57, _y+0.4, _z-0.25);
	glVertex3f(_x+0.83, _y+0.4, _z-0.25);
	glEnd();

	glBegin(GL_QUADS);//face lateral direita
	glNormal3f(1, 0, 0);
	glVertex3f(_x+0.57, _y-0.4, _z+0.25);
	glVertex3f(_x+0.57, _y-0.4, _z-0.25);
	glVertex3f(_x+0.57, _y+0.4, _z-0.25);
	glVertex3f(_x+0.57, _y+0.4, _z+0.25);
	glEnd();

	glBegin(GL_QUADS);//face lateral esquerda
	glNormal3f(-1, 0, 0);
	glVertex3f(_x+0.83, _y-0.4, _z+0.25);
	glVertex3f(_x+0.83, _y-0.4, _z-0.25);
	glVertex3f(_x+0.83, _y+0.4, _z-0.25);
	glVertex3f(_x+0.83, _y+0.4, _z+0.25);
	glEnd();

	glBegin(GL_QUADS);//face de cima
	glNormal3f(0, 1, 0);
	glVertex3f(_x+0.83, _y+0.4, _z-0.25);
	glVertex3f(_x+0.57, _y+0.4, _z-0.25);
	glVertex3f(_x+0.57, _y+0.4, _z+0.25);
	glVertex3f(_x+0.83, _y+0.4, _z+0.25);
	glEnd();

	glBegin(GL_QUADS);//face de baixo
	glNormal3f(0, -1, 0);
	glVertex3f(_x+0.83, _y+0.4, _z-0.25);
	glVertex3f(_x+0.57, _y+0.4, _z-0.25);
	glVertex3f(_x+0.57, _y+0.4, _z+0.25);
	glVertex3f(_x+0.83, _y+0.4, _z+0.25);
	glEnd();

	glBegin(GL_QUADS);//face de baixo
	glNormal3f(0, -1, 0);
	glVertex3f(_x+0.83, _y+0.4, _z-0.25);
	glVertex3f(_x+0.57, _y+0.4, _z-0.25);
	glVertex3f(_x+0.57, _y+0.4, _z+0.25);
	glVertex3f(_x+0.83, _y+0.4, _z+0.25);
	glEnd();

	//piramide
	glBegin(GL_TRIANGLES);//face de cima
	glNormal3f(0, 0, 1);
	glVertex3f(_x-0.13, _y+0.7, _z+0.25);
	glVertex3f(_x+0.13, _y+0.7, _z+0.25);
	glVertex3f(_x, _y+1, _z+0.25);
	glEnd();

	glBegin(GL_TRIANGLES);//face de baixo
	glNormal3f(0, 0, -1);
	glVertex3f(_x-0.13, _y+0.7, _z-0.25);
	glVertex3f(_x+0.13, _y+0.7, _z-0.25);
	glVertex3f(_x, _y+1, _z-0.25);
	glEnd();

	glBegin(GL_QUADS);//face do lado direito
	glNormal3f(0.15, 0.065, 0);
	glVertex3f(_x+0.13, _y+0.7, _z+0.25);
	glVertex3f(_x+0.13, _y+0.7, _z-0.25);
	glVertex3f(_x, _y+1, _z-0.25);
	glVertex3f(_x, _y+1, _z+0.25);
	glEnd();

	glBegin(GL_QUADS);//face do lado esquerdo
	glNormal3f(-0.15, 0.065, 0);
	glVertex3f(_x-0.13, _y+0.7, _z+0.25);
	glVertex3f(_x-0.13, _y+0.7, _z-0.25);
	glVertex3f(_x, _y+1, _z-0.25);
	glVertex3f(_x, _y+1, _z+0.25);
	glEnd();

	glBegin(GL_QUADS);//base
	glNormal3f(0, -1, 0);
	glVertex3f(_x+0.13, _y+0.7, _z+0.25);
	glVertex3f(_x+0.13, _y+0.7, _z-0.25);
	glVertex3f(_x-0.13, _y+0.7, _z-0.25);
	glVertex3f(_x-0.13, _y+0.7, _z+0.25);
	glEnd();

	glPopMatrix();
	glPopMatrix();
}

void Spaceship::actualizaPos(float x){
	_x += x;
}

float Spaceship::getX(){
	return _x;
}

float Spaceship::getY(){
	return _y;
}

float Spaceship::getZ(){
	return _z;
}

void Spaceship::disable() 
{
	glEnable(GL_LIGHT0); // ENABLE AMBIENT LIGHT
	glDisable(GL_LIGHT1);
	GLfloat ambient[] = { 0.6, 0.6, 0.6, 1.0};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
	_lightON = false;
}

void Spaceship::enable()
{
	glDisable(GL_LIGHT0); // DISABLE AMBIENT LIGHT
	glEnable(GL_LIGHT1); // ENABLE LIGHT 1
	GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
	_lightON = true;
}

bool Spaceship::getLightsStatus()
{
	return _lightON;
}

int Spaceship::getLives()
{
	return _Lives;
}

void Spaceship::wasHit()
{
	_Lives --;
}