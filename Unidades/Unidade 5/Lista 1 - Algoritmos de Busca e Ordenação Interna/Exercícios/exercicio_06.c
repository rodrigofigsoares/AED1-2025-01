#include <stdio.h>

#define N 100

void imprime_vetor(int * v, int start, int end) {
    for(int i=start;i<end;i++)
    {
        printf("%d", v[i]);
        if(i < end-1) printf(" ");
    }
    printf("\n");
}

void ordena_vetor(int * geral, int tam) {
    int k = 0, temp;
    for(int i=0;i<tam;i++)
    {
        if(geral[i]%2 == 0)
        {
            temp = geral[k];
            geral[k] = geral[i];
            geral[i] = temp;
            k++;
        }
    }

    int menor, id_menor;
    for(int i=0;i<k-1;i++)
    {
        menor = geral[i];
        id_menor = i;
        for(int j=i+1;j<k;j++)
        {
            if(geral[j] < menor)
            {
                menor = geral[j];
                id_menor = j;
            }
        }
        temp = geral[i];
        geral[i] = menor;
        geral[id_menor] = temp;
    }

    int maior, id_maior;
    for(int i=k;i<tam-1;i++)
    {
        maior = geral[i];
        id_maior = i;
        for(int j=i+1;j<tam;j++)
        {
            if(geral[j] > maior)
            {
                maior = geral[j];
                id_maior = j;
            }
        }
        temp = geral[i];
        geral[i] = maior;
        geral[id_maior] = temp;
    }

    if(k != 0) imprime_vetor(geral, 0, k);
    if(k != tam) imprime_vetor(geral, k, tam);
}


int main() {
    int geral[N];
    int qtd;
    scanf("%d", &qtd);
    for(int i=0;i<qtd;i++)
    {
        scanf("%d", &geral[i]);
    }

    ordena_vetor(geral, qtd);
    return 0;
}