#include <stdio.h>
#include "soma.h"

int main() {
    int n1, n2;
    float f1, f2;
    double d1, d2;
    char c1, c2;
    scanf("%d%d", &n1, &n2);
    printf("%d\n", somaint(n1, n2));
    scanf("%f%f", &f1, &f2);
    printf("%.2f\n", somafloat(f1, f2));
    scanf("%lf%lf", &d1, &d2);
    printf("%.2lf\n", somadouble(d1, d2));
    scanf("%c%c", &c1, &c2);
    printf("%c, %d\n", somachar(c1, c2), somachar(c1, c2));
    return 0;
}