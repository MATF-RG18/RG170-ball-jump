#include <math.h>
#include <stdio.h>
#include "model.h"


//biramo koliko paketa bacamo u f-ji vremena
int getKardinalnost(int timer)
{
  //hocemo max 6 predmeta i min 1 pa korigujemo actg vrednost
  return floor(1 + DIFICULTY_ITEM_NUMBER * atan(timer / DIFICULTY_TIME_DIVIDER) / M_PI);
}

//biramo timer za koliko cemo da bacimo pakete- sa vremenom cesce
int getFrekvencija(int timer)
{
  //baca negde izmedju 1 i 3 sec
  return floor(1000 + DIFICULTY_FREQUENCY* atan(-timer/ DIFICULTY_TIME_DIVIDER) / M_PI);
}

//funkcija za brzinu ali ne iskoriscena 
int getSpeed(int timer){
  printf("brzina= %.2f\n",(2 + 4 * atan(timer / DIFICULTY_TIME_DIVIDER) / M_PI)
    / (double) 60);
  return (2 + 4 * atan(timer / DIFICULTY_TIME_DIVIDER) / M_PI)
    / (double) 60;
}

int nizSadrzi(int broj, int *niz, int n) {
  for(int i = 0; i < n; i++) {
    if(niz[i] == broj) return 1;
  }
  return 0;
}
