#include <stdio.h>
#include <stdlib.h>

void superior(long long int ** M, int dim, long long int inicial);

void inferior(long long int ** M, int dim, long long int inicial);

void print_matriz(long long int ** M, int dim);

int main() {
    int dim;
    long long int **M, inicial;
    char tipo;
    printf("Informe a dimensão da matriz triângular: ");
    scanf("%d%*c", &dim);
    M = (long long int**)malloc(dim*sizeof(long int*));
    for(int i=0;i<dim;i++) M[i] = (long long int*)malloc(dim*sizeof(long long int));
    printf("Informe se a matriz é triangular superior ou inferior (S/I): ");
    scanf("%c", &tipo);
    printf("Informe o valor inicial da matriz: ");
    scanf("%lld", &inicial);
    if(tipo == 'S') superior(M, dim, inicial);
    else inferior(M, dim, inicial);
    print_matriz(M, dim);
    for(int i=0;i<dim;i++) free(M[i]);
    free(M);
    return 0;
}

void superior(long long int ** M, int dim, long long int inicial) {
    for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
        {
            if(j >= i) 
            {
                M[i][j] = inicial;
                inicial *= 2;
            }
            else M[i][j] = 0;
        }
    }
}

void inferior(long long int ** M, int dim, long long int inicial) {
    for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
        {
            if(j <= i) 
            {
                M[i][j] = inicial;
                inicial *= 2;
            }
            else M[i][j] = 0;
        }
    }
}

void print_matriz(long long int ** M, int dim) {
    for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
        {
            if(M[i][j] == 0) for(int k=0;k<j+1;k++) printf(" ");
            else printf("%lld ", M[i][j]);
        }
        printf("\n");
    }
}