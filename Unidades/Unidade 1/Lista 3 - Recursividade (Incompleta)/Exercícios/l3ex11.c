#include <stdio.h>
#include <stdlib.h>

#define NAVIO 1
#define AGUA -1
#define NAVIO_QUEBRADO 0
#define DESTRUIDO 1
#define NAO_DESTRUIDO 0
#define TRUE 1
#define FALSE 0

void ataque(char ** campo, int ** navios, int linha, int coluna, int * qtd_destruidos, int linhas_totais, int colunas_totais);

int verifica_destruicao(int ** navios, int linha, int coluna, int linhas_totais, int colunas_totais, int cima, int baixo, int direita, int esquerda);

int main() {
    int linhas, colunas, qtd_disparos, disparo_linha, disparo_coluna, qtd_destuidos = 0;
    scanf("%d%d%*c", &linhas, &colunas);
    char ** campo = (char**)malloc(linhas*sizeof(char*));
    int ** navios = (int**)malloc(linhas*sizeof(int*));
    for(int i=0;i<linhas;i++)
    {
        campo[i] = (char*)malloc(colunas*sizeof(char));
        navios[i] = (int*)malloc(colunas*sizeof(int));
        for(int j=0;j<colunas;j++)
        {
            scanf("%c", &campo[i][j]);
            if(campo[i][j] == '#') navios[i][j] = NAVIO;
            else navios[i][j] = AGUA;
        }
        scanf("%*c");
    }
    scanf("%d", &qtd_disparos);
    for(int i=0;i<qtd_disparos;i++)
    {
        scanf("%d%d", &disparo_linha, &disparo_coluna);
        ataque(campo, navios, disparo_linha-1, disparo_coluna-1, &qtd_destuidos, linhas, colunas);
    }
    printf("%d\n", qtd_destuidos);
    for(int i=0;i<linhas;i++)
    {
        free(campo[i]);
        free(navios[i]);
    }
    free(campo);
    free(navios);
    return 0;
}

void ataque(char ** campo, int ** navios, int linha, int coluna, int * qtd_destruidos, int linhas_totais, int colunas_totais) {
    if(navios[linha][coluna] == NAVIO)
    {
        navios[linha][coluna] = NAVIO_QUEBRADO;
        if(verifica_destruicao(navios, linha, coluna, linhas_totais, colunas_totais, TRUE, TRUE, TRUE, TRUE) == DESTRUIDO)
        {
            *qtd_destruidos += 1;
        }
    }
}

int verifica_destruicao(int ** navios, int linha, int coluna, int linhas_totais, int colunas_totais, int cima, int baixo, int direita, int esquerda) {
    int destruido = 0;
    if(linha+1 == linhas_totais || navios[linha+1][coluna] == AGUA) destruido = DESTRUIDO;
    else if(linha < linhas_totais-1 && navios[linha+1][coluna] == NAVIO)
    {
        destruido = NAO_DESTRUIDO;
        return NAO_DESTRUIDO;
    }
    if(linha-1 < 0 || navios[linha-1][coluna] == AGUA) destruido = DESTRUIDO;
    else if(linha > 0 && navios[linha-1][coluna] == NAVIO)
    {
        destruido = NAO_DESTRUIDO;
        return NAO_DESTRUIDO;
    }
    if(coluna+1 == colunas_totais || navios[linha][coluna+1] == AGUA) destruido = DESTRUIDO;
    else if(coluna < colunas_totais-1 && navios[linha][coluna+1] == NAVIO)
    {
        destruido = NAO_DESTRUIDO;
        return NAO_DESTRUIDO;
    }
    if(coluna-1 < 0 || navios[linha][coluna-1] == AGUA) destruido = DESTRUIDO;
    else if(coluna > 0 && navios[linha][coluna-1] == NAVIO)
    {
        destruido = NAO_DESTRUIDO;
        return NAO_DESTRUIDO;
    }
    if(baixo == TRUE && linha < linhas_totais-1 && navios[linha+1][coluna] == NAVIO_QUEBRADO) return verifica_destruicao(navios, linha+1, coluna, linhas_totais, colunas_totais, FALSE, TRUE, FALSE, FALSE);
    if(cima == TRUE && linha > 0 && navios[linha-1][coluna] == NAVIO_QUEBRADO) return verifica_destruicao(navios, linha-1, coluna, linhas_totais, colunas_totais, TRUE, FALSE, FALSE, FALSE);
    if(direita == TRUE && coluna < colunas_totais-1 && navios[linha][coluna+1] == NAVIO_QUEBRADO) return verifica_destruicao(navios, linha, coluna+1, linhas_totais, colunas_totais, FALSE, FALSE, TRUE, FALSE);
    if(esquerda == TRUE && coluna > 0 && navios[linha][coluna-1] == NAVIO_QUEBRADO) return verifica_destruicao(navios, linha, coluna-1, linhas_totais, colunas_totais, FALSE, FALSE, FALSE, TRUE);
    if(destruido == DESTRUIDO) return DESTRUIDO;
    else return NAO_DESTRUIDO;
}