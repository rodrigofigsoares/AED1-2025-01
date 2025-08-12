#include <stdio.h>
#include <stdlib.h>
#include "banco.h"

struct Elemento {
    patient paciente;
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
    printf("Nome do paciente..: %s\n", queue->inicio->paciente.nome);
    printf("Código do paciente: %d\n", queue->inicio->paciente.codigo);
    return SUCESSO;
}

int push(fila * queue, patient paciente) {
    if(queue == NULL)
    {
        printf("Fila não alocada.\n");
        return FALHA;
    }
    
    elemento * no = (elemento*)malloc(sizeof(elemento));
    no->paciente = paciente;
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
    printf("Paciente %s, código %d, por favor entrar no consultório.\n", no->paciente.nome, no->paciente.codigo);
    free(no);
    queue->tamanho--;
    if(queue->inicio == NULL) queue->final = NULL; // fila ficou vazia
    return SUCESSO;
}

int quantidade_pacientes(fila * queue) {
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

int lista_pacientes(fila * queue) {
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
        printf("--------------------------------------------\n");
        printf("Nome do paciente..: %s\n", no->paciente.nome);
        printf("Código do paciente: %d\n", no->paciente.codigo);
        no = no->prox;
    }
    printf("--------------------------------------------\n");
    return SUCESSO;
}

int tempo_espera(fila * queue) {
    if(queue == NULL)
    {
        printf("Fila não alocada.\n");
        return FALHA;
    }

    if(fila_vazia(queue) == VERDADEIRO) printf("Há 0 pacientes na fila e tempo de espera é de 0 minutos.\n");
    else printf("Há %d pacientes na fila e o tempo de espera é de %d minutos.\n", quantidade_pacientes(queue), quantidade_pacientes(queue)*10);
    
    return SUCESSO;
}