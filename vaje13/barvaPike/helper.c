#include <stdio.h>
#include <stdlib.h>

#define SEG printf("%s:%d\n", __FILE__, __LINE__);

int main(int argc, char* argv[]){
    FILE* slika = fopen(argv[1], "rb");
    int vrstica = atoi(argv[2]);
    int stolpec = atoi(argv[3]);
    char* sirinaArr = calloc(10, sizeof(char));
    char* visinaArr = calloc(10, sizeof(char));
    int sirina = 0;
    int visina = 0;
    char buffer = '\0';
    int R = 0;
    int G = 0;
    int B = 0;
    int* buff = malloc(300000);

    // P6'\n' (header)
    for(int i = 0; i < 3; i++){
        putchar(fgetc(slika));
    }

    // pridobimo visino in sirino
    int i = 0;
    while((buffer = fgetc(slika)) != ' '){
        sirinaArr[i] = buffer;
        i++;
    }
    sirina = atoi(sirinaArr);
    printf("%d\n", sirina);
    i = 0;
    while((buffer = fgetc(slika)) != '\n'){
        visinaArr[i] = buffer;
        i++;
    }
    visina = atoi(visinaArr);
    printf("%d\n", visina);

    // 255'\n' (header pred podatki.)
    for(int i = 0; i < 4; i++){
        putchar(fgetc(slika));
    }

    // pridemo do prave vrstice in stolpca
    //fread(buff, 3, (vrstica)*(sirina), slika);
    //fread(buff, 3, (stolpec), slika);

    for(int i = 0; i < visina; i++){
        printf("%d: ", i);
        for(int j = 0; j < sirina; j++){
            fread(&R, 1, 1, slika);
            fread(&G, 1, 1, slika);
            fread(&B, 1, 1, slika);
            printf("[%d %d %d] ", R, G, B);
        }
        printf("\n");
    }
    fclose(slika);
}