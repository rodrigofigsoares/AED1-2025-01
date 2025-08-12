#include <stdio.h>
#include <stdlib.h>
#include "pilha_estatica.h"

int main() {
    pilha * stack = concebe_pilha();
    elemento elem;
    int qtd;
   if(pilha_vazia(stack) == VERDADEIRO) printf("Pilha vazia.\n");
    else printf("Pilha não vazia.\n");
    printf("Informe quantos elementos serão empilhados: ");
    while(1)
    {
        scanf("%d", &qtd);
        if(qtd <= TAMANHO_MAXIMO_PILHA && qtd > 0) break;
        printf("Valor inválido, tente novamente: ");
    }
    for(int i=0;i<qtd;i++)
    {
        printf("Informe o elemento: ");
        scanf("%d", &(elem.dado));
        elem.chave = tamanho_pilha(stack) + 1;
        if(push(stack, &elem) == SUCESSO) printf("Elemento empilhado.\n");
        else printf("Elemento não empilhado.\n");
        printf("Tamanho da pilha: %d\n", tamanho_pilha(stack));
    }
    if(pilha_vazia(stack) == VERDADEIRO) printf("Pilha vazia.\n");
    else printf("Pilha não vazia.\n");
    if(imprime_pilha(stack) == SUCESSO) printf("Pilha impressa.\n");

    if(pilha_cheia(stack) == VERDADEIRO) printf("Pilha cheia.\n");
    else printf("Pilha não cheia.\n");

    if(consulta_topo(stack) == SUCESSO) printf("Topo consultado.\n");
    if(pop(stack) == SUCESSO) printf("Elemento desempilhado.\n");
    printf("Tamanho da pilha: %d\n", tamanho_pilha(stack));
    if(consulta_topo(stack) == SUCESSO) printf("Topo consultado.\n");
    if(imprime_pilha(stack) == VERDADEIRO) printf("Pilha impressa.\n");

    destroi_pilha(stack);
    return 0;
}