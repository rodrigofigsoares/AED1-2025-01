#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lista_estatica.h"

struct Lista {
    int tamanho;
    int elementos[TAM_MAX_LISTA];
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

int push_inicio(lista * list, int num) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_cheia(list) == VERDADEIRO) return FALHA;

    for(int i=list->tamanho;i>0;i--) list->elementos[i] = list->elementos[i-1];
    list->elementos[0] = num;
    list->tamanho++;
    return SUCESSO;
}

int push_ordenado(lista * list, int num) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_cheia(list) == VERDADEIRO) return FALHA;

    for(int i=0;i<tamanho_lista(list);i++)
    {
        if(list->elementos[i] > num)
        {
            for(int k=tamanho_lista(list);k>i;k--) list->elementos[k] = list->elementos[k-1];
            list->elementos[i] = num;
            break;
        }
    }

    list->tamanho++;
    return SUCESSO;
}

int push_final(lista * list, int num) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_cheia(list) == VERDADEIRO) return FALHA;

    list->elementos[list->tamanho] = num;
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

    for(int i=0;i<list->tamanho-1;i++) list->elementos[i] = list->elementos[i+1];
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

    int num;
    int i = 0;
    printf("Informe o número que deve ser removido: ");
    scanf("%d", &num);
    for(int i=0;i<tamanho_lista(list);i++)
    {
        if(list->elementos[i] == num)
        {
            for(int k=i;k<list->tamanho-1;k++) list->elementos[k] = list->elementos[k+1];
        }
    }
    if(i == list->tamanho) return FALHA;
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

    list->tamanho--;
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
        printf("Elemento...: %d\n", list->elementos[i]);
    }
    return SUCESSO;
}

int quantidade_pares(lista * list) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_vazia(list) == VERDADEIRO) return FALHA;

    int pares = 0;
    for(int i=0;i<tamanho_lista(list);i++) if((list->elementos[i])%2 == 0) pares++;

    return pares;
}

float media_elementos(lista * list) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_vazia(list) == VERDADEIRO) return FALHA;

    int soma = somatorio_elementos(list);
    float media = (1.0*soma)/tamanho_lista(list);

    return media;
}

int maior_elemento(lista * list) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_vazia(list) == VERDADEIRO) return FALHA;

    int maior = list->elementos[0];
    for(int i=1;i<tamanho_lista(list);i++) if((list->elementos[i]) > maior) maior = list->elementos[i];

    return maior;
}

int menor_elemento(lista * list) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_vazia(list) == VERDADEIRO) return FALHA;

    int menor = list->elementos[0];
    for(int i=1;i<tamanho_lista(list);i++) if((list->elementos[i]) < menor) menor = list->elementos[i];

    return menor;
}

int somatorio_elementos(lista * list) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_vazia(list) == VERDADEIRO) return FALHA;

    float soma = 0;
    for(int i=0;i<tamanho_lista(list);i++) soma += list->elementos[i];

    return soma;
}

int qtd_primos(lista * list) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_vazia(list) == VERDADEIRO) return FALHA;

    int primos = 0;
    for(int i=0;i<tamanho_lista(list);i++) if(verifica_primo(list->elementos[i]) == VERDADEIRO) primos++;

    return primos;
}

int verifica_primo(int num) {
    for(int i=2;i<=sqrt(num);i++) if(num%i == 0) return FALSO;

    return VERDADEIRO;
}