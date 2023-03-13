#include <stdio.h>

int main() {
    int c = 0;
    int result = '1';
    int zacetek = 1;
    int druga = 0;

    // glavna funkcija

    main:
    while((c = getchar()) != '\n'){

        // ce konec stevilke, izpisi, resetiraj rezultat in zacetek.
        if (c == ' '){
            // "druga check" - torej ce je samo "+ " je to narobe.
            if (druga){
                result = '0';
            }
            putchar(result);
            result = '1';
            zacetek = 1;
            druga = 0;
            goto main;
        }

        // DEJANSKA LOGIKA

        // ce je druga prisla do sem, je good
        if (druga){
            druga = 0;
            zacetek = 0;
            // po tem nadaljujes.
        }

        // ce je na zacetku + ali - je kul.
        if (zacetek == 1 && c == '+' || zacetek == 1 && c == '-'){
            //printf("%s\n", "MJAU");
            zacetek = 0;
            druga = 1;
            goto main;
            //printf("%s\n", "MJAU");
        }

        if ((zacetek != 1) && c < '0' || (zacetek != 1) && c > '9'){
            //printf("%s\n", "bingo!");
            result = '0';
            goto main;
        }
    }

    // ce konec cele reci, izpisi zadnjega
    // (ne bo zadetka pri == ' ')

    // ponoven "druga" check - ce je "+\n" je to narobe.
    if (druga){
        result = '0';
    }
    putchar(result);
    putchar('\n');

    return 0;
}