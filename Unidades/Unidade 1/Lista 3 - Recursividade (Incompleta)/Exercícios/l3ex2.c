#include <stdio.h>

unsigned long long int fibonacci(unsigned long long int anterior, unsigned long long int atual, int qtd_total);

int main() {
    int qtd_total;
    printf("Informe quantos termos há na sequência de Fibonacci: ");
    scanf("%d", &qtd_total);
    printf("0 ");
    fibonacci(0, 1, qtd_total);
    printf("\n");
    return 0;
}

unsigned long long int fibonacci(unsigned long long int anterior, unsigned long long int atual, int qtd_total) {
    unsigned long long int temp;
    if(qtd_total == 0) return;
    printf("%llu ", atual);
    temp = atual;
    atual = anterior+atual;
    anterior = temp;
    return fibonacci(anterior, atual, qtd_total-1);
}