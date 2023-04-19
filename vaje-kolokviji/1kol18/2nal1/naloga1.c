#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define P(msg) {printf("%s\n", msg);}

int manjse(int a, int b);

int main(){
    // nafilamo obe tabeli.
    int dolzina1;
    int dolzina2; 

    scanf("%d", &dolzina1);
    int* tabela1 = malloc(dolzina1*sizeof(int));
    for (int i = 0; i < dolzina1; i++){
        scanf("%d", &tabela1[i]);
    }

    scanf("%d", &dolzina2);
    int* tabela2 = malloc(dolzina2*sizeof(int));
    for (int i = 0; i < dolzina2; i++){
        scanf("%d", &tabela2[i]);
    }

    int* rezultat = malloc((dolzina1 + dolzina2)*sizeof(int));

    int i = 0;
    int j = 0;
    int stevec = 0;
    //printf("mjau\n");
    while (i < dolzina1 || j < dolzina2){
        while (i < dolzina1 && tabela1[i] == rezultat[stevec]){
            i++;
        }
        while (j < dolzina2 && tabela2[j] == rezultat[stevec]){
            j++;
        }
        
        if (tabela1[i] == tabela2[j]){
            //printf("1. moznost iteracija i=%d j=%d\n", i, j);
            rezultat[stevec] = tabela1[i];

            while(i < dolzina1 && tabela1[i] == rezultat[stevec]){
                i++;
                //printf("Po inkrementu i=%d\n", i);
            }
            while(j < dolzina2 && tabela2[j] == rezultat[stevec]){
                j++;
                //printf("Po inkrementu j=%d\n", j);
            }
            stevec++;
            //printf("mjau?\n");
        } else if (i < dolzina1 && j < dolzina2 && tabela1[i] < tabela2[j]){
            //printf("2. moznost iteracija %d\n", i);
            rezultat[stevec] = tabela1[i];
            while(i < dolzina1 && tabela1[i] == rezultat[stevec]){
            //if (j == 9) printf("MJAUUU\n");
                i++;
            }
            stevec++;
        } else if (j < dolzina2 && i < dolzina1 && tabela1[i] > tabela2[j] ){
            rezultat[stevec] = tabela2[j];
            while(j < dolzina2 && tabela2[j] == rezultat[stevec]){
                j++;
            }
            stevec++;
        }
        if(i == dolzina1){
            rezultat[stevec] = tabela2[j];
            while(j < dolzina2 && tabela2[j] == rezultat[stevec]){
                j++;
            }
            stevec++;
        }
        if(j == dolzina2){
            rezultat[stevec] = tabela1[i];
            while(i < dolzina1 && tabela1[i] == rezultat[stevec]){
                i++;
            }
            stevec++;
        }
    }
    bool jeVecKotNic = false;
    for (int k = 0; k <= stevec; k++){
        if (rezultat[k] > 0) jeVecKotNic = true;
        if (jeVecKotNic && rezultat[k] == 0) break;
        printf("%d\n", rezultat[k]);
    }
}

int manjse(int a, int b){
    if (a < b){
        return a;
    } else {
        return b;
    }
}