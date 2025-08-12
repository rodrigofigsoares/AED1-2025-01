#include <stdio.h>
#include "cilindro.h"

int main() {
    cilindro * cilinder;
    double raio, altura;
    printf("Informe o raio do cilindro: ");
    scanf("%lf", &raio);
    printf("Informe a altura do cilindro: ");
    scanf("%lf", &altura);
    cilinder = cria_cilindro(raio, altura);
    printf("O cilindro tem altura = %.2lf\n", altura_cilindro(cilinder));
    printf("O cilindro tem raio = %.2lf\n", raio_cilindro(cilinder));
    printf("O cilindro tem área = %.2lf\n", area_cilindro(cilinder));
    printf("O cilindro tem volume = %.2lf\n", volume_cilindro(cilinder));
    destroi_cilindro(cilinder);
    return 0;
}