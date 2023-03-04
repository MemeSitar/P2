#include <stdio.h>

int main() {
    int n;
    int out;
    int a, drugo;

    n = getchar() - '0' - 2;
    getchar();
    a = getchar();
    getchar();
    drugo = getchar();
    if (drugo >= a) {
        drugo = a;
    }

    while (n > 0) {
        getchar();
        if ((a = getchar()) >= drugo){
            drugo = a;
        }
        --n;
    }

    putchar(drugo);
    putchar('\n');
}