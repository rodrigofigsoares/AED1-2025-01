#define SUCESSO 1
#define FALHA -1
#define VERDADEIRO 1
#define FALSO 0

typedef struct Paciente {
    int codigo;
    char nome[50];
} patient;

typedef struct no_descritor fila;

fila * concebe_fila();
void inicializa_fila(fila * queue);
void destroi_fila(fila * queue);
int consulta_inicio(fila * queue);
int push(fila * queue, patient Paciente);
int pop(fila * queue);
int quantidade_pacientes(fila * queue);
int fila_vazia(fila * queue);
int fila_cheia(fila * queue);
int lista_pacientes(fila * queue);
int tempo_espera(fila * queue);