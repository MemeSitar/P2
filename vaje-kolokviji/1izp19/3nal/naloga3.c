#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define P(msg) {printf("%s\n", msg);}

long stMoznosti(int gor, int dol, int visina, long** t);

int main(){
    int n;
    scanf("%d", &n);

    long* tabela[n / 2 + 1];
    for (int i = 0; i < n/2 + 1; i++){
        tabela[i] = calloc(n / 2 + 1, sizeof(long));
    }

    long rezultat = stMoznosti(n/2, n/2, 0, tabela);
    printf("%ld\n", rezultat);
    
    for (int i = 0; i < n/2 + 1; i++){
        free(tabela[i]);
    }
    return 0;
}

long stMoznosti(int gor, int dol, int visina, long** t){

    if (gor == 0){
        t[gor][dol] = 1;
        return 1;
    }
    if (t[gor][dol] != 0){
        return t[gor][dol];
    }
    // dol == 0 ne more biti, brez gor == 0, ker bi to pomenilo da smo šli pod visina.

    long rezultat = 0;
    
    rezultat += stMoznosti(gor - 1, dol, visina + 1, t);
    if (visina > 0){
        rezultat += stMoznosti(gor, dol - 1, visina - 1, t);
    }
    t[gor][dol] = rezultat;
    return rezultat;
}
