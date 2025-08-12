#include <stdio.h>

typedef struct {
    char logradouro[150];
    char numero[10];
    char bairro[100];
    char complemento[50];
    unsigned int cep;
    char cidade[50];
    char estado [50];
} address;

typedef struct {
    char nome[100];
    int idade;
    address endereco;
} person;

void scan_info(person * pessoa) {
    printf("Informe o nome completo: ");
    scanf("%[^\n]%*c", pessoa->nome);
    printf("Informe a idade: ");
    while(1)
    {
        scanf("%d", &pessoa->idade);
        if(pessoa->idade > 120 || pessoa->idade < 0) printf("Idade inválida! Tente novamente: ");
        else break;
    }
    printf("\nInforme seu endereço:\n");
    printf("Logradouro: ");
    scanf("%*c%[^\n]%*c", pessoa->endereco.logradouro);
    printf("Número: ");
    scanf("%[^\n]%*c", pessoa->endereco.numero);
    printf("Bairro: ");
    scanf("%[^\n]%*c", pessoa->endereco.bairro);
    printf("Complemento: ");
    scanf("%[^\n]%*c", pessoa->endereco.complemento);
    printf("CEP: ");
    scanf("%u%*c", &pessoa->endereco.cep);
    printf("Cidade: ");
    scanf("%[^\n]%*c", pessoa->endereco.cidade);
    printf("Estado: ");
    scanf("%[^\n]%*c", pessoa->endereco.estado);

}

void print_info(person * pessoa) {
    printf("\n");
    printf("Nome: %s\n", pessoa->nome);
    printf("Idade: %d\n", pessoa->idade);
    printf("Endereço: %s, ", pessoa->endereco.logradouro);
    if(pessoa->endereco.numero[0] == 'S' || pessoa->endereco.numero[0] == 's') printf("S/N, ");
    else printf("%s, ", pessoa->endereco.numero);
    printf("%s, %s\n", pessoa->endereco.complemento, pessoa->endereco.bairro);
    printf("CEP: %u\n", pessoa->endereco.cep);
    printf("%s, %s\n", pessoa->endereco.cidade, pessoa->endereco.estado);
}

int main() {
    person pessoa;
    person * p = &pessoa;
    scan_info(p);
    print_info(p);
    return 0;
}