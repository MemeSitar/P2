#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_FILENAME_LEN 100
#define SEG printf("%s:%d\n", __FILE__, __LINE__);

int main(){
    int n = 0;
    char ime_datoteke[100];
    scanf("%d", &n);
    FILE** tabelaDatotek = malloc(n * sizeof(FILE*));
    for (int i = 0; i < n; i++){
        scanf("%s", ime_datoteke);
        tabelaDatotek[i] = fopen(ime_datoteke, "r");
    }
    scanf("%s", ime_datoteke);
    FILE* izhodnaDatoteka = fopen(ime_datoteke, "w");
}