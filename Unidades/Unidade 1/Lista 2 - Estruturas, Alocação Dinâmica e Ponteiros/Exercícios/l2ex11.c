#include <stdio.h>

int main() {
    int v[5];
    int * ptr;
    printf("Informe 5 valores inteiros:\n");
    for(int i=0;i<5;i++) scanf("%d", &v[i]);
    ptr = v;
    for(int i=0;i<5;i++) *(ptr+i) += 1;
    for(int i=0;i<5;i++) printf("%d ", *(ptr+i));
    printf("\n");
    return 0;
}