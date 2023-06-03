
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

void delaj(FILE* vhodna, FILE* izhodna);

int main(int argc, char** argv) {
    char c;
    FILE* vhodna = fopen(argv[1], "r");
    FILE* izhodna = fopen(argv[2], "w");

    while((c = fgetc(vhodna)) != EOF){
        if (c == '"'){
            delaj(vhodna, izhodna);
        } else {
            fputc(c, izhodna);
        }
    } 

    fclose(vhodna);
    fclose(izhodna);
    return 0;
}

void delaj(FILE* vhodna, FILE* izhodna){
    char c = fgetc(vhodna);
    if (c == 'S' || c == 's' || c == 'Z' || c == 'z' || c == 'C' || c == 'c'){
        fputc(c, izhodna);
        return;
    }
    if (c == '"'){
        fputc(c, izhodna);
        delaj(vhodna, izhodna);
        return;
    }
    fputc('"', izhodna);
    fputc(c, izhodna);
}