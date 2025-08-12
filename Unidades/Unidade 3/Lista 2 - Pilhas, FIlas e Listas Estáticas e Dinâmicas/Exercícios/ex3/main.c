#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

int main() {
    lista * list = concebe_lista();
    int qtd;
    if(lista_vazia(list) == VERDADEIRO) printf("Lista vazia.\n");
    else printf("Lista não vazia.\n");

    printf("Informe quantos produtos serão cadastrados: ");
    while(1)
    {
        scanf("%d%*c", &qtd);
        if(qtd > 0) break;
        printf("Valor inválido. Tente novamente: ");
    }

    for(int i=0;i<qtd;i++)
    {
        if(cadastra_produto(list) == SUCESSO) printf("Produto cadastrado com sucesso.\n");
        else printf("Não foi possível cadastrar o produto.\n");
        printf("Tamanho da lista: %d\n", tamanho_lista(list));
        if(imprime_lista(list) == SUCESSO) printf("Lista impressa.\n");
        else printf("Não foi possível imprimir a lista.\n");
    }

    if(mais_barato(list) == SUCESSO) printf("SUCESSO.\n");
    else printf("FALHA.\n");

    int codigo;
    printf("Informe o código do produto que será consultado: ");
    scanf("%d", &codigo);
    if(consulta_produto(list, codigo) == SUCESSO) printf("Elemento consultado.\n");
    else printf("Não foi possível consultar o elemento.\n");

    if(atualizar_estoque(list) == SUCESSO) printf("Estoque atualizado.\n");
    else printf("Não foi possível atualizar o estoque.\n");

    printf("Informe o código do produto que será consultado: ");
    scanf("%d", &codigo);
    if(consulta_produto(list, codigo) == SUCESSO) printf("Elemento consultado.\n");
    else printf("Não foi possível consultar o elemento.\n");

    if(imprime_lista(list) == SUCESSO) printf("Lista impressa.\n");
    else printf("Não foi possível imprimir a lista.\n");

    printf("Informe quantos produtos serão removidos: ");
    while(1)
    {
        scanf("%d%*c", &qtd);
        if(qtd > 0) break;
        printf("Valor inválido. Tente novamente: ");
    }

    for(int i=0;i<qtd;i++)
    {
        printf("Informe o código do produto que será removido: ");
        scanf("%d", &codigo);
        if(pop(list, codigo) == SUCESSO) printf("Produto removido com sucesso.\n");
        else printf("Não foi possível remover o produto.\n");
        printf("Tamanho da lista: %d\n", tamanho_lista(list));
        if(imprime_lista(list) == SUCESSO) printf("Lista impressa.\n");
        else printf("Não foi possível imprimir a lista.\n");
    }

    destroi_lista(list);
    return 0;
}