#include <stdio.h>
#include <unistd.h> // sleep
#include "szimulacio.h"
#include "kiir.h"
#include "reszecske.h"

int main() {
    int n = 50;
    double limit_x = 140.0;
    double limit_y = 40.0;
    double dt = 1;

    szimulacio* sim = szimulacio_csinal(n, limit_x, limit_y);
    //printf("Szimulacio letrehozva %zu reszecskevel a(z) %.2fx%.2f teruleten.\n", n, limit_x, limit_y);
    szimulacio_init(sim);
    //printf("Szimulacio inicializalva.\n");

    kiiro* r = kiiro_csinal(sim, 80, 20);

    for(int step=0; step<55550; step++) {
        system("clear"); // Linux / Mac, Windows: "cls"
        printf("Step %d\n", step);
        kiiro_rajzol(r);
        szimulacio_leptet(sim, dt);
        usleep(100000); // 0.1s
    }

    kiiro_torol(r);
    szimulacio_torol(sim);
    return 0;
}