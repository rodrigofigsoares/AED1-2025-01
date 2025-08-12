#include <stdio.h>
#include <stdlib.h>
#include "pilha_dinamica.h"

struct Elemento {
    student aluno;
    struct Elemento *prox;
};

typedef struct Elemento elemento;

pilha * concebe_pilha() {
    pilha * stack = (pilha*)malloc(sizeof(pilha));
    if(stack == NULL)
    {
        printf("Pilha não alocada.\n");
        exit(1);
    }

    inicializa_pilha(stack);
    return stack;
}

void inicializa_pilha(pilha * stack) {
    if(stack == NULL)
    {
        printf("Pilha não alocada.\n");
        exit(1);
    }

    *stack = NULL;
}

void destroi_pilha(pilha * stack) {
    if(stack == NULL)
    {
        printf("Pilha não alocada.\n");
        exit(1);
    }

    pilha no;
    while(1)
    {
        if(*stack == NULL) break;
        no = *stack;
        *stack = (*stack)->prox;
        free(no);
    }
    free(stack);
}

int consulta_topo(pilha * stack) {
    if(stack == NULL)
    {
        printf("Pilha não alocada.\n");
        return FALHA;
    }
    if(pilha_vazia(stack) == VERDADEIRO)
    {
        printf("Pilha vazia.\n");
        return FALHA;
    }

    printf("Elemento do topo da pilha:\n");
    printf("Nome do aluno.....: %s\n", (*stack)->aluno.nome);
    printf("Matrícula do aluno: %s\n", (*stack)->aluno.matricula);
    printf("\n");
    return SUCESSO;
}

int push(pilha * stack, student aluno) {
    if(stack == NULL)
    {
        printf("Pilha não alocada.\n");
        return FALHA;
    }

    pilha no = (pilha)malloc(sizeof(elemento));
    if(no == NULL) return FALHA;
    no->aluno = aluno;
    no->prox = *stack;
    *stack = no;
    return SUCESSO;
}

int pop(pilha * stack) {
    if(stack == NULL)
    {
        printf("Pilha não alocada.\n");
        return FALHA;
    }
    if(pilha_vazia(stack) == VERDADEIRO)
    {
        printf("Pilha vazia.\n");
        return FALHA;
    }

    pilha no = *stack;
    *stack = no->prox;
    free(no);
    return SUCESSO;
}

int tamanho_pilha(pilha * stack) {
    if(stack == NULL)
    {
        printf("Pilha não alocada.\n");
        return FALHA;
    }

    pilha no = *stack;
    int tamanho = 0;
    while(1)
    {
        if(no == NULL) break;
        no = no->prox;
        tamanho++;
    }
    return tamanho;
}

int pilha_vazia(pilha * stack) {
    if(stack == NULL)
    {
        printf("Pilha não alocada.\n");
        return FALHA;
    }

    if(*stack == NULL) return VERDADEIRO; // topo da pilha aponta para nada
    else return FALSO;
}

int pilha_cheia(pilha * stack) {
    if(stack == NULL)
    {
        printf("Pilha não alocada.\n");
        return FALHA;
    }

    return FALSO; // O limite de uma pilha dinâmica é a memória do computador
}

int imprime_pilha(pilha * stack) {
    if(stack == NULL)
    {
        printf("Pilha não alocada.\n");
        return FALHA;
    }
    if(pilha_vazia(stack) == VERDADEIRO)
    {
        printf("Pilha vazia.\n");
        return FALHA;
    }

    pilha no = *stack;
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