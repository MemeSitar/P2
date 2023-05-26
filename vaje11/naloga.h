
#ifndef _NALOGA_H
#define _NALOGA_H

typedef struct Vozlisce Vozlisce;

struct Vozlisce {
    int podatek;
    Vozlisce* naslednje;
};

int vsotaI(Vozlisce* zacetek);
int vsotaR(Vozlisce* zacetek);
Vozlisce* vstaviUrejenoI(Vozlisce* zacetek, int element);
Vozlisce* vstaviUrejenoR(Vozlisce* zacetek, int element);

#endif
