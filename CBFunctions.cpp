#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

#include "ALL.h"

float racio = 0.f;
float size = 10.5f;
float angle = 0.f;
float SSsize = 2.5f;
bool cam1 = true;
bool cam2 = false;
bool cam3 = false;

GameManager* GM = new GameManager();

void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
   GM->init(6, 6, 5, 5, 0, -8.5, 0, -8, 8, 0, 5, size, racio); 

   //int Aliens Fila 1, int Aliens Fila 2, int Aliens Fila 3, int Aliens Fila 4, 
   //float SpaceshipX, float SpaceshipY, float SpaceshipZ,
   //float AlienX, float AlienY, float AlienZ,
   //int Shields;  
}

void display(void)
{	
   if(GM->getRestart())
   { 
	   delete GM;
	   GM = new GameManager();
	   GM->init(6, 6, 5, 5, 0, -8.5, 0, -8, 8, 0, 5, size, racio); 
   }

   glClear (GL_COLOR_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);

   actCam(racio, size);

   drawTextureandHUD();

   glPushMatrix();
		GM->showCam();
		updateScene();
   glPopMatrix();
	    
   GM->alienMoving(size);
   glFlush();
   glutPostRedisplay();
}

void HUD()
{
	glDisable(GL_LIGHTING);
	stringstream n (stringstream::in | stringstream::out); // SPOTLIGHT
	stringstream l (stringstream::in | stringstream::out); // LIVES
	stringstream m (stringstream::in | stringstream::out); // POINTS/SCORE

	n.str(std::string());
	//if(glIsEnabled(GL_LIGHT1))	n << "SpotLight ON";
	//if(glIsEnabled(GL_LIGHT0))	n << "Spotlight OFF";

	GM->HUD(-MAX_GAME_POSITION, MAX_GAME_POSITION, n.str());

	l.str(std::string()); 
	l << "Lives: " << GM->getLives();
	GM->HUD(-MAX_GAME_POSITION, -MAX_GAME_POSITION-1.5, l.str());

	m.str(std::string()); 
	m << "Score: " << GM->getPoints();
	GM->HUD(MAX_GAME_POSITION - 3, -MAX_GAME_POSITION-1.5, m.str());

	//GM->HUD(MAX_GAME_POSITION/2, -MAX_GAME_POSITION-1, "Press 'r' to Restart");
	glEnable(GL_LIGHTING);
}

void updateScene()
{
   glPushMatrix();
		GM->disparoAliens();
   glPopMatrix();

   glPushMatrix();
		glRotatef(angle, 1, 1 ,1);	
		GM->draw();
   glPopMatrix();
}

void drawTextureandHUD()
{
	if(GM->getCurrentCam() == 0) 
	{
		glPushMatrix();
		GM->drawBackground();
		glRotatef(2.5, 1, 0, 0);
		HUD();
		glPopMatrix();
	}
	
	else if(GM->getCurrentCam() == 1) 
	{
		glPushMatrix();
		glTranslatef(0, 0, -10);
		GM->drawBackground();
		glTranslatef(0, +1, 0);
		HUD();
		glPopMatrix();
	}	
	
	else if(GM->getCurrentCam() == 2) 
	{
		glPushMatrix();
		glTranslatef(0, +3, -7);
		glRotatef(7.5, 1, 0, 0);
		GM->drawBackground();
		HUD();
		glPopMatrix();
	}
}

void teclado(unsigned char key, int x, int y){

	switch (key) {

	case (' ') :
	{
		GM->disparar();
	} break;


	case ('1') :
	{
		cam1 = true;
		cam2 = false;
		cam3 = false;
	} break;

	case ('2') :
	{
		cam1 = false;
		cam2 = true;
		cam3 = false;
	} break;
	
	case ('3') :
	{
		cam1 = false;
		cam2 = false;
		cam3 = true;
	} break;


	case ('l') :
	{
		if (GM->getSpaceshipLightsStatus())
		{
			GM->setSpotlightOFF();
		}
		
		else if (!(GM->getSpaceshipLightsStatus()))
		{
			GM->setSpotlightON();
		}
	} break;
	
	
	case ('d') :
	{
		if ((GM->getSpaceshipX() + (SSsize/2)) < size)
		{
			GM->actualizaNave(0.2);
		}
	} break;  //RIGHT 

	
	case ('a') :
	{
		if ((GM->getSpaceshipX() - (SSsize/2)) > (-size))
		{
			GM->actualizaNave(-.2);	
		}
	} break; //LEFT

	case ('r') :
	{
		GM->setRestart(true);
	}

  }
}
 
void reshape(GLsizei w, GLsizei h)
{
	racio = ((float) w) / (float)h;
	glViewport(0,0,w,h);

	GM->setupBackground();
}

void actCam(float racio, float size){

	if(cam1){

		GM->changeCamera("Vista Ortogonal", racio, size);
	}

	if(cam2){
	
		GM->changeCamera("Camera Retaguarda", racio, size);
	}
	
	if(cam3){
	
		GM->changeCamera("Camera Primeira Pessoa", racio, size);
	}
}

float getSize(){
	return size;
}