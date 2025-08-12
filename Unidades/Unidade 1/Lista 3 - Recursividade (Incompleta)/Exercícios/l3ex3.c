#include <stdio.h>

int ackermann(int m, int n);

int main() {
    int entrada1, entrada2;
    printf("Informe os valores de entrada: ");
    scanf("%d%d", &entrada1, &entrada2);
    printf("%d\n", ackermann(entrada1, entrada2));
    return 0;
}

int ackermann(int m, int n) {
    if(m == 0) return n+1;
    else if(m > 0 && n == 0) return ackermann(m-1, 1);
    else if(m > 0 && n > 0) return ackermann(m-1, ackermann(m, n-1));
}