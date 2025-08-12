#include <stdio.h>
#include <math.h>

#define N 25

int main() {
    int a, b;
    int i;
    for(i = 0;i<=N;i++)
    {
        a = pow(i, 5);
        b = pow(2, i);
        printf("n = %d\n", i);
        printf("n^5 = %d\n", a);
        printf("2^n = %d\n", b);
        printf("\n");
    }

    return 0;
}