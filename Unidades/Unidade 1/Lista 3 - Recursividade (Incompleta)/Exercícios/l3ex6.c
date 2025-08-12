#include <stdio.h>

unsigned long long int fatorial_duplo(unsigned long long int num);

int main() {
    int num;
    printf("Informe o valor de n: ");
    scanf("%d", &num);
    printf("%d!! = %llu\n", num, fatorial_duplo(num));
    return 0;
}

unsigned long long int fatorial_duplo(unsigned long long int num) {
    if(num == 0) return 1;
    if(num%2 == 0) return fatorial_duplo(num-1);
    else return num*fatorial_duplo(num-1);
}