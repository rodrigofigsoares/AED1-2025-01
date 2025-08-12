#include <stdio.h>
#include <stdlib.h>
#include "pilha_dinamica.h"

int main() {
    pilha * stack = concebe_pilha();
    int num;
    int qtd;

    if(pilha_vazia(stack) == VERDADEIRO) printf("Pilha vazia.\n");
    else printf("Pilha não vazia.\n");
    
    printf("Informe quantos elementos serão inseridos na pilha: ");
    while(1)
    {
        scanf("%d%*c", &qtd);
        if(qtd > 0) break;
        printf("Valor inválido. Tente novamente: ");
    }
    for(int i=0;i<qtd;i++)
    {
        printf("Informe o elemento que será inserido: ");
        scanf("%d", &num);
        if(push(stack, num) == SUCESSO) printf("Elemento adicionado a pilha.\n");
        else printf("Elemento não adicionado a pilha.\n");
        printf("Tamanho da pilha: %d\n", tamanho_pilha(stack));
        if(imprime_pilha(stack) == SUCESSO) printf("Pilha impressa.\n");
    }

    if(consulta_topo(stack) == SUCESSO) printf("Topo consultado.\n");
    else printf("Não foi possível consultar o topo da pilha.\n");
    printf("Há %d números ímpares na pilha.\n", qtd_impares(stack));
    if(pop(stack) == SUCESSO) printf("Elemento removido da pilha.\n");
    else printf("Não foi possível remover o elemento da pilha.\n");
    printf("Tamanho da pilha: %d\n", tamanho_pilha(stack));
    if(imprime_pilha(stack) == SUCESSO) printf("Pilha impressa.\n");
    if(consulta_topo(stack) == SUCESSO) printf("Topo consultado.\n");
    else printf("Não foi possível consultar o topo da pilha.\n");
    printf("Há %d números ímpares na pilha.\n", qtd_impares(stack));

    destroi_pilha(stack);
    return 0;
}