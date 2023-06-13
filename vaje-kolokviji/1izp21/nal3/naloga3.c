#include <stdlib.h>
#include <stdio.h>

void iteriraj(char* izpis, int globina, int max);

int main(){
    int stevilo = 0;
    scanf("%d", &stevilo);

    char izpis[2*stevilo];
    izpis[2*stevilo-1] = '\0';

    iteriraj(izpis, 0, stevilo - 1);
}

void iteriraj(char* izpis, int globina, int max){
    if (globina == max){
        for(int i = 0; i <= 9; i++){
            izpis[2*globina] = i + 48;
            printf("%s\n", izpis);
        }
        return;
    }

    for (int i = 0; i <= 9; i++){
        izpis[2*globina] = i + 48;
        izpis[2*globina + 1] = '+';
        iteriraj(izpis, globina + 1, max);
        izpis[2*globina + 1] = '-';
        iteriraj(izpis, globina + 1, max);
    }
}