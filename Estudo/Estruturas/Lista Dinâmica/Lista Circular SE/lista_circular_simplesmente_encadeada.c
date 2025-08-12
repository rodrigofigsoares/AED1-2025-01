#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_circular_simplesmente_encadeada.h"

struct Elemento {
    student aluno;
    struct Elemento * prox;
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

    elemento * no = *list;
    elemento * temp;
    while(1)
    {
        if(no->prox == *list) break;
        temp = no;
        no = no->prox;
        free(temp);
    }
    free(no);
    free(list);
}

int push(lista * list, student aluno) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }

    int insert_type;
    printf("Como esse elemento deve ser inserido?\n");
    printf("|\n");
    printf("| 0 - Início\n");
    printf("| 1 - Meio\n");
    printf("| 2 - Final\n");
    printf("|\n");
    printf("Resposta: ");
    scanf("%d%*c", &insert_type);
    if(insert_type == 0)
    {
        if(push_inicio(list, aluno) == SUCESSO) printf("Elemento inserido no início.\n");
    }
    else if(insert_type == 1)
    {
        if(push_ordenado(list, aluno) == SUCESSO) printf("Elemento inserido no meio.\n");
    }
    else if(insert_type == 2)
    {
        if(push_final(list, aluno) == SUCESSO) printf("Elemento inserido no final.\n");
    }
    return SUCESSO;
}

int push_inicio(lista * list, student aluno) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }

    elemento * no = (elemento*)malloc(sizeof(elemento));
    no->aluno = aluno;
    if(lista_vazia(list) == VERDADEIRO)
    {
        *list = no;
        (*list)->prox = *list;
    }
    else
    {
        no->prox = *list;
        elemento * temp = *list;
        while(1)
        {
            if(temp->prox == *list) break;
            temp = temp->prox;
        }
        temp->prox = no;
        *list = no;
    }
    return SUCESSO;
}

int push_final(lista * list, student aluno) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }

    elemento * no = (elemento*)malloc(sizeof(elemento));
    no->aluno = aluno;
    no->prox = *list;
    if(lista_vazia(list) == VERDADEIRO)
    {
        *list = no;
        (*list)->prox = *list;
    }
    else
    {
        elemento * temp = *list;
        while(1)
        {
            if(temp->prox == *list) break;
            temp = temp->prox;
        }
        temp->prox = no;
    }
    return SUCESSO;
}

