
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int steviloZnakov(char* niz, char znak) {
    int stevilo = 0;
    for (int i = 0; niz[i] != '\0'; i++){
        if (niz[i] == znak){
            stevilo++;
        }
    }
    return stevilo;
}

char* kopirajDoZnaka(char* niz, char znak) {
    int velikost = 0;
    while (niz[velikost] != '\0' && niz[velikost] != znak){
        velikost++;
    }

    char* tabela = malloc((velikost + 1)*sizeof(char));

    for (int i = 0; i < velikost; i++){
        tabela[i] = niz[i];
    }

    tabela[velikost] = '\0';
    return tabela;
}

char** razcleni(char* niz, char locilo, int* stOdsekov) {
    int steviloClenov = steviloZnakov(niz, locilo) + 1;
    *stOdsekov = steviloClenov;

    char ** tabelaKazalcev;
    tabelaKazalcev = malloc(steviloClenov*sizeof(char*));

    int velikostNiza = 0;
    while (niz[velikostNiza] != '\0'){
        velikostNiza++;
    }

    int offset = 0;
    for (int i = 0; i < steviloClenov; i++){
        tabelaKazalcev[i] = kopirajDoZnaka(&niz[offset], locilo);
        offset += dolzinaNiza(tabelaKazalcev[i]) + 1;
    }
    return tabelaKazalcev;
}

int dolzinaNiza(char * niz){
    int stevilo = 0;
    for (int i = 0; niz[i] != '\0'; i++){
        stevilo++;
    }
    return stevilo;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    printf("%d\n", dolzinaNiza("meowmeow"));
    printf("%d\n", dolzinaNiza(kopirajDoZnaka("meow", '.')));
    return 0;
}

#endif
