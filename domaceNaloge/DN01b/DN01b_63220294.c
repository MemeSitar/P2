#include <stdio.h>

int charValue(int c);
void putcharPrint(int sum);

int main(){
    int count = 0;
	int roundFlag = 0;
    int c = 0;

    while ((c = getchar()) == '0'){}
    while ((c = getchar()) != '\n'){
		if (c == '1')
			roundFlag = 1;
        count++;
	}
	if (roundFlag)
		count++;
	
    putcharPrint(count);
    putchar('\n');
    return 0;
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

int charValue(int c){
    return c + '0';
}