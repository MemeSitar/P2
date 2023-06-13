#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char* imeVhodne = calloc(20, sizeof(char));
    char* imeIzhodne = calloc(20, sizeof(char));
    char znak[2];
    znak[1] = '\0';
    char* zadnjaVrstica = calloc(1000, sizeof(char));
    char* buffer = calloc(1000, sizeof(char));

    scanf("%s\n%s\n%c", imeVhodne, imeIzhodne, &znak[0]);

    //printf("\nISKAN ZNAK JE: '%s'\n", znak);

    FILE* vhodna = fopen(imeVhodne, "r");
    FILE* izhodna = fopen(imeIzhodne, "w");

    while(fgets(buffer, 1000, vhodna) != NULL){
        //printf("%s", buffer);
        if (strstr(buffer, znak) != NULL){
            //printf("BINGO");
            strcpy(zadnjaVrstica, buffer);
        }
    }
    fputs(zadnjaVrstica, izhodna);

    // koncaj
    fclose(vhodna);
    fclose(izhodna);
    free(imeVhodne);
    free(imeIzhodne);
    free(zadnjaVrstica);
    free(buffer);
    return 0;
}