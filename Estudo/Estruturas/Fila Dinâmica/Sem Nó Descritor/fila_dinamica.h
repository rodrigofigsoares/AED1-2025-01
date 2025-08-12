#define SUCESSO 1
#define FALHA -1
#define VERDADEIRO 1
#define FALSO 0

typedef struct Aluno {
    char nome[50];
    char matricula[10];
} student;

typedef struct Elemento * fila;

fila * concebe_fila();
void inicializa_fila(fila * queue);
void destroi_fila(fila * queue);
int consulta_inicio(fila * queue);
int push(fila * queue, student aluno);
int pop(fila * queue);
int tamanho_fila(fila * queue);
int fila_vazia(fila * queue);
int fila_cheia(fila * queue);
int imprime_fila(fila * queue);