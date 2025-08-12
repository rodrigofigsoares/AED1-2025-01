/*
Faça um programa que leia um valor n e crie dinamicamente um
vetor de n elementos e passe esse vetor para uma função que vai ler
os elementos desse vetor. Depois, no programa principal, o vetor
preenchido deve ser impresso. Além disso, antes de finalizar o
programa, deve-se liberar a área de memória alocada.
*/

#include <stdio.h>
#include <stdlib.h>

void read_v(int * v, int size) {
    for(int i=0;i<size;i++) scanf("%d", &v[i]);
}

void print_v(int * v, int size) {
    for(int i=0;i<size;i++) printf("%d ", v[i]);
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int * v = (int*)malloc(n*sizeof(int));
    read_v(v, n);
    print_v(v, n);
    free(v);
    return 0;
}