#include <stdio.h>
#include <strings.h>

#define N 3

typedef struct Animal {
    int codigo;
    char nome[50];
    char classe[20];
} animal;

int compara_nome(animal A, animal B) {
    if(strcasecmp(A.nome, B.nome) <= 0) return 1;
    else return 2;
}

int verifica_ordenado(animal * zoologico, int tam) {
    for(int i=0;i<tam-1;i++)
    {
        if(compara_nome(zoologico[i], zoologico[i+1]) == 2) return 0;
    }
    return 1;
}

void bubble_sort(animal * zoologico, int tam) {
    animal temp;
    while(1)
    {
        for(int i=0;i<tam-1;i++)
        {
            if(compara_nome(zoologico[i], zoologico[i+1]) == 2) 
            {
                temp = zoologico[i];
                zoologico[i] = zoologico[i+1];
                zoologico[i+1] = temp;
            }
        }
        if(verifica_ordenado(zoologico, tam) == 1) break;
    }

}

int main() {
    animal zoologico[N];
    for(int i=0;i<N;i++)
    {
        printf("Informe o nome do animal: ");
        scanf("%[^\n]%*c", zoologico[i].nome);
        printf("Informe o código do animal: ");
        scanf("%d%*c", &zoologico[i].codigo);
        printf("Informe a classe do animal: ");
        scanf("%[^\n]%*c", zoologico[i].classe);
    }
    bubble_sort(zoologico, N);
    printf("\n\n");
    for(int i=0;i<N;i++)
    {
        printf("%s --- %d\n", zoologico[i].nome, zoologico[i].codigo);
        printf("%s\n", zoologico[i].classe);
        printf("\n\n");
    }
    return 0;
}