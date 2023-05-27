#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define __

void iteracija(int meja, int trenutna, char c1, char c2, char* crke);

int main(){
    int trenutna = 0;
    int zgMeja = 0;
    char c1, c2;
    scanf("%d %c %c", &zgMeja, &c1, &c2);
    char* crke = calloc(zgMeja + 1, sizeof(char));
    crke[zgMeja] = '\0';
    #ifdef __DEBUG__
        putchar(c1);
        putchar(c2);
        putchar('\n');
    #endif

    iteracija(zgMeja, trenutna, c1, c2, crke);
    return 0;
}

void iteracija(int meja, int trenutna, char c1, char c2, char* crke){
    if (c1 == c2 || meja == 0){
        return;
    }
    char tmpc1 = c1;
    while(tmpc1 <= c2){
        crke[trenutna] = tmpc1;
        printf("%s\n", crke);
        iteracija(meja - 1, trenutna + 1, c1, c2, crke);
        tmpc1++;
    }
}