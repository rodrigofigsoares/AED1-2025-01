#include <stdio.h>
#include <math.h>

int reverso(int num, int potencia, int invertido, int reducoes);

int determine_potencia(int num, int potencia);

int main() {
    int num, potencia, invertido = 0, reducoes = 0;
    printf("Informe um número natural maior que 0: ");
    scanf("%d", &num);
    potencia = determine_potencia(num, 1);
    printf("O reverso de %d é %d\n", num, reverso(num, potencia, invertido, reducoes));
    return 0;
}

int reverso(int num, int potencia, int invertido, int reducoes) {
    if(potencia == 1 && reducoes == 0) return num;
    if(potencia == 1) return (invertido + num*pow(10, reducoes));
    invertido += (num/potencia)*pow(10, reducoes);
    num = num%potencia;
    potencia /= 10;
    reducoes += 1;
    invertido += reverso(num, potencia, invertido, reducoes);
}

int determine_potencia(int num, int potencia) {
    if(potencia > num) return potencia/10;
    potencia *= 10;
    return determine_potencia(num, potencia);
}

