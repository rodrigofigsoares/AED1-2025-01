/*
* Código retirado e adaptado de: BACKES, André Ricardo. Algoritmos e Estruturas de Dados em C. Rio de Janeiro: LTC, 2023. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Usar -lm para compilar

void imprimeVet(int* vet, int tam) {
    int i;
    for (i = 0; i < tam; i++)
        printf("%2d ", vet[i]);
    printf("\n");
}

void merge(int* vet, int inicio, int meio, int fim) {
    int* temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int*)malloc(tamanho * sizeof(int));
    if (temp != NULL) {
        for (i = 0; i < tamanho; i++) {
            if (!fim1 && !fim2) {
                if (vet[p1] < vet[p2])
                    temp[i] = vet[p1++];
                else
                    temp[i] = vet[p2++];

                if (p1 > meio) fim1 = 1;
                if (p2 > fim) fim2 = 1;
            }
            else {
                if (!fim1)
                    temp[i] = vet[p1++];
                else
                    temp[i] = vet[p2++];
            }
        }
        for (j = 0, k = inicio; j < tamanho; j++, k++)
            vet[k] = temp[j];
    }
    free(temp);
}

void mergeSort(int* vet, int inicio, int fim) {
    int meio;
    if (inicio < fim) {
        meio = floor((inicio + fim) / 2);
        mergeSort(vet, inicio, meio);
        mergeSort(vet, meio + 1, fim);
        merge(vet, inicio, meio, fim);
    }
}

int main() {

    int vet[] = { -8, 4, 23, 54, 90, 90, 21, 34, -3, 10 };
    int tam = 10;

    printf("Antes de ordenar. \n");
    imprimeVet(vet, tam);

    mergeSort(vet, 0, tam - 1);

    printf("Depois de ordenar. \n");
    imprimeVet(vet, tam);

    return 0;
}
