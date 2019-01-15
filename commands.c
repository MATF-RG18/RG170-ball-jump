#include "model.h"

int ignoreCommands = 0;

void commandLeft()
{
  //ovo je za blinkovanje loptice levo desno
  //ballPosition.x -= 1;

  //ovo je za animaciju levo desno
  movVector[0] += - X_INTENSITY;

  if(movVector[0] < 0)
    sgnMovVecX = -1;
}
void commandRight()
{
  movVector[0] += X_INTENSITY;

  if(movVector[0] > 0)
    sgnMovVecX = 1;
}
void commandBack()
{
  ballPosition.z += movSpeed;
  if(ballPosition.z > backLine) ballPosition.z = backLine;
}
void commandForward()
{
  ballPosition.z -= movSpeed;
  if(ballPosition.z < frontLine) ballPosition.z = frontLine;
}
void commandJump()
{
  movVector[1] = JUMP_INTENSITY;
}

void commandCameraUp()
{
  cameraPosition[2] += CAMERA_SENSITIVITY;
}
void commandCameraDown()
{
  cameraPosition[2] -= CAMERA_SENSITIVITY;
}
void commandCameraLeft()
{
  cameraPosition[0] -= CAMERA_SENSITIVITY;
}
void commandCameraRight()
{
  cameraPosition[0] += CAMERA_SENSITIVITY;
}
