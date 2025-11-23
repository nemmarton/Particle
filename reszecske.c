#include "reszecske.h"
#include <stdio.h>
#include <stdlib.h>
/*Létrehozzuk a részecskét, nyilván dinamikusan, kár lenne, ha ideje korán meghalnának...*/
reszecske* csinal_reszecsket(double x, double y, double vx, double vy){//x,y,vx,vy=?
}

/*szabályos törlés, dinamikus a részecske, szóval ez kell*/
void torol_reszecsket(reszecske* regi){
}


/*ún. getterek, hogy kívülről is elérjük az adatokat*/
double get_x(reszecske* resz){return resz->x;}//névhasználat javítandó, mi van, ha másnak is van x-je?
double get_y(reszecske*resz){return resz->y;}
double get_vx(reszecske*resz){return resz->vx;}
double get_vy(reszecske*resz){return resz->vy;}

//update, egyszerűen elmozdítjuk a részecskét a sebessége alapján
void mozgat_reszecsket(reszecske* resz,double dt){

}