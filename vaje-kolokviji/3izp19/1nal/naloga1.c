#include <stdlib.h>
#include <stdio.h>

int main(){
    char* vhodnaIme = malloc(20*sizeof(char));
    char* izhodnaIme = malloc(20*sizeof(char));
    int dolzina = 0;
    scanf("%s\n%d\n%s\n", vhodnaIme, &dolzina, izhodnaIme);
    FILE* vhodna = fopen(vhodnaIme, "rb");
    FILE* izhodna = fopen(izhodnaIme, "w");
    int stevilka = 0;
    for(int i = 0; i < dolzina; i++){
        stevilka = fgetc(vhodna);
        if (stevilka < 16){
            fprintf(izhodna, "0");
        }
        fprintf(izhodna, "%0X\n", stevilka);
    }
    fclose(vhodna);
    fclose(izhodna);
}