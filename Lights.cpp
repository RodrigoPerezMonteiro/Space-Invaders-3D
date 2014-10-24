#include "Lights.h"

Lights::Lights(){};

void Lights::lighter(const float x, const float y, const float z, const float amb1, const float amb2, const float amb3, const float diff1, const float diff2, const float diff3, const float spec1, const float spec2, const float spec3)
{
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0); 

  GLfloat light_ambient[] = {amb1, amb2, amb3, 1.0 };
  GLfloat light_diffuse[] = {diff1, diff2, diff3, 1 };
  GLfloat light_specular[] = {spec1, spec2, spec3, 1.0 };
  GLfloat light_position[] = {x, y, z, 0.0};
 
  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}
