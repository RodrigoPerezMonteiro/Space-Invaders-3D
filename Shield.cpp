#include "Shield.h"

Shield::Shield(float x, float y, float z):_Lives(3), _x(x), _y(y),_z(z){};
		
		
void Shield::draw(){
		
		GLfloat mat_ambient[] = {1, 1, 1, 1};
		GLfloat mat_diffuse[] = { 0.0, 0.0, 0.0, 1.0 };
		GLfloat mat_specular[] = { 0.1, 0.1, 0.1, 1.0 };
		GLfloat mat_shine = 0.6*128;

		glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf (GL_FRONT, GL_SHININESS, mat_shine);

	   glPushMatrix();
	   glTranslatef(_x, _y, _z);

	   glPushMatrix();
	   glColor3f (0.439, 0.54, 0.565);
	   glScalef(1.5, 0.6, 1);
	   glutSolidCube(1.0f);
	   glPopMatrix();

	   glPushMatrix();
	   glColor3f (0.439, 0.54, 0.565);
	   glTranslatef(0, 0.45, 0);
	   glScalef(1, 0.3, 1);
	   glutSolidCube(1.0f);
	   glPopMatrix();
	   
	glPopMatrix();
}

void Shield::wasHit()
{
	_Lives --;
}