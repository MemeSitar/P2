
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

int main(int argc, char** argv) {
    FILE * vhodna = fopen(argv[1], "rb");
    FILE * izhodna = fopen(argv[2], "wb");

    __u_int buff = 0x0;
    __u_int byte = fgetc(vhodna);


    while((byte = fgetc(vhodna)) != EOF){
        if (buff != byte)
        {
            fputc(byte, izhodna);
            buff = byte;
        }
    }
    fclose(izhodna);
    fclose(vhodna);
    return 0;
}