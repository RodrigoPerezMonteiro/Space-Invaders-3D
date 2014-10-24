#ifndef CBFUNCTIONS_H
#define CBFUNCTIONS_H

#include <iostream>
#include <stdlib.h>

using namespace std;

void init(void);
void display(void);
void teclado(unsigned char key, int x, int y);
void reshape(GLsizei w, GLsizei h);
void actCam(float racio, float size);
void updateScene();
void drawTextureandHUD();
void HUD();
float getSize();

#endif