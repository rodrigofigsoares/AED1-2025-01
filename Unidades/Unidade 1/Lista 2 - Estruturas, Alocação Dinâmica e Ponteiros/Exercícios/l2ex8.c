#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho, i = 0;
    while(1)
    {
        printf("Informe o tamanho do vetor (num>0): ");
        scanf("%d", &tamanho);
        if(tamanho >= 0) break;
        else printf("Valor inválido, tente novamente.\n");
    }
    int * vetor = (int*)malloc(tamanho*sizeof(int));
    printf("Informe os valores do vetor (num>=2):\n");
    while(1)
    {
        scanf("%d", &vetor[i]);
        if(vetor[i] >= 2) i++;
        else printf("Valor inválido, tente novamente (num>=2).\n");
        if(i == tamanho) break;
    }
    printf("Vetor = {");
    for(i=0;i<tamanho-1;i++) printf("%d, ", vetor[i]);
    printf("%d}\n", vetor[i]);
    free(vetor);
    return 0;
}