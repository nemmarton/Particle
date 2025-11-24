#include "reszecske.h"
#include <stdio.h> //NULL
#include <stdlib.h>
#include <time.h>
#include "szimulacio.h"
/*
foglalunk egy új-at, beállítjuk a darabszámot, x és y limitet, lefoglaljuk a 
részecskék tömbjét (indefinit még a tartalmom!)
*/
szimulacio* szimulacio_csinal(int db, double x_limit,double y_limit){   
 szimulacio* uj=(szimulacio*)malloc(sizeof(szimulacio));
 uj->darab=db;
 uj->x_limit=x_limit;
 uj->y_limit=y_limit;
 uj->reszecskek=(reszecske**)malloc(db*sizeof(reszecske*));
 return uj;
}
/* minden részecskét törlünk, mielőőt az őkat címző tömböt törölnénk!*/
void szimulacio_torol(szimulacio* szim){
    for(int i=0;i<szim->darab;i++){
        torol_reszecsket(szim->reszecskek[i]);
    }    
    free(szim->reszecskek);
    free(szim);
}
/*
    random helyekre és sebességekre állítjuk be a részecskéket, random=rand()/(double)RAND_MAX*limit
    először inicializáljuk a random szám generátort: srand((unsigned int)time(NULL));
    meghivjuk csinal_reszecsket()-et! 
    V_max nincs a rendszerben, mert csak bemutató jellegű a szimuláció!
*/
void szimulacio_init(szimulacio* szim){   
    srand((unsigned int)time(NULL));
    for(int i=0;i<szim->darab;i++){
        double x=rand()/(double)RAND_MAX*szim->x_limit;
        double y=rand()/(double)RAND_MAX*szim->y_limit;
        double vx=2*rand()/(double)RAND_MAX-1;
        double vy=2*rand()/(double)RAND_MAX-1;
        szim->reszecskek[i]=csinal_reszecsket(x,y,vx,vy);

    }
}

/*
léptetjük az összes részecskét a dt idővel, majd ellenőrizzük, hogy nem lépett-e ki a határokon! Ha igen, akkor állítsuk vissza a határra, és fordítsuk meg a sebességét!
ez nem helyes, de egyszerű.
*/
void szimulacio_leptet(szimulacio* szim,double dt){ 
    for(int i=0;i<szim->darab;i++){
        mozgat_reszecsket(szim->reszecskek[i],dt);
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
            szim->reszecskek[i]->vy=-szim->reszecskek[i]->vy; 

        }
    }
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
