#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]){
    FILE* slika = fopen(argv[1], "rb");
    FILE* izhodna = fopen(argv[2], "wb");
    char* sirinaArr = calloc(10, sizeof(char));
    char* visinaArr = calloc(10, sizeof(char));
    int sirina = 0;
    int visina = 0;
    char buffer = '\0';
    int R = 0;
    int G = 0;
    int B = 0;
    __uint8_t buff = 0;

    // P6'\n' (header)
    for(int i = 0; i < 3; i++){
        fgetc(slika);
    }
    fprintf(izhodna, "P5\n");

    // pridobimo visino in sirino
    int i = 0;
    while((buffer = fgetc(slika)) != ' '){
        sirinaArr[i] = buffer;
        i++;
    }
    sirina = atoi(sirinaArr);
    //printf("%d\n", sirina);
    i = 0;
    while((buffer = fgetc(slika)) != '\n'){
        visinaArr[i] = buffer;
        i++;
    }
    visina = atoi(visinaArr);
    //printf("%d\n", visina);

    fprintf(izhodna, "%d %d\n", sirina, visina);

    // 255'\n' (header pred podatki.)
    for(int i = 0; i < 4; i++){
        fgetc(slika);
    }
    fprintf(izhodna, "255\n");

    for(int i = 0; i < visina*sirina; i++){
        fread(&R, 1, 1, slika);
        fread(&G, 1, 1, slika);
        fread(&B, 1, 1, slika);

        buff = (__uint8_t) ceil((30*R + 59*G + 11*B)/100);
        fwrite(&buff, 1, 1, izhodna);
        //printf("%d %d %d\n", R, G, B);
    }

    fclose(slika);
    fclose(izhodna);
    return 0;
}