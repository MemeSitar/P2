#include <stdlib.h>
#include <stdio.h>

int main(){
    int stevilo = 0;
    int najvisje = 0;
    int trenutno = 0;
    char* pot = malloc(500*sizeof(char));
    scanf("%d\n%s", &stevilo, pot);
    int tabelaVisin[stevilo];
    char izpis = '\0';

    // poiscemo visino
    for(int i = 0; i < stevilo; i++){
        if (pot[i] == 'G'){
            trenutno++;
            tabelaVisin[i] = trenutno;
            if (trenutno > najvisje){
                najvisje = trenutno;
            }
        } else if (pot[i] == 'D'){
            tabelaVisin[i] = trenutno;
            trenutno--;
        }
    }
    // po tem vemo da je pravokotnik velik stevilo * najvisje

    for(int j = najvisje; j > 0; j--){
        for (int i = 0; i < stevilo; i++){
            if (tabelaVisin[i] == j){
                izpis = (pot[i] == 'G') ? '/' : '\\';
                printf("%c", izpis);
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    return 0;
}