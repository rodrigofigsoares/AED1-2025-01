/*
* Código retirado e adaptado de: BACKES, André Ricardo. Algoritmos e Estruturas de Dados em C. Rio de Janeiro: LTC, 2023. 
*/

#include <stdio.h>
#include <stdlib.h>

void selectionSort(int* vet, int tam) {
    int i, j, menor, troca;
    for (i = 0; i < tam - 1; i++) {
        menor = i;
        for (j = i + 1; j < tam; j++) {
            if (vet[j] < vet[menor])
                menor = j;
        }
        if (i != menor) {
            troca = vet[i];
            vet[i] = vet[menor];
            vet[menor] = troca;
        }
    }
}

int main() {
    int vet[] = { -8, 4, 23, 54, 90, 90, 21, 34, -3, 10 };
    int tam = 10;

    printf("Antes de ordenar. \n");
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n\n");

    selectionSort(vet, tam);

    printf("Depois de ordenar. \n");
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;
}