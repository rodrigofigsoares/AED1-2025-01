#include <stdio.h>
#include <stdlib.h>
#include "pilha_estatica.h"

struct Pilha {
    elemento elem[TAMANHO_MAXIMO_PILHA];
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

int push(pilha * stack, elemento * elem) {
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

    stack->elem[stack->tam_pilha] = *elem;
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
    
    stack->elem[stack->tam_pilha - 1].chave = CHAVE_INVALIDA;
    stack->tam_pilha--;
    return SUCESSO;
}

int consulta_topo(pilha * stack) {
    if(stack == NULL)
    {
        printf("Pilha não alocada.\n");
        return FALHA;
    }
    printf("Elemento do topo:\n");
    printf("Chave..: %d\n", stack->elem[stack->tam_pilha - 1].chave);
    printf("Dado...: %d\n", stack->elem[stack->tam_pilha - 1].dado);
    return SUCESSO;
}

int imprime_pilha(pilha * stack) {
    if(stack == NULL)
    {
        printf("Pilha não alocada.\n");
        return FALHA;
    }
    for(int i=stack->tam_pilha-1;i>=0;i--)
    {
        printf("Chave..: %d\n", stack->elem[i].chave);
        printf("Dado...: %d\n", stack->elem[i].dado);
    }
    return SUCESSO;
}