#include <stdio.h>
#include <stdlib.h>
#include "esfera.h"

struct Esfera {
    double raio;
    double pi;
};

esfera * cria_esfera(double raio) {
    esfera * sphere = (esfera*)malloc(sizeof(esfera));
    if(sphere == NULL)
    {
        printf("error\n");
        exit(0);
    }
    sphere->raio = raio;
    sphere->pi = 3.14;
    return sphere;
}

double raio_esfera(esfera * sphere) {
    return sphere->raio;
}

double area_esfera(esfera * sphere) {
    return 4*sphere->pi*sphere->raio*sphere->raio;
}

double volume_esfera(esfera * sphere) {
    double volume;
    volume = 4*sphere->pi;
    volume *= sphere->raio*sphere->raio*sphere->raio;
    volume /= 3;
    return volume;
}

void destroi_esfera(esfera * sphere) {
    free(sphere);
}