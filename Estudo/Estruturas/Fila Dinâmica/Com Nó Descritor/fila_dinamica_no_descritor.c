#include <stdio.h>
#include <stdlib.h>
#include "fila_dinamica_no_descritor.h"

struct Elemento {
    student aluno;
    struct Elemento * prox;
};

typedef struct Elemento elemento;

struct no_descritor {
    elemento * inicio;
    elemento * final;
    int tamanho;
};

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

    queue->tamanho = 0;
    queue->inicio = NULL;
    queue->final = NULL;
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
        no = queue->inicio;
        if(no == NULL) break;
        queue->inicio = queue->inicio->prox;
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

    printf("Frente da fila:\n");
    printf("Nome do aluno.....: %s\n", queue->inicio->aluno.nome);
    printf("Matrícula do aluno: %s\n", queue->inicio->aluno.matricula);
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
    no->prox = NULL;
    if(fila_vazia(queue) == VERDADEIRO) queue->inicio = no;
    else queue->final->prox = no;
    queue->final = no;
    queue->tamanho++;
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
    no = queue->inicio;
    queue->inicio = queue->inicio->prox;
    free(no);
    queue->tamanho--;
    if(queue->inicio == NULL) queue->final = NULL; // fila ficou vazia
    return SUCESSO;
}

int tamanho_fila(fila * queue) {
    if(queue == NULL)
    {
        printf("Fila não alocada.\n");
        return FALHA;
    }

    return queue->tamanho;
}

int fila_vazia(fila * queue) {
    if(queue == NULL)
    {
        printf("Fila não alocada.\n");
        return FALHA;
    }

    if(queue->inicio == NULL) return VERDADEIRO;
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

    elemento * no = queue->inicio;
    while(1)
    {
        if(no == NULL) break;
        printf("Nome do aluno.....: %s\n", no->aluno.nome);
        printf("Matrícula do aluno: %s\n", no->aluno.matricula);
        printf("\n");
        no = no->prox;
    }
    return SUCESSO;
}