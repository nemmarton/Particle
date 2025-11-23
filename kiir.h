#ifndef KIIR_H
#define KIIR_H

#include "szimulacio.h"
//itt elrejtjük az adatszerkezetet is! Nem kell kívülről látni!
typedef struct kiiro kiiro;

// Létrehozás / felszabadítás
kiiro* kiiro_csinal(szimulacio* sim, int width, int height);
void kiiro_torol(kiiro* r);

// Kirajzolás
void kiiro_rajzol(kiiro* r);

#endif
