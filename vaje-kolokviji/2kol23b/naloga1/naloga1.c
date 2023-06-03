
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

int main(int argc, char** argv) {
    FILE* vhodna = fopen(argv[1], "r");
    FILE* izhodna = fopen(argv[2], "w");

    bool zacetek = true;
    char c;

    while((c = fgetc(vhodna)) != EOF){
        if (zacetek && c == ' '){
            while((c = fgetc(vhodna)) == ' ');
        }
        fputc(c, izhodna);
        zacetek = false;
        if (c == '\n'){
            zacetek = true;
        }
    }

    fclose(vhodna);
    fclose(izhodna);
    return 0;
}
