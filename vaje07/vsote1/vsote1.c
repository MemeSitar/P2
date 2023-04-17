#include <stdio.h>

int jeManjse(int a, int b);
int stMoznosti(int n, int k);

int main(){
    int n, k;

    scanf("%d %d", &n, &k);
    printf("%d\n", stMoznosti(n, k));
    return 0;
}

int stMoznosti(int n, int k){
    int stevec = 0;
    if (n <= 1){
        return 1;
    }
    if (k <= 1){
        return 1;
    }
    do {
        stevec += stMoznosti(n - k, jeManjse(n-k, k));
        k--;
    } while (k >= 1);
    return stevec;
}

int jeManjse(int a, int b){
    if (a < b){
        return a;
    } else {
        return b;
    }
}