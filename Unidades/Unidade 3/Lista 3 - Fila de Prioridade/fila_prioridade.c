#include <stdio.h>
#include <stdlib.h>
#include "fila_prioridade.h"

struct Fila_Prioridade {
    Paciente paciente[TAM_MAX_FILA];
    int tamanho;
};

prio * concebe_fila_prioridade() {
    prio * fila = (prio*)malloc(sizeof(prio));
    if(fila == NULL)
    {
        printf("Não foi possível alocar a fila de prioridade.\n");
        exit(1);
    }

    inicializa_fila(fila);
    return fila;
}

void inicializa_fila(prio * fila) {
    if(fila == NULL)
    {
        printf("Fila de prioridade não alocada.\n");
        exit(1);
    }

    fila->tamanho = 0;
}

int push_prioridade(prio * fila, Paciente * paciente) {
    if(fila == NULL)
    {
        printf("Fila não alocada.\n");
        return FALHA;
    }
    if(fila_cheia(fila) == VERDADEIRO)
    {
        printf("Fila cheia. Não foi possível inserir.\n");
        return FALHA;
    }

    int i = 0;
    while(i < fila->tamanho)
    {
        if(fila->paciente[i].prioridade < paciente->prioridade) i++;
        else break;
    }
    if(i < fila->tamanho) for(int k=fila->tamanho;k>i;k--) fila->paciente[k] = fila->paciente[k-1];
    fila->paciente[i] = *paciente;
    fila->tamanho++;
    return SUCESSO;
}

int pop_prioridade(prio * fila) {
    if(fila == NULL)
    {
        printf("Fila não alocada.\n");
        return FALHA;
    }
    if(fila_vazia(fila) == VERDADEIRO)
    {
        printf("Fila vazia. Não foi possível remover.\n");
        return FALHA;
    }

    fila->paciente[fila->tamanho].prioridade = INVALIDO;
    fila->tamanho--;
    return SUCESSO;
}

int consulta_frente(prio * fila) {
    if(fila == NULL)
    {
        printf("Fila de prioridade não alocada.\n");
        return FALHA;
    }

    printf("Primeiro elemento da fila:\n");
    printf("Paciente..: %s\n", fila->paciente[fila->tamanho-1].nome);
    printf("Prioridade: %d\n", fila->paciente[fila->tamanho-1].prioridade);
    return SUCESSO;
}

void destroi_fila(prio * fila) {
    if(fila == NULL)
    {
        printf("Fila não alocada.\n");
        exit(1);
    }

    free(fila);
}

int tamanho_fila(prio * fila) {
    if(fila == NULL)
    {
        printf("Fila não alocada.\n");
        return FALHA;
    }

    return fila->tamanho;
}

int fila_cheia(prio * fila) {
    if(fila == NULL)
    {
        printf("Fila não alocada.\n");
        return FALHA;
    }
    
    if(fila->tamanho < TAM_MAX_FILA) return FALSO;
    return VERDADEIRO;
}

int fila_vazia(prio * fila) {
    if(fila == NULL)
    {
        printf("Fila não alocada.\n");
        return FALHA;
    }
    
    if(fila->tamanho > 0) return FALSO;
    return VERDADEIRO;
}

int imprime_fila(prio * fila) {
    if(fila == NULL)
    {
        printf("Fila não alocada.\n");
        return FALHA;
    }
    if(fila_vazia(fila) == VERDADEIRO)
    {
        printf("Fila vazia.\n");
        return FALHA;
    }
    
    printf("\n");
    for(int i=fila->tamanho-1;i>=0;i--)
    {
        printf("Paciente..: %s\n", fila->paciente[i].nome);
        printf("Prioridade: %d\n", fila->paciente[i].prioridade);
        printf("\n");
    }

    return SUCESSO;
}