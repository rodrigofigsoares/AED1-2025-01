#define TAMANHO_MAXIMO_PILHA 3

#define SUCESSO 1
#define FALHA -1
#define CHAVE_INVALIDA 0
#define VERDADEIRO 1
#define FALSO 0

typedef struct Elemento {
    int dado;
    int chave;
} elemento;

typedef struct Pilha pilha;

pilha * concebe_pilha();
void inicializa_pilha(pilha * stack);
void destroi_pilha(pilha * stack);
int tamanho_pilha(pilha * stack);
int pilha_vazia(pilha * stack);
int pilha_cheia(pilha * stack);
int push(pilha * stack, elemento * elem);
int pop(pilha * stack);
int consulta_topo(pilha * stack);
int imprime_pilha(pilha * stack);