#define SUCESSO 1
#define FALHA -1
#define VERDADEIRO 1
#define FALSO 0

typedef struct produto{
    int codigo;
    char nomeProd[30];
    float preco;
    int qtd;
} product;

typedef struct Elemento * lista;

lista * concebe_lista();
void inicializa_lista(lista * list);
void destroi_lista(lista * list);
int push(lista * list, product prod);
int push_inicio(lista * list, product prod);
int push_final(lista * list, product prod);
int push_ordenado(lista * list, product prod);
int pop(lista * list, int codigo);
int lista_vazia(lista * list);
int lista_cheia(lista * list);
int tamanho_lista(lista * list);
int consulta_produto(lista * list, int codigo);
int imprime_lista(lista * list);
int cadastra_produto(lista * list);
int mais_barato(lista * list);
int atualizar_estoque(lista * list);