#include <stdio.h>
#include <stdlib.h>
#include "fila_estatica.h"

struct Fila {
    int inicio, fim;
    elemento elem[TAM_MAX_FILA];
};

fila * concebe_fila() {
    fila * queue = (fila*)malloc(sizeof(fila));
    if(queue == NULL)
    {
        printf("Não foi possível alocar a fila.\n");
        exit(1);
    }
    inicializa_fila(queue);
    return queue;
}

void inicializa_fila(fila * queue) {
    if(queue == NULL)
    {
        printf("Fila não alocada.\n");
        exit(1);
    }
    queue->inicio = 0;
    queue->fim = 0;
}

void destroi_fila(fila * queue) {
    if(queue == NULL)
    {
        printf("Fila não alocada.\n");
        exit(1);
    }
    free(queue);
}


int tamanho_fila(fila * queue) {
    if(queue == NULL)
    {
        printf("Fila não alocada.\n");
        return FALHA;
    }
    return queue->fim;
}

int fila_vazia(fila * queue) {
    if(queue == NULL)
    {
        printf("Fila não alocada.\n");
        return FALHA;
    }
    if(queue->fim == 0) return VERDADEIRO;
    else return FALSO;
}

int fila_cheia(fila * queue) {
    if(queue == NULL)
    {
        printf("Fila não alocada.\n");
        return FALHA;
    }
    if(queue->fim == TAM_MAX_FILA) return VERDADEIRO;
    else return FALSO;
}

int push(fila * queue, elemento * elem) {
    if(queue == NULL)
    {
        printf("Fila não alocada.\n");
        return FALHA;
    }
    if(fila_cheia(queue) == VERDADEIRO)
    {
        printf("A fila está cheia.\n");
        return FALHA;
    }

    queue->fim++;
    queue->elem[queue->fim-1] = *elem;

    return SUCESSO;
}

int pop(fila * queue) {
    if(queue == NULL)
    {
        printf("Fila não alocada.\n");
        return FALHA;
    }
    if(fila_vazia(queue) == VERDADEIRO)
    {
        printf("A fila está vazia.\n");
        return FALHA;
    }
    
    for(int i=0;i<queue->fim-1;i++) queue->elem[i] = queue->elem[i+1];
    queue->elem[queue->fim-1].chave = CHAVE_INVALIDA;
    queue->fim--;

    return SUCESSO;
}

int consulta_primeiro(fila * queue) {
    if(queue == NULL)
    {
        printf("Fila não alocada.\n");
        return FALHA;
    }
    printf("Primeiro elemento:\n");
    printf("Chave..: %d\n", queue->elem[queue->inicio].chave);
    printf("Dado...: %d\n", queue->elem[queue->inicio].dado);
    return SUCESSO;
}

int imprime_fila(fila * queue) {
    if(queue == NULL)
    {
        printf("Fila não alocada.\n");
        return FALHA;
    }
    for(int i=queue->inicio;i<queue->fim;i++)
    {
        printf("Chave..: %d\n", queue->elem[i].chave);
        printf("Dado...: %d\n", queue->elem[i].dado);
    }
    return SUCESSO;
}