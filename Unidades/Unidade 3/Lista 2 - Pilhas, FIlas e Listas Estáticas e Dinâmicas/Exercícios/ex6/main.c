#include <stdio.h>
#include <stdlib.h>
#include "intercala_fila.h"

int main() {
    fila * queue1 = concebe_fila();
    fila * queue2 = concebe_fila();
    fila * queue3 = concebe_fila();
    elemento elem;
    int qtd;
    if(fila_vazia(queue1) == VERDADEIRO) printf("Fila vazia.\n");
    else printf("Fila não vazia.\n");
    if(fila_vazia(queue2) == VERDADEIRO) printf("Fila vazia.\n");
    else printf("Fila não vazia.\n");

    printf("Informe quantos elementos serão enfileirados na fila 1: ");
    while(1)
    {
        scanf("%d", &qtd);
        if(qtd <= TAM_MAX_FILA && qtd > 0) break;
        printf("Valor inválido, tente novamente: ");
    }
    for(int i=0;i<qtd;i++)
    {
        printf("Informe o elemento: ");
        scanf("%d", &(elem.dado));
        elem.chave = tamanho_fila(queue1) + 1;
        if(push(queue1, &elem) == SUCESSO) printf("Elemento enfileirado.\n");
        else printf("Elemento não enfileirado.\n");
        printf("Tamanho da fila: %d\n", tamanho_fila(queue1));
    }

    printf("Informe quantos elementos serão enfileirados na fila 2: ");
    while(1)
    {
        scanf("%d", &qtd);
        if(qtd <= TAM_MAX_FILA && qtd > 0) break;
        printf("Valor inválido, tente novamente: ");
    }
    for(int i=0;i<qtd;i++)
    {
        printf("Informe o elemento: ");
        scanf("%d", &(elem.dado));
        elem.chave = tamanho_fila(queue2) + 1;
        if(push(queue2, &elem) == SUCESSO) printf("Elemento enfileirado.\n");
        else printf("Elemento não enfileirado.\n");
        printf("Tamanho da fila: %d\n", tamanho_fila(queue2));
    }


    if(fila_vazia(queue1) == VERDADEIRO) printf("Fila vazia.\n");
    else printf("Fila não vazia.\n");
    if(imprime_fila(queue1) == SUCESSO) printf("Fila impressa.\n");

    if(fila_vazia(queue2) == VERDADEIRO) printf("Fila vazia.\n");
    else printf("Fila não vazia.\n");
    if(imprime_fila(queue2) == SUCESSO) printf("Fila impressa.\n");

    if(fila_cheia(queue1) == VERDADEIRO) printf("Fila cheia.\n");
    else printf("Fila não cheia.\n");
    if(fila_cheia(queue2) == VERDADEIRO) printf("Fila cheia.\n");
    else printf("Fila não cheia.\n");

    if(consulta_primeiro(queue1) == SUCESSO) printf("Frente consultada.\n");
    if(pop(queue1) == SUCESSO) printf("Elemento removido.\n");
    printf("Tamanho da fila: %d\n", tamanho_fila(queue1));
    if(consulta_primeiro(queue1) == SUCESSO) printf("Frente consultada.\n");
    if(imprime_fila(queue1) == VERDADEIRO) printf("Fila impressa.\n");

    if(consulta_primeiro(queue2) == SUCESSO) printf("Frente consultada.\n");
    if(pop(queue2) == SUCESSO) printf("Elemento removido.\n");
    printf("Tamanho da fila: %d\n", tamanho_fila(queue2));
    if(consulta_primeiro(queue2) == SUCESSO) printf("Frente consultada.\n");
    if(imprime_fila(queue2) == VERDADEIRO) printf("Fila impressa.\n");

    printf("Filas:\n");
    printf("-------- FILA 1 --------\n");
    if(imprime_fila(queue1) == VERDADEIRO) printf("Fila impressa.\n");
    printf("-------- FILA 2 --------\n");
    if(imprime_fila(queue2) == VERDADEIRO) printf("Fila impressa.\n");

    if(fila_intercalada(queue1, queue2, queue3) == SUCESSO) printf("Fila intercalada.\n");
    else printf("Não foi possível intercalar as filas.\n");

    printf("Filas:\n");
    printf("-------- FILA 1 --------\n");
    if(imprime_fila(queue1) == VERDADEIRO) printf("Fila impressa.\n");
    printf("-------- FILA 2 --------\n");
    if(imprime_fila(queue2) == VERDADEIRO) printf("Fila impressa.\n");
    printf("-------- FILA 3 --------\n");
    if(tamanho_fila(queue3) != 0)
    {
        if(imprime_fila(queue3) == VERDADEIRO) printf("Fila impressa.\n");
    }
    else printf("Fila não intercalada.\n");

    destroi_fila(queue1);
    destroi_fila(queue2);
    destroi_fila(queue3);
    return 0;
}