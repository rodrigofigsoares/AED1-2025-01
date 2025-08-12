# include "lista_est.h"
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

struct item {
    int valor, pos;
};

struct lista {
    Item * itens[10000000];
    int tamanho;
};

typedef struct {
    double time;
    int trades;
} statistics;

int limpar (Lista * LISTA) {
    if (LISTA == NULL) {
        return 0;
    }
    int i;
    for (i = 0; i < LISTA->tamanho; i++) {
        remover_elem_pos(LISTA, i);
    }
    return 1;
}

Lista * criar_lista () {
    Lista * LISTA = (Lista*)malloc(sizeof(Lista));
    if (LISTA == NULL) {
        exit (1);
    } 
    LISTA->tamanho = 0;
    return LISTA;
}

void mostrar_elemento(Item * ITEM) {
    printf("Chave : %d\n", ITEM->pos);
    printf("Dado : %d\n", ITEM->valor);
}

int adicionar_elem_final (Lista * LISTA, int ELEM) {
    if (LISTA == NULL) {
        return 0;
    }
    if (LISTA->tamanho > 25000) {
        return 0;
    }
    LISTA->itens[LISTA->tamanho] = (Item*)malloc(sizeof(Item));
    LISTA->itens[LISTA->tamanho]->valor = ELEM;
    LISTA->itens[LISTA->tamanho]->pos = LISTA->tamanho + 1;
    LISTA->tamanho++;
    return 1; 
}

int remover_elem_final (Lista * LISTA) {
    if (LISTA == NULL) {
        return 0;
    }
    int retorno = LISTA->itens[LISTA->tamanho - 1]->valor;
    free(LISTA->itens[LISTA->tamanho - 1]);
    LISTA->tamanho--;
    return retorno;
}

int adicionar_elem_inicio (Lista * LISTA, int ELEM) {
    if (LISTA == NULL) {
        return 0;
    }
    if (LISTA->tamanho > 25000) {
        return 0;
    }
    int i, tmp;
    LISTA->itens[LISTA->tamanho] = (Item*)malloc(sizeof(Item));
    for (i = 0; i < LISTA->tamanho; i++) {
        tmp = LISTA->itens[i + 1]->valor;
        LISTA->itens[i + 1]->valor = LISTA->itens[0]->valor;
        LISTA->itens[0]->valor = tmp;
        LISTA->itens[i + 1]->pos = i + 2;
    }
    LISTA->itens[0]->valor = ELEM;
    LISTA->itens[0]->pos = 1;
    LISTA->tamanho++;
    return 1;
}

int remover_elem_inicio (Lista * LISTA) {
    if (LISTA == NULL) {
        return 0;
    }
    int i, tmp, retorno = LISTA->itens[0]->valor;
    for (i = LISTA->tamanho - 1; i > 0; i--) {
        tmp = LISTA->itens[i - 1]->valor;
        LISTA->itens[i - 1]->valor = LISTA->itens[LISTA->tamanho - 1]->valor;
        LISTA->itens[LISTA->tamanho - 1]->valor = tmp;
        LISTA->itens[i - 1]->pos = i;
    }
    free(LISTA->itens[LISTA->tamanho - 1]);
    LISTA->tamanho--;
    return retorno;
}

int adicionar_elem_pos (Lista * LISTA, int ELEM, int index) {
    if (LISTA == NULL) {
        return 0;
    }
    if (LISTA->tamanho > 25000) {
        return 0;
    }
    if ((index < 0) || (index > LISTA->tamanho - 1)) {
        return 0;
    }
    int i, tmp;
    LISTA->itens[LISTA->tamanho] = (Item*)malloc(sizeof(Item));
    for (i = index; i < LISTA->tamanho + 1; i++) {
        tmp = LISTA->itens[i + 1]->valor;
        LISTA->itens[i + 1]->valor = LISTA->itens[index]->valor;
        LISTA->itens[index]->valor = tmp;
        LISTA->itens[i + 1]->pos = i + 2;
    }
    LISTA->itens[index]->valor = ELEM;
    LISTA->itens[index]->pos = index + 1;
    LISTA->tamanho++;
    return 1;
}

int remover_elem_pos (Lista * LISTA, int index) {
    if (LISTA == NULL) {
        return 0;
    }
    if ((index < 0) || (index > LISTA->tamanho - 1)) {
        return 0;
    }
    int i, tmp, retorno = LISTA->itens[index]->valor;
    for (i = LISTA->tamanho - 1; i > index; i--) {
        tmp = LISTA->itens[i - 1]->valor;
        LISTA->itens[i - 1]->valor = LISTA->itens[LISTA->tamanho - 1]->valor;
        LISTA->itens[LISTA->tamanho - 1]->valor = tmp;
        LISTA->itens[i - 1]->pos = i;
    }
    free(LISTA->itens[LISTA->tamanho - 1]);
    LISTA->tamanho--;
    return retorno;
}

