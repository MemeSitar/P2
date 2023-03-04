#include <stdio.h>

int main() {
    int n;
    int out = '1';
    int prva;

    n = getchar() - '0';
    getchar();

    if (n > 0){
        prva = getchar();
        --n;
    }

    while (n > 0) {
        getchar();
        if (getchar() != prva){
            out = '0';
        }
        --n;
    }

    putchar(out);
    putchar('\n');

    return 0;
}