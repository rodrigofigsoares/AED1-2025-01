#include <stdio.h>
#include "esfera.h"

int main() {
    esfera * sphere;
    double raio;
    printf("Informe o raio da esfera: ");
    scanf("%lf", &raio);
    sphere = cria_esfera(raio);
    printf("A esfera tem raio = %.2lf\n", raio_esfera(sphere));
    printf("A esfera tem área = %.2lf\n", area_esfera(sphere));
    printf("A esfera tem volume = %.2lf\n", volume_esfera(sphere));
    destroi_esfera(sphere);
    return 0;
}