#include <stdio.h>
#include <string.h>

#define QTD_FUNCIONARIOS 2

typedef struct {
    char nome[100];
    char cargo[50];
    double salario_base;
    char cpf[15];
    char departamento[100];
} worker;

void scan_funcionario(worker * funcionario);
double calcula_salario_medio(worker * funcionario);

int main() {
    worker funcionario[QTD_FUNCIONARIOS];
    scan_funcionario(funcionario);
    printf("Salario medio: %.2lf\n", calcula_salario_medio(funcionario));
    return 0;
}

void scan_funcionario(worker * funcionario) {
    for(int i=0;i<QTD_FUNCIONARIOS;i++)
    {
        printf("Informe o nome do(a) funcionario(a): ");
        scanf("%[^\n]%*c", funcionario[i].nome);
        printf("Informe o cargo do(a) funcionario(a): ");
        scanf("%[^\n]%*c", funcionario[i].cargo);
        printf("Informe o salario-base do(a) funcionario(a): ");
        scanf("%lf%*c", &funcionario[i].salario_base);
        printf("Informe o CPF do(a) funcionario(a): ");
        scanf("%[^\n]%*c", funcionario[i].cpf);
        printf("Informe o departamento do(a) funcionario(a): ");
        scanf("%[^\n]%*c", funcionario[i].departamento);
        printf("\n");
    }
}

double calcula_salario_medio(worker * funcionario) {
    double salario_medio = 0;
    for(int i=0;i<QTD_FUNCIONARIOS;i++)
    {
        if(strcmp(funcionario[i].cargo, "Assistente") == 0 || strcmp(funcionario[i].cargo, "assistente") == 0) salario_medio += funcionario[i].salario_base * 1.05;
        else if(strcmp(funcionario[i].cargo, "Supervisor") == 0 || strcmp(funcionario[i].cargo, "supervisor") == 0) salario_medio += funcionario[i].salario_base * 1.10;
        else if(strcmp(funcionario[i].cargo, "Gerente") == 0 || strcmp(funcionario[i].cargo, "gerente") == 0) salario_medio += funcionario[i].salario_base * 1.15;
        else salario_medio += funcionario[i].salario_base * 1.02;
    }
    salario_medio = salario_medio/QTD_FUNCIONARIOS;
    return salario_medio;
}