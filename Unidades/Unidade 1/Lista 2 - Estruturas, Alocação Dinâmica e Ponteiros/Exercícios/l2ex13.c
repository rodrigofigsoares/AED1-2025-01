#include <stdio.h>
#include <stdlib.h>

int main() {
    int dim;
    int ** M;
    printf("Informe a dimensão da matriz: ");
    scanf("%d", &dim);
    printf("Informe os valores da matriz:\n");
    M = (int**)malloc(dim*sizeof(int*));
    for(int i=0;i<dim;i++)
    {
        M[i] = (int*)malloc(dim*sizeof(int));
        for(int j=0;j<dim;j++)
        {
            while(1)
            {
                scanf("%d", &M[i][j]);
                if(M[i][j]%2 != 0) printf("O valor precisa ser par. Tente novamente:\n");
                else break;
            }
        }
    }
    for(int i=0;i<dim;i++)
    {
        printf("| ");
        for(int j=0;j<dim;j++) printf("%d ", M[i][j]);
        free(M[i]);
        printf("|\n");
    }
    free(M);    
    return 0;
}