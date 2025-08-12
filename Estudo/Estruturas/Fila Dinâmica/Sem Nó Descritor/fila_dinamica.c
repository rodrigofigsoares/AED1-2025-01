#include <stdio.h>
#include <stdlib.h>
#include "fila_dinamica.h"

struct Elemento {
    student aluno;
    struct Elemento * prox;
};

typedef struct Elemento elemento;

fila * concebe_fila() {
    fila * queue = (fila*)malloc(sizeof(fila));
    if(queue == NULL)
    {
        printf("Falha ao alocar a fila.\n");
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
    
    *queue = NULL;
}

void destroi_fila(fila * queue) {
    if(queue == NULL)
    {
        printf("Fila não alocada.\n");
        exit(1);
    }

    elemento * no;
    while(1)
    {
        no = *queue;
        if(no == NULL) break;
        *queue = (*queue)->prox;
        free(no);
    }
    free(queue);
}

int consulta_inicio(fila * queue) {
    if(queue == NULL)
    {
        printf("Fila não alocada.\n");
        return FALHA;
    }
    if(fila_vazia(queue) == VERDADEIRO)
    {
        printf("Fila vazia.\n");
        return FALHA;
    }

    elemento * no = *queue;
    while(1)
    {
        if(no->prox == NULL) break;
        no = no->prox;
    }
    printf("Frente da fila:\n");
    printf("Nome do aluno.....: %s\n", no->aluno.nome);
    printf("Matrícula do aluno: %s\n", no->aluno.matricula);
    return SUCESSO;
}

int push(fila * queue, student aluno) {
    if(queue == NULL)
    {
        printf("Fila não alocada.\n");
        return FALHA;
    }
    
    elemento * no = (elemento*)malloc(sizeof(elemento));
    no->aluno = aluno;
    if(fila_vazia(queue) == VERDADEIRO) no->prox = NULL;
    else no->prox = *queue;
    *queue = no;
    return VERDADEIRO;
}

int pop(fila * queue) {
    if(queue == NULL)
    {
        printf("Fila não alocada.\n");
        return FALHA;
    }
    if(fila_vazia(queue) == SUCESSO)
    {
        printf("Fila vazia.\n");
        return FALHA;
    }

    elemento * no;
    no = *queue;
    while(1)
    {
        if((no->prox)->prox == NULL) break;
        no = no->prox;
    }
    free(no->prox);
    no->prox = NULL;
    return SUCESSO;
}

int tamanho_fila(fila * queue) {
    if(queue == NULL)
    {
        printf("Fila não alocada.\n");
        return FALHA;
    }

    elemento * no = *queue;
    int tamanho = 0;
    while(1)
    {
        if(no == NULL) break;
        no = no->prox;
        tamanho++;
    }
    return tamanho;
}

int fila_vazia(fila * queue) {
    if(queue == NULL)
    {
        printf("Fila não alocada.\n");
        return FALHA;
    }

    if(*queue == NULL) return VERDADEIRO;
    else return FALSO;
}

int fila_cheia(fila * queue) {
    if(queue == NULL)
    {
        printf("Fila não alocada.\n");
        return FALHA;
    }

    return FALSO; // O limite de uma fila dinâmica é a memória do computador
}

int imprime_fila(fila * queue) {
    if(queue == NULL)
    {
        printf("Fila não alocada.\n");
        return FALHA;
    }
    if(fila_vazia(queue) == VERDADEIRO)
    {
        printf("Fila vazia.\n");
        return FALHA;
    }

    elemento * elementos_da_fila = (elemento*)malloc(tamanho_fila(queue) * sizeof(elemento));
    elemento * no = *queue;
    int i = 0;
    while(1)
    {
        if(no == NULL) break;
        elementos_da_fila[i].aluno = no->aluno;
        no = no->prox;
        i++;
    }
    for(i = tamanho_fila(queue)-1;i>=0;i--)
    {
        printf("\n");
        printf("Nome do aluno.....: %s\n", elementos_da_fila[i].aluno.nome);
        printf("Matrícula do aluno: %s\n", elementos_da_fila[i].aluno.matricula);
    }
    return SUCESSO;
}