#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int steviloKta(char* niz, int k, int* indeks);
void indeksi(char* niz, int** t);
char** zadnje(char** nizi);

int steviloKta(char* niz, int k, int* indeks){
    int stevec = 0;
    for(int i = 0; niz[i] != '\0'; i++){
        if (niz[i] >= 'A' && niz[i] <= 'Z'){
            stevec++;
            if (stevec == k){
                *indeks = i;
            }
        }
    }
    if (stevec < k){
        *indeks = -1;
    }
    return stevec;
}

void indeksi(char* niz, int** t){
    //najprej pogruntamo stevilo velikih crk in dolzino tabele
    int zadnjiIndeks = 0;
    int stVelikih = 0;
    while(niz[zadnjiIndeks] != '\0'){
        if (niz[zadnjiIndeks] >= 'A' && niz[zadnjiIndeks] <= 'Z'){
            stVelikih++;
        }
        zadnjiIndeks++;
    }

    int* tabela = malloc(sizeof(int)*(stVelikih+1));
    *t = tabela;
    int stevec = 0;
    while(zadnjiIndeks >= 0){
        if (niz[zadnjiIndeks] >= 'A' && niz[zadnjiIndeks] <= 'Z'){
            tabela[stevec] = zadnjiIndeks;
            stevec++;
        }
        zadnjiIndeks--;
    }
    tabela[stevec] = -1;
}

char** zadnje(char** nizi){
    // pogruntamo velikost tabele
    int stevec = 0;
    for(int i = 0; nizi[i] != NULL; i++){
        stevec++;
    }
    char** tabela = malloc(stevec*sizeof(char*));
    // gremo cez vse tabele
    bool imaVeliko = false;
    for(int i = 0; nizi[i] != NULL; i++){
        //printf("%s\n", nizi[i]);
        //printf("mjau%d\n", i);
        for(int j = 0; nizi[i][j] != '\0'; j++){
            if(nizi[i][j] >= 'A' && nizi[i][j]<= 'Z'){
                tabela[i] = &nizi[i][j];
                imaVeliko = true;
            }
        }
        if (imaVeliko == false){
            tabela[i] = NULL;
        }
        imaVeliko = false;
    }
    //printf("KONEC!\n");
    return tabela;
}

int main(){
    // testiranje prvega dela
    int indeks = 0;
    char* niz = "Jaz sem Jurij Sitar";
    int k = 2;
    char* niz2 = "Jaz sem jurij sitar";
    int steviloVelikih = steviloKta(
        niz, k, &indeks
    );
    printf("Stevilo velikih crk = %d\nIndeks %d. crke = %d\n", steviloVelikih, k, indeks);
    steviloVelikih = steviloKta(
        niz2, k, &indeks
    );
    printf("Stevilo velikih crk = %d\nIndeks %d. crke = %d\n", steviloVelikih, k, indeks);

    // testiranje drugega dela
    int *tabela;
    indeksi(niz, &tabela);
    for(int i = 0; i < 4; i++){
        printf("%d ", tabela[i]);
    }
    printf("\n");

    // testiranje tretjega dela
    char* tabelaNizov[] = {"Jaz sem Jurij Sitar", "jaz sem jurij", "TEST", NULL};
    char** tabelaZadnjih = zadnje(tabelaNizov);
    for (int i = 0; i < 3; i++){
        if (tabelaZadnjih[i] == NULL){
            printf("NULL\n");
        } else {
            printf("%c\n", *tabelaZadnjih[i]);
        }
    }
    return 0;
}