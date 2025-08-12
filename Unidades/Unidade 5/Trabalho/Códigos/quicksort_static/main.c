# include "lista_est.h"
# include <stdio.h>

int main () {
    Lista * L = criar_lista();
    generate_random_nums(25000, "nums_rand");
    adicionar_numero_de_arquivo_para_lista("nums_rand", L);
    double tempo_total = 0.0;
    int n_trocas = 0;
    quick_sort_numeros_cres(L, 0, tamanho(L) - 1, &tempo_total, &n_trocas);
    tempo_total = 0.0;
    n_trocas = 0;
    quick_sort_numeros_decr(L, 0, tamanho(L) - 1, &tempo_total, &n_trocas);
    adicionar_numero_de_lista_para_arquivo(L, "nums_ord");
    limpar(L);
    return 0;
}



