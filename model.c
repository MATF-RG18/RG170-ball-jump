#include "model.h"

double DIFICULTY_SPEED_INITIAL = 2;
double DIFICULTY_SPEED = 2 / (double) 60;

BallPosition ballPosition;
double movSpeed = .1;
double movVector[3];
short sgnMovVecX = 0;
double backLine = -0.5;
double frontLine = -5;
double dropLine = 20;
double cameraPosition[3];

int brojSekundi = 0;
int brojSekundiZaPoavljivanjeBedza=0;
double predmeti[MAX_PREDMETA][3];
int brojPredmeta;

int poceteniIndex = 0;
int krajnjiIndex = 0;
int jePopunjeno = 0;
