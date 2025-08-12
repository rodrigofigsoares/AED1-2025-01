#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

struct Elemento {
    product prod;
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

int push(lista * list, product prod) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }

    int insert_type;
    while(1)
    {
        printf("Como esse elemento deve ser inserido?\n");
        printf("|\n");
        printf("| 0 - Início\n");
        printf("| 1 - Meio\n");
        printf("| 2 - Final\n");
        printf("|\n");
        printf("Resposta: ");
        scanf("%d%*c", &insert_type);
        if(insert_type == 0 || insert_type == 1 || insert_type == 2) break;
        printf("Valor inválido. Tente novamente.\n");
    }

    if(insert_type == 0)
    {
        if(push_inicio(list, prod) == SUCESSO) printf("Elemento inserido no início.\n");
    }
    else if(insert_type == 1)
    {
        if(push_ordenado(list, prod) == SUCESSO) printf("Elemento inserido no meio.\n");
    }
    else if(insert_type == 2)
    {
        if(push_final(list, prod) == SUCESSO) printf("Elemento inserido no final.\n");
    }
    return SUCESSO;
}

int push_inicio(lista * list, product prod) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }

    elemento * no = (elemento*)malloc(sizeof(elemento));
    no->prod = prod;
    if(lista_vazia(list) == VERDADEIRO)
    {
        *list = no;
        no->prox = NULL;
    }
    else
    {
        no->prox = *list;
        *list = no;
    }
    return SUCESSO;
}

int push_final(lista * list, product prod) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }

    elemento * no = (elemento*)malloc(sizeof(elemento));
    no->prod = prod;
    no->prox = NULL;
    if(lista_vazia(list) == VERDADEIRO) *list = no;
    else
    {
        elemento * temp = *list;
        while(1)
        {
            if(temp->prox == NULL) break;
            temp = temp->prox;
        }
        temp->prox = no;
    }
    return SUCESSO;
}

int push_ordenado(lista * list, product prod) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }

    elemento * no = (elemento*)malloc(sizeof(elemento));
    no->prod = prod;
    if(lista_vazia(list) == VERDADEIRO)
    {
        *list = no;
        no->prox = NULL;
    }
    else
    {
        elemento * temp = *list;
        elemento * aux = NULL;
        while(1)
        {
            if(temp->prox != NULL)
            {
                if(no->prod.codigo < temp->prox->prod.codigo && aux == NULL) aux = temp;
            }
            if(no->prod.codigo < temp->prod.codigo)
            {
                no->prox = temp;
                aux->prox = no;
                break;
            }
            temp = temp->prox;
            if(temp == NULL)
            {
                temp = no;
                no->prox = NULL;
                break;
            }
        }
    }
    return SUCESSO;
}

int pop(lista * list, int codigo) {
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
    if(no->prod.codigo == codigo)
    {
        *list = (*list)->prox;
        free(no);
    }
    else
    {
        while(1)
        {
            if(no->prox->prod.codigo == codigo)
            {
                elemento * temp = no->prox;
                no->prox = temp->prox;
                free(temp);
                break;
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

int consulta_produto(lista * list, int codigo) {
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
        if(no->prod.codigo == codigo)
        {
            printf("-------------------------------------------\n");
            printf("Nome do produto......: %s\n", no->prod.nomeProd);
            printf("Código do produto....: %d\n", no->prod.codigo);
            printf("Preço do produto.....: %.2f\n", no->prod.preco);
            printf("Quantidade em estoque: %d\n", no->prod.qtd);
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
       printf("-------------------------------------------\n");
        printf("Nome do produto.....: %s\n", no->prod.nomeProd);
        printf("Código do produto...: %d\n", no->prod.codigo);
        no = no->prox;
        if(no == NULL)
        {
            printf("-------------------------------------------\n");
            break;
        }
    }
    return SUCESSO;
}

int cadastra_produto(lista * list) {
    if(list == NULL)
    {
        printf("Lista não alocada.\n");
        return FALHA;
    }

    product prod;
    printf("Informe o nome do produto: ");
    scanf("%[^\n]%*c", prod.nomeProd);
    printf("Informe o código do produto: ");
    scanf("%d", &prod.codigo);
    printf("Informe o preço da unidade do produto: ");
    scanf("%f", &prod.preco);
    printf("Informe quantos itens desse produto há em estoque inicialmente: ");
    scanf("%d", &prod.qtd);

    if(push(list, prod) == SUCESSO) printf("SUCESSO.\n");
    else printf("FALHA.\n");

    return SUCESSO;
}

int mais_barato(lista * list) {
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
    float menor = no->prod.preco;
    while(1)
    {
        if(no->prod.preco < menor)
        {
            menor = no->prod.preco;
            temp = no;
        }
        no = no->prox;
        if(no == NULL) break;
    }

    printf("Produto de menor preço:\n");
    printf("Nome do produto......: %s\n", temp->prod.nomeProd);
    printf("Código do produto....: %d\n", temp->prod.codigo);
    printf("Preço da unidade.....: %.2f\n", temp->prod.preco);
    printf("Quantidade em estoque: %d\n", temp->prod.qtd);

    return SUCESSO;
}

int atualizar_estoque(lista * list) {
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

    int codigo;
    printf("Informe o código do produto cujo estoque será atualizado: ");
    scanf("%d", &codigo);    
    elemento * no = *list;
    while(1)
    {
        if(no->prod.codigo == codigo) break;
        no = no->prox;
        if(no == NULL)
        {
            printf("Código inexistente.\n");
            return FALHA;
        }
    }

    int operation;
    while(1)
    {
        printf("Desejar atualizar uma adição ou uma remoção de produtos do estoque?\n");
        printf("|\n");
        printf("| 0 - Adição\n");
        printf("| 1 - Remoção\n");
        printf("|\n");
        printf("Resposta: ");
        scanf("%d", &operation);
        if(operation == 0 || operation == 1) break;
        printf("Valor inválido. Tente novamente.\n");
    }
    int qtd;
    if(operation == 0)
    {
        printf("Informe quantos itens serão adicionados ao estoque do produto: ");
        scanf("%d", &qtd);
        no->prod.qtd += qtd;
    }
    else if(operation == 1)
    {
        printf("Informe quantos itens serão removidos do estoque do produto: ");
        while(1)
        {
            scanf("%d", &qtd);
            if(qtd > no->prod.qtd)
            {
                printf("Não é possível remover %d itens do estoque. Há apenas %d itens em estoque.\n", qtd, no->prod.qtd);
                printf("Tente novamente: ");
            }
            else break;
        }
        no->prod.qtd -= qtd;
    }
    
    return SUCESSO;
}