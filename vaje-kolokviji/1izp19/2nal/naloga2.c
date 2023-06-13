#include <stdlib.h>
#include <stdio.h>

#include <naloga2.h>

Vozlisce* obrni(Vozlisce* zacetek){
    int dolzina = 1000;
    int stevec = 1;
    Vozlisce** tabelaVozlisc = malloc(dolzina*sizeof(Vozlisce*));
    Vozlisce* trenutno = zacetek;
    tabelaVozlisc[0] = NULL;

    while(trenutno != NULL){
        if (stevec >= dolzina){
            dolzina += 1000;
            realloc(tabelaVozlisc, dolzina*sizeof(Vozlisce*));
        }
        tabelaVozlisc[stevec] = trenutno;
        stevec++;
        trenutno = trenutno->naslednje;
    }

    for(int i = 0; i <= stevec; i++){
        trenutno = tabelaVozlisc[i+1];
        trenutno->naslednje = tabelaVozlisc[i];
    }
    return trenutno;
}

// za testiranje
int main(){
    return 0;
}