int push_ordenado(lista * list, student aluno) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }

    elemento * no = (elemento*)malloc(sizeof(elemento));
    no->aluno = aluno;
    if(lista_vazia(list) == VERDADEIRO)
    {
        *list = no;
        (*list)->prox = *list;
    }
    else
    {
        elemento * temp = *list;
        if(no->aluno.matricula < (*list)->aluno.matricula) (void)push_inicio(list, aluno);
        else
        {
            while(1)
            {
                if(no->aluno.matricula < temp->prox->aluno.matricula || temp->prox == *list)
                {
                    if(temp->prox == *list) (void)push_final(list, aluno);
                    else
                    {
                        no->prox = temp->prox;
                        temp->prox = no;
                    }
                    break;
                }
                else temp = temp->prox;
            }
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
        if(tamanho_lista(list) == 1)
        {
            *list = NULL;
            return SUCESSO;
            printf("Elemento removido do início.\n");
        }
        else if(pop_inicio(list) == SUCESSO) printf("Elemento removido do início.\n");
    }
    else if(remove_type == 1)
    {
        int matricula;
        printf("Informe a matrícula do aluno que será removido da lista: ");
        scanf("%d", &matricula);
        if(pop_especifico(list, matricula) == SUCESSO) printf("Matrícula %d removida.\n", matricula);
    }
    else if(remove_type == 2)
    {
        if(tamanho_lista(list) == 1)
        {
            *list = NULL;
            return SUCESSO;
            printf("Elemento removido do final.\n");
        }
        else if(pop_final(list) == SUCESSO) printf("Elemento removido do final.\n");
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
    elemento * temp = *list;
    while(1)
    {
        if(temp->prox == *list) break;
        temp = temp->prox;
    }
    temp->prox = (*list)->prox;
    *list = (*list)->prox;
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
    elemento * temp;
    while(1)
    {
        if(no->prox->prox == *list) break;
        no = no->prox;
    }
    temp = no->prox;
    no->prox = *list;
    free(temp);
    return SUCESSO;
}

int pop_especifico(lista * list, int matricula) {
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
    elemento * temp;
    while(1)
    {
        if(no->prox->aluno.matricula == matricula) break;
        no = no->prox;
        if(no == *list)
        {
            printf("Elemento não presente na lista.\n");
            return FALHA;
        }
    }
    temp = no->prox;
    no->prox = temp->prox;
    if(temp == *list) *list = temp->prox;
    free(temp);
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
        no = no->prox;
        tamanho++;
        if(no == *list) break;
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


    int consult_type;
    printf("Como o elemento deve ser consultado?\n");
    printf("|\n");
    printf("| 0 - Matrícula\n");
    printf("| 1 - Nome\n");
    printf("| 2 - Posição\n");
    printf("|\n");
    printf("Resposta: ");
    scanf("%d%*c", &consult_type);
    if(consult_type == 0)
    {
        int matricula;
        printf("Informe a matrícula do aluno: ");
        scanf("%d", &matricula);
        if(consulta_por_matricula(list, matricula) == SUCESSO) printf("Matrícula consultada.\n");
        else printf("Matrícula não consultada.\n");
    }
    else if(consult_type == 1)
    {
        char nome[50];
        printf("Informe o nome do aluno: ");
        scanf("%[^\n]%*c", nome);
        if(consulta_por_nome(list, nome) == SUCESSO) printf("Nome consultado.\n");
        else printf("Nome não consultado.\n");
    }
    else if(consult_type == 2)
    {
        int position;
        printf("Informe a posição do aluno na lista: ");
        scanf("%d", &position);
        if(consulta_por_posicao(list, position) == SUCESSO) printf("Posição consultada.\n");
        else printf("Posição não consultado.\n");
    }
    return SUCESSO;
}

int consulta_por_matricula(lista * list, int matricula) {
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
    int pos = 1;
    while(1)
    {
        if(no->aluno.matricula == matricula)
        {
            printf("-------------------------------------------\n");
            printf("Nome do aluno.....: %s\n", no->aluno.nome);
            printf("Matrícula do aluno: %d\n", no->aluno.matricula);
            printf("Posição na lista..: %d\n", pos);
            printf("-------------------------------------------\n");
            break;
        }
        no = no->prox;
        pos++;
        if(no == *list)
        {
            printf("Elemento não presente na lista.\n");
            return FALHA;
        }
    }
    return SUCESSO;
}

int consulta_por_nome(lista * list, char * nome) {
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
    int pos = 1;
    while(1)
    {
        if(strcmp(no->aluno.nome, nome) == 0)
        {
            printf("-------------------------------------------\n");
            printf("Nome do aluno.....: %s\n", no->aluno.nome);
            printf("Matrícula do aluno: %d\n", no->aluno.matricula);
            printf("Posição na lista..: %d\n", pos);
            printf("-------------------------------------------\n");
            break;
        }
        no = no->prox;
        pos++;
        if(no == *list)
        {
            printf("Elemento não presente na lista.\n");
            return FALHA;
        }
    }
    return SUCESSO;
}

int consulta_por_posicao(lista * list, int position) {
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
    int pos = 1;
    if(position > tamanho_lista(list))
    {
        printf("Posição fora da lista.\n");
        return FALHA;
    }
    while(1)
    {
        if(pos == position)
        {
            printf("-------------------------------------------\n");
            printf("Nome do aluno.....: %s\n", no->aluno.nome);
            printf("Matrícula do aluno: %d\n", no->aluno.matricula);
            printf("Posição na lista..: %d\n", pos);
            printf("-------------------------------------------\n");
            break;
        }
        no = no->prox;
        pos++;
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
    int pos = 1;
    while(1)
    {
        printf("-------------------------------------------\n");
        printf("Nome do aluno.....: %s\n", no->aluno.nome);
        printf("Matrícula do aluno: %d\n", no->aluno.matricula);
        printf("Posição na lista..: %d\n", pos);

        pos++;
        no = no->prox;
        if(no == *list)
        {
            printf("-------------------------------------------\n");
            break;
        }
    }
    return SUCESSO;
}