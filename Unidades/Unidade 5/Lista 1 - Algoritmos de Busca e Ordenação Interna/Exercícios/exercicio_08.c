#include <stdio.h>

#define N 1000

void imprime_vetor(int * v, int tam) {
    for(int i=0;i<tam;i++)
    {
        printf("%d", v[i]);
        if(i != tam-1) printf(" ");
    }
    printf("\n");
}

int selection_sort(int * v, int tam) {
    int menor, id_menor, temp;
    int trocas = 0;
    for(int i=0;i<tam-1;i++)
    {
        menor = v[i];
        id_menor = i;
        for(int j=i+1;j<tam;j++)
        {
            if(v[j] < menor)
            {
                menor = v[j];
                id_menor = j;
            }
        }
        if(i != id_menor)
        {
            temp = v[i];
            v[i] = v[id_menor];
            v[id_menor] = temp;
            trocas++;
        }
    }
    return trocas;
}

int insertion_sort(int * v, int tam) {
    int temp, j;
    int trocas = 0;
    for(int i=0;i<tam-1;i++)
    {
        if(v[i] > v[i+1])
        {
            temp = v[i];
            v[i] = v[i+1];
            v[i+1] = temp;
            trocas++;

            j = i;
            while(1)
            {
                if(v[j] < v[j-1])
                {
                    temp = v[j];
                    v[j] = v[j-1];
                    v[j-1] = temp;
                    trocas++;
                    j--;
                }
                else break;
            }
        }
    }
    return trocas;
}

int main() {
    int qtd;
    int v_selection[N], v_insertion[N];
    scanf("%d", &qtd);
    for(int i=0;i<qtd;i++)
    {
        scanf("%d", &v_selection[i]);
        v_insertion[i] = v_selection[i];
    }
    
    printf("%d\n", insertion_sort(v_insertion, qtd) - selection_sort(v_selection, qtd));

    return 0;
}