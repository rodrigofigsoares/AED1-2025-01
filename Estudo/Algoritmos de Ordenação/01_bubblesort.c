/*
* Código retirado e adaptado de: BACKES, André Ricardo. Algoritmos e Estruturas de Dados em C. Rio de Janeiro: LTC, 2023. 
*/

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* vet, int tam) {//otimizado
    int i, continua, aux, fim = tam;
    do {
        continua = 0;
        for (i = 0; i < fim - 1; i++) {
            if (vet[i] > vet[i + 1]) {
                aux = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = aux;
                continua = i;
            }
        }
        fim--;
    } while (continua != 0);
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

    bubbleSort(vet, tam);

    printf("Depois de ordenar. \n");
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;
}