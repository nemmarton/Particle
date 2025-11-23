#ifndef SZIMULACIO_H
#define SZIMULACIO_H

#include "reszecske.h"
#include <stdio.h> //NULL
#include <stdlib.h>
#include <time.h>
// valójában ez is mehetne a .c-be, el kellene rejteni!
typedef struct Szimulacio{
    int darab;
    double x_limit;
    double y_limit;
    reszecske** reszecskek;
} szimulacio;
//csinálók, destruktorok, inicializálók:
szimulacio* szimulacio_csinal(int db, double x_limit,double y_limit);
void szimulacio_torol(szimulacio* szim);
void szimulacio_init(szimulacio* szim);
//léptető függvény:
void szimulacio_leptet(szimulacio* szim,double dt);

//getterek:

reszecske* get_reszecske(szimulacio* szim,int i);
double get_x_limit(szimulacio* szim);
double get_y_limit(szimulacio* szim);
int get_db(szimulacio* szim);


#endif