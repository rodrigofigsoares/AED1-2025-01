#include <stdio.h>
#include <strings.h>

#define N 100

typedef struct Aluno {
    char nome[80];
    int questoes;
} student;

void imprime_vetor(student * alunos, int tam) {
    for(int i=0;i<tam;i++)
    {
        printf("%s %d", alunos[i].nome, alunos[i].questoes);
        if(i == tam-1) printf(" #reprovado(a)");
        printf("\n");
    }
}

int compara_nomes(char * nome1, char * nome2) {
    if(strcasecmp(nome1, nome2) < 0) return 1;
    else return 2;
}

void ordena_alunos(student * alunos, int tam) {
    int maior, id_maior;
    student temp;
    for(int i=0;i<tam-1;i++)
    {
        maior = alunos[i].questoes;
        id_maior = i;
        for(int j=i+1;j<tam;j++)
        {
            if(alunos[j].questoes > maior)
            {
                maior = alunos[j].questoes;
                id_maior = j;
            }
            else if(alunos[j].questoes == maior)
            {
                if(compara_nomes(alunos[j].nome, alunos[id_maior].nome) == 1)
                {
                    maior = alunos[j].questoes;
                    id_maior = j;
                }
            }
        }
        temp = alunos[i];
        alunos[i] = alunos[id_maior];
        alunos[id_maior] = temp;
    }
}

int main() {
    int qtd;
    student alunos[N];
    scanf("%d%*c", &qtd);
    for(int i=0;i<qtd;i++)
    {
        scanf("%s%*c", alunos[i].nome);
        scanf("%d%*c", &alunos[i].questoes);
    }

    ordena_alunos(alunos, qtd);
    imprime_vetor(alunos, qtd);

    return 0;
}