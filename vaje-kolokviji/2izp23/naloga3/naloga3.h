
#ifndef _NALOGA3_H
#define _NALOGA3_H

typedef struct _Vozlisce Vozlisce;

struct _Vozlisce {
    int vsebina;
    Vozlisce* desno;
    Vozlisce* dol;
};

Vozlisce* diagonala(Vozlisce* start, int* vsota);

#endif
