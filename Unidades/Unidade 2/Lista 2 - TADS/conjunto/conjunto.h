#define SUCESSO 1
#define FALHA 0
#define TRUE 1
#define FALSE 0
#define CRESCENTE 1
#define DECRESCENTE 0

typedef struct {
    unsigned long long int tamanho;
    unsigned long long int * elementos;
} Conjunto;

// void printFuncoes();
void alocaConjunto(Conjunto *** C);
int criaConjunto(Conjunto ** C);
int conjuntoVazio(Conjunto ** C);
int insereElementoConjunto(unsigned long long int elemento, Conjunto ** C);
int excluirElementoConjunto(unsigned long long int elemento, Conjunto ** C);
int tamanhoConjunto(Conjunto ** C);
int maior(unsigned long long int elemento, Conjunto ** C);
int menor(unsigned long long int elemento, Conjunto ** C);
int pertenceConjunto(unsigned long long int elemento, Conjunto ** C);
int conjuntosIdenticos(Conjunto ** C1, Conjunto ** C2);
int subconjunto(Conjunto ** C1, Conjunto ** C2);
Conjunto ** complemento(Conjunto ** C1, Conjunto ** C2);
Conjunto ** uniao(Conjunto ** C1, Conjunto ** C2);
Conjunto ** interseccao(Conjunto ** C1, Conjunto ** C2);
Conjunto ** diferenca(Conjunto ** C1, Conjunto ** C2);
void ordenaConjunto(Conjunto ** C);
void mostraConjunto(Conjunto ** C, int ordem);
int copiarConjunto(Conjunto ** C1, Conjunto ** C2);
int destroiConjunto(Conjunto ** C);