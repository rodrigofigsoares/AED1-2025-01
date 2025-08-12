/*
Criar um tipo abstrato de dados que represente uma pessoa,
contendo nome, data de nascimento e CPF. Crie uma variável que
é um ponteiro para este TAD (no programa principal). Depois crie
uma função que receba este ponteiro e preencha os dados da
estrutura e também uma uma função que receba este ponteiro e
imprima os dados da estrutura. Finalmente, faça a chamada a esta
função na função principal.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
    char nascimento[11];
    char cpf[15];
} person;

void preencher_info(person * pessoa) {
    printf("Informe o nome completo: ");
    scanf("%[^\n]%*c", pessoa->nome);
    printf("Informe a data de nascimento (dd/mm/aaaa): ");
    scanf("%[^\n]%*c", pessoa->nascimento);
    printf("Informe o CPF: ");
    scanf("%[^\n]%*c", pessoa->cpf);
}

void print_info(person * pessoa) {
    printf("\n");
    printf("Nome: %s\n", pessoa->nome);
    printf("Data de Nascimento: %s\n", pessoa->nascimento);
    printf("CPF: %s\n", pessoa->cpf);
}

int main() {
    person pessoa;
    person * ptr = &pessoa;
    preencher_info(ptr);
    print_info(ptr);
    return 0;
}