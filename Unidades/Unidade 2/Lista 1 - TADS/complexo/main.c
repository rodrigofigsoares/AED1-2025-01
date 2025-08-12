#include <stdio.h>
#include "complexo.h"

int main() {
    complexo *complex1, *complex2, *complexSum, *complexSub, *complexProd;
    double real, imaginaria;
    printf("Informe os valores da parte real e da parte imaginária do primeiro complexo: ");
    scanf("%lf%lf", &real, &imaginaria);
    complex1 = cria_complexo(real, imaginaria);
    printf("Informe os valores da parte real e da parte imaginária do segundo complexo: ");
    scanf("%lf%lf", &real, &imaginaria);
    complex2 = cria_complexo(real, imaginaria);
    complexSum = cria_complexo(0, 0);
    complexSub = cria_complexo(0, 0);
    complexProd = cria_complexo(0, 0);
    real = le_parte_real(complex1);
    imaginaria = le_parte_imaginaria(complex1);
    printf("Complexo 1: %.2lf + %.2lfi\n", real, imaginaria);
    real = le_parte_real(complex2);
    imaginaria = le_parte_imaginaria(complex2);
    printf("Complexo 2: %.2lf + %.2lfi\n", real, imaginaria);
    soma_complexo(complex1, complex2, complexSum);
    real = le_parte_real(complexSum);
    imaginaria = le_parte_imaginaria(complexSum);
    printf("Soma dos complexos: %.2lf", real);
    if(imaginaria >= 0) printf(" + %.2lfi\n", imaginaria);
    else printf(" - %.2lfi\n", -imaginaria);
    subtrai_complexo(complex1, complex2, complexSub);
    real = le_parte_real(complexSub);
    imaginaria = le_parte_imaginaria(complexSub);
    printf("Subtração dos complexos: %.2lf", real);
    if(imaginaria >= 0) printf(" + %.2lfi\n", imaginaria);
    else printf(" - %.2lfi\n", -imaginaria);
    multiplica_complexo(complex1, complex2, complexProd);
    real = le_parte_real(complexProd);
    imaginaria = le_parte_imaginaria(complexProd);
    printf("Produto dos complexos: %.2lf", real);
    if(imaginaria >= 0) printf(" + %.2lfi\n", imaginaria);
    else printf(" - %.2lfi\n", -imaginaria);
    destroi_complexo(complex1);
    destroi_complexo(complex2);
    destroi_complexo(complexSum);
    destroi_complexo(complexSub);
    destroi_complexo(complexProd);
    return 0;
}