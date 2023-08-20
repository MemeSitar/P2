
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga1
 * make test
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

void hendlaj(FILE* vhodna, FILE* izhodna);

int main(int argc, char* argv[]) {
    FILE* vhodna = fopen(argv[1], "rb");
    FILE* izhodna = fopen(argv[2], "wb");

    int buffer;

    while((buffer = fgetc(vhodna)) != EOF){
        if (buffer == 27){
            hendlaj(vhodna, izhodna);
        } else {
            fputc(buffer, izhodna);
        }
    }
    return 0;
}

void hendlaj(FILE* vhodna, FILE* izhodna){
    int buffer = fgetc(vhodna);
    if (buffer == 201){
        fputc(buffer, izhodna);
    } else if (buffer == EOF){
        fputc(27, izhodna);
    } else if (buffer == 27){
        fputc(27, izhodna);
        hendlaj(vhodna, izhodna);
    } else {
        fputc(27, izhodna);
        fputc(buffer, izhodna);
    }
}