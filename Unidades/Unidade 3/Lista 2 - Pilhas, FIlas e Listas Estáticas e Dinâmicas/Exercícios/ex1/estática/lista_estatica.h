#define TAM_MAX_LISTA 10

#define FALHA -1
#define SUCESSO 1
#define MATRICULA_INVALIDA -1
#define FALSO 0
#define VERDADEIRO 1

typedef struct Aluno {
    char nome[50];
    int matricula;
} student;

typedef struct Lista lista;

lista * concebe_lista();
void inicializa_lista(lista * list);
void destroi_lista(lista * list);
int tamanho_lista(lista * list);
int lista_vazia(lista * list);
int lista_cheia(lista * list);
int push_inicio(lista * list, student * elem);
int push_ordenado(lista * list, student * elem);
int push_final(lista * list, student * elem);
int pop_inicio(lista * list);
int pop_especifico(lista * list, int matricula);
int pop_final(lista * list);
int consulta_por_matricula(lista * list, int matricula);
int imprime_lista(lista * list);
int remove_n_primeiros(lista * list, int qtd);
int remove_n_ultimos(lista * list, int qtd);