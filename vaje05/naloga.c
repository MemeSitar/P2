
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
    int *t = malloc(26*sizeof(int));
    for (int i = 0; i < 26; i++){
        t[i] = 0;
    }
    
    for(int i = 0; niz[i] != '\0'; i++){
        if (niz[i] >= 'a' && niz[i] <= 'z'){
            t[niz[i] - 'a']++;
        }
        if (niz[i] >= 'A' && niz[i] <= 'Z'){
            t[niz[i] - 'A']++;
        }
    }
    *frekvence = t;
}

#ifndef test

int main() {
    int t[5]  = {1,4,5,1,4};
    int rezultat = vsota(t+1, t+3);
    printf("%d", rezultat);
    return 0;
}

#endif
