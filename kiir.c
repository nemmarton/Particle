#include "kiir.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct kiiro {//beslo megjelenítes lehet angolul is akár, senki sem látja (kivéve te:))
    szimulacio* szim;
    int width;//karakterek száma
    int height;
};

kiiro* kiiro_csinal(szimulacio* szim, int width, int height) {
    kiiro* r = (kiiro*)malloc(sizeof(kiiro));
    if(r==NULL) return NULL;//legalább ez szabályos legyen
    r->szim = szim;
    r->width = width;
    r->height = height;
    return r;
}

void kiiro_torol(kiiro* r) {
    free(r);
}

void kiiro_rajzol(kiiro* r) {
    char** grid = (char**)malloc(r->height * sizeof(char*));//bemutatónak jó lesz, de nem kellene mindig újra foglalni, csak egyszer
    for(int y=0;y<r->height;y++) {//része lehetne a struct-nak is
        grid[y] = (char*)malloc(r->width * sizeof(char));
        for(int x=0;x<r->width;x++) grid[y][x] = ' ';
    }

    size_t n =get_db(r->szim);
    double box_w = get_x_limit(r->szim);//jó ez így? valahogy kellene tudni, hogy szimulációhoz tartozik-e
    double box_h = get_y_limit(r->szim);

    for(size_t i=0;i<n;i++) {
        reszecske* p = get_reszecske(r->szim,i);
        int px = (int)(get_x(p) / box_w * r->width);//skálázás x_limit és box_w között
        int py = (int)(get_y(p) / box_h * r->height);//meg lefelé kerekítünk... hát ez sem szép
        if(px >= r->width) px = r->width-1;
        if(py >= r->height) py = r->height-1;
        grid[py][px] = '*';
    }

    // Kiírás (felső sor a 0)
    for(int y=r->height-1;y>=0;y--) {
        for(int x=0;x<r->width;x++)
            putchar(grid[y][x]);
        putchar('\n');
        free(grid[y]);
    }
    free(grid);
}
