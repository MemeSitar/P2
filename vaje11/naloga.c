
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int vsotaI(Vozlisce* zacetek) {
    int vsota = 0;
    Vozlisce* naslednje = zacetek;
    while(naslednje != NULL){
        vsota += naslednje->podatek;
        naslednje = naslednje->naslednje;
    }
    return vsota;
}

int vsotaR(Vozlisce* zacetek) {
    if(zacetek == NULL){
        return 0;
    }
    if(zacetek->naslednje == NULL){
        return zacetek->podatek;
    }
    return zacetek->podatek + vsotaR(zacetek->naslednje);
}

Vozlisce* vstaviUrejenoI(Vozlisce* zacetek, int element) {
    // popravite / dopolnite ...
    return zacetek;
}

Vozlisce* vstaviUrejenoR(Vozlisce* zacetek, int element) {
    // popravite / dopolnite ...
    return NULL;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}

#endif
