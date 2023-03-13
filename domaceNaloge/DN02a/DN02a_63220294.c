#include <stdio.h>

int main() {
    int c = 0;
    int result = '1';

    // glavna funkcija
    while((c = getchar()) != '\n'){

        // ce konec stevilke, izpisi.
        if (c == ' '){
            putchar(result);
            result = '1';
        }

        // dejanska logika
        
    }

    // ce konec cele reci, izpisi zadnjega
    // (ne bo zadetka pri == ' ')
    putchar(result);

    return 0;
}