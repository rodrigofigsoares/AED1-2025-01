#include <stdio.h>

#define N 10

int busca_normal(int * v, int tam, int elem) {
    for(int i=0;i<tam;i++)
    {
        if(v[i] = elem) return 1;
    }
    return 0;
}

int busca_binaria(int * v, int tam, int elem) {
    int inicio = 0, meio;
    while(1)
    {
        meio = (inicio+tam)/2;
        if(v[meio] == elem) return 1;
        if(inicio == tam) return 0;
        else if(elem > v[meio]) inicio = meio+1;
        else if(elem < v[meio]) tam = meio-1;
    }
}

int main() {
    int v[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};    
    return 0;
}