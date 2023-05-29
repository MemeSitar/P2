#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILENAME_LEN 100
#define SEG printf("%s:%d\n", __FILE__, __LINE__);

int main(){
    // preberi vse osnovne reci
    int n = 0;
    char ime_datoteke[100];
    scanf("%d", &n);
    int stevila[n];
    char stevilka[11];
    bool konec = false;
    int najmanjsiIndex = 0;
    int najmanjseStevilo = __INT_MAX__;

    // zapolni stevila z -1
    for (int i = 0; i < n; i++){
        stevila[i] = -1;
    }

    // naredi tabelo datotek.
    FILE** tabelaDatotek = malloc(n * sizeof(FILE*));
    // zapolni tabelo datotek z odprtimi datotekami
    for (int i = 0; i < n; i++){
        scanf("%s", ime_datoteke);
        tabelaDatotek[i] = fopen(ime_datoteke, "r");
    }

    // odpri datoteko za pisati
    scanf("%s", ime_datoteke);
    FILE* izhodnaDatoteka = fopen(ime_datoteke, "w");
    while (!konec){
        //printf("[");
        for (int i = 0; i < n; i++){
            if ((stevila[i]) == -1){
                if (fscanf(tabelaDatotek[i], "%s", stevilka) == EOF){
                    stevila[i] = -1;
                } else {
                    stevila[i] = atoi(stevilka);
                }
            }
            //printf("%d,",stevila[i]);
        }
        //printf("]\n");
        konec = true;
        for (int i = 0; i < n; i++){
            if(stevila[i] > 0){
                if (stevila[i] < najmanjseStevilo){
                    najmanjseStevilo = stevila[i];
                    najmanjsiIndex = i;
                }
                konec = false;
            }
        }
        najmanjseStevilo = __INT_MAX__;
        //printf("najmanjsi index je %d\n", najmanjsiIndex);
        if (stevila[najmanjsiIndex] != -1){
            fprintf(izhodnaDatoteka, "%d\n", stevila[najmanjsiIndex]);
        }
        stevila[najmanjsiIndex] = -1;
    }

    // konec programa
    for (int i = 0; i < n; i++){
        fclose(tabelaDatotek[i]);
    }
    fclose(izhodnaDatoteka);
}