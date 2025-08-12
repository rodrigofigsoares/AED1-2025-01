#include <stdio.h>
#include <stdlib.h>
#include "fila_dinamica.h"

int main() {
    fila * queue = concebe_fila();
    student aluno;
    int qtd;
    if(fila_vazia(queue) == VERDADEIRO) printf("Fila vazia.\n");
    else printf("Fila não vazia.\n");

    printf("Informe quantos alunos serão enfileirados: ");
    while(1)
    {
        scanf("%d%*c", &qtd);
        if(qtd > 0) break;
        printf("Valor inválido. Tente novamente: ");
    }
    for(int i=0;i<qtd;i++)
    {
        printf("Informe o nome do aluno: ");
        scanf("%[^\n]%*c", aluno.nome);
        printf("Informe a matrícula do aluno: ");
        scanf("%[^\n]%*c", aluno.matricula);
        push(queue, aluno);
        printf("Tamanho da fila: %d\n", tamanho_fila(queue));
        if(imprime_fila(queue) == SUCESSO) printf("Fila impressa.\n");
        else printf("Não foi possível imprimir a fila.\n");
    }

    if(consulta_inicio(queue) == SUCESSO) printf("Frente consultada.\n");
    else printf("Não foi possível consultar o início da fila.\n");
    if(pop(queue) == SUCESSO) printf("Fila andou.\n");
    else printf("Não foi possível remover o elemento da fila.\n");
    if(consulta_inicio(queue) == SUCESSO) printf("Frente consultada.\n");
    else printf("Não foi possível consultar o início da fila.\n");
    printf("\n");
    if(imprime_fila(queue) == SUCESSO) printf("Fila impressa.\n");
    else printf("Não foi possível imprimir a fila.\n");

    destroi_fila(queue);
    return 0;
}