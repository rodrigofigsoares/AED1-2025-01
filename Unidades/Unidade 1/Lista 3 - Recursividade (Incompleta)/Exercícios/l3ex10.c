#include <stdio.h>
#include <stdlib.h>

#define INDEFINIDO -1
#define SEGURO 1
#define NAO_SEGURO 0

int checa_seguranca(char ** tabuleiro, int ** seguranca, int dim_tabuleiro, int i, int j);

int main() {
    int dim_tabuleiro, casas_seguras = 0;
    printf("Informe a dimensão do tabuleiro: ");
    scanf("%d%*c", &dim_tabuleiro);
    char ** tabuleiro = (char**)malloc(dim_tabuleiro*sizeof(char*));
    int ** seguranca = (int**)malloc(dim_tabuleiro*sizeof(int*));
    for(int i=0;i<dim_tabuleiro;i++)
    {
        tabuleiro[i] = (char*)malloc(dim_tabuleiro*sizeof(char));
        seguranca[i] = (int*)malloc(dim_tabuleiro*sizeof(int));
        for(int j=0;j<dim_tabuleiro;j++)
        {
            scanf("%c", &tabuleiro[i][j]);
            seguranca[i][j] = INDEFINIDO;
        }
        scanf("%*c");
    }
    for(int i=0;i<dim_tabuleiro;i++)
    {
        for(int j=0;j<dim_tabuleiro;j++)
        {
            if(seguranca[i][j] == 1) casas_seguras++;
            else if(checa_seguranca(tabuleiro, seguranca, dim_tabuleiro, i, j) == 1) casas_seguras++;
        }
    }
    printf("%d\n", casas_seguras);
    for(int i=0;i<dim_tabuleiro;i++)
    {
        free(tabuleiro[i]);
        free(seguranca[i]);
    }
    free(tabuleiro);
    free(seguranca);
    return 0;
}

int checa_seguranca(char ** tabuleiro, int ** seguranca, int dim_tabuleiro, int i, int j) {
    if(i == dim_tabuleiro || j == dim_tabuleiro || i < 0 || j < 0) return NAO_SEGURO;
    if(seguranca[i][j] == SEGURO) return SEGURO;
    if(seguranca[i][j] == INDEFINIDO) seguranca[i][j] = SEGURO;
    if(tabuleiro[i][j] == 'V')
    {
        if(checa_seguranca(tabuleiro, seguranca, dim_tabuleiro, i+1, j) == NAO_SEGURO)
        {
            seguranca[i][j] = NAO_SEGURO;
            return NAO_SEGURO;
        }
        else
        {
            seguranca[i][j] = SEGURO;
            return SEGURO;
        }
    }
    else if(tabuleiro[i][j] == '<')
    {
        if(checa_seguranca(tabuleiro, seguranca, dim_tabuleiro, i, j-1) == NAO_SEGURO)
        {
            seguranca[i][j] = NAO_SEGURO;
            return NAO_SEGURO;
        }
        else
        {
            seguranca[i][j] = SEGURO;
            return SEGURO;
        }
    }
    else if(tabuleiro[i][j] == '>')
    {
        if(checa_seguranca(tabuleiro, seguranca, dim_tabuleiro, i, j+1) == NAO_SEGURO)
        {
            seguranca[i][j] = NAO_SEGURO;
            return NAO_SEGURO;
        }
        else
        {
            seguranca[i][j] = SEGURO;
            return SEGURO;
        }
    }
    else if(tabuleiro[i][j] == 'A')
    {
        if(checa_seguranca(tabuleiro, seguranca, dim_tabuleiro, i-1, j) == NAO_SEGURO)
        {
            seguranca[i][j] = NAO_SEGURO;
            return NAO_SEGURO;
        }
        else
        {
            seguranca[i][j] = SEGURO;
            return SEGURO;
        }
    }
}