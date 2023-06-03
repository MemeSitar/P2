#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
    if (argc != 3){
        printf("Premalo argumentov!\n");
        exit(1);
    }
    char* izhodnaIme = calloc(64, sizeof(char));
    int overflow = 0;
    int maxSize = atoi(argv[2]);
    FILE* vhodna = fopen(argv[1], "rb");
    FILE* izhodna;

    unsigned char* bytes = calloc(maxSize, sizeof(unsigned char));

    fseek(vhodna, 0L, SEEK_END);
    int filesize = ftell(vhodna);
    rewind(vhodna);

    int fileNo = filesize / maxSize;
    overflow = filesize % maxSize;

    for (int i = 0; i < fileNo; i++){
        sprintf(izhodnaIme, "%s.%d", argv[1], i);
        printf("%s\n", izhodnaIme);
        izhodna = fopen(izhodnaIme, "wb");
        fread(bytes, maxSize, 1, vhodna);
        fwrite(bytes, maxSize, 1, izhodna);
        fclose(izhodna);
    }

    if (overflow){
        sprintf(izhodnaIme, "%s.%d", argv[1], fileNo);
        izhodna = fopen(izhodnaIme, "wb");
        fread(bytes, overflow, 1, vhodna);
        fwrite(bytes, overflow, 1, izhodna);
        fclose(izhodna);
    }

    fclose(vhodna);
}