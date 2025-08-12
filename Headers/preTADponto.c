#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
    float x;
    float y;
    bool visibilidade; // true = visível | false = invisível
} ponto;

ponto * ponto_cria(float x, float y, bool visibilidade) {
    ponto * p = (ponto*)malloc(sizeof(ponto));
    if(p != NULL)
    {
        p->x = x;
        p->y = y;
        p->visibilidade = visibilidade;
    }
    return p;
}

void ponto_libera(ponto * p) {
    if(p != NULL) free(p);
}

void ponto_acessa(ponto * p, float * x, float * y) {
    if(p != NULL)
    {
        *x = p->x;
        *y = p->y;
    }
}

void ponto_atribui(ponto * p, float x, float y) {
    if(p != NULL)
    {
        p->x = x;
        p->y = y;
    }
}

float ponto_distancia(ponto * p1, ponto * p2) {
    float dx, dy;
    dx = p1->x - p2->x;
    dy = p1->y - p2->y;
    return sqrt(dx*dx+dy*dy);
}

// void ponto_move(ponto * p, float x, float y, int movimento) {}

void ponto_oculta(ponto * p) {
    p->visibilidade = false;
}

void ponto_mostra(ponto * p) {
    p->visibilidade = true;
}

int main() {
    float xp, yp, xq, yq, d;
    ponto *p, *q;
    printf("Digite as coordenadas x e y para o ponto 1: ");
    scanf("%f%f", &xp, &yp);
    printf("Digite as coordenadas x e y para o ponto 2: ");
    scanf("%f%f", &xq, &yq);
    p = ponto_cria(xp, yp, true);
    q = ponto_cria(xq, yq, true);
    d = ponto_distancia(p, q);
    ponto_acessa(p, &xp, &yp);
    ponto_acessa(q, &xq, &yq);
    printf("Distância entre os pontos: (%.2f,%.2f) e (%.2f,%.2f) = %.5f\n", xp, yp, xq, yq, d);
    ponto_libera(p);
    ponto_libera(q);
    return 0;
}