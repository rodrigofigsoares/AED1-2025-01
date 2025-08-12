#include <stdio.h>
#include <stdlib.h>
#include "cubo.h"

int main() {
    cubo * cube;
    double aresta;
    printf("Informe o tamanho da aresta do cubo: ");
    scanf("%lf", &aresta);
    cube = cria_cubo(aresta);
    printf("O cubo tem lado = %.2lf\n", lado_cubo(cube));
    printf("O cubo tem área = %.2lf\n", area_cubo(cube));
    printf("O cubo tem volume = %.2lf\n", volume_cubo(cube));
    destroi_cubo(cube);
    return 0;
}