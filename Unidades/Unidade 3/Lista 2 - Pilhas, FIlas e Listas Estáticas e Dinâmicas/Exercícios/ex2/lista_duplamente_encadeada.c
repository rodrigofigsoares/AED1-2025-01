#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_duplamente_encadeada.h"

struct Elemento {
    int num;
    struct Elemento * prox;
    struct Elemento * ant;
};

typedef struct Elemento elemento;

lista * concebe_lista() {
    lista * list = (lista*)malloc(sizeof(lista));
    if(list == NULL)
    {
        printf("Falha ao alocar a lista.\n");
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

    *list = NULL;
}

void destroi_lista(lista * list) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        exit(1);
    }

    elemento * no;
    while(1)
    {
        no = *list;
        if(no == NULL) break;
        *list = (*list)->prox;
        free(no);
    }
    free(list);
}

int push(lista * list, int num) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }

    elemento * no = (elemento*)malloc(sizeof(elemento));
    no->num = num;
    if(lista_vazia(list) == VERDADEIRO)
    {
        *list = no;
        no->prox = NULL;
        no->ant = NULL;
    }
    else
    {
        elemento * temp = *list;
        elemento * aux;
        while(1)
        {
            if(temp->num > no->num)
            {
                if(temp == *list)
                {
                    temp->ant = no;
                    no->prox = temp;
                    no->ant = NULL;
                }
                else
                {
                    aux = temp;
                    temp = temp->ant;

                    temp->prox = no;
                    no->ant = temp;
                    no->prox = aux;
                    aux->ant = no;
                }
                break;
            }
            else if(temp->prox == NULL)
            {
                temp->prox = no;
                no->ant = temp;
                no->prox = NULL;
                break;
            }
            else temp = temp->prox;
        }
    }
    return SUCESSO;
}

int pop(lista * list) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }

    int remove_type;
    printf("Como o elemento deve ser removido?\n");
    printf("|\n");
    printf("| 0 - Início\n");
    printf("| 1 - Específico\n");
    printf("| 2 - Final\n");
    printf("|\n");
    printf("Resposta: ");
    scanf("%d", &remove_type);
    if(remove_type == 0)
    {
        if(pop_inicio(list) == SUCESSO) printf("Elemento removido do início.\n");
    }
    else if(remove_type == 1)
    {
        int num;
        printf("Informe o número que será removido da lista: ");
        scanf("%d", &num);
        if(pop_especifico(list, num) == SUCESSO) printf("Número %d removido.\n", num);
    }
    else if(remove_type == 2)
    {
        if(pop_final(list) == SUCESSO) printf("Elemento removido do final.\n");
    }
    return SUCESSO;
}

int pop_inicio(lista * list) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_vazia(list) == VERDADEIRO)
    {
        printf("Lista vazia.\n");
        return FALHA;
    }

    elemento * no = *list;
    if(tamanho_lista(list) == 1)
    {
        *list = NULL;
    }
    else
    {
        *list = (*list)->prox;
        (*list)->ant = NULL;
    }
    free(no);
    return SUCESSO;
}

int pop_final(lista * list) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_vazia(list) == VERDADEIRO)
    {
        printf("Lista vazia.\n");
        return FALHA;
    }

    elemento * no = *list;
    if(tamanho_lista(list) == 1)
    {
        *list = NULL;
        free(no);
    }
    else
    {
        elemento * temp;
        while(1)
        {
            if(no->prox == NULL) break;
            no = no->prox;
        }
        temp = no->ant;
        temp->prox = NULL;
        free(no);
    }
    return SUCESSO;
}

int pop_especifico(lista * list, int num) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_vazia(list) == VERDADEIRO)
    {
        printf("Lista vazia.\n");
        return FALHA;
    }

    elemento * no = *list;
    if(no->num == num)
    {
        *list = (*list)->prox;
        (*list)->ant = NULL;
        free(no);
    }
    else
    {
        while(1)
        {
            if(no->num == num)
            {
                elemento * temp;
                if(no->prox == NULL)
                {
                    temp = no;
                    no = no->ant;
                    no->prox = NULL;
                    free(temp);
                }
                else
                {
                    elemento * aux = no;
                    temp = no->prox;
                    no = no->ant;
                    no->prox = temp;
                    temp->ant = no;
                    free(aux);
                }
                
            }
            no = no->prox;
            if(no == NULL)
            {
                printf("Elemento não presente na lista.\n");
                return FALHA;
            }
        }
    }
    return SUCESSO;
}

int lista_vazia(lista * list) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }

    if(*list == NULL) return VERDADEIRO;
    else return FALSO;
}

int lista_cheia(lista * list) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }

    return FALSO; // o tamanho máximo é o limite da memória do computador
}

int tamanho_lista(lista * list) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }

    int tamanho = 0;
    if(lista_vazia(list) == VERDADEIRO) return tamanho;
    elemento * no = *list;
    while(1)
    {
        if(no == NULL) break;
        no = no->prox;
        tamanho++;
    }
    return tamanho;
}

int consulta_elemento(lista * list) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_vazia(list) == VERDADEIRO)
    {
        printf("Lista vazia.\n");
        return FALHA;
    }


    int num;
    printf("Informe o elemento que deve ser consultado: ");
    scanf("%d%*c", &num);
    elemento * no = *list;
    while(1)
    {
        if(no->num == num)
        {
            printf("-------------------------------------------\n");
            printf("Número....: %d\n", no->num);
            printf("Sucessor..: %d\n", no->prox->num);
            printf("Antecessor: %d\n", no->ant->num);
            printf("-------------------------------------------\n");
            break;
        }
        no = no->prox;
        if(no == NULL)
        {
            printf("Elemento não presente na lista.\n");
            return FALHA;
        }
    }
    return SUCESSO;
}

int imprime_lista(lista * list) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_vazia(list) == VERDADEIRO)
    {
        printf("Lista vazia.\n");
        return FALHA;
    }

    elemento * no = *list;
    while(1)
    {
        printf("-------------------------\n");
        printf("NÚMERO: %d\n", no->num);
        no = no->prox;
        if(no == NULL)
        {
            printf("-------------------------\n");
            break;
        }
    }
    return SUCESSO;
}