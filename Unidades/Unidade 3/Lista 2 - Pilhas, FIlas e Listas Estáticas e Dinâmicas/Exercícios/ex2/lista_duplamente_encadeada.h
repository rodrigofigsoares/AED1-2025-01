#define SUCESSO 1
#define FALHA -1
#define VERDADEIRO 1
#define FALSO 0

typedef struct Elemento * lista;

lista * concebe_lista();
void inicializa_lista(lista * list);
void destroi_lista(lista * list);
int push(lista * list, int num);
int pop(lista * list);
int pop_inicio(lista * list);
int pop_final(lista * list);
int pop_especifico(lista * list, int num);
int lista_vazia(lista * list);
int lista_cheia(lista * list);
int tamanho_lista(lista * list);
int consulta_elemento(lista * list);
int imprime_lista(lista * list);