int tamanho (Lista * LISTA) {
    return LISTA->tamanho;
} 

int vazia (Lista * LISTA) {
    if (LISTA->tamanho == 0) {
        return 1;
    } else {
        return 0;
    }
}

int primeiro (Lista * LISTA) {
    return LISTA->itens[0]->valor;
}

void print_1_n (Lista * LISTA) {
    int i;
    for (i = 0; i < LISTA->tamanho; i++) {
        printf("POSICAO = %d\n", i + 1);
        mostrar_elemento(LISTA->itens[i]);
        printf("-------------------------------------------------\n");
    }
}

void print_n_1 (Lista * LISTA) {
    int i, pos = 1;
    if (LISTA->tamanho == 0) {
        return;
    }
    for (i = LISTA->tamanho - 1; i >= 0; i--) {
        printf("POSICAO = %d\n", pos);
        mostrar_elemento(LISTA->itens[i]);
        printf("-------------------------------------------------\n");
        pos++;
    }
}

void quick_sort_numeros_cres (Lista * LISTA, int inicio, int fim, double * tempo_total, int * n_trocas) {
    if (inicio < fim) {
        int pivo = LISTA->itens[fim]->valor;
        clock_t t_inicio, t_final;
        t_inicio = clock();
        int i = inicio - 1, j, tmp;
        for (j = inicio; j <= fim - 1; j++) {
            if (LISTA->itens[j]->valor <= pivo) {
                (*n_trocas)++;
                i++;
                tmp = LISTA->itens[i]->valor;
                LISTA->itens[i]->valor = LISTA->itens[j]->valor;
                LISTA->itens[j]->valor = tmp;
            }
        }
        tmp = LISTA->itens[i + 1]->valor;
        LISTA->itens[i + 1]->valor = LISTA->itens[fim]->valor;
        LISTA->itens[fim]->valor = tmp;
        (*n_trocas)++;
        int partition_index = i + 1;
        t_final = clock();
        double tempo_gasto = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;
        (*tempo_total) += tempo_gasto;
        quick_sort_numeros_cres(LISTA, inicio, partition_index - 1, tempo_total, n_trocas);
        quick_sort_numeros_cres(LISTA, partition_index + 1, fim, tempo_total, n_trocas);
    }
}

void quick_sort_numeros_decr (Lista * LISTA, int inicio, int fim, double * tempo_total, int * n_trocas) {
   if (inicio < fim) {
        int pivo = LISTA->itens[fim]->valor;
        clock_t t_inicio, t_final;
        t_inicio = clock();
        int i = inicio - 1, j, tmp;
        for (j = inicio; j <= fim - 1; j++) {
            if (LISTA->itens[j]->valor >= pivo) {
                (*n_trocas)++;
                i++;
                tmp = LISTA->itens[i]->valor;
                LISTA->itens[i]->valor = LISTA->itens[j]->valor;
                LISTA->itens[j]->valor = tmp;
            }
        }
        tmp = LISTA->itens[i + 1]->valor;
        LISTA->itens[i + 1]->valor = LISTA->itens[fim]->valor;
        LISTA->itens[fim]->valor = tmp;
        (*n_trocas)++;
        int partition_index = i + 1;
        t_final = clock();
        double tempo_gasto = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;
        (*tempo_total) += tempo_gasto;
        quick_sort_numeros_decr(LISTA, inicio, partition_index - 1, tempo_total, n_trocas);
        quick_sort_numeros_decr(LISTA, partition_index + 1, fim, tempo_total, n_trocas);
    }
}

int adicionar_numero_de_lista_para_arquivo (Lista * LISTA, char * file_name) {
    if (LISTA == NULL) {
        return 0;
    }
    FILE * arq = fopen(file_name, "w");
    if (arq == NULL) {
        return 0;
    }
    int i;
    for (i = 0; i < LISTA->tamanho; i++) {
        fprintf(arq, "%d\n", LISTA->itens[i]->valor);
    }
    fclose(arq);
    return 1;
}

int adicionar_numero_de_arquivo_para_lista (char * file_name, Lista * LISTA) {
    if (LISTA == NULL) {
        return 0;
    }
    int i, num;
    FILE * arq = fopen(file_name, "r");
    if (arq == NULL) return 0;
    while (fscanf(arq, "%d", &num) == 1) {
        adicionar_elem_inicio(LISTA, num);
    }
    fclose(arq);
    return 1;
}

int generate_random_nums (unsigned long long int num_of_nums, char * name) {
    srand(5);
    int k = 0, signal;
    FILE * arq = fopen(name, "w");
    for (k = 0; k < num_of_nums; k++) {
        signal = rand() % 2;
        if (signal == 0) signal = -1;
        if (signal == 1) signal = 1;
        fprintf(arq, "%d\n", signal * (rand() % 10000));
    }
    fclose(arq);
    return 1;
}