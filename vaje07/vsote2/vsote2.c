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
    printf("%d", k);
    if (n - k == 0){
        printf("\n");
        return 1;
    } else if (k == 1) {
        while (n > 1){
            printf(" + 1");
            n--;
        }
        printf("\n");
    } else {
        printf(" + ");
        stMoznosti(n - k, jeManjse(n - k, k));
    }
    return 0;
}

int jeManjse(int a, int b){
    if (a < b){
        return a;
    } else {
        return b;
    }
}