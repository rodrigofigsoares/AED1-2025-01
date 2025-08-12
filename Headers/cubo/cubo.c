#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cubo.h"

struct Cubo {
    float aresta;
};

cubo * cria_cubo(float dim) {
    cubo * cube = (cubo*)malloc(dim*sizeof(cube));
    if(cube == NULL)
    {
        printf("error\n");
        exit(1);
    }
    cube->aresta = dim;
    return cube;
}

void destroi_cubo(cubo * cube) {
    free(cube);
}

float tamanho_aresta(cubo * cube) {
    return cube->aresta;
}

float perimetro_cubo(cubo * cube) {
    return cube->aresta*12;
}

float area_uma_face(cubo * cube) {
    return cube->aresta*cube->aresta;
}

float area_total(cubo * cube) {
    return cube->aresta*cube->aresta*6;
}

float volume_cubo(cubo * cube) {
    return pow(cube->aresta, 3);
}

float diagonal(cubo * cube) {
    return cube->aresta*sqrt(3);
}

void atribui_aresta(cubo * cube, float nova_aresta) {
    cube->aresta = nova_aresta;
}