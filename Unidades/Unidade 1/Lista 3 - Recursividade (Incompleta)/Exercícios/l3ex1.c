#include <stdio.h>

unsigned long long int contagem(unsigned long long int num, unsigned long long int contador);

int main() {
    unsigned long long int num_final;
    printf("Informe o número final da contagem: ");
    scanf("%llu", &num_final);
    contagem(num_final, 1);
    printf("\n");
    return 0;
}

unsigned long long int contagem(unsigned long long int num, unsigned long long int contador) {
    if(contador > num) return;
    else
    {
        printf("%llu ", contador);
        return contagem(num, contador+1);
    }
}