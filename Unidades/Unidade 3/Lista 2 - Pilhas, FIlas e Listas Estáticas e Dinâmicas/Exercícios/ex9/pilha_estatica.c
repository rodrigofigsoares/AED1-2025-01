#include <stdio.h>
#include <stdlib.h>
#include "pilha_estatica.h"

struct Pilha {
    char letra[TAMANHO_MAXIMO_PILHA];
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

int push(pilha * stack, char letra) {
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

    stack->letra[stack->tam_pilha] = letra;
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
    printf("Elemento do topo: %c\n", stack->letra[0]);
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

    for(int i=stack->tam_pilha-1;i>=0;i--) printf("Elemento: %c\n", stack->letra[i]);
    return SUCESSO;
}

int verifica_palindromo(pilha * stack) {
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

    char * contrario = (char*)malloc((tamanho_pilha(stack)*sizeof(char)));
    char * texto = (char*)malloc((tamanho_pilha(stack)*sizeof(char)));
    int j = 0, k = tamanho_pilha(stack);
    int tamanho = 0;
    for(int i=0;i<tamanho_pilha(stack);i++)
    {
        if(stack->letra[i] > 64 && stack->letra[i] < 91)
        {
            texto[j] = stack->letra[i] + 32;
            contrario[k] = stack->letra[i] + 32;
            j++;
            k--;
            tamanho++;
        }
        else if(stack->letra[i] > 96 && stack->letra[i] < 123)
        {
            texto[j] = stack->letra[i];
            contrario[k] = stack->letra[i];
            j++;
            k--;
            tamanho++;
        }
    }
    int VouF = FALSO;
    while(1)
    {
        int i = 0, j = 0;
        if(texto[i] == contrario[j])
        {
            i++;
            j++;
        }
        if(i == tamanho) VouF = VERDADEIRO;
    }
    free(contrario);
    free(texto);
    return VouF;
}