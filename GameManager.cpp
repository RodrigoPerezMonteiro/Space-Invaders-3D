#include <iostream>
#include <stdlib.h>
#include <string>
#include <GL/glut.h>
#include "ALL.h"

Lights *light = new Lights();
int _lights;
bool existeTiro = false;
bool existeTiroAlien = false;

void GameManager::init(int Aliens1, int Aliens2, int Aliens3, int Aliens4, float SpaceshipX, float SpaceshipY, float SpaceshipZ, float AlienX, float AlienY, float AlienZ, int Shields, float size, float racio)
{
	_GameOver = false;
	_Restart = false;
	
	_Size = size;
	_Racio = racio;
	
	_Aliens1 = Aliens1;
	_Aliens2 = Aliens2;
	_Aliens3 = Aliens3;
	_Aliens4 = Aliens4;
	
	_SpaceshipX = SpaceshipX;
	_SpaceshipY = SpaceshipY;
	_SpaceshipZ = SpaceshipZ;
	
	_AlienX = AlienX;
	_AlienY = AlienY;
	_AlienZ = AlienZ;
	
	_NShields = Shields;
	
	_Score = 0;

	LeftToRight = true;
	RightToLeft = false;
	onlyOnce = false;
	
	_Cameras.push_back(new Camera("Vista Ortogonal", _SpaceshipX, _Size, _Racio));
	_Cameras.push_back(new Camera("Camara Retaguarda", _SpaceshipX, _Size, _Racio));
	_Cameras.push_back(new Camera("Camera Primeira Pessoa", _SpaceshipX, _Size, _Racio));

	GameManager::setup(); //Cria nave, aliens e escudos e guarda nas estruturas;
	
	light->lighter(-size, -size, 3.f, 0.5, 0.5, 0.5, 0.5, 0.5, 0.1, 1.0, 1.0, 0.5);
	_lights = 0;

	//const float x, const float y, const float z,
	//const float amb1, const float amb2, const float amb3,
	//const float diff1, const float diff2, const float res q diff3,
	//const float spec1, const float spec2, const float spec3
}

void GameManager::setup()
{
	_totalAliens = _Aliens1 + _Aliens2 + _Aliens3 + _Aliens4;
	float CoordX = _AlienX;

	GameManager::_Spaceship = new Spaceship(_SpaceshipX, _SpaceshipY, _SpaceshipZ);

	for (int i = 0; i < _Aliens1; i++)
	{
		alien = new AlienType1(CoordX, _AlienY, _AlienZ);
		GameManager::_Aliens.push_back(alien);
		CoordX += 2.0;
	}

	CoordX = _AlienX;

	for (int j = 0; j < _Aliens2; j++)
	{
		alien = new AlienType2Blue(CoordX, (_AlienY-2.f), _AlienZ);
		GameManager::_Aliens.push_back(alien);
		CoordX += 2.0;
	}

	CoordX = _AlienX;

	for (int k = 0; k < _Aliens3; k++)
	{
		alien = new AlienType3(CoordX, (_AlienY-4.25f), _AlienZ);
		GameManager::_Aliens.push_back(alien);
		CoordX += 2.3;
	}

	CoordX = _AlienX;

	for (int l = 0; l < _Aliens4; l++)
	{
		alien = new AlienType4(CoordX, _AlienY-6.5f, _AlienZ);
		GameManager::_Aliens.push_back(alien);
		CoordX += 2.3;
	}


	//SHIELDS
	float ShieldX = -6.0;

	for (int m = 0; m < _NShields; m++)
	{
		_shield = new Shield(ShieldX, -6.0, 0);
		GameManager::_Shields.push_back(_shield);
		ShieldX += 3.0;
	}

	Cam = _Cameras[0]; //INICIALIZAÇÃO: A câmara default é a 0.
	_currentCam = 0;
}


void GameManager::setRestart(bool restart)
{
	_Restart = restart;
}

bool GameManager::getRestart()
{
	return _Restart;
}

bool GameManager::getGameOver()
{
	return _GameOver;
}

int GameManager::getLives()
{
	return _Spaceship->getLives();
}

int GameManager::getPoints()
{
	return _Score;
}

