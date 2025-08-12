/*
Faça um programa que faça o cadastro dos alunos da turma de
PC1, o número máximo de alunos na turma são 50. Para cadastrar
um aluno, o usuário devera digitar o número de matricula, o nome
do aluno, as notas de 3 provas e a quantidade de presenças. O seu
programa deverá realizar o cadastro dos alunos, fazer a consulta de
um aluno por número de matricula ou nome, imprimir a lista dos
alunos com conceito aprovado ou reprovado.
Obs.:O aluno será considerado aprovado se a Média for maior que
seis e frequência maior que 75%, sendo que o número de aulas é de
64 horas aulas.
*/

#include <stdio.h>

typedef struct {
    unsigned int matricula;
    char nome[100];
    double nota1, nota2, nota3;
    int frequencia;
} student;

int main() {
    student aluno[50];
    int qtd;
    printf("Informe a quantidade de alunos: ");
    scanf("%d", &qtd);
    for(int i = 0; i < qtd; i++)
    {
        printf("Aluno %d\n", i+1);
        printf("Informe a matrícula do aluno: ");
        scanf("%u", &aluno[i].matricula);
        printf("Informe o nome completo do aluno: ");
        scanf("%*c%[^\n]%*c", aluno[i].nome);
        printf("Informe as notas das 3 provas do aluno e a quantidade de presenças: ");
        scanf("%lf%lf%lf%d", &aluno[i].nota1, &aluno[i].nota2, &aluno[i].nota3, &aluno[i].frequencia);
        printf("\n");
    }
    for(int i = 0; i < qtd; i++)
    {
        printf("Aluno: %s\n", aluno[i].nome);
        printf("Matrícula: %u\n", aluno[i].matricula);
        printf("Nota Final: %.2lf\n", (aluno[i].nota1 + aluno[i].nota2 + aluno[i].nota3)/3);
        printf("Frequência: %d\n", aluno[i].frequencia);
        if((aluno[i].nota1 + aluno[i].nota2 + aluno[i].nota3)/3 >= 6 && aluno[i].frequencia > 0.75*64) printf("APROVADO\n");
        else printf("REPROVADO\n");
        printf("\n");
    }
    return 0;
}