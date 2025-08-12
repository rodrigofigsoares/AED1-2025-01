/*
* Código retirado e adaptado de: BACKES, André Ricardo. Algoritmos e Estruturas de Dados em C. Rio de Janeiro: LTC, 2023. 
*/

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *vet, int tam){
    int i, j, aux;
    for(i = 1; i < tam; i++){
        aux = vet[i];
        for(j = i; (j > 0) && (aux < vet[j - 1]); j--)
            vet[j] = vet[j - 1];
        vet[j] = aux;
        // printfVet(vet,tam);
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

    insertionSort(vet, tam);

    printf("Depois de ordenar. \n");
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;
}