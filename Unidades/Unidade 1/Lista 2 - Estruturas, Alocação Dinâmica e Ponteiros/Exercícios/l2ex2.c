#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y;
} ponto;

double calc_dist(ponto A, ponto B) {
    double dist = pow((A.x - B.x), 2) + pow((A.y - B.y), 2);
    return sqrt(dist);
}

int main() {
    ponto A, B;
    printf("Informe as coordenadas do ponto A: ");
    scanf("%lf%lf", &A.x, &A.y);
    printf("Informe as coordenadas do ponto B: ");
    scanf("%lf%lf", &B.x, &B.y);
    printf("Distancia entre A e B: %.2lf\n", calc_dist(A, B));
    return 0;
}