
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
void odstraniTrenutno(Vozlisce* prejsnje);

// po potrebi dopolnite ...

void izlociSkupne(Vozlisce* a, Vozlisce* b, Vozlisce** noviA, Vozlisce** noviB) {
    noviA = a;
    noviB = b;
    
    Vozlisce* Atrenutno = a;
    Vozlisce* Aprejsnje = a;
    Vozlisce* Btrenutno = b;
    Vozlisce* Bprejsnje = b;

    int Avrednost = 0;
    int Bvrednost = 0;

    while(Atrenutno != NULL){
        Avrednost = Atrenutno->podatek;
        
        
    }
}

void odstraniTrenutno(Vozlisce* prejsnje){
    Vozlisce* trenutno = prejsnje->naslednje;
    prejsnje->naslednje = trenutno->naslednje;
    free(trenutno);
}

void primerjaj(Vozlisce* vozlisceA, Vozlisce* vozlisceB){
    int Avrednost = vozlisceA->podatek;
    Vozlisce* Bprejsnje = vozlisceB;

    while(vozlisceB != NULL){
        if(vozlisceB->podatek == Avrednost){

        }
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
