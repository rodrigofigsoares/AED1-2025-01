#include <stdio.h>
#include <stdlib.h>
#include "pilha_dinamica.h"

int main() {
    pilha * stack = concebe_pilha();
    student aluno;
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
        printf("Informe o nome do aluno: ");
        scanf("%[^\n]%*c", aluno.nome);
        printf("Informe a matrícula do aluno: ");
        scanf("%[^\n]%*c", aluno.matricula);
        if(push(stack, aluno) == SUCESSO) printf("Aluno adicionado a pilha.\n");
        else printf("Aluno não adicionado a pilha.\n");
        printf("Tamanho da pilha: %d\n", tamanho_pilha(stack));
        imprime_pilha(stack);
    }

    if(consulta_topo(stack) == SUCESSO) printf("Topo consultado.\n");
    else printf("Não foi possível consultar o topo da pilha.\n");
    if(pop(stack) == SUCESSO) printf("Elemento removido da pilha.\n");
    else printf("Não foi possível remover o elemento da pilha.\n");
    printf("Tamanho da pilha: %d\n", tamanho_pilha(stack));
    if(consulta_topo(stack) == SUCESSO) printf("Topo consultado.\n");
    else printf("Não foi possível consultar o topo da pilha.\n");

    destroi_pilha(stack);
    return 0;
}