#include <stdio.h>
#include <stdlib.h>
#include "lista_estatica.h"

struct Lista {
    int tamanho;
    student aluno[TAM_MAX_LISTA];
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

int push_inicio(lista * list, student * aluno) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_cheia(list) == VERDADEIRO) return FALHA;

    for(int i=list->tamanho;i>0;i--) list->aluno[i] = list->aluno[i-1];
    list->aluno[0] = *aluno;
    list->tamanho++;
    return SUCESSO;
}

int push_ordenado(lista * list, student * aluno) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_cheia(list) == VERDADEIRO) return FALHA;

    int i;
    for(i=0;i<tamanho_lista(list);i++)
    {
        if(list->aluno[i].matricula < aluno->matricula)
        {
            for(int k=tamanho_lista(list);k>i;k--)
            {
                list->aluno[k] = list->aluno[k-1];
            }
            list->aluno[i] = *aluno;
            break;
        }
    }
    if(i == tamanho_lista(list)) list->aluno[list->tamanho] = *aluno;
    list->tamanho++;
    return SUCESSO;
}

int push_final(lista * list, student * aluno) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_cheia(list) == VERDADEIRO) return FALHA;

    list->aluno[list->tamanho] = *aluno;
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

    for(int i=0;i<list->tamanho-1;i++) list->aluno[i] = list->aluno[i+1];
    list->tamanho--;
    return SUCESSO;
}

int pop_especifico(lista * list, int matricula) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_vazia(list) == VERDADEIRO) return FALHA;

    int i;
    for(i=0;i<tamanho_lista(list);i++)
    {
        if(list->aluno[i].matricula == matricula)
        {
            for(int k=i;k<tamanho_lista(list)-1;k++)
            {
                list->aluno[k] = list->aluno[k+1];
            }
        }
        break;
    }
    if(i == tamanho_lista(list))
    {
        printf("Elemento não presente na lista.\n");
        return FALHA;
    }
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

    list->aluno[list->tamanho-1].matricula = MATRICULA_INVALIDA;
    list->tamanho--;
    return SUCESSO;
}

int consulta_por_matricula(lista * list, int matricula) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_vazia(list) == VERDADEIRO) return FALHA;

    int i;
    for(i=0;i<tamanho_lista(list);i++)
    {
        if(list->aluno[i].matricula == matricula)
        {
            printf("Nome do aluno.....: %s\n", list->aluno[i].nome);
            printf("Matrícula do aluno: %d\n", list->aluno[i].matricula);
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
    if(lista_vazia(list) == VERDADEIRO) return FALHA;

    int i;
    for(i=0;i<list->tamanho;i++)
    {
        printf("-------------------------------------------------------\n");
        printf("Nome do aluno.....: %s\n", list->aluno[i].nome);
        printf("Matrícula do aluno: %d\n", list->aluno[i].matricula);
    }
    if(i == tamanho_lista(list)) printf("-------------------------------------------------------\n");
    return SUCESSO;
}

int remove_n_primeiros(lista * list, int qtd) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_vazia(list) == VERDADEIRO) return FALHA;

    int contador = 1;
    if(qtd > tamanho_lista(list))
    {
        int continua;
        printf("Você está tentando remover mais elementos do que a quantidade presente na lista.\n");
        printf("Se você continuar com a operação, todos os elementos serão removidos da lista.\n");
        printf("Deseja continuar? (Digite 1 para sim e 0 para não): ");
        scanf("%d", &continua);
        if(continua == 0) return FALHA;
        else
        {
            for(int i=0;i<tamanho_lista(list);i++)
            {
                if(pop_inicio(list) == SUCESSO)
                {
                    printf("Elementos removidos: %d/%d\n", contador, qtd);
                    contador++;
                }
            }
        }
    }
    else
    {
        for(int i=0;i<qtd;i++)
        {
            if(pop_inicio(list) == SUCESSO)
            {
                printf("Elementos removidos: %d/%d", contador, qtd);
                contador++;
            }
        }
    }
    return SUCESSO;
}

int remove_n_ultimos(lista * list, int qtd) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }
    if(lista_vazia(list) == VERDADEIRO) return FALHA;

    int contador = 1;
    if(qtd > tamanho_lista(list))
    {
        int continua;
        printf("Você está tentando remover mais elementos do que a quantidade presente na lista.\n");
        printf("Se você continuar com a operação, todos os elementos serão removidos da lista.\n");
        printf("Deseja continuar? (Digite 1 para sim e 0 para não): ");
        scanf("%d", &continua);
        if(continua == 0) return FALHA;
        else
        {
            for(int i=0;i<tamanho_lista(list);i++)
            {
                if(pop_final(list) == SUCESSO)
                {
                    printf("Elementos removidos: %d/%d\n", contador, qtd);
                    contador++;
                }
            }
        }
    }
    else
    {
        for(int i=0;i<qtd;i++)
        {
            if(pop_final(list) == SUCESSO)
            {
                printf("Elementos removidos: %d/%d\n", contador, qtd);
                contador++;
            }
        }
    }
    return SUCESSO;
}