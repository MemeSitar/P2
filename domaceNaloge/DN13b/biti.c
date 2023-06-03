#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if (argc != 4){
        printf("delas neumnost\n");
    }

    FILE* vhodna = fopen(argv[1], "rb");
    int zacetek = atoi(argv[2]);
    int konec = atoi(argv[3]);
    int* buff;

    int zacetniBajt = zacetek / 8;
    int zacetniOffset = zacetek % 8;
    int koncniBajt = konec / 8;
    int koncniOffset = konec % 8;

    fseek(vhodna, zacetniBajt, SEEK_CUR);
    fread(buff, 1, 1, vhodna);

}