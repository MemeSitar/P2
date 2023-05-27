#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int sestevek = 0;
    scanf("%d", &n);
    int* mnozica = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d", &mnozica[i]);
        sestevek += mnozica[i];
    }
    return 0;
}