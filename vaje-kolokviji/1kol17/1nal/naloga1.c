#include <stdio.h>
#define P(msg) {printf("%s\n",msg);}

int funkcija(int n, unsigned int* t){
    int stevec = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < sizeof(unsigned int)*8; j++){
            if ((t[i] >> j) & 1) stevec++;
        }
    }
    return stevec;
}

int main(){
    unsigned int tabela[] = {0b10101010, 0b1111, 0b0001, 0b1001};
    int rezultat = funkcija(4, tabela);
    printf("%d\n", rezultat);

    // rezultat je 11
}
