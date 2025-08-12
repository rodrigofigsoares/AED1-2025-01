#define TAM_MAX_LISTA 10

#define FALHA -1
#define SUCESSO 1
#define CHAVE_INVALIDA 0
#define FALSO 0
#define VERDADEIRO 1

typedef struct Elemento {
    int dado;
    int chave;
} elemento;

typedef struct Lista lista;

lista * concebe_lista();
void inicializa_lista(lista * list);
void destroi_lista(lista * list);
int tamanho_lista(lista * list);
int lista_vazia(lista * list);
int lista_cheia(lista * list);
int push_inicio(lista * list, elemento * elem);
int push_ordenado(lista * list, elemento * elem);
int push_final(lista * list, elemento * elem);
int pop_inicio(lista * list);
int pop_especifico(lista * list);
int pop_final(lista * list);
int consulta_por_dado(lista * list, int dado);
int consulta_por_chave(lista * list, int chave);
int imprime_lista(lista * list);

