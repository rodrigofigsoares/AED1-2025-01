#define SUCESSO 1
#define FALHA -1
#define VERDADEIRO 1
#define FALSO 0

typedef struct Aluno {
    char nome[50];
    int matricula;
} student;

typedef struct descritor lista;

lista * concebe_lista();
void inicializa_lista(lista * list);
void destroi_lista(lista * list);
int push(lista * list, student aluno);
int push_inicio(lista * list, student aluno);
int push_final(lista * list, student aluno);
int push_ordenado(lista * list, student aluno);
int pop(lista * list);
int pop_inicio(lista * list);
int pop_final(lista * list);
int pop_especifico(lista * list, int matricula);
int lista_vazia(lista * list);
int lista_cheia(lista * list);
int tamanho_lista(lista * list);
int consulta_elemento(lista * list);
int consulta_por_matricula(lista * list, int matricula);
int consulta_por_nome(lista * list, char * nome);
int consulta_por_posicao(lista * list, int position);
int imprime_lista(lista * list);