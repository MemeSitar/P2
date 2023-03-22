#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int tabela[1000000];

int main() {
    int n;
    int vsota = 0;
    //bool soPozitivna = false;
    scanf("%d", &n);

    /*for (int i = 0; i < n; i++){
        scanf("%d", &tabela[i]);
        if (!soPozitivna){
            if (tabela[i] > 0){
                soPozitivna = true;
            }
        }
    }*/

    int najVsota = INT_MIN;
    int clen = 0;
    for (int i = 0; i < n; i++){
        scanf("%d", &clen);
        vsota += clen;
        /*if (soPozitivna && tabela[i] < 0){
            continue;
        } else if ((tabela[i] + tabela[i + 1]) < tabela[i]){
            continue;
        } /else  {*/

        if (vsota > najVsota){
            najVsota = vsota;
        }

        if (vsota < 0){
            vsota = 0;
        }
    }
    printf("%d\n", najVsota);
    return 0;
}