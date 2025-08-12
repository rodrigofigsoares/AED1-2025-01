#include <stdio.h>
#include <stdlib.h>
#include "cilindro.h"

struct Cilindro {
    double pi;
    double raio;
    double altura;
};

cilindro * cria_cilindro(double raio, double altura) {
    cilindro * cilinder = (cilindro*)malloc(sizeof(cilindro));
    if(cilinder == NULL)
    {
        printf("error\n");
        exit(0);
    }
    cilinder->pi = 3.14;
    cilinder->raio = raio;
    cilinder->altura = altura;
    return cilinder;
}

double altura_cilindro(cilindro * cilinder) {
    return cilinder->altura;
}

double raio_cilindro(cilindro * cilinder) {
    return cilinder->raio;
}

double area_cilindro(cilindro * cilinder) {
    double area;
    area = 2*cilinder->pi*cilinder->raio*cilinder->altura;
    area += cilinder->pi*cilinder->raio*cilinder->raio;
    return area;
}

double volume_cilindro(cilindro * cilinder) {
    return cilinder->pi*cilinder->raio*cilinder->raio*cilinder->altura;
}

void destroi_cilindro(cilindro * cilinder) {
    free(cilinder);
}