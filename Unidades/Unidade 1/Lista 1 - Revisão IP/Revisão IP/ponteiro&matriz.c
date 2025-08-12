// Varra uma matriz e imprima seus valores utilizando um ponteiro

#include <stdio.h>

int main() {
    int M[2][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i, j;
    for(i=0;i<10;i++)
    {
        printf("%d\n", *(*M+i));
    }
    return 0;
}