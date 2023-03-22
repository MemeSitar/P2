#include <stdio.h>
#include <stdbool.h>

int tabela[1000000];

int main() {
    int n;
    int vsota = 0;
    bool soPozitivna = false;
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        scanf("%d", &tabela[i]);
        if (!soPozitivna){
            if (tabela[i] > 0){
                soPozitivna = true;
            }
        }
    }
    
    int najVsota = tabela[0];
    for (int i = 0; i < n; i++){
        vsota = 0;
        if (soPozitivna && tabela[i] < 0){
            continue;
        } /*else if ((tabela[i] + tabela[i + 1]) < tabela[i]){
            continue;
        } */else  { 
            for (int j = i; j < n; j++){
                vsota += tabela[j];
                if (vsota > najVsota){
                    najVsota = vsota;
                }
            }
        }
    }
    printf("%d\n", najVsota);
    return 0;
}