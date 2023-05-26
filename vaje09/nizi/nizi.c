#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define __

void iteracija(int meja, char c1, char c2);

int main(){
    int zgMeja = 0;
    char c1, c2;
    scanf("%d %c %c", &zgMeja, &c1, &c2);

    #ifdef __DEBUG__
        putchar(c1);
        putchar(c2);
        putchar('\n');
    #endif

    iteracija(zgMeja, c1, c2);
    return 0;
}

void iteracija(int meja, char c1, char c2){
    if (c1 == c2){
        return;
    }
    if (meja == 0){
        return;
    }
    char tmpc1 = c1;
    char tmpc2 = c2;
    while(c1 <= c2){
        putchar(c1);
        
    }
}