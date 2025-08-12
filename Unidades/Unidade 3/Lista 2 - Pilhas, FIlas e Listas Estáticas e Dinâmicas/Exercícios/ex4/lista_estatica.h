#define TAM_MAX_LISTA 10

#define FALHA -1
#define SUCESSO 1
#define FALSO 0
#define VERDADEIRO 1

typedef struct Lista lista;

lista * concebe_lista();
void inicializa_lista(lista * list);
void destroi_lista(lista * list);
int tamanho_lista(lista * list);
int lista_vazia(lista * list);
int lista_cheia(lista * list);
int push_inicio(lista * list, int num);
int push_ordenado(lista * list, int num);
int push_final(lista * list, int num);
int pop_inicio(lista * list);
int pop_especifico(lista * list);
int pop_final(lista * list);
int imprime_lista(lista * list);
int quantidade_pares(lista * list);
float media_elementos(lista * list);
int maior_elemento(lista * list);
int menor_elemento(lista * list);
int somatorio_elementos(lista * list);
int qtd_primos(lista * list);
int verifica_primo(int num);