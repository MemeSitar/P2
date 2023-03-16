#include <stdio.h>

long vsota_pravih_deliteljev(long);
long prijateljsko_stevilo(long);

int main() {
    long n = 0;
    scanf("%li", &n);

    // rezultat bo 0 v primeru da prijateljskega stevila ni, sicer stevilo.
    long rezultat = prijateljsko_stevilo(n);

    if (rezultat == 0){
        printf("NIMA");
    } else {
        printf("%li", rezultat);
    }
    printf("\n");
    return 0;
}

long vsota_pravih_deliteljev(long st) {
    long vsota = 0;

    for (long i = 1; i < st; i++){
        if ((st % i) == 0) {
            vsota += i;
        }
    }
    //printf("%li", vsota);
    return vsota;
}

long prijateljsko_stevilo(long st) {
    long drugoStevilo = vsota_pravih_deliteljev(st);
    long vsotaDrugoStevilo = vsota_pravih_deliteljev(drugoStevilo);

    if (vsotaDrugoStevilo == st && st != drugoStevilo){
        return drugoStevilo;
    } else {
        return 0;
    }
}