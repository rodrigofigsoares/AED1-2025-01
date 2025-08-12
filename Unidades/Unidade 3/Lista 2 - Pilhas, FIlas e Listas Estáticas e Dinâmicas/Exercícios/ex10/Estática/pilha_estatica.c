#include <stdio.h>
#include <stdlib.h>
#include "pilha_estatica.h"

struct Pilha {
    int num[TAMANHO_MAXIMO_PILHA];
    int tam_pilha;
};

pilha * concebe_pilha() {
    pilha * stack = (pilha*)malloc(sizeof(pilha));
    if(stack == NULL)
    {
        printf("Não foi possível alocar a pilha.\n");
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
    stack->tam_pilha = 0;
}

void destroi_pilha(pilha * stack) {
    if(stack == NULL)
    {
        printf("Pilha não alocada.\n");
        exit(1);
    }
    free(stack);
}


int tamanho_pilha(pilha * stack) {
    if(stack == NULL)
    {
        printf("Pilha não alocada.\n");
        return FALHA;
    }
    return stack->tam_pilha;
}

int pilha_vazia(pilha * stack) {
    if(stack == NULL)
    {
        printf("Pilha não alocada.\n");
        return FALHA;
    }
    if(stack->tam_pilha == 0) return VERDADEIRO;
    else return FALSO;
}

int pilha_cheia(pilha * stack) {
    if(stack == NULL)
    {
        printf("Pilha não alocada.\n");
        return FALHA;
    }
    if(stack->tam_pilha == TAMANHO_MAXIMO_PILHA) return VERDADEIRO;
    else return FALSO;
}

int push(pilha * stack, int num) {
    if(stack == NULL)
    {
        printf("Pilha não alocada.\n");
        return FALHA;
    }
    if(pilha_cheia(stack) == VERDADEIRO)
    {
        printf("A pilha está cheia.\n");
        return FALHA;
    }

    stack->num[stack->tam_pilha] = num;
    stack->tam_pilha++;

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
        printf("A pilha está vazia.\n");
        return FALHA;
    }
    
    stack->tam_pilha--;
    return SUCESSO;
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
    printf("Elemento do topo: %d\n", stack->num[0]);
    return SUCESSO;
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

    for(int i=stack->tam_pilha-1;i>=0;i--) printf("Elemento: %d\n", stack->num[i]);
    return SUCESSO;
}

int qtd_impares(pilha * stack) {
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

    int impares = 0;
    for(int i=0;i<tamanho_pilha(stack);i++) if((stack->num[i])%2 != 0) impares++;

    return impares;
}