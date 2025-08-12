#include <stdio.h>

#define N 10

int verifica_ordenado(int * v, int tam) {
    for(int i=0;i<tam-1;i++)
    {
        if(v[i] > v[i+1]) return 0;
    }
    return 1;
}

int main() {
    int v[N];
    for(int i=0;i<N;i++)
    {
        scanf("%d", v[i]);
    }
    if(verifica_ordenado(v, N) == 1) printf("ORDENADO\n");
    else printf("NÃO ORDENADO\n");
    return 0;
}