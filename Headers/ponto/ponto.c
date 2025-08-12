#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct ponto {
    float x, y;
};

Ponto * ponto_cria(float x, float y) {
    Ponto *p = (Ponto*)malloc(sizeof(Ponto));
    // if(p != NULL)
    // {
    //     p->x = x;
    //     p->y = y;
    // }
    if(p == NULL)
    {
        printf("error\n");
        exit(1); // Melhor (Encerra o código a partir da função)
    }
    p->x = x;
    p->y = y;
    return p;
}

void ponto_libera(Ponto *p) {
    free(p);
}

int ponto_acessa(Ponto *p, float *x, float *y) {
    if (p == NULL) return 0;
    *x = p->x;
    *y = p->y;
    return 1;
}

int ponto_atribui(Ponto *p, float x, float y) {
    if(p == NULL) return 0;
    p->x = x;
    p->y = y;
    return 1;
}

float ponto_distancia(Ponto *p1, Ponto *p2) {
    if(p1 == NULL || p2 == NULL)
    {
        printf("error");
        exit(1);
    }
    float dx, dy;
    dx = p1->x - p2->x;
    dy = p1->y - p2->y;
    return sqrt(dx*dx + dy*dy);
}