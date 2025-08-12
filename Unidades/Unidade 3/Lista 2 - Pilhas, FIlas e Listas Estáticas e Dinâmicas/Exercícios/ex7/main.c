#include <stdio.h>
#include <stdlib.h>
#include "banco.h"

int main() {
    fila * queue = concebe_fila();
    patient paciente;
    int qtd;
    if(fila_vazia(queue) == VERDADEIRO) printf("Fila vazia.\n");
    else printf("Fila não vazia.\n");

    printf("Informe quantos pacientes serão enfileirados: ");
    while(1)
    {
        scanf("%d%*c", &qtd);
        if(qtd > 0) break;
        printf("Valor inválido. Tente novamente: ");
    }
    for(int i=0;i<qtd;i++)
    {
        printf("Informe o nome do paciente: ");
        scanf("%[^\n]%*c", paciente.nome);
        printf("Informe o código do paciente: ");
        scanf("%d%*c", &paciente.codigo);
        if(push(queue, paciente) == SUCESSO) printf("Elemento inserido com sucesso.\n");
        printf("Tamanho da fila: %d\n", quantidade_pacientes(queue));
        if(lista_pacientes(queue) == SUCESSO) printf("Fila impressa.\n");
        else printf("Não foi possível imprimir a fila.\n");
    }

    if(consulta_inicio(queue) == SUCESSO) printf("Frente consultada.\n");
    else printf("Não foi possível consultar o início da fila.\n");
    if(pop(queue) == SUCESSO) printf("Fila andou.\n");
    else printf("Fila não andou.\n");
    if(consulta_inicio(queue) == SUCESSO) printf("Frente consultada.\n");
    else printf("Não foi possível consultar o início da fila.\n");
    printf("\n");
    if(lista_pacientes(queue) == SUCESSO) printf("Fila impressa.\n");
    else printf("Não foi possível imprimir a fila.\n");

    if(tempo_espera(queue) == SUCESSO) printf("Tempo de espera consultado.\n");

    destroi_fila(queue);
    return 0;
}