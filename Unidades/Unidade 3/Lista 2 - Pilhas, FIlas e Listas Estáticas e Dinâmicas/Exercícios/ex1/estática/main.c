#include <stdio.h>
#include <stdlib.h>
#include "lista_estatica.h"

// printf alterando o valor da variável (ainda não sei como resolver)

int main() {
    lista * list = concebe_lista();
    student aluno;
    int qtd, form;
    if(lista_vazia(list) == VERDADEIRO) printf("Lista vazia.\n");
    else printf("Lista não vazia.\n");

    printf("Informe quantos elementos serão listados: ");
    while(1)
    {
        scanf("%d%*c", &qtd);
        if(qtd <= TAM_MAX_LISTA && qtd > 0) break;
        printf("Valor inválido. Tente novamente: ");        
    }
    for(int i=0;i<qtd;i++)
    {
        printf("Informe o nome do aluno: ");
        scanf("%[^\n]%*c", aluno.nome);
        printf("Informe a matrícula do aluno: ");
        scanf("%d%*c", &(aluno.matricula));
        printf("Informe como ele será inserido.\n");
        printf("|\n");
        printf("| 0 - Inserido no início.\n");
        printf("| 1 - Inserido no meio.\n");
        printf("| 2 - Inserido no final.\n");
        printf("|\n");
        printf("Resposta: ");
        scanf("%d", &form);
        if(form == 0) 
        {
            if(push_inicio(list, &aluno) == SUCESSO) printf("Elemento inserido no início da lista.\n");
        }
        else if(form == 1)
        {
            if(push_ordenado(list, &aluno) == SUCESSO) printf("Elemento inserido no meio da lista.\n");
        }
        else if(form == 2)
        {
            if(push_final(list, &aluno) == SUCESSO) printf("Elemento inserido no final da lista.\n");
        }
        printf("Tamanho da lista: %d\n", tamanho_lista(list));
        if(imprime_lista(list) == SUCESSO) printf("Lista impressa.\n");
    }
    if(lista_cheia(list) == VERDADEIRO) printf("Lista cheia.\n");
    else printf("Lista não cheia.\n");
    printf("\n");

    int matricula;
    printf("Informe uma matrícula para consultar um elemento: ");
    scanf("%d", &matricula);
    if(consulta_por_matricula(list, matricula) == SUCESSO) printf("Elemento consultado.\n");
    else printf("Não foi possível consultar o elemento.\n");
    printf("\n");
    if(imprime_lista(list) == SUCESSO) printf("Lista impressa.\n");

    int temp = qtd;
    printf("Informe quantos elementos serão removidos: ");
    while(1)
    {
        scanf("%d", &qtd);
        if(qtd <= temp && qtd > 0) break;
        printf("Valor inválido. Tente novamente: ");
    }
    for(int i=0;i<qtd;i++)
    {
        printf("Informe como o elemento será removido.\n");
        printf("|\n");
        printf("| 0 - Removido do início.\n");
        printf("| 1 - Removido por especificação.\n");
        printf("| 2 - Removido do final.\n");
        printf("|\n");
        printf("Resposta: ");
        scanf("%d", &form);
        if(form == 0) 
        {
            if(pop_inicio(list) == SUCESSO) printf("Elemento removido do início da lista.\n");
        }
        else if(form == 1)
        {
            printf("Informe a matrícula do aluno que será removido da lista: ");
            scanf("%d", &matricula);
            if(pop_especifico(list, matricula) == SUCESSO) printf("Elemento removido da lista.\n");
        }
        else if(form == 2)
        {
            if(pop_final(list) == SUCESSO) printf("Elemento removido do final da lista.\n");
        }
        printf("Tamanho da lista: %d\n", tamanho_lista(list));
        if(imprime_lista(list) == SUCESSO) printf("Lista impressa.\n");
    }
    if(lista_cheia(list) == VERDADEIRO) printf("Lista cheia.\n");
    else printf("Lista não cheia.\n");
    printf("\n");

    printf("Informe uma matrícula para consultar um elemento: ");
    scanf("%d", &matricula);
    if(consulta_por_matricula(list, matricula) == SUCESSO) printf("Elemento consultado.\n");
    else printf("Não foi possível consultar o elemento.\n");
    printf("\n");
    if(imprime_lista(list) == SUCESSO) printf("Lista impressa.\n");

    destroi_lista(list);
    return 0;
}