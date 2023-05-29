
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
        PO *tabelaOcen = malloc(sizeof(PO) * 10);
        tabelaOcen[0].ocena = ocena;
        Student * novStudent = malloc(sizeof(Student));
        novStudent->po = tabelaOcen;
        novStudent->stPO = 1;
        novStudent->vpisna = vpisna;
        memcpy(tabelaOcen[0].predmet , predmet, 4);
        studentje[stStudentov] = novStudent;
        stStudentov++;
    } else {
        Student * student = studentje[indeks];
        int indeksPo = poisciPO(student, predmet);
        if(indeksPo == -1){
            student->po[student->stPO].ocena = ocena;
            memcpy(student->po[student->stPO].predmet, predmet, 4);
            student->stPO++;
        } else {
            student->po[indeksPo].ocena = ocena;
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
