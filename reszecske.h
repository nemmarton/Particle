#ifndef RESZECSKE_H
#define RESZECSKE_H
#include <stdio.h> //NULL
typedef struct reszecske{
    double x,y,vx,vy;
}reszecske; //eltuntetni->.c

//letrehozo
reszecske* csinal_reszecsket(double x, double y, double vx, double vy);//x,y,vx,vy
void torol_reszecsket(reszecske*);


//ún. getterek
double get_x(reszecske*);
double get_y(reszecske*);
double get_vx(reszecske*);
double get_vy(reszecske*);
//update
void mozgat_reszecsket(reszecske*,double);

#endif