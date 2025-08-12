/*
* Código retirado e adaptado de: BACKES, André Ricardo. Algoritmos e Estruturas de Dados em C. Rio de Janeiro: LTC, 2023. 
*/

#include <stdio.h>
#include <stdlib.h>

void imprimeVet(int* vet, int tam) {
    int i;
    for (i = 0; i < tam; i++)
        printf("%2d ", vet[i]);
    printf("\n");
}

int particiona(int* vet, int inicio, int final) {
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = final;
    pivo = vet[inicio];
    while (esq < dir) {
        while (esq <= final && vet[esq] <= pivo)
            esq++;

        while (dir >= 0 && vet[dir] > pivo)
            dir--;

        if (esq < dir) {
            aux = vet[esq];
            vet[esq] = vet[dir];
            vet[dir] = aux;
        }
    }
    vet[inicio] = vet[dir];
    vet[dir] = pivo;
    return dir;
}

void quickSort(int* V, int inicio, int fim) {
    int pivo;
    if (fim > inicio) {
        pivo = particiona(V, inicio, fim);
        quickSort(V, inicio, pivo - 1);
        quickSort(V, pivo + 1, fim);
    }
}


int main() {

    int vet[] = { -8, 4, 23, 54, 90, 90, 21, 34, -3, 10 };
    int tam = 10;

    printf("Antes de ordenar. \n");
    imprimeVet(vet, tam);

    quickSort(vet, 0, tam - 1);

    printf("Depois de ordenar. \n");
    imprimeVet(vet, tam);

    return 0;
}
