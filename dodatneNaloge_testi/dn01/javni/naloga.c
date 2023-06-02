#include <stdio.h>

int tenPow(int a);

int main(){
    int prvo = 0;
    int drugo = 0;
    int dolzina = 0;
    int dolzinaPrvo = 0;
    scanf("%d %d", &prvo, &drugo);
    int tmpDrugo = drugo;
    while(tmpDrugo % 10 != 0){
        dolzinaPrvo += tmpDrugo % 10;
        tmpDrugo = tmpDrugo / 10;
        dolzina++;
    }
    int novoPrvo = prvo;
    int tmpPrvo = 0;
    tmpDrugo = drugo;
    for (int i = 0; i < dolzina; i++){
        tmpDrugo = drugo/tenPow(dolzina - i);
        tmpPrvo = novoPrvo / tenPow(dolzinaPrvo - tmpDrugo);
        printf("%d\n", tmpPrvo);
        drugo = drugo - tmpDrugo*tenPow(dolzina - i);
        novoPrvo = novoPrvo - (tmpPrvo * tenPow(dolzinaPrvo - tmpDrugo));
    }
    return 0;
}

int tenPow(int a){
    int res = 1;
    for(int i = 0; i < a; i++){
        res = res * 10;
    }
    return res;
}