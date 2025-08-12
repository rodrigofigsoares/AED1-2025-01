#include <stdio.h>
#include <math.h>

double dist_origem(ponto P);

typedef struct {
    double x, y;
} ponto;

double dist_origem(ponto P) {
    double dist = pow(P.x, 2) + pow(P.y, 2);
    return sqrt(dist);
}

int main() {
    ponto P;
    printf("Informe as coordenadas do ponto: ");
    scanf("%lf%lf", &P.x, &P.y);
    printf("Distancia entre o ponto e a origem: %.2lf\n", dist_origem(P));
    return 0;
}