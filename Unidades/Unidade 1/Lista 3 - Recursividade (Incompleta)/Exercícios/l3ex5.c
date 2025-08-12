#include <stdio.h>

unsigned long long int converte_decimal_binario(int decimal, unsigned long long int potencia, unsigned long long int binario);

int main() {
    int qtd_casos, decimal;
    printf("Informe quantos números serão convertidos: ");
    scanf("%d", &qtd_casos);
    printf("Informe os números que serão convertidos:\n");
    for(int i=0;i<qtd_casos;i++)
    {
        scanf("%d", &decimal);
        printf("%d em binário é %llu\n", decimal, converte_decimal_binario(decimal, 1, 0));
    }
    return 0;
}

unsigned long long int converte_decimal_binario(int decimal, unsigned long long int potencia, unsigned long long int binario) {
    int resto;
    if(decimal < 2)
    {
        binario += decimal*potencia;
        return binario;
    }
    resto = decimal%2;
    decimal /= 2;
    binario += resto*potencia;
    potencia *= 10;
    return converte_decimal_binario(decimal, potencia, binario);
}