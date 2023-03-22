#include <stdio.h>

int tabela[1000000];

int main() {
    int n;
    int tmp = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        scanf("%d", &tmp);
        if (tmp < 0){
            printf("NE\n");
            return 0;
        }
        tabela[tmp]++;
    }

    for (int i = 0; i < n; i++){
        if (tabela[i] != 1){
            printf("NE\n");
            return 0;
        }
    }
    printf("DA\n");
    return 1;
}