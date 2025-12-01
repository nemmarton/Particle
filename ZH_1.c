
#include <stdio.h>
/* 10. palindrom prim*/
int prim_e(int n){
    for(int i=2;i<n/2;i++)
        if(n%i==0)
            return 0;
    return 1;
}
int palindrom_e(int n){
    int egyik=n;
    int masik=0;
    int i=1;
    while(egyik>0){
        masik+=i*(egyik%10);
        masik*=10;
        egyik=egyik/10;
    }
    masik/=10;
    printf("%d-",n);
    printf("%d\n",masik);
    return n==masik;

}

int main(){
    int db=0;
    int i=10;
    while(db<10){
        if(prim_e(i)&&palindrom_e(i)){
            db++;
        } 
        i++;
    }
    printf("%d",--i);
    return 0;
}
/*

gcc -c ZH_1.c
gcc -o ZH_1 ZH_1.o
./ZH_1
*/