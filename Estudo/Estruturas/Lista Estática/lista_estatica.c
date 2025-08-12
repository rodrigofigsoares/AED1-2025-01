#include <stdio.h>
#include <stdlib.h>
#include "lista_estatica.h"

struct Lista {
    int tamanho;
    elemento elem[TAM_MAX_LISTA];
};

lista * concebe_lista() {
    lista * list = (lista*)malloc(sizeof(list));
    if(list == NULL)
    {
        printf("Não foi possível alocar a lista.\n");
        exit(1);
    }
    inicializa_lista(list);
    
    return list;
}

void inicializa_lista(lista * list) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        exit(1);
    }

    list->tamanho = 0;
}

void destroi_lista(lista * list) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        exit(1);
    }

    free(list);
}

int tamanho_lista(lista * list) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    
    return list->tamanho;
}

int lista_vazia(lista * list) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }

    if(list->tamanho > 0) return FALSO;
    else return VERDADEIRO;
}

int lista_cheia(lista * list) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }

    if(list->tamanho == TAM_MAX_LISTA) return VERDADEIRO;
    else return FALSO;
}

int push_inicio(lista * list, elemento * elem) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_cheia(list) == VERDADEIRO) return FALHA;

    for(int i=list->tamanho;i>0;i--) list->elem[i] = list->elem[i-1];
    list->elem[0] = *elem;
    list->tamanho++;
    return SUCESSO;
}

int push_ordenado(lista * list, elemento * elem) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_cheia(list) == VERDADEIRO) return FALHA;

    int order_type;
    int i = 0;
    printf("Inserir por dado (digite 0) ou por chave (digite 1)?\n");
    printf("Resposta: ");
    scanf("%d", &order_type);
    if(order_type == 0) while(i < list->tamanho && list->elem[i].dado < elem->dado) i++;
    else if(order_type == 1) while(i < list->tamanho && list->elem[i].chave < elem->chave) i++;
    if(i < list->tamanho) for(int k=list->tamanho;k>i;k--) list->elem[k] = list->elem[k-1];
    list->elem[i] = *elem;
    list->tamanho++;
    return SUCESSO;
}

int push_final(lista * list, elemento * elem) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_cheia(list) == VERDADEIRO) return FALHA;

    list->elem[list->tamanho] = *elem;
    list->tamanho++;
    return SUCESSO;
}

int pop_inicio(lista * list) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_vazia(list) == VERDADEIRO) return FALHA;

    for(int i=0;i<list->tamanho-1;i++) list->elem[i] = list->elem[i+1];
    list->tamanho--;
    return SUCESSO;
}

int pop_especifico(lista * list) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_vazia(list) == VERDADEIRO) return FALHA;

    int order_type, value;
    int i = 0;
    printf("Remover por dado (digite 0) ou por chave (digite 1)?\n");
    printf("Resposta: ");
    scanf("%d", &order_type);
    if(order_type == 0)
    {
        printf("Informe o dado: ");
        scanf("%d", &value);
        while(i < list->tamanho && list->elem[i].dado != value) i++;
    }
    else if(order_type == 1)
    {
        printf("Informe a chave: ");
        scanf("%d", &value);
        while(i < list->tamanho && list->elem[i].chave != value) i++;
    }
    if(i == list->tamanho) return FALHA;
    for(int k=i;k<list->tamanho-1;k++) list->elem[k] = list->elem[k+1];
    list->elem[list->tamanho-1].chave = CHAVE_INVALIDA;
    list->tamanho--;
    return SUCESSO;
}

int pop_final(lista * list) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_vazia(list) == VERDADEIRO) return FALHA;

    list->elem[list->tamanho-1].chave = CHAVE_INVALIDA;
    list->tamanho--;
    return SUCESSO;
}

int consulta_por_dado(lista * list, int dado) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_vazia(list) == VERDADEIRO) return FALHA;

    int i=0;
    while(i < list->tamanho && list->elem[i].dado != dado) i++;
    if(i == list->tamanho) return FALHA;
    printf("Elemento...: %d\n", list->elem[i].dado);
    printf("Chave......: %d\n", list->elem[i].chave);
    return SUCESSO;
}

int consulta_por_chave(lista * list, int chave) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_vazia(list) == VERDADEIRO) return FALHA;

    int i=0;
    while(i < list->tamanho && list->elem[i].chave != chave) i++;
    if(i == list->tamanho) return FALHA;
    printf("Elemento...: %d\n", list->elem[i].dado);
    printf("Chave......: %d\n", list->elem[i].chave);
    return SUCESSO;
}

int imprime_lista(lista * list) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_vazia(list) == VERDADEIRO) return FALHA;

    for(int i=0;i<list->tamanho;i++)
    {
        printf("Elemento...: %d\n", list->elem[i].dado);
        printf("Chave......: %d\n", list->elem[i].chave);
    }
    return SUCESSO;
}