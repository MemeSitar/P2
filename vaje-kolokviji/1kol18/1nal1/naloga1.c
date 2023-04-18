#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define OFFSET 100000

int main(){
    // t[0] = -100000
    // t[100000] = 0
    // t[200000] = 100000
    int* prvaPojavitev = calloc(200001, sizeof(int));

    int n;
    scanf("%d", &n);
    int* tabelaRezultatov = calloc(n, sizeof(int));
    
    int stevec = 0;
    int tmp;
    int maxRazdalja = 0;
    int tmpRazdalja = 0;
    for (int i = 0; i < n; i++){
        scanf("%d", &tmp);
        if (prvaPojavitev[tmp + OFFSET] == 0){
            prvaPojavitev[tmp + OFFSET] = i + 1;
        } else {
            tmpRazdalja = i - prvaPojavitev[tmp + OFFSET] + 1;
            if (tmpRazdalja > maxRazdalja){
                stevec = 0;
                maxRazdalja = tmpRazdalja;
                tabelaRezultatov[stevec++] = tmp;
            } else if (tmpRazdalja == maxRazdalja){
                tabelaRezultatov[stevec++] = tmp;
            }
        }
    }
    printf("%d\n", maxRazdalja);
    for (int i = 0; i < stevec; i++){
        printf("%d\n", tabelaRezultatov[i]);
    }
}