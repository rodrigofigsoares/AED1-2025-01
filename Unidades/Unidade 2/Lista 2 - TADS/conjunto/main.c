#include <stdio.h>
#include "conjunto.h"

int main() {
    Conjunto ** C1, **C2, **Complemento, **Uniao, **Interseccao, **Diferenca;
    unsigned long long int qtd, temp;

    alocaConjunto(&C1);
    if(criaConjunto(C1) == FALHA) return 0;
    printf("Informe quantos elementos há no conjunto C1: ");
    scanf("%llu", &qtd);
    printf("Informe os elementos de C1:\n");
    for(int i=0;i<qtd;i++)
    {
        scanf("%llu", &temp);
        if(insereElementoConjunto(temp, C1) == FALHA) return 0;
    }
    printf("C1 = ");
    mostraConjunto(C1, CRESCENTE);
    printf("|C1| = %d\n", tamanhoConjunto(C1));

    alocaConjunto(&C2);
    if(criaConjunto(C2) == FALHA) return 0;
    if(conjuntoVazio(C2) == TRUE) printf("C2 = Vazio\n");
    else printf("C2 = Não vazio\n");
    printf("Informe quantos elementos há no conjunto C2: ");
    scanf("%llu", &qtd);
    printf("Informe os elementos de C2:\n");
    for(int i=0;i<qtd;i++)
    {
        scanf("%llu", &temp);
        if(insereElementoConjunto(temp, C2) == FALHA) return 0;
    }
    printf("C2 = ");
    mostraConjunto(C2, DECRESCENTE);
    printf("|C2| = %d\n", tamanhoConjunto(C2));
    if(conjuntoVazio(C2) == TRUE) printf("C2 = Vazio\n");
    else printf("C2 = Não vazio\n");

    alocaConjunto(&Complemento);
    Complemento = complemento(C1, C2);
    printf("C2 complemento de C1 = ");
    mostraConjunto(Complemento, CRESCENTE);
    printf("|C2 complemento de C1| = %d\n", tamanhoConjunto(Complemento));

    alocaConjunto(&Uniao);
    Uniao = uniao(C1, C2);
    printf("C1 U C2 = ");
    mostraConjunto(Uniao, CRESCENTE);
    printf("|C1 U C2| = %d\n", tamanhoConjunto(Uniao));

    alocaConjunto(&Interseccao);
    Interseccao = interseccao(C1, C2);
    printf("C1 intersecção C2 = ");
    mostraConjunto(Interseccao, CRESCENTE);
    printf("|C1 intersecção C2| = %d\n", tamanhoConjunto(Interseccao));

    alocaConjunto(&Diferenca);
    Diferenca = diferenca(C1, C2);
    printf("C1 - C2 = ");
    mostraConjunto(Diferenca, CRESCENTE);
    printf("|C1 - C2| = %d\n", tamanhoConjunto(Diferenca));

    printf("Copiando C1 para C2...");
    if(copiarConjunto(C1, C2) == FALHA) return 0;
    printf("C1 = ");
    mostraConjunto(C1, CRESCENTE);
    printf("C2 = ");
    mostraConjunto(C2, CRESCENTE);

    printf("Informe um elemento para ser removido de C1: ");
    scanf("%llu", &temp);
    printf("C1 antes = ");
    mostraConjunto(C1, CRESCENTE);
    printf("|C1| = %d\n", tamanhoConjunto(C1));
    if(excluirElementoConjunto(temp, C1) == FALHA) return 0;
    printf("C1 depois = ");
    mostraConjunto(C1, CRESCENTE);
    printf("|C1| = %d\n", tamanhoConjunto(C1));
    
    printf("\nInforme um valor: ");
    scanf("%llu", &temp);
    printf("Quantidade de valores maiores que %llu em C1 = %d\n", temp, maior(temp, C1));
    printf("Quantidade de valores menores que %llu em C1 = %d\n", temp, menor(temp, C1));

    printf("Informe um valor para verificar se ele pertence ao conjunto C1: ");
    scanf("%llu", &temp);
    if(pertenceConjunto(temp, C1) == TRUE) printf("%llu pertence a C1\n", temp);
    else printf("%llu não pertence a C1\n", temp);

    if(conjuntosIdenticos(C1, C2) == TRUE) printf("C1 = C2\n");
    else printf("C1 != C2\n");

    if(subconjunto(C1, C2) == TRUE) printf("C1 é subconjunto de C2\n");
    else printf("C1 não é subconjunto de C2\n");

    destroiConjunto(C1);
    destroiConjunto(C2);
    destroiConjunto(Complemento);
    destroiConjunto(Uniao);
    destroiConjunto(Interseccao);
    destroiConjunto(Diferenca);
    return 0;
}