#include <stdio.h>
#include <stdlib.h>

void matriz_superior(int ** M, int size) {
    int i, j;
    for(i=0;i<size;i++)
    {
        M[i] = (int*)malloc(size*sizeof(int));
        for(j=0;j<size;j++)
        {
            if(j >= i) scanf("%d", &M[i][j]);
            else M[i][j] = 0;
        }
    }
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            printf("%d ", M[i][j]);
        }
        free(M[i]);
        printf("\n");
    }
    free(M);
}
void matriz_inferior(int ** M, int size) {
    int i, j;
    for(i=0;i<size;i++)
    {
        M[i] = (int*)malloc(size*sizeof(int));
        for(j=0;j<size;j++)
        {
            if(j <= i) scanf("%d", &M[i][j]);
            else M[i][j] = 0;
        }
    }
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            printf("%d ", M[i][j]);
        }
        free(M[i]);
        printf("\n");
    }
    free(M);
}

int main() {
    int tam;
    char tipo;
    printf("Qual o tamanho da matriz triangular: ");
    scanf("%d%*c", &tam);
    printf("Informe se a matriz é triangular superior ou triangular inferior (Digite S/s para superior e I/i para inferior): ");
    scanf("%c", &tipo);
    printf("Informe os números da Matriz:\n");
    int ** M = (int**)malloc(tam*sizeof(int*));
    if(tipo == 'I' || tipo == 'i') matriz_inferior(M, tam);
    if(tipo == 'S' || tipo == 's') matriz_superior(M, tam);
    return 0;
}