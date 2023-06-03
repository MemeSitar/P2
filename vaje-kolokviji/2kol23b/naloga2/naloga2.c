
/*
 * Prevajanje in zagon testnega programa testXY.c:
 *
 * gcc -D=test testXY.c naloga2.c
 * ./a.out
 *
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga2
 * make test
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

#define SEG printf("%s:%d\n", __FILE__, __LINE__);
// po potrebi dopolnite ...

void izlociDuplikate(Vozlisce* zacetek) {
    Vozlisce* trenutno = zacetek;
    Vozlisce* prejsnje;
    Vozlisce* iskano;
    int vrednost;

    while(trenutno != NULL){
        //printf("mjau\n");
        iskano = trenutno->naslednje;
        prejsnje = trenutno;
        vrednost = *trenutno->p;
        while(iskano != NULL){
            if (vrednost == *iskano->p){
                prejsnje->naslednje = iskano->naslednje;
            } else {
                prejsnje = iskano;
            }
            iskano = iskano->naslednje;
        }
        trenutno = trenutno->naslednje;
    }
}

//=============================================================================

#ifndef test

int main() {
    // "Ce "zelite funkcijo izlociSkupne testirati brez testnih primerov,
    // dopolnite to funkcijo in prevedite datoteko na obi"cajen na"cin
    // (gcc naloga2.c).
    return 0;
}

#endif
