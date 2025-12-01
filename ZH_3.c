#include <stdio.h>
/* int tömbből válogassuk le a negatív elemeket meg a pozitív elemeket egy függvénnyel, próbáljuk ki*/
#include <stdlib.h>

void valogat(int* eredeti, int eredeti_n, int* negativ[], int* negativ_n,int* pozitiv[],int*pozitiv_n){
    //eloszor szamolunk
    for (int i=0;i<eredeti_n;i++){
        if(eredeti[i]>0)
            (*pozitiv_n)++;
        else
            (*negativ_n)++;
    }
        //majd foglalunk
        *negativ=(int*)malloc(sizeof(int)*(*negativ_n));
        *pozitiv=(int*)malloc(sizeof(int)*(*pozitiv_n));
        if(*negativ==NULL||*pozitiv==NULL)
            return;
        //pakolunk:
        int n=0,p=0;
        for (int i=0;i<eredeti_n;i++){
        if(eredeti[i]>0)
            (*pozitiv)[p++]=eredeti[i];
        else
            (*negativ)[n++]=eredeti[i];    
    }//kész....
return;
}

int main(){//demonstráljunk
    int tomb[]={-1,1,2,3,4,-5,-6,-7,-8};//próba tömb
    int* poz;//helytartója a foglalásnak
    int poz_n=0; //helytartója a méretnek
    int* neg;//....
    int neg_n=0;
    valogat(tomb,9,&neg,&neg_n,&poz,&poz_n);
    if(neg==NULL||poz==NULL)
        return -1; //itt tudom kezelni a gondot, nem hivatkozok NULL-ra!
    for(int i=0;i<neg_n;i++){
        printf("%d",neg[i]);
    }
    free(neg);
    free(poz);
    return 0;
}
/*
gcc -o ZH_3 ZH_3.o
gcc -c ZH_3.c
./ZH_3
*/