void GameManager::draw()
{    
	//Aliens

	glPushMatrix();
	glScalef(0.8, 0.8, 1);

	for(int n = 0; n<_Aliens.size(); n++)
	{  
		GameManager::_Aliens[n]->roda();
	}

	glPopMatrix();

	////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////

	//Fila de Escudos

	glPushMatrix();

	for(int o = 0; o<_Shields.size(); o++)
	{
		GameManager::_Shields[o]->draw();
	}

	glPopMatrix();

	////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////

	//SpaceShip

    glPushMatrix();

	GameManager::_Spaceship->draw();

	glPopMatrix();

	////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////

	if(getExisteTiro()){
		if(getTiroY() < _Size){
			 moveTiro();
			 desenhaTiro();
		}
		
		else{setTiroFalse();}
	}

	if(existeTiroAlien){
		if(getTiroAlienY() > -_Size){
			 moveTiroAlien();
			 desenhaTiroAlien();
		}
		
		else{setTiroAlienFalse();}
	}


	// Actualiza Total Aliens
	
	_totalAliens = _Aliens1 + _Aliens2 + _Aliens3 + _Aliens4;
}

void GameManager::drawBackground(){
	GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shine = 128;

	glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf (GL_FRONT, GL_SHININESS, mat_shine);


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _background);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	
	int quality = 300;
	float tex = 7.0/quality;
	float dim = 150.0/quality;
	for(int y=0; y<quality; y++)
	{
		float ytex=y*tex;
		float ydim=y*dim;
		for(int x=0; x<quality; x++)
		{
			float xtex=x*tex;
			float xdim=x*dim;
			glBegin(GL_TRIANGLE_STRIP);
				glNormal3f( 0., 0., 1.);
				glTexCoord2f(0+xtex, 0+ytex);		glVertex3f(xdim-CENTER, 0+ydim-MAX_WINDOW, 0);
				glTexCoord2f(tex+xtex, 0+ytex);		glVertex3f(dim+xdim-CENTER, 0+ydim-MAX_WINDOW, 0);
				glTexCoord2f(0+xtex, tex+ytex);		glVertex3f(0+xdim-CENTER, dim+ydim-MAX_WINDOW, 0);
				glTexCoord2f(tex+xtex, tex+ytex);	glVertex3f(dim+xdim-CENTER, dim+ydim-MAX_WINDOW, 0);
			glEnd();
		}
	}

	glDisable(GL_TEXTURE_2D);
}

void GameManager::setupBackground()
{
	_background = _texture.LoadBitmap("stars.bmp");
	glBlendFunc(GL_SRC_ALPHA,GL_ONE);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
}

void GameManager::actualizaNave(float pos)
{
	_Spaceship->actualizaPos(pos);
}

float GameManager::getSpaceshipX()
{
	return _Spaceship->getX();
}

float GameManager::getSpaceshipY()
{
	return _Spaceship->getY();
}

float GameManager::getSpaceshipZ()
{
	return _Spaceship->getZ();
}

bool GameManager::getSpaceshipLightsStatus()
{
	return _Spaceship->getLightsStatus();
}

void GameManager::alienMoving(float WinSize)
{
	float maiorX = -10000.f;
	float menorX = 10000.f;
	onlyOnce = false;

	while(1==1){

		onlyOnce = false;

		if(LeftToRight){ 

			moveRight();

			for(int n = 0; n<_Aliens.size(); n++)
			{  
				if(GameManager::_Aliens[n]->getX() > maiorX){ 

					maiorX = GameManager::_Aliens[n]->getX();

				}
			}

			if((maiorX + .5f) > WinSize){
				int i;
				for (i=0; i<50; i++)
				{
						moveDown();

				}
				LeftToRight = false;
				RightToLeft = true;
			}

			onlyOnce = true;
		}

		if (onlyOnce)
			break;

		if(RightToLeft){ 

			moveLeft();

			for(int n = 0; n<_Aliens.size(); n++)
			{  
				if(GameManager::_Aliens[n]->getX() < menorX){ 

					menorX = GameManager::_Aliens[n]->getX();

				}
			}

			if((menorX - .5f) < -WinSize){

				RightToLeft = false;
				LeftToRight = true;
				int i;
				for (i=0; i<50; i++)
				{
						moveDown();
				}
			}
		}
	break;
	}
}

void GameManager::moveRight(){

	for(int n = 0; n<_Aliens.size(); n++)
	{  
		GameManager::_Aliens[n]->moveRight();
	}

}

void GameManager::moveLeft(){

	for(int n = 0; n<_Aliens.size(); n++)
	{  
		GameManager::_Aliens[n]->moveLeft();
	}

}

void GameManager::moveDown(){

	for(int n = 0; n<_Aliens.size(); n++)
	{  
		GameManager::_Aliens[n]->moveDown();
	}

}

