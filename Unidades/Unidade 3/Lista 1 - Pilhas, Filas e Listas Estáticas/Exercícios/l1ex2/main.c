#include <stdio.h>
#include <stdlib.h>
#include "fila_estatica.h"

int main() {
    fila * queue = concebe_fila();
    elemento elem;
    int qtd;
    if(fila_vazia(queue) == VERDADEIRO) printf("Fila vazia.\n");
    else printf("Fila não vazia.\n");
    printf("Informe quantos elementos serão enfileirados: ");
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
        elem.chave = tamanho_fila(queue);
        if(push(queue, &elem) == SUCESSO) printf("Elemento enfileirado.\n");
        else printf("Elemento não enfileirado.\n");
        printf("Tamanho da fila: %d\n", tamanho_fila(queue));
    }
    if(fila_vazia(queue) == VERDADEIRO) printf("Fila vazia.\n");
    else printf("Fila não vazia.\n");
    if(imprime_fila(queue) == SUCESSO) printf("Fila impressa.\n");

    if(fila_cheia(queue) == VERDADEIRO) printf("Fila cheia.\n");
    else printf("Fila não cheia.\n");

    if(consulta_primeiro(queue) == SUCESSO) printf("Frente consultada.\n");
    if(pop(queue) == SUCESSO) printf("Elemento removido.\n");
    printf("Tamanho da fila: %d\n", tamanho_fila(queue));
    if(consulta_primeiro(queue) == SUCESSO) printf("Frente consultada.\n");
    if(imprime_fila(queue) == VERDADEIRO) printf("Fila impressa.\n");

    destroi_fila(queue);
    return 0;
}