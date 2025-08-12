#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"

// void printFuncoes() {
//     printf("0 - Encerrar o programa\n");
//     printf("1 - Criar um conjunto\n");
//     printf("2 - Verificar se um conjunto é vazio\n");
//     printf("3 - Incluir um elemento no conjunto\n");
//     printf("4 - Excluir um elemento do conjunto\n");
//     printf("5 - Calcular a cardinalidade do conjunto\n");
//     printf("6 - Determinar a quantidade de elementos do conjunto que são maiores que um valor informado\n");
//     printf("7 - Determinar a quantidade de elementos do conjunto que são menores que um valor informado\n");
//     printf("8 - Verificar se um elemento pertence a um conjunto\n");
//     printf("9 - Comparar se dois conjuntos são idênticos\n");
//     printf("10 - Identificar se um conjunto é subconjunto de outro\n");
//     printf("11 - Gerar o complemento de um conjunto\n");
//     printf("12 - Gerar a união de dois conjuntos\n");
//     printf("13 - Gerar a intersecção de dois conjuntos\n");
//     printf("14 - Gerar a diferença entre dois conjuntos\n");
//     printf("15 - Imprimir um conjunto\n");
//     printf("16 - Copiar um conjunto para outro\n");
//     printf("17 - DESTRUIR um conjunto\n");
//     printf("Informe o número da função que deseja usar: ");
// }

void alocaConjunto(Conjunto *** C) {
    *C = (Conjunto**)malloc(sizeof(Conjunto*));
}

int criaConjunto(Conjunto ** C) {
    *C = (Conjunto*)malloc(sizeof(Conjunto));
    (*C)->elementos = (unsigned long long int *)malloc(sizeof(unsigned long long int));
    if(*C == NULL) return FALHA;
    if((*C)->elementos == NULL) return FALHA;
    (*C)->tamanho = 0;
    return SUCESSO;
}

int conjuntoVazio(Conjunto ** C) {
    if((*C)->tamanho == 0) return TRUE;
    return FALSE;
}

int insereElementoConjunto(unsigned long long int elemento, Conjunto ** C) {
    int temp;
    if(*C == NULL) return FALHA;
    (*C)->tamanho++;
    temp = (*C)->tamanho;
    for(int i=0;i<(*C)->tamanho;i++) if(elemento == (*C)->elementos[i])
    {
        (*C)->tamanho--;
        return FALHA;
    }
    if((*C)->tamanho != 1 && temp != (*C)->tamanho) (*C)->elementos = realloc((*C)->elementos, temp*sizeof(int));
    if((*C)->elementos == NULL) return FALHA;
    (*C)->elementos[(*C)->tamanho-1] = elemento;
    return SUCESSO;
}

int excluirElementoConjunto(unsigned long long int elemento, Conjunto ** C) {
    int temp;
    if(*C == NULL) return FALHA;
    for(int i=0;i<(*C)->tamanho;i++) 
    {
        if(elemento == (*C)->elementos[i])
        {
            for(int j=i;j<(*C)->tamanho;j++) (*C)->elementos[j] = (*C)->elementos[j+1];
            (*C)->tamanho--;
            temp = (*C)->tamanho;
            (*C)->elementos = realloc((*C)->elementos, temp*sizeof(int));
            if((*C)->elementos == NULL) return FALHA;
            return SUCESSO;
        }
    }
    return FALHA;
}

int tamanhoConjunto(Conjunto ** C) {
    return (*C)->tamanho;
}

int maior(unsigned long long int elemento, Conjunto ** C) {
    int maior = 0;
    for(int i=0;i<(*C)->tamanho;i++) if(elemento < (*C)->elementos[i]) maior++;
    return maior;
}

int menor(unsigned long long int elemento, Conjunto ** C) {
    int menor = 0;
    for(int i=0;i<(*C)->tamanho;i++) if(elemento > (*C)->elementos[i]) menor++;
    return menor;
}

int pertenceConjunto(unsigned long long int elemento, Conjunto ** C) {
    for(int i=0;i<(*C)->tamanho;i++) if(elemento == (*C)->elementos[i]) return TRUE;
    return FALSE;
}

int conjuntosIdenticos(Conjunto ** C1, Conjunto ** C2) {
    int igual = 0, temp;
    if((*C1)->tamanho != (*C2)->tamanho) return FALSE;
    for(int i=0;i<(*C1)->tamanho;i++)
    {
        temp = igual;
        for(int j=0;j<(*C2)->tamanho;j++)
        {
            if((*C1)->elementos[i] == (*C2)->elementos[j]) 
            {
                igual++;
                j = (*C2)->tamanho;
            }
        }
        if(igual == temp) return FALSE;
    }
    return TRUE;
}

int subconjunto(Conjunto ** C1, Conjunto ** C2) {
    int igual = 0, temp;
    for(int i=0;i<(*C1)->tamanho;i++)
    {
        temp = igual;
        for(int j=0;j<(*C2)->tamanho;j++)
        {
            if((*C1)->elementos[i] == (*C2)->elementos[j]) 
            {
                igual++;
                j = (*C2)->tamanho;
            }
        }
        if(igual == temp) return FALSE;
    }
    return TRUE;
}

Conjunto ** complemento(Conjunto ** C1, Conjunto ** C2) {
    Conjunto ** Complemento;
    int result;
    char pertence;
    alocaConjunto(&Complemento);
    if(criaConjunto(Complemento) == SUCESSO)
    {
        for(int i=0;i<(*C2)->tamanho;i++)
        {
            pertence = 'n';
            for(int j=0;j<(*C1)->tamanho;j++) if((*C2)->elementos[i] == (*C1)->elementos[j]) 
            {
                pertence = 's';
                j = (*C1)->tamanho;
            }
            if(pertence == 'n') result = insereElementoConjunto((*C2)->elementos[i], Complemento);
        }
        return Complemento;
    }
}

Conjunto ** uniao(Conjunto ** C1, Conjunto ** C2) {
    Conjunto ** Uniao;
    alocaConjunto(&Uniao);
    if(criaConjunto(Uniao) == SUCESSO)
    {
        int i=0;
        while(1)
        {
            if(i == (*C1)->tamanho) break;
            if(insereElementoConjunto((*C1)->elementos[i], Uniao) == SUCESSO) i++;
        }
        if(conjuntosIdenticos(C1, C2) == TRUE) return Uniao;
        if(subconjunto(C2, C1) == TRUE) return Uniao;
        Conjunto ** Complemento;
        alocaConjunto(&Complemento);
        if(criaConjunto(Complemento) == SUCESSO) Complemento = complemento(C1, C2);
        i = 0;
        while(1)
        {
            if(i == (*Complemento)->tamanho) break;
            if(insereElementoConjunto((*Complemento)->elementos[i], Uniao) == SUCESSO) i++;
        }
        return Uniao;
    }
}

Conjunto ** interseccao(Conjunto ** C1, Conjunto ** C2) {
    Conjunto ** Interseccao;
    char pertence;
    int result;
    alocaConjunto(&Interseccao);
    if(criaConjunto(Interseccao) == SUCESSO)
    {
        for(int i=0;i<(*C1)->tamanho;i++)
        {
            pertence = 'n';
            for(int j=0;j<(*C2)->tamanho;j++)
            {
                if((*C1)->elementos[i] == (*C2)->elementos[j]) 
                {
                    pertence = 's';
                    j = (*C2)->tamanho;
                }
                if(pertence == 's') result = insereElementoConjunto((*C1)->elementos[i], Interseccao);
            }
        }
        return Interseccao;
    }
}

Conjunto ** diferenca(Conjunto ** C1, Conjunto ** C2) {
    Conjunto ** Diferenca;
    char pertence;
    int result;
    alocaConjunto(&Diferenca);
    if(criaConjunto(Diferenca) == SUCESSO)
    {
        for(int i=0;i<(*C1)->tamanho;i++)
        {
            pertence = 's';
            for(int j=0;j<(*C2)->tamanho;j++)
            {
                if((*C1)->elementos[i] == (*C2)->elementos[j])
                {
                    pertence = 'n';
                    j = (*C2)->tamanho;
                }
            }
            if(pertence == 's') result = insereElementoConjunto((*C1)->elementos[i], Diferenca);
        }
        if(conjuntosIdenticos(C1, C2) == TRUE) return Diferenca;
        if(subconjunto(C2, C1) == TRUE) return Diferenca;

        Conjunto ** Complemento;
        alocaConjunto(&Complemento);
        if(criaConjunto(Complemento) == SUCESSO)
        {
            Complemento = complemento(C1, C2);
            for(int i=0;i<(*Complemento)->tamanho;i++) result = insereElementoConjunto((*Complemento)->elementos[i], Diferenca);
        }
        return Diferenca;
    }
}

void ordenaConjunto(Conjunto ** C) {
    unsigned long long int menor, temp, id_menor;
    for(int i=0;i<(*C)->tamanho;i++)
    {
        menor = (*C)->elementos[i];
        id_menor = i;
        for(int j=i+1;j<(*C)->tamanho;j++) 
        {
            if((*C)->elementos[j] < menor) 
            {
                menor = (*C)->elementos[j];
                id_menor = j;
            }
        }
        temp = (*C)->elementos[i];
        (*C)->elementos[i] = menor;
        (*C)->elementos[id_menor] = temp;
    }
}

void mostraConjunto(Conjunto ** C, int ordem) {
    ordenaConjunto(C);
    printf("{");
    if(ordem == CRESCENTE)
    {
        for(int i=0;i<(*C)->tamanho;i++)
        {
            if(i < (*C)->tamanho - 1) printf("%llu, ", (*C)->elementos[i]);
            else printf("%llu}\n", (*C)->elementos[i]);
        }
    }
    if(ordem == DECRESCENTE)
    {
        for(int i=(*C)->tamanho-1;i>=0;i--)
        {
            if(i > 0) printf("%llu, ", (*C)->elementos[i]);
            else printf("%llu}\n", (*C)->elementos[i]);
        }
    }
}

int copiarConjunto(Conjunto ** C1, Conjunto ** C2) {
    for(int i=0;i<(*C1)->tamanho;i++) if(insereElementoConjunto((*C1)->elementos[i], C2) == FALHA) return FALHA;
    return SUCESSO;
}

int destroiConjunto(Conjunto ** C) {
    free((*C)->elementos);
    free(*C);
    free(C);
}