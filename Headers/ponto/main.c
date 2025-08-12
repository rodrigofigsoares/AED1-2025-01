#include <stdio.h>
#include "ponto.h"

int main() {
    float dist;
    Ponto *p1, *p2;
    float a = 0, b = 0;
    p1 = ponto_cria(10, 21);
    p2 = ponto_cria(7,25);
    // Crie os dois pontos
    p1 = ponto_cria(10, 21);
    // p2(7,25)
    p2 = ponto_cria(7,25);
    // Acesse os valores dos pontos criados
    printf("Valores dos pontos antes \"a\" e \"b\": %.2f -- %.2f\n", a, b);
    ponto_acessa(p1, &a, &b);
    printf("Valores dos pontos depois \"a\" e \"b\": %.2f -- %.2f\n", a, b);
    // Calcule a distância de p1 para p2
    dist = ponto_distancia(p1, p2);
    // Imprima a distância calculada
    printf("Distância entre (%.2f,%.2f) ", a, b);
    ponto_acessa(p2, &a, &b);
    printf("e (%.2f, %.2f): %.2f\n", a, b, dist);
    // Mude os valores de p2
    ponto_atribui(p2, 25, 7);
    ponto_acessa(p2, &a, &b);
    printf("Novas coordenadas de p2: (%.2f,%.2f)\n", a, b);
    // Libere os dois ponteiros p1 e p2
    ponto_libera(p1);
    ponto_libera(p2);
    return 0;
}