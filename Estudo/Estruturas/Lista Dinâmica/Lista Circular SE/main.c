#include <stdio.h>
#include <stdlib.h>
#include "lista_circular_simplesmente_encadeada.h"

int main() {
    lista * list = concebe_lista();
    student aluno;
    int qtd;
    if(lista_vazia(list) == VERDADEIRO) printf("Lista vazia.\n");
    else printf("Lista não vazia.\n");

    printf("Informe a quantidade de elementos que serão listados: ");
    while(1)
    {
        scanf("%d%*c", &qtd);
        if(qtd > 0) break;
        printf("Valor inválido. Tente novamene: ");
    }
    for(int i=0;i<qtd;i++)
    {
        printf("Informe o nome do aluno: ");
        scanf("%[^\n]%*c", aluno.nome);
        printf("Informe a matrícula do aluno: ");
        scanf("%d", &aluno.matricula);
        if(push(list, aluno) == SUCESSO) printf("SUCESSO.\n");
        else printf("FALHA.\n");
        printf("Tamanho da lista: %d\n", tamanho_lista(list));
        if(imprime_lista(list) == SUCESSO) printf("Lista impressa.\n");
        else printf("Não foi possível imprimir a lista.\n");
    }

    if(consulta_elemento(list) == SUCESSO) printf("SUCESSO.\n");
    else printf("FALHA\n");
    if(pop(list) == SUCESSO) printf("SUCESSO.\n");
    else printf("FALHA.\n");
    printf("Tamanho da lista: %d\n", tamanho_lista(list));
    if(pop(list) == SUCESSO) printf("SUCESSO.\n");
    else printf("FALHA.\n");
    printf("Tamanho da lista: %d\n", tamanho_lista(list));
    if(consulta_elemento(list) == SUCESSO) printf("SUCESSO.\n");
    else printf("FALHA.\n");
    if(imprime_lista(list) == SUCESSO) printf("Lista impressa.\n");
    else printf("Não foi possível imprimir a lista.\n");

    destroi_lista(list);
    return 0;
}