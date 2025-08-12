/*
Não sabia qual forma você queria que fizessemos o "valor fixo informado pelo usuário",
portanto, essa é uma versão do código no qual o valor é definido previamente por meio
do #define.
*/

#include <stdio.h>

#define QTD_FUNCIONARIOS 2

typedef struct {
    char nome[100];
    int qtd_funcionarios, tempo_existencia;
} departamento;

typedef struct {
    char nome[100];
    long long int matricula;
    int anos_trabalhados;
    departamento dep;
} funcionario;

int main() {
    funcionario trabalhador[QTD_FUNCIONARIOS];
    int i;
    for(i=0;i<QTD_FUNCIONARIOS;i++)
    {
        printf("Funcionário(a) %d:\n\n", i+1);
        printf("Informe o nome completo: ");
        scanf("%[^\n]", trabalhador[i].nome);
        printf("Informe o número de matrícula: ");
        scanf("%lld", &trabalhador[i].matricula);
        printf("Informe por quantos anos o(a) funcionário(a) trabalhou: ");
        scanf("%d%*c", &trabalhador[i].anos_trabalhados);
        printf("Informe o departamento: ");
        scanf("%[^\n]", trabalhador[i].dep.nome);
        printf("Informe quantos funcionários há neste departamento: ");
        scanf("%d", &trabalhador[i].dep.qtd_funcionarios);
        printf("Informe há quantos anos o departamento existe: ");
        scanf("%d%*c", &trabalhador[i].dep.tempo_existencia);
    }
    for(i=0;i<QTD_FUNCIONARIOS;i++)
    {
        printf("Funcionário(a): %s\n", trabalhador[i].nome);
        printf("Número de matrícula: %lld\n", trabalhador[i].matricula);
        printf("Anos trabalhados: %d", trabalhador[i].anos_trabalhados);
        if(trabalhador[i].anos_trabalhados >= 30) printf(" - É possível solicitar aposentadoria");
        printf("\nDepartamento: %s\n", trabalhador[i].dep.nome);
        printf("Quantidade de funcionários no departamento: %d\n", trabalhador[i].dep.qtd_funcionarios);
        printf("O departamento existe há %d anos\n", trabalhador[i].dep.tempo_existencia);
    }
    return 0;
}