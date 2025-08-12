#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned long long int matricula;
    char * nome;
    double n1, n2, n3;
} student;

int main() {
    student aluno;
    int i = 0;
    char temp_char;
    aluno.nome = (char*)malloc(sizeof(char));
    printf("Informe o nome do aluno: ");
    while(1)
    {
        scanf("%c", &temp_char);
        if(temp_char != '\n') 
        {
            aluno.nome[i] = temp_char;
            aluno.nome = realloc(aluno.nome, sizeof(aluno.nome)+1);
        }
        else break;
        i++;
    }
    printf("Informe a matricula do aluno: ");
    scanf("%llu", &aluno.matricula);
    printf("Informe as notas das tres provas separadas por um espaço: ");
    scanf("%lf%lf%lf", &aluno.n1, &aluno.n2, &aluno.n3);
    printf("Tamanho da estrutura: %lu bytes\n", sizeof(aluno));
    free(aluno.nome);
    return 0;
}