#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    int n = 0;
    char vrstica[1024];
    char najVrstica[1024];
    int naj = 0;
    FILE * filePtr = fopen(argv[1], "r");
    while(fgets(vrstica, 1023, filePtr) != NULL){
        n = 0;
        n = strlen(vrstica);
        if (n > naj){
            naj = n; 
            strcpy(najVrstica, vrstica);
        }
    }
    printf("%s", najVrstica);
    fclose(filePtr);
    return 0;
}