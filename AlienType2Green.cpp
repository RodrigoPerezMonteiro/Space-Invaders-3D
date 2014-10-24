#include "Alien.h"
#include "AlienType2.h"
#include "AlienType2Green.h"

AlienType2Green::AlienType2Green(float x, float y, float z): _x(x), _y(y), _z(z), _dead(false){};

void AlienType2Green::draw(){
	
	  
	  glPushMatrix();
	  glTranslatef(_x, _y, _z);
	    //Cabeça
	    glPushMatrix();
	    glColor3f (0.0, 1.0, 0.0);
	    glScalef(1, 1, 1);
	    glutSolidCube(1.0f);
	    glPopMatrix();
	    
	    //Perna Esquerda
	    glPushMatrix();
	    glColor3f (0.0, 1.0, 0.0);
	    glTranslatef(-0.2, -0.9, 0);
	    glScalef(0.2, 0.8, 0.2);
	    glutSolidCube(1.0f);
	    glPopMatrix();

	    //Pé Esquerdo
	    glPushMatrix();
	    glColor3f (0.0, 1.0, 0.0);
	    glTranslatef(-0.35, -1.2, 0);
	    glScalef(0.2, 0.2, 0.2);
	    glutSolidCube(1.0f);
	    glPopMatrix();

	    //Perna Direita
	    glPushMatrix();
	    glColor3f (0.0, 1.0, 0.0);
	    glTranslatef(0.2, -0.9, 0);
	    glScalef(0.2, 0.8, 0.2);
	    glutSolidCube(1.0f);
	    glPopMatrix();

	    //Pé Direito
	    glPushMatrix();
	    glColor3f (0.0, 1.0, 0.0);
	    glTranslatef(0.35, -1.2, 0);
	    glScalef(0.2, 0.2, 0.2);
	    glutSolidCube(1.0f);
	    glPopMatrix();

	    //Olho Direito
	    glPushMatrix();
	    glColor3f (0,0,0);
	    glTranslatef(0.2, 0, 0.55);
	    glScalef(0.2, 0.2, 0.1);
	    glutSolidCube(1.0f);
	    glPopMatrix();

	    //Olho Esquerdo
	    glPushMatrix();
	    glColor3f (0,0,0);
	    glTranslatef(-0.2, 0, 0.55);
	    glScalef(0.2, 0.2, 0.1);
	    glutSolidCube(1.0f);
	    glPopMatrix();

	    //Boca
	    glPushMatrix();
	    glColor3f (0,0,0);
	    glTranslatef(0, -0.3, 0.55);
	    glScalef(0.4, 0.2, 0.1);
	    glutSolidCube(1.0f);
	    glPopMatrix();
	    
	  glPopMatrix();
	  
}
	    
void AlienType2Green::roda(){

	glPushMatrix();
	glTranslatef(_x, _y, _z);
	glRotatef(90, 1, 0, 0);
	glTranslatef(-_x, -_y, -_z);
	draw();
	glPopMatrix();

}
	    
void AlienType2Green::setDead(bool x)
{
	_dead = x;
}

bool AlienType2Green::getDead()
{
	return _dead;
}