#include <stdio.h>

int main() {
    int a, b, c;
    a = getchar() - '0'; // pretvori v dejansko stevilo
    getchar();
    b = getchar() - '0'; 
    c = (a + b) % 10;
    putchar(c + '0');
    putchar('\n');
    
    return 0;
}