
/*
 * Prevajanje in zagon testnega programa testXY.c:
 *
 * gcc -D=test testXY.c naloga3.c
 * ./a.out
 *
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 *
 * Testni primeri:
 * 02, 03: h = 1
 * 04, 05, 06: preverjajo samo vsoto
 * 01, 07--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

// po potrebi dopolnite ...

int izracunajVsoto(int kolicina, int* stevilke){
    int vsota = 0;
    for(int i = 0; i < kolicina; i++){
        vsota += stevilke[i];
    }
    return vsota;
}

Vozlisce* ustvariSeznam(int kolicina, int* stevilke){
    if(kolicina == 0)
        return NULL;
    Vozlisce* vozl = malloc(sizeof(Vozlisce));
    vozl->vsebina=stevilke[0];
    vozl->dol=NULL;
    vozl->desno=ustvariSeznam(kolicina-1, &stevilke[1]);
    return vozl;
}

Vozlisce* diagonala(Vozlisce* start, int* vsota) {
    Vozlisce* levoDol = start;
    Vozlisce* desnoGor = start;
    int sirina = 1;
    int visina = 1;

    // pogruntaj sirino
    while(desnoGor->desno != NULL){
        desnoGor = desnoGor->desno;
        sirina++;
    }

    // pogruntaj visino
    while(levoDol->dol != NULL){
        levoDol = levoDol->dol;
        visina++;
    }

    if (visina == 1){
        *vsota = desnoGor->vsebina;
        Vozlisce* rezultat = malloc(sizeof(Vozlisce));
        rezultat->desno = NULL;
        rezultat->dol = NULL;
        rezultat->vsebina = desnoGor->vsebina;
        return rezultat;
    }

    int kolicina = visina < sirina ? visina : sirina;
    //printf("kolicina: %d\n", kolicina);
    int stevilke[kolicina];

    Vozlisce* navpicno = start;
    Vozlisce* vodoravno = navpicno;

    for(int i = 0; i < kolicina; i++){
        for(int j = 0; j < sirina - i -1; j++){
            vodoravno = vodoravno->desno;
        }
        //printf("%d\n", vodoravno->vsebina);

        stevilke[i] = vodoravno->vsebina;
        navpicno = navpicno->dol;
        vodoravno = navpicno;
    }

    //printf("meow\n");
    *vsota = izracunajVsoto(kolicina, stevilke);
    return ustvariSeznam(kolicina, stevilke);
}

//=============================================================================

#ifndef test

int main() {
    int stevilke[3] = {1, 2, 3};
    printf("%d\n", izracunajVsoto(3, stevilke));
    return 0;
}

#endif
