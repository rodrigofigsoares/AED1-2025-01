#define TAM_MAX_FILA 5

#define FALHA -1
#define SUCESSO 1
#define CHAVE_INVALIDA 0
#define FALSO 0
#define VERDADEIRO 1

typedef struct Elemento {
    int dado;
    int chave;
} elemento;

typedef struct Fila fila;

fila * concebe_fila();
void inicializa_fila(fila * queue);
void destroi_fila(fila * queue);
int tamanho_fila(fila * queue);
int fila_vazia(fila * queue);
int fila_cheia(fila * queue);
int push(fila * queue, elemento * elem);
int pop(fila * queue);
int consulta_primeiro(fila * queue);
int imprime_fila(fila * queue);
int copia_fila(fila * queue1, fila * queue2);