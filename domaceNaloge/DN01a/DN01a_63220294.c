#include <stdio.h>

int intValue(int c);
int charValue(int c);
void putcharPrint(int sum);

int main(){
    int c = 0;
    int neg = 1;
    int num = 0;
    int sum = 0;

    while ((c = getchar()) != ' '){
        if (c == '-'){
            neg = -1;
        } else {
            num = num*10;
            num += intValue(c);
        }
    }
    sum += num * neg;
    neg = 1;
    num = 0;

    while ((c = getchar()) != '\n'){
        if (c == '-'){
            neg = -1;
        } else {
            num = num*10;
            num += intValue(c);
        }
    }
    sum += num * neg;
    neg = 1;

    putcharPrint(sum);
    putchar('\n');

    return 0;
}

int intValue(int c){
    return c - '0';
}

int charValue(int c){
    return c + '0';
}

void putcharPrint(int sum){
    if (sum < 0){
        putchar('-');
        sum = -sum;
    }
    if (sum/10 != 0){
        putcharPrint(sum/10);
    }

    putchar(charValue(sum%10));
}