#include "TiroAlien.h"

TiroAlien::TiroAlien(float x, float y, float z):_x(x), _y(y),_z(z){};

void TiroAlien::draw(){

	 glPushMatrix();

		GLfloat mat_ambient[] = { 0.25, 0.25, 0.25, 1.0 };
		GLfloat mat_diffuse[] = { 0.4, 0.4, 0.4, 1.0 };
		GLfloat mat_specular[] = { 0.774597, 0.774597, 0.774597, 1.0 };
		GLfloat mat_shine = 0.6*128;

		glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf (GL_FRONT, GL_SHININESS, mat_shine);

	 glTranslatef(_x, _y, _z);
	 
	   glColor3f (1, 0, 0);
	   glScalef(0.2, 0.2, 0.2);
	   glutSolidSphere(1.0f, 100, 100);
	   
	 glPopMatrix();	 
}

void TiroAlien::movingDown()
{
	_y -= 0.3f;
}

float TiroAlien::getPosY(){

	return _y;
}
