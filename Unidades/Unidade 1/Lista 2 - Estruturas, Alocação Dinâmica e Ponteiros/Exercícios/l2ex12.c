#include <stdio.h>

int main() {
    int var;
    int * ptr1 = &var;
    int ** ptr2 = &ptr1;
    int *** ptr3 = &ptr2;
    printf("Informe um valor inteiro: ");
    scanf("%d", &var);
    printf("Valor base: %d\n", var);
    printf("Dobro: %d\n", *(ptr1)*2);
    printf("Triplo: %d\n", **(ptr2)*3);
    printf("Quádruplo: %d\n", ***(ptr3)*4);
    return 0;
}