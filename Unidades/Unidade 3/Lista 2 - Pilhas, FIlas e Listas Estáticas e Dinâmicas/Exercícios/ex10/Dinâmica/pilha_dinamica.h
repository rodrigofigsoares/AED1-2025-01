#define SUCESSO 1
#define FALHA -1
#define VERDADEIRO 1
#define FALSO 0

typedef struct Elemento * pilha;
// pilha * stack ==> struct Elemento ** stack

pilha * concebe_pilha();
void inicializa_pilha(pilha * stack);
void destroi_pilha(pilha * stack);
int consulta_topo(pilha * stack);
int push(pilha * stack, int num);
int pop(pilha * stack);
int tamanho_pilha(pilha * stack);
int pilha_vazia(pilha * stack);
int pilha_cheia(pilha * stack);
int imprime_pilha(pilha * stack);
int qtd_impares(pilha * stack);