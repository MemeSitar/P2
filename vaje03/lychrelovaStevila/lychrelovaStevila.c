#include <stdio.h>
#include <stdbool.h>

#define MEJA 1e17

bool lychrel(long, int);
bool je_palindrom(long);
long iteracija(long);
long obrni_stevilo(long);

int main(){
    int koraki = 0;
    int a = 0;
    int b = 0;
    int stevec = 0;

    scanf("%d %d %d", &koraki, &a, &b);

    for (int i = a; i <= b; i++){
        if (lychrel(i, koraki)){
            stevec++;
        }
    }

    printf("%d\n", stevec);

    return 0;
}

// funkcija lychrel vrne 1 ce je st lychrelovo stevilo.
bool lychrel(long st, int koraki){
    int k = 0;

    do {
        st = iteracija(st);
        k++;
    } while (!(je_palindrom(st)) && k < koraki && st <= MEJA);
    return !je_palindrom(st);

}

long iteracija(long stevilo){
    long rezultat = stevilo + obrni_stevilo(stevilo);
    return rezultat;
}

long obrni_stevilo(long stevilo){
    long obrnjeno = 0;
    while (stevilo > 0){
        obrnjeno = 10 * obrnjeno + (stevilo % 10);
        stevilo /= 10;
    }
    return obrnjeno;
}

bool je_palindrom(long stevilo){
    if (obrni_stevilo(stevilo) == stevilo){
        return true;
    } else {
        return false;
    }
}