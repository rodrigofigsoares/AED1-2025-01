#include <stdio.h>
#include <stdlib.h>
#include "cubo.h"

struct Cubo {
    double aresta;
};

cubo * cria_cubo(double aresta) {
    cubo * cube = (cubo*)malloc(sizeof(cubo));
    if(cube == NULL)
    {
        printf("error\n");
        exit(0);
    }
    cube->aresta = aresta;
    return cube;
}

double lado_cubo(cubo * cube) {
    return cube->aresta;
}

double area_cubo(cubo * cube) {
    return cube->aresta*cube->aresta*6;
}

double volume_cubo(cubo * cube) {
    return cube->aresta*cube->aresta*cube->aresta;
}

void destroi_cubo(cubo * cube) {
    free(cube);
}