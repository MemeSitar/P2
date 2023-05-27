
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "naloga.h"

int poisciStudenta(Student** studentje, int stStudentov, int vpisna) {
    for(int i = 0; i < stStudentov; i++){
        if(studentje[i]->vpisna == vpisna){
            return i;
        }
    }
    return -1;
}

int poisciPO(Student* student, char* predmet) {
    for(int i = 0; i < student->stPO; i++){
        if (strcmp(student->po[i].predmet, predmet)==0 ){
            return i;
        }
    }
    return -1;
}

int dodaj(Student** studentje, int stStudentov, int vpisna, char* predmet, int ocena) {
    int indeks = poisciStudenta(studentje, stStudentov, vpisna);
    if (indeks == -1){
        studentje[stStudentov] = (Student[]) {vpisna, (PO[]){{predmet, ocena}}, 1};
        stStudentov++;
    } else {
        int indeksPo = poisciPO(studentje[indeks], predmet);
        if(indeksPo == -1){
            studentje[indeks]->po[studentje[indeks]->stPO] = (PO){predmet, ocena};
            studentje[indeks]->stPO++;
        } else {
            studentje[indeks]->po[indeksPo].ocena = ocena;
        }
    }
    return stStudentov;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}

#endif
