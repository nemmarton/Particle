#include <stdio.h>
/* ZH eredmenyek file-ban, NEPTUN EREDMENY formában, olvassuk tömbbe, kereshető legyen!*/
#include <stdlib.h>
#include <string.h>

typedef struct Hallgato{
    char neptun[7];
    int jegy;
}Hallg;

int main(){
    //nyissunk file-t olvassuk be az adatokat:
    FILE* fp=fopen("jegyek.txt","r");
    //Ha nem megy:
    if (fp==NULL){
        return -1;
    }
    int meret;
    fscanf(fp,"%d",&meret);
    //foglaljunk tömböt
    Hallg* hallgatok=(Hallg*)malloc(meret*sizeof(Hallg));
    //sikerült?
    if(hallgatok==NULL){
        fclose(fp);
        return -2;
    }
    //soronként olvassuk, tároljuk
    for(int i=0;i<meret;i++){
        fscanf(fp,"%s %d",hallgatok[i].neptun, &hallgatok[i].jegy); //stringhez nem kell cím mert az már maga cím
    }
    fclose(fp);//már nem kell!
    //akkor keresheto: 
    printf("adja meg a neptunt");
    char mit[7];
    while(scanf("%s",mit)>0&&strcmp(mit,"NEMNEM")){//azért itt ez nem biztonságos...
    //keressük meg
    for(int i=0;i<meret;i++){
        if(!strcmp(mit,hallgatok[i].neptun))
            printf("%s hallgato jegye: %d",mit,hallgatok[i].jegy);}
    printf("adja meg a neptunt"); //kell jelezni, ha nincs találat? ha igen int kimegy for elé, és csekkolom i==meret!
    }
    free(hallgatok);
    return 0;
}
/*
gcc -o ZH_4 ZH_4.o
gcc -c ZH_4.c
./ZH_4
*/