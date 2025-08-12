#include <stdio.h>
#include "fila_prioridade.h"

int main() {
    prio * fila = concebe_fila_prioridade();
    Paciente paciente;
    int qtd;

    if(fila_vazia(fila) == VERDADEIRO) printf("Fila vazia.\n");
    else printf("Fila não vazia.\n");
    printf("Informe quantos pacientes entrarão na fila: ");
    while(1)
    {
        scanf("%d", &qtd);
        if(qtd <= TAM_MAX_FILA && qtd > 0) break;
        printf("Quantidade inválida. Tente novamente: ");
    }

    for(int i=0;i<qtd;i++)
    {
        printf("Informe o nome do paciente: ");
        scanf("%*c%[^\n]%*c", paciente.nome);
        printf("Informe o nível de prioridade desse paciente: ");
        scanf("%d", &(paciente.prioridade));
        if(push_prioridade(fila, &paciente) == SUCESSO) printf("Paciente adicionado a fila.\n");
        else printf("Paciente não adicionado a fila.\n");
        printf("Tamanho da fila: %d\n", tamanho_fila(fila));
        if(imprime_fila(fila) == SUCESSO) printf("Fila impressa.\n\n");
    }
    if(fila_cheia(fila) == VERDADEIRO) printf("Fila cheia.\n");
    else printf("Fila não cheia.\n");

    if(consulta_frente(fila) == SUCESSO) printf("Frente consultada.\n");
    else printf("Frente não consultada.\n");
    if(pop_prioridade(fila) == SUCESSO) printf("Paciente atendido.\n");
    else printf("Nenhum paciente foi atendido.\n");
    if(consulta_frente(fila) == SUCESSO) printf("Frente consultada.\n");
    else printf("Frente não consultada.\n");
    if(imprime_fila(fila) == SUCESSO) printf("Fila impressa.\n");

    destroi_fila(fila);

    return 0;
}