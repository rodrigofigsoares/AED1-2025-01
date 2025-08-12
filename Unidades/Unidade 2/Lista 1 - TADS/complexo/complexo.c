#include <stdio.h>
#include <stdlib.h>
#include "complexo.h"

struct Complexo {
    double real;
    double imaginaria;
};

complexo * cria_complexo(double real, double imaginaria) {
    complexo * complex = (complexo*)malloc(sizeof(complexo));
    if(complex == NULL)
    {
        printf("error\n");
        exit(0);
    }
    complex->real = real;
    complex->imaginaria = imaginaria;
    return complex;
}

void soma_complexo(complexo * complex1, complexo * complex2, complexo * complexSum) {
    complexSum->real = complex1->real + complex2->real;
    complexSum->imaginaria = complex1->imaginaria + complex2->imaginaria;
}

void subtrai_complexo(complexo * complex1, complexo * complex2, complexo * complexSub) {
    complexSub->real = complex1->real - complex2->real;
    complexSub->imaginaria = complex1->imaginaria - complex2->imaginaria;
}

void multiplica_complexo(complexo * complex1, complexo * complex2, complexo * complexProd) {
    complexProd->real = complex1->real*complex2->real - complex1->imaginaria*complex2->imaginaria;
    complexProd->imaginaria = complex1->real*complex2->imaginaria + complex1->imaginaria*complex2->real;
}

double le_parte_real(complexo * complex) {
    return complex->real;
}

double le_parte_imaginaria(complexo * complex) {
    return complex->imaginaria;
}

void destroi_complexo(complexo * complex) {
    free(complex);
}