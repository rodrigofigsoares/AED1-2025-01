#include<stdio.h>
#include<stdlib.h>
#include"pilha.h"

int main(){
    Pilha *pilha_real = cria_pilha();

    printf("\tTamanho da pilha: %d\n", tamanho_pilha(pilha_real));

    pilha_cheia(pilha_real);
    pilha_vazia(pilha_real);

    printf("Empilhando...\n");
    insere_pilha(pilha_real, 200);
    insere_pilha(pilha_real, 50);
    printf("\tTamanho da pilha: %d\n", tamanho_pilha(pilha_real));
    printf("\tElemento no topo: %d\n\n", consulta_topo(pilha_real));


    printf("Desempilhando...\n");
    int deleted = remove_pilha(pilha_real);
    printf("\tElemento desempilhado %d\n", deleted);
    printf("\tTamanho da pilha: %d\n", tamanho_pilha(pilha_real));
    printf("\tElemento do topo: %d\n\n", consulta_topo(pilha_real));

    printf("Empilhando...\n");
    insere_pilha(pilha_real, 30);
    insere_pilha(pilha_real, 15);
    printf("\tTamanho da pilha eh: %d\n", tamanho_pilha(pilha_real));
    printf("\tElemento do topo: %d\n\n", consulta_topo(pilha_real));

    printf("Imprimindo...\n");
    imprime_pilha(pilha_real);

    printf("\n");
    return 0;
}