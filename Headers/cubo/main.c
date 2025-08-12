#include <stdio.h>
#include <stdio.h>
#include "cubo.h"

int main() {
    cubo * cube;
    float aresta;
    int contador = 0;
    printf("Informe a dimensão do cubo: ");
    scanf("%f", &aresta);
    cube = cria_cubo(aresta);
    for(int i=0;i<2;i++)
    {
        printf("A aresta do cubo tem medida: %.2f\n", tamanho_aresta(cube));
        printf("O cubo tem perímetro igual a: %.2f\n", perimetro_cubo(cube));
        printf("Uma face desse cubo, tem medida: %.2f\n", area_uma_face(cube));
        printf("A área total das faces do cubo é: %.2f\n", area_total(cube));
        printf("O volume do cubo é: %.2f\n", volume_cubo(cube));
        printf("A diagonal do cubo tem medida: %.2f\n", diagonal(cube));
        if(contador == 0)
        {
            printf("\nInforme a nova dimensão do cubo: ");
            scanf("%f", &aresta);
            atribui_aresta(cube, aresta);
            contador++;
        }
    }
    destroi_cubo(cube);
    return 0;
}