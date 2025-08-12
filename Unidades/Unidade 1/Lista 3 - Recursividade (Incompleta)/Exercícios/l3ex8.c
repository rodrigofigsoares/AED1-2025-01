#include <stdio.h>
#include <stdlib.h>

int contagem_familias(int ** pessoas, int qtd_pessoas, int qtd_familias, int i, int j);

int main() {
    int qtd_pessoas, qtd_entradas, pessoa1, pessoa2, qtd_familias = 0;
    scanf("%d%d", &qtd_pessoas, &qtd_entradas);
    int ** pessoas = (int**)malloc(qtd_pessoas*sizeof(int*));
    for(int i=0;i<qtd_pessoas;i++)
    {
        pessoas[i] = (int*)malloc(qtd_pessoas*sizeof(int));
        for(int j=0;j<qtd_pessoas;j++) pessoas[i][j] = 0;
    }
    for(int i=0;i<qtd_entradas;i++)
    {
        scanf("%d%d", &pessoa1, &pessoa2);
        pessoas[pessoa1-1][pessoa2-1] = 1;
        pessoas[pessoa2-1][pessoa1-1] = 1;
    }
    qtd_familias = contagem_familias(pessoas, qtd_pessoas, qtd_familias, 0, 0);
    printf("%d\n", qtd_familias);
    for(int i=0;i<qtd_pessoas;i++) free(pessoas[i]);
    free(pessoas);
    return 0;
}

int contagem_familias(int ** pessoas, int qtd_pessoas, int qtd_familias, int i, int j) {
    while(j < qtd_pessoas)
    {
        if(pessoas[i][j] == 1)
        {
            pessoas[i][j] = 0;
            return contagem_familias(pessoas, qtd_pessoas, qtd_familias, i, j);
        }
        else j++;
    }
    qtd_familias++;
    return qtd_familias;
}