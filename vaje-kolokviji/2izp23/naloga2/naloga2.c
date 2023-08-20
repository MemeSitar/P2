
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga2
 * make test
 *
 * Testni primeri:
 * 02--06: a = 1, b = n
 * 01, 07--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...
void razbij(int najmanj, int najvec, char* niz);
void kopirajDoKonca(char* niz1, char* niz2, int trenutna1, int trenutna2);

int main() {
    char* buffer = calloc(100, sizeof(char));
    char* niz = calloc(16, sizeof(char));
    int najmanj;
    int najvec;
    scanf("%s%d%d", niz, &najmanj, &najvec);

    buffer[0] = niz[0];
    buffer[1] = '|';
    kopirajDoKonca(niz, buffer, 1, 2);
    printf("%s\n", buffer);
    return 0;
}

void razbij(int najmanj, int najvec, char* niz){

}

void kopirajDoKonca(char* source, char* dest, int trenutna1, int trenutna2){
    while(source[trenutna1] != EOF){
        dest[trenutna2] = source[trenutna1];
        trenutna2++;
        trenutna1++;
    }
}