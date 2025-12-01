#include <stdio.h>
/*
Határozzuk meg x=tan(log(x)) egyenlet megoldását 2-5 intervallumon, felhasználó adja meg a konvergenciakritériumot!
*/
#include <math.h>
double f(double x){
return x-tan(log(x));}

double gyok_keres(double bal, double jobb,double eps){
    double k;
    //TFH csökken... Ha nem akkor kell egy -1!
    while(jobb-bal>eps){
        k=(bal+jobb)/2;
        if(f(k)>0)
            bal=k;
        else
            jobb=k;
        }
    return k;
}

int main(){
printf("adj konv kritériumot!");
double konv;
scanf("%lf",&konv);
double eps=0.00001;
double bal=2.0;
double jobb=4.5;
double k_regi=2,k_uj=4;
while(fabs(f(k_regi)-f(k_uj))>konv){
    k_regi=k_uj;
    eps=eps/2;
    k_uj=gyok_keres(bal,jobb,eps);
    printf("gyok: %f, eps: %f",k_uj,k_regi);
}
printf("gyok: %f, eps: %f",k_uj,eps);

}
//gcc -c ZH_2.c
//gcc -o ZH_2 ZH_2.o -lm
//./ZH_2