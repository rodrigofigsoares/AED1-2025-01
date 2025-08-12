#include <stdio.h>
#include <stdlib.h>
#include "lista_estatica.h"

// printf alterando o valor da variável (ainda não sei como resolver)

int main() {
    lista * list = concebe_lista();
    int num;
    int qtd, form;
    if(lista_vazia(list) == VERDADEIRO) printf("Lista vazia.\n");
    else printf("Lista não vazia.\n");

    printf("Informe quantos elementos serão listados: ");
    while(1)
    {
        scanf("%d", &qtd);
        if(qtd <= TAM_MAX_LISTA && qtd > 0) break;
        printf("Valor inválido. Tente novamente: ");        
    }
    for(int i=0;i<qtd;i++)
    {
        printf("Informe o elemento que será inserido na lista: ");
        scanf("%d", &num);
        printf("Informe como ele será inserido.\n");
        printf("|\n");
        printf("| 0 - Inserido no início.\n");
        printf("| 1 - Inserido no meio.\n");
        printf("| 2 - Inserido no final.\n");
        printf("|\n");
        printf("Resposta: ");
        scanf("%d", &form);
        if(form == 0) 
        {
            if(push_inicio(list, num) == SUCESSO) printf("Elemento inserido no início da lista.\n");
        }
        else if(form == 1)
        {
            if(push_ordenado(list, num) == SUCESSO) printf("Elemento inserido no meio da lista.\n");
        }
        else if(form == 2)
        {
            if(push_final(list, num) == SUCESSO) printf("Elemento inserido no final da lista.\n");
        }
        printf("Tamanho da lista: %d\n", tamanho_lista(list));
        if(imprime_lista(list) == SUCESSO) printf("Lista impressa.\n");
    }
    if(lista_cheia(list) == VERDADEIRO) printf("Lista cheia.\n");
    else printf("Lista não cheia.\n");
    printf("\n");

    int temp = qtd;
    printf("Informe quantos elementos serão removidos: ");
    while(1)
    {
        scanf("%d", &qtd);
        if(qtd <= temp && qtd > 0) break;
        printf("Valor inválido. Tente novamente: ");
    }
    for(int i=0;i<qtd;i++)
    {
        printf("Informe como o elemento será removido.\n");
        printf("|\n");
        printf("| 0 - Removido do início.\n");
        printf("| 1 - Removido por especificação.\n");
        printf("| 2 - Removido do final.\n");
        printf("|\n");
        printf("Resposta: ");
        scanf("%d", &form);
        if(form == 0) 
        {
            if(pop_inicio(list) == SUCESSO) printf("Elemento removido do início da lista.\n");
            else printf("Não foi possível remover o elemento da lista.\n");
        }
        else if(form == 1)
        {
            if(pop_especifico(list) == SUCESSO) printf("Elemento especificado removido da lista.\n");
            else printf("Não foi possível remover o elemento especificado da lista.\n");
        }
        else if(form == 2)
        {
            if(pop_final(list) == SUCESSO) printf("Elemento removido do final da lista.\n");
            else printf("Não foi possível remover o elemento da lista.\n");
        }
        printf("Tamanho da lista: %d\n", tamanho_lista(list));
        if(imprime_lista(list) == SUCESSO) printf("Lista impressa.\n");
    }
    if(lista_cheia(list) == VERDADEIRO) printf("Lista cheia.\n");
    else printf("Lista não cheia.\n");

    destroi_lista(list);
    return 0;
}