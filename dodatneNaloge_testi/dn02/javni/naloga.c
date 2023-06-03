#include <stdio.h>
#include <stdbool.h>

void zakodiraj();
void dekodiraj();
void natisniDekodirano();
void natisniKodirano(int n, char c);

int main(){
    char c = getchar();
    getchar();
    if (c == '1'){
        zakodiraj();
    } else if (c == '2'){
        dekodiraj();
    }
    return 0 ;
}

void zakodiraj(){
    char last = getchar(); 
    char c;
    int count = 1;
    while ((c = getchar()) != '\n'){
        if (c != last){
            natisniKodirano(count, last);
            last = c;
            count = 1;
        } else {
            count++;
        }
    }
    natisniKodirano(count, last);
    printf("\n");
}

void dekodiraj(){
    char c;
    while ((c = getchar()) != '\n'){
        if (c == '#'){
            natisniDekodirano();
        } else {
            putchar(c);
        }
    }
    printf("\n");
}

void natisniKodirano(int n, char c){
    if (c == '#'){
        printf("##%d#", n);
    } else if (n < 5){
        for(int i = 0; i < n; i++){
            putchar(c);
        }
    } else {
        printf("#%c%d#", c, n);
    }
}

void natisniDekodirano(){
    char c = getchar();
    char buffer;
    int num = 0;
    while((buffer = getchar()) != '#'){
        num = 10*num + buffer - '0';
    }
    for (int i = 0; i < num; i++){
        putchar(c);
    }
}