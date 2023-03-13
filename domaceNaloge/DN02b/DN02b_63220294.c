#include <stdio.h>

int main() {

    /*
    stanja:
    0 = A = zacetek
    1 = B = desetiska
    2 = C = zacne se z 0
    3 = D = binarno
    4 = E = osmiska
    5 = F = hex
    6 = G = uspesno -> izpisi 1 -> A
    7 = H = neuspesno -> izpisi 0 -> pozri vse invalid -> A
    */

    int state = 0;
    while ((c = getchar() != '\n')){
        switch (state){

            case 0: // zacetek
                if (c == '0'){ // binarna, osmiska ali hex
                    state = 2;
                } else if (c >= '1' && c <= '9'){ // desetiska
                    state = 1;
                }
                break;

            case 1: // desetiska
                if (c == ' '){ // konec stevilke
                    state = 6;
                } else if (c < '0' || c > '9'){ // neuspesno
                    state = 7;
                }
                // sicer naprej bere.
                break;

            case 2: // zacne se z 0
                if (c == 'x'){ //hex
                    state = 5;
                } else if (c == 'b'){ //bin
                    state = 3;
                } else if (c >= '0' && c <= '7'){ // osmiska
                    state = 4;
                } else { // neuspesno.
                    state = 7;
                }
                break;

            case 3: // binarno
                if (c == ' '){ // uspesno konec
                    state = 6; 
                }else if (c < '0' || c > '1'){ // napaka!
                    state = 7;
                }
                // sicer naprej.
                break;

            case 4: // osmisko
                if (c == ' '){ // uspesno konec
                    state = 6; 
                }else if (c < '0' || c > '7'){ // napaka!
                    state = 7;
                }
                // sicer naprej.
                break;

            case 5: // hex

                break;

            case 6: // uspesno
                putchar('1');
                state = 0;
                break;

            case 7: // neuspesno
                if (c == ' '){
                    putchar('0');
                    state = 0; // nazaj v A
                }
                break;
        }
    }
    return 0;
}