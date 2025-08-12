#include <stdio.h>
#include <stdlib.h>

int main() {
    int dim;
    int ** M;
    printf("Informe a dimensão da matriz: ");
    scanf("%d", &dim);
    M = (int**)malloc(dim*sizeof(int*));
    for(int i=0;i<dim;i++)
    {
        M[i] = (int*)malloc(dim*sizeof(int));
        for(int j=0;j<dim;j++)
        {
            if(j < i) M[i][j] = -1;
            else if(j == i) M[i][j] = 0;
            else if(j > i) M[i][j] = 1;
        }
    }
    for(int i=0;i<dim;i++)
    {
        printf("| ");
        for(int j=0;j<dim;j++)
        {
            if(j >= i) printf(" %d ", M[i][j]);
            else printf("%d ", M[i][j]);
        }
        printf("|\n");
        free(M[i]);
    }
    free(M);
    return 0;
}