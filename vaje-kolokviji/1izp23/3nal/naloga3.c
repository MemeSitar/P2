
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
 * 04, 05, 06: mesto = 0
 * 01, 07--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <naloga3.h>

#define SEG //printf("%s:%d\n", __FILE__, __LINE__);

Vozlisce* vriniLevo(int vrednost, Vozlisce* trenutno, Vozlisce* spodnje);
Vozlisce* vriniDoDol(int vrednost, Vozlisce* trenutno);
void posodobiStolpec(Vozlisce* trenuten, Vozlisce* vrinjen);

// po potrebi dopolnite ...

Vozlisce* vstaviStolpec(Vozlisce* start, int mesto, int vsebina) {
    int visina = 0;
    SEG


    // Poiscemo visino
    Vozlisce* nizje = start;
    while(nizje != NULL){
        visina++;
        nizje = nizje->dol;
    }
    

    Vozlisce* trenutno = start;
    Vozlisce* prejsnje = trenutno;
    if (visina == 1){
        for(int i = 0; i < mesto; i++){
            prejsnje = trenutno;
            trenutno = trenutno->desno;
        }
        Vozlisce* vrinjeno = vriniLevo(vsebina, trenutno, NULL);
        if(mesto == 0){
            return vrinjeno;
        } else {
            prejsnje->desno = vrinjeno;
            return start;
        }
    }

    if (mesto == 0){
        return vriniDoDol(vsebina, start);
    }

    SEG
    trenutno = start;
    prejsnje = trenutno;
    for(int i = 0; i < mesto; i++){
        SEG
        prejsnje = trenutno;
        SEG
        trenutno = trenutno->desno;
        SEG
    }
    SEG
    Vozlisce* vrinjeno = vriniDoDol(vsebina, trenutno);
    SEG
    posodobiStolpec(prejsnje, vrinjeno);
    SEG
    return start;
}

Vozlisce* vriniDesno(int vrednost, Vozlisce* trenutno, Vozlisce* spodnje){
    Vozlisce* novoVozlisce = malloc(sizeof(Vozlisce));
    novoVozlisce->vsebina = vrednost;
    novoVozlisce->desno = trenutno->desno;
    novoVozlisce->dol = spodnje;
    trenutno->desno = novoVozlisce;
    return novoVozlisce;
}

Vozlisce* vriniLevo(int vrednost, Vozlisce* trenutno, Vozlisce* spodnje){
    Vozlisce* novoVozlisce = malloc(sizeof(Vozlisce));
    novoVozlisce->vsebina = vrednost;
    novoVozlisce->desno = trenutno;
    novoVozlisce->dol = spodnje;
    return novoVozlisce;
}

Vozlisce* vriniDoDol(int vrednost, Vozlisce* trenutno){
    SEG
    Vozlisce* novoVozlisce = malloc(sizeof(Vozlisce));
    SEG
    if(trenutno == NULL || trenutno->dol == NULL){
        novoVozlisce->dol = NULL;
        SEG
        novoVozlisce->desno = trenutno;
        novoVozlisce->vsebina = vrednost;
        SEG
        return novoVozlisce;
    }
    SEG
    novoVozlisce->desno = trenutno;
    novoVozlisce->vsebina = vrednost;
    SEG
    novoVozlisce->dol = vriniDoDol(vrednost+1, trenutno->dol);
    SEG
    return novoVozlisce;
}

void posodobiStolpec(Vozlisce* trenuten, Vozlisce* vrinjen){
    while(vrinjen != NULL){
        trenuten->desno = vrinjen;
        trenuten = trenuten->dol;
        vrinjen = vrinjen->dol;
    }
}

//=============================================================================

#ifndef test

int main() {
    // "Ce "zelite funkcijo <vstaviStolpec> testirati brez testnih primerov,
    // dopolnite to funkcijo in prevedite datoteko na obi"cajen na"cin
    // (gcc naloga3.c).
    return 0;
}

#endif
