
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 *
 * Testni primeri:
 * 02--06: y = 0, koordinate x nara"s"cajo
 * 01, 07--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// po potrebi dopolnite ...

void isci(int* koordinate, int* pot, int stKamnov, int globina, int razdalja);
double razdalja(int, int, int, int);

int main() {
    int stKamnov;
    int maxRazdalja;
    int globina = 0;
    scanf("%d %d", &stKamnov, &maxRazdalja);

    int* koordinate = malloc(2*stKamnov*sizeof(int));

    int* pot = malloc(stKamnov*sizeof(int));

    for(int i = 0; i < stKamnov; i++){
        scanf("%d %d", &koordinate[2*i], &koordinate[2*i+1]);
    }

    isci(koordinate, pot, stKamnov, globina, maxRazdalja);

    return 0;
}

void isci(int* koordinate, int* pot, int stKamnov, int globina, int maxRazdalja){
    if (globina == 0){
        pot[0] = 0;
    }
    int tarcaX = koordinate[2*(stKamnov - 1)];
    int tarcaY = koordinate[2*(stKamnov -1) + 1];
    int trenutenX = koordinate[pot[globina]*2];
    int trenutenY = koordinate[pot[globina]*2 + 1];
    double trenutnaRazdaljaTarce = razdalja(tarcaX, tarcaY, trenutenX, trenutenY);
    double novaRazdaljaDoTarce;


    // preverimo ce smo prisli do konca.
    if(trenutnaRazdaljaTarce == 0){
        printf("0");
        for(int i = 1; i < globina; i++){
            printf("->%d", pot[globina]);
        }
        printf("\n");
        return;
    }

    // sicer iteriramo cez vse
    for(int i = 1; i < stKamnov; i++){
        novaRazdaljaDoTarce = razdalja(koordinate[2*i], koordinate[2*i+1], tarcaX, tarcaY);
        if((novaRazdaljaDoTarce < trenutnaRazdaljaTarce) && ((int) novaRazdaljaDoTarce < maxRazdalja)){
            globina++;
            pot[globina] = i;
            isci(koordinate, pot, stKamnov, globina, maxRazdalja);
        }
    }
    
}

double razdalja(int x1, int y1, int x2, int y2){
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}