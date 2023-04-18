#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int pojavitve(char* niz, char c, int* indeks);
void naslednjaPojavitev(char* niz, int* indeks);
char* kopijaPodniza(char* niz, char c, int k);

int pojavitve(char* niz, char c, int* indeks){
    int stevec = 0;
    for(int i = 0; niz[i] != '\0'; i++){
        if (niz[i] == c){
            if (stevec == 0){
                *indeks = i;
            }
            stevec++;
        }
    }
    if (stevec == 0){
        *indeks = -1;
    }
    return stevec;
}

void naslednjaPojavitev(char* niz, int* indeks){
    char c = niz[*indeks];
    if (niz[*indeks+1] == '\0'){
        *indeks = -1;
    } else {
        int novIndeks = 0;
        pojavitve(&niz[*indeks+1], c, &novIndeks);
        *indeks += novIndeks + 1;
    }
}

char* kopijaPodniza(char* niz, char c, int k){
    int prviIndeks = 0;
    pojavitve(niz, c, &prviIndeks);
    int drugiIndeks = prviIndeks;
    naslednjaPojavitev(niz, &drugiIndeks);
    int dolzinaNiza = drugiIndeks - prviIndeks;
    char* novNiz = malloc((dolzinaNiza+1)*sizeof(char));
    int stevec = 0;
    for(int i = prviIndeks+1; i < drugiIndeks; i++, stevec++){
        novNiz[stevec] = niz[i];
    }
    novNiz[stevec+1] = '\0';
    return novNiz;
}

int main(){
    // prvi test
    char* niz = "Ime mi je Jurij Sitar.";
    char c = 'j';
    int indeks = 0;
    int stPojavitev = pojavitve(niz, c, &indeks);
    printf(
            "%c se v nizu pojavi %d-krat, najprej na %d. mestu.\n",
            c, stPojavitev, indeks
        );
    c = 'z';
    stPojavitev = pojavitve(niz, c, &indeks);
    printf(
            "%c se v nizu pojavi %d-krat, najprej na %d. mestu.\n",
            c, stPojavitev, indeks
        );
    
    // drugi test
    naslednjaPojavitev(niz, &indeks);
    printf(
        "%c se v nizu drugic pojavi na %d. mestu.\n",
                c, indeks
    );

    //tretji test
    char* novNiz = kopijaPodniza(niz, 'i', 1);
    printf("%s\n", novNiz);
    return 0;
}