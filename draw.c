#include <GL/glut.h>

#include "model.h"

BallPosition magicBedz;


void drawLight(){
  /* Pozicija svetla (u pitanju je direkcionalno svetlo). */
    GLfloat light_position[] = { cameraPosition[0], cameraPosition[1], cameraPosition[2], 0 };

    /* Ambijentalna boja svetla. */
    GLfloat light_ambient[] = { 0.2, 0.15, 0.15, 1 };

    /* Difuzna boja svetla. */
    GLfloat light_diffuse[] = { 0.5, 1, 0.2, 1 };

    /* Spekularna boja svetla. */
    GLfloat light_specular[] = { 0.6, 0.6, 0.6, 1 };

    /* Koeficijenti ambijentalne refleksije materijala. */
    GLfloat ambient_coeffs[] = { 0.8, 0.4, 0.2, 1 };

    /* Koeficijenti difuzne refleksije materijala. */
    GLfloat diffuse_coeffs[] = { 0.2, 0.3, 0.4, 1 };

    /* Koeficijenti spekularne refleksije materijala. */
    GLfloat specular_coeffs[] = { 0.5, .4,.6 , 1 };

    /* Koeficijent glatkosti materijala. */
    GLfloat shininess = 20;



  /* Ukljucuje se osvjetljenje i podesavaju parametri svetla. */
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    /* Podesavaju se parametri materijala. */
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}

void drawPath()
{ //ovi su uvek u ravni pa ne mora triangles. Nema transformacija nad stazom
   
  //leva staza
  glEnable(GL_COLOR_MATERIAL);
  glColor3f(1,0,0);
  glBegin(GL_QUADS);
  glVertex3i(0, 0, 0);
  glVertex3i(1, 0, 0);
  glVertex3i(1, 0, PATH_LENGTH);
  glVertex3i(0, 0, PATH_LENGTH);
  glEnd();

  //srednja staza
  glColor3f(0,1,0);
  glBegin(GL_QUADS);
  glVertex3i(1, 0, 0);
  glVertex3i(2, 0, 0);
  glVertex3i(2, 0, PATH_LENGTH);
  glVertex3i(1, 0, PATH_LENGTH);
  glEnd();

  //desna staza
  glColor3f(0,0,1);
  glBegin(GL_QUADS);
  glVertex3i(2, 0, 0);
  glVertex3i(3, 0, 0);
  glVertex3i(3, 0, PATH_LENGTH);
  glVertex3i(2, 0, PATH_LENGTH);
  glEnd();
  glDisable(GL_COLOR_MATERIAL);
}
void drawBall()
{
  
  glPushMatrix();
  drawLight();
  glTranslatef(ballPosition.x, ballPosition.y, ballPosition.z);
  glutSolidSphere(BALL_RADIUS, 20, 20);
  glPopMatrix();
  
}
void drawObstacles()
{
  GLfloat diffuse_coeffs[4];
  for(int i = poceteniIndex; i < krajnjiIndex; i++, i %= MAX_PREDMETA) {
    
    glPushMatrix();
    drawLight();
    diffuse_coeffs[0] = 0.1; 
    diffuse_coeffs[1] = 0.95;
    diffuse_coeffs[2] = 0.1;
    diffuse_coeffs[3]=1;
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_coeffs);
    glTranslatef(predmeti[i][0] + .5,
		predmeti[i][1] + .5,
        predmeti[i][2] );
    glutSolidCube(1);
    glPopMatrix();
    
  }
}
void drawMagicBall(){
  glPushMatrix();
  drawLight();
  glTranslatef(magicBedz.x,magicBedz.y,magicBedz.z);
  glutSolidTorus(0.1,0.2,50,50);
  glPopMatrix();
}
