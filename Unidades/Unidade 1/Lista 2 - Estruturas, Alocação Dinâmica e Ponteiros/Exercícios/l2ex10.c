#include <stdio.h>

int main() {
    int x, y;
    printf("Informe dois valores inteiros: ");
    scanf("%d%d", &x, &y);
    if(&x > &y) printf("&x > &y\n");
    else printf("&y > &x\n");
    return 0;
}