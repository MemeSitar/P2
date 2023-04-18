#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    while (i < dolzina1 || j < dolzina2){
        if (tabela1[i] == tabela2[j]){
            rezultat[stevec] = tabela1[i];

            while(tabela1[i] == rezultat[stevec] && i < dolzina1){
                i++;
            }
            while(tabela2[j] == rezultat[stevec] && j < dolzina2){
                j++;
            }
            stevec++;
        } else if (tabela1[i] < tabela2[j]){
            rezultat[stevec] = tabela1[i];
            while(tabela1[i] == rezultat[stevec] && i < dolzina1){
                i++;
            }
            stevec++;
        } else if (tabela1[i] > tabela2[j]){
            rezultat[stevec] = tabela2[j];
            while(tabela2[j] == rezultat[stevec] && j < dolzina2){
                j++;
            }
            stevec++;
        }
    }
    for (int k = 0; k <= stevec; k++){
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