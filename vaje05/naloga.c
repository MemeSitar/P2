
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

int vsota(int* zac, int* kon) {
    int vsota = 0;
    while (zac <= kon){
        vsota += *zac;
        zac++;
    }
    return vsota;
}

void indeksInKazalec(int* t, int* indeks, int** kazalec) {
    if (*indeks == -1){
        *indeks = *kazalec - t;
    } else {
        *kazalec = &t[*indeks];
    }
}

void frekvenceCrk(char* niz, int** frekvence) {
    // dopolnite ...
}

#ifndef test

int main() {
    int t[5]  = {1,4,5,1,4};
    int rezultat = vsota(t+1, t+3);
    printf("%d", rezultat);
    return 0;
}

#endif
