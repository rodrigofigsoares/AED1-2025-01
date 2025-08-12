#define TAM_MAX_FILA 5

#define SUCESSO 1
#define FALHA -1
#define INVALIDO 0
#define VERDADEIRO 1
#define FALSO 0

typedef struct Elemento {
    char nome[50];
    int prioridade;
} Paciente;

typedef struct Fila_Prioridade prio;

prio * concebe_fila_prioridade();
void inicializa_fila(prio * fila);
int push_prioridade(prio * fila, Paciente * paciente);
int pop_prioridade(prio * fila);
int consulta_frente(prio * fila);
void destroi_fila(prio * fila);
int tamanho_fila(prio * fila);
int fila_cheia(prio * fila);
int fila_vazia(prio * fila);
int imprime_fila(prio * fila);
