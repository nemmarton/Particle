#include "reszecske.h"
#include <stdio.h> //NULL
#include <stdlib.h>
#include <time.h>
#include "szimulacio.h"
/*
foglalunk egy új-at, beállítjuk a darabszámot, x és y limitet, lefoglaljuk a részecskék tömbjét (indefinit még a tartalmom!)
*/
szimulacio* szimulacio_csinal(int db, double x_limit,double y_limit){

}
/* minden részecskét törlünk, mielőőt az őkat címző tömböt törölnénk!*/
void szimulacio_torol(szimulacio* szim){

}
/*
    random helyekre és sebességekre állítjuk be a részecskéket, random=rand()/(double)RAND_MAX*limit
    először inicializáljuk a random szám generátort: srand((unsigned int)time(NULL));
    meghivjuk csinal_reszecsket()-et! 
    V_max nincs a rendszerben, mert csak bemutató jellegű a szimuláció!
*/
void szimulacio_init(szimulacio* szim){
}

/*
léptetjük az összes részecskét a dt idővel, majd ellenőrizzük, hogy nem lépett-e ki a határokon! Ha igen, akkor állítsuk vissza a határra, és fordítsuk meg a sebességét!
ez nem helyes, de egyszerű.
*/
void szimulacio_leptet(szimulacio* szim,double dt){

    
    }
/*
        if(szim->reszecskek[i]->x<0){
            szim->reszecskek[i]->x=0;
            szim->reszecskek[i]->vx=-szim->reszecskek[i]->vx;
        }
        if(szim->reszecskek[i]->x>szim->x_limit){
            szim->reszecskek[i]->x=szim->x_limit;
            szim->reszecskek[i]->vx=-szim->reszecskek[i]->vx;
        }
        if(szim->reszecskek[i]->y<0){
            szim->reszecskek[i]->y=0;
            szim->reszecskek[i]->vy=-szim->reszecskek[i]->vy;
        }
        if(szim->reszecskek[i]->y>szim->y_limit){
            szim->reszecskek[i]->y=szim->y_limit;
            szim->reszecskek[i]->vy=-szim->reszecskek[i]->vy; */
/* "getter" függvények, arra szolgálnak, hogy 'szabványos' módon lekérjük a szimuláció állapotát!*/

reszecske* get_reszecske(szimulacio* szim,int i){//Az elenevezésen lenne mit csiszolni, a globális térben honnan tudom, hogy ez szimulációhoz tartozik?
    return szim->reszecskek[i];
}
double get_x_limit(szimulacio* szim){
    return szim->x_limit;
}
double get_y_limit(szimulacio* szim){
    return szim->y_limit;
}
int get_db(szimulacio* szim){
    return szim->darab;
}
