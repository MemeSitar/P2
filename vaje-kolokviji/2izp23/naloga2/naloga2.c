
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
void razbij(int trenutna, int najmanj, int najvec, char* niz, char* buffer);


int main() {
    char* buffer = calloc(100, sizeof(char));
    char* niz = calloc(16, sizeof(char));
    int najmanj;
    int najvec;
    scanf("%s%d%d", niz, &najmanj, &najvec);

    // prestej stevilo characterjev v nizu.
    int dolzina = 0;
    for(int i = 0; niz[i] != '\0'; i++){
        dolzina++;
    }

    printf("%s je dolg %d\n", niz, dolzina);

    kopirajDoKonca(niz, buffer, 1, 2);
    printf("%s\n", buffer);
    return 0;
}

void razbij(int trenutna, int najmanj, int najvec, char* niz, char* buffer){
    if(niz[0] == '\0' || najvec == 1){
        printf("%s\n", buffer);
        return;
    }
    
    int dolzina = 0;
    for(int i = 0; niz[i] != '\0'; i++){
        dolzina++;
    }

    if(dolzina < najmanj){
        return;
    }

    for(int i = 0; i < dolzina; i++){
        buffer[trenutna + i] = niz[i];
    }
}