void GameManager::changeCamera(std::string nome, float racio, float size){

	if(nome.compare("Vista Ortogonal") == 0){ //1

		_Cameras[0]->changePos(getSpaceshipX());
		_Cameras[0]->changeSize(size);
		_Cameras[0]->changeRacio(racio);
		Cam = _Cameras[0];
		_currentCam = 0;

	}


	if(nome.compare("Camera Retaguarda") == 0){ //2

		_Cameras[1]->changePos(getSpaceshipX());
		_Cameras[1]->changeSize(size);
		_Cameras[1]->changeRacio(racio);
		Cam = _Cameras[1];
		_currentCam = 1;

	}


	if(nome.compare("Camera Primeira Pessoa") == 0){ //3
	
		_Cameras[2]->changePos(getSpaceshipX());
		_Cameras[2]->changeSize(size);
		_Cameras[2]->changeRacio(racio);
		Cam = _Cameras[2];
		_currentCam = 2;

	}

}

int GameManager::getCurrentCam()
{
	return _currentCam;
}

void GameManager::desenhaTiro(){

	_Tiro->draw();

}

void GameManager::desenhaTiroAlien(){

	_TiroAlien->draw();

}

void GameManager::moveTiro(){

	 _Tiro->movingUp();

}

void GameManager::moveTiroAlien(){

	 _TiroAlien->movingDown();

}

bool GameManager::getExisteTiro(){

	return existeTiro;

}

float GameManager::getTiroY(){

	return _Tiro->getPositionY();

}

float GameManager::getTiroAlienY(){

	return _TiroAlien->getPosY();

}

void GameManager::disparar(){
	
	if(!(existeTiro)){

		GameManager::_Tiro = new Tiro(getSpaceshipX(), getSpaceshipY() + 2.5, getSpaceshipZ());
		existeTiro = true;
	}

}

void GameManager::disparoAliens(){
	
	if(!(existeTiroAlien)){

		dispAlien();
		existeTiroAlien = true;
	}
}

void GameManager::setTiroFalse(){

		existeTiro = false;
}

void GameManager::setTiroAlienFalse(){

		existeTiroAlien = false;
}

void GameManager::showCam(){
	Cam->showCam();
}

int GameManager::randomnumber()
{
    int j = rand() % _totalAliens;
    return j;
}

void GameManager::dispAlien()
{
	int n = randomnumber();

	if(podeDisparar(n))
	{
		_TiroAlien = new TiroAlien(GameManager::_Aliens[n]->getX(), GameManager::_Aliens[n]->getY() - 0.5f, GameManager::_Aliens[n]->getZ());
	}
}

bool GameManager::podeDisparar(int n)
{
	bool clearToFire = true;
	if (n >= _totalAliens - _Aliens4) // ESTÁ NA FILA 4
	{
		if ( (! (_Aliens[n]->getDead()))) 
		{
			clearToFire = false;
		}
	}

	else if (n >= _totalAliens - _Aliens4 - _Aliens3) // ESTÁ NA FILA 3
	{
		int i = n+_Aliens3;
		if (_Aliens[n + _Aliens3]->getDead()  )
		{
			clearToFire = false;
		}
	}
	else if (n >= _totalAliens - _Aliens4 - _Aliens3 - _Aliens2) // ESTÁ NA FILA 2
	{	
		if ((_Aliens[n+_Aliens2]->getDead()  ) || (_Aliens[n+_Aliens2+_Aliens3]->getDead()  ))
		{
			clearToFire = false;
		}
	}

	else if (n >= _totalAliens - _Aliens4 - _Aliens3 - _Aliens2 - _Aliens1) // ESTÁ NA FILA 1
	{	
		if ((_Aliens[n+_Aliens1]->getDead()  ) || (_Aliens[n+_Aliens1+_Aliens2]->getDead()  ) || (_Aliens[n+_Aliens1+_Aliens2+_Aliens3]->getDead()  ))
		{
			clearToFire = false;
		}
	}
	
	return clearToFire;
}

void GameManager::setSpotlightOFF()
{
	if(_lights == 1)
	{	
		_Spaceship->disable(); // DISABLE SPOTLIGHT
		_lights = 0;
	}
}

void GameManager::setSpotlightON()
{
	_Spaceship->enable(); // ENABLE SPOTLIGHT
	_lights = 1;
}

void GameManager::HUD(GLfloat x, GLfloat y, std::string text)
{
	glPushMatrix();
	glColor3f(0.0f, 1.0f, 0.0f);

	glRasterPos2i(x, y);
	
	for(string::iterator it = text.begin(); it != text.end(); ++it)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it);
	glPopMatrix();
}