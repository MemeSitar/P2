
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

#define SEG printf("%s:%d\n", __FILE__, __LINE__);

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
    Vozlisce* current = zacetek;
    Vozlisce* next = current->naslednje;
    if (current->podatek > element){
        Vozlisce* novoVozlisce = malloc(sizeof(Vozlisce));
        novoVozlisce->podatek = element;
        novoVozlisce->naslednje = current;
        return novoVozlisce;
    }
    
    while(next != NULL && next->podatek < element){
        current = next;
        next = current->naslednje;
    }
    if (next->podatek >= element){
        Vozlisce* novoVozlisce = malloc(sizeof(Vozlisce));
        novoVozlisce->podatek = element;
        current->naslednje = novoVozlisce;
        novoVozlisce->naslednje = next;
    } else if (next == NULL){
        Vozlisce* novoVozlisce = malloc(sizeof(Vozlisce));
        novoVozlisce->podatek = element;
        current->naslednje = novoVozlisce;
        novoVozlisce->naslednje = NULL;
    }
    return zacetek;
}

Vozlisce* vstaviUrejenoR(Vozlisce* zacetek, int element) {
    if (zacetek->podatek >= element){
        Vozlisce * novoVozlisce = malloc(sizeof(Vozlisce));
        novoVozlisce->podatek = element;
        novoVozlisce->naslednje = zacetek;
        return novoVozlisce;
    }
    if (zacetek->podatek < element && zacetek->naslednje->podatek >= element){
        Vozlisce * novoVozlisce = malloc(sizeof(Vozlisce));
        novoVozlisce->podatek = element;
        novoVozlisce->naslednje = zacetek->naslednje;
        zacetek->naslednje = novoVozlisce;
        return zacetek;
    }
    if (zacetek->naslednje->podatek < element){
        return vstaviUrejenoR(zacetek->naslednje, element);
    }
    return zacetek;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}

#endif
