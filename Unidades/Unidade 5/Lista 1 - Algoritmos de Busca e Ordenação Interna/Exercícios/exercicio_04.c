#include <stdio.h>

#define N 5

int busca_binaria(int * v, int tam, int elem) {
    int inicio = 0, meio;
    tam = tam-1;
    while(1)
    {
        meio = (inicio + tam)/2;
        if(v[meio] == elem) return v[meio];
        if(tam == -1) return v[0];
        if(inicio > tam) return v[N-1];
        if(v[meio+1] > elem && v[meio] < elem)
        {
            if(-(v[meio] - elem) > v[meio+1] - elem) return v[meio+1];
            else return v[meio];
        }
        else if(v[meio] > elem) tam = meio - 1;
        else if(v[meio] < elem) inicio = meio + 1;
    }
}

int main() {
    int v[N] = {3, 7, 10, 14, 16};
    int elem;
    scanf("%d", &elem);
    printf("%d\n", busca_binaria(v, N, elem));

    return 0;
}