/*---------------------------------------------------------------------------*/
/* UNIVERSIDADE FEDERAL DE GOIÁS - UFG                                       */
/* INSTITUTO DE INFORMÁTICA - INF                                            */
/*                                                                           */
/* Disciplina: Algoritmos e Estruturas de Dados - 1                          */
/* Professor.: Wanderley de Souza Alencar                                    */
/*                                                                           */
/* Observacoes:                                                              */
/*                                                                           */
/* Este programa implementa, de maneira simples, um conjunto basico de ope-  */
/* racoes sobre a estrutura de PILHA, que utiliza a reprepresentação por     */
/* contiguidade, ou seja, um VETOR representa a PILHA.                       */
/* O tamanho máximo do vetor é dado pela constante:                          */
/*   TAMANHO_MAXIMO_PILHA                                                    */
/*                                                                           */
/* A chave de cada célula da PILHA  está no intervalo 1..N, sendo o valor    */
/* ZERO considerado flag de "chave inválida" -- CHAVE_INVALIDA               */
/*                                                                           */
/* Operações:                                                                */
/*                                                                           */
/* 0) Criar uma pilha vazia                 -> criarPilha                    */
/* 1) Insercao de Elemento na pilha         -> push                          */
/* 2) Remocao  de Elemento da pilha         -> pop                           */
/* 5) Mostrar, no video, a pilha            -> mostrarPilha                  */
/* 6) Tamanho (numero de Celulas) da pilha  -> tamPilha                      */
/*                                                                           */
/*                                                                           */
/* A estrutura de cada célula da pilha obedece ao seguinte leiaute:          */
/*                                                                           */
/*              +-------+-------+                                            */
/*              | chave | dado  |                                            */
/*              +-------+-------+                                            */
/*                                                                           */
/*---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define SUCESSO                1
#define FALHA                 -1
#define CHAVE_INVALIDA         0

#define TAMANHO_MAXIMO_PILHA   100

/*
 * Representação de uma célula da pilha: [<chave>, <dado>], onde a chave pode 
 * estar no intervalo de 1 ao "máximo inteiro" e o valor ZERO é considerado
 * um valor inválido -- flag
 */
typedef struct elemento { 
     unsigned int chave;
     unsigned int dado;
} Elemento;  

/*
 * Representação da pilha 
 */
typedef struct pilha {
    Elemento elementos  [TAMANHO_MAXIMO_PILHA];
    unsigned int    tamanho;
} Pilha; 

/*
* Protótipos das funções
*/

int      criarPilha      (Pilha * pilha);
int      tamanhoPilha    (Pilha pilha);
int      push            (Pilha * pilha, Elemento elemento);
Elemento pop             (Pilha * pilha);
void     mostrarElemento (Elemento elemento);
void     mostrarPilha    (Pilha pilha);

/*
 * Criação da pilha ...
 *     Pode-se criar uma pilha  inicialmente vazia ou com uma <chave/dado>
 *     já inserida.
 * 
 */
int criarPilha(Pilha * pilha ) {
    pilha->tamanho = 0;
    return (SUCESSO);
}

/*
 * Determina, e retorna, o número de células presentes na pilha.
 */
int tamanhoPilha(Pilha pilha) {
    unsigned int i;
    
    if (pilha.tamanho >= 0) { 
       return(pilha.tamanho);   
    }
    else {
       return(FALHA);
    }
}

/*
 *  A inserção de uma <chave/dado> pode ocorrer...
 *    - no final da pilha : após a última célula.
 */

int push (Pilha * pilha, Elemento elemento) {
    if (pilha->tamanho == TAMANHO_MAXIMO_PILHA) {
        return(FALHA); // Overflow da pilha. 
    }
    else { 
       // 
       // Insere a célula recebida após a última célula atualmente
       // presente na pilha 
       // 
       pilha->elementos[pilha ->tamanho] = elemento;
       pilha->tamanho++;
       return(SUCESSO);
    }
}
/*
 *  A removção de uma <chave/dado> pode ocorrer...
 *    - no final da pilha
 */

Elemento pop (Pilha * pilha) {
    unsigned int i;
    Elemento elementoResultado;
        
    if (pilha-> tamanho == 0) {     
        elementoResultado.chave = CHAVE_INVALIDA;
        return(elementoResultado);
    }
    else {
       elementoResultado = pilha->elementos[((pilha->tamanho) - 1)];
       pilha->tamanho--;
       return(elementoResultado);
    }
}
/*
 * Apresenta, no dispositivo de saída (monitor de vídeo), o valor
 * da <chave> e do <dado> de uma célula recebida como entrada.
 */
void mostrarElemento(Elemento elemento) {
    printf("Chave......: %u\n", elemento.chave);
    printf("Dado.......: %u\n", elemento.dado);
}

/*
 * Mostra as células da pilha , a partir de sua 'cabeça' até sua 'cauda'.
 */
void mostrarPilha(Pilha pilha) {
    int i;
    
    if (pilha.tamanho == 0) { 
       printf("Atenção: A pilha  está vazia.\n");   
    }
    else {
       printf("A pilha possui %u elementos.\n\n", pilha.tamanho); 
       for (i = 0; (i < pilha.tamanho); i++) {
           printf("Elemento nº: %u\n", (i+1)); 
           mostrarElemento(pilha.elementos[(pilha.tamanho - 1) - i]);
       }
    }
}
/*
 * Programa principal: utiliza as funções de pilha
 * 
 */
int main(int argc, char** argv) {
    int          i;
    int          intResultado;
    Pilha         pilha;
    Elemento       elemento;
    //
    // Cria, inicialmente, uma pilha  vazia...
    //
    intResultado =  criarPilha(&pilha);
    if (intResultado == FALHA) {
        return(EXIT_FAILURE);
    }
    mostrarPilha(pilha);
    //
    // Inserção na pilha ...
    // 
    printf("Inserção na pilha:\n");
    printf("Observação: Forneça <chave> igual [0] para finalizar.\n\n");
    do { 
        printf("Chave: ");
        scanf("%u", &elemento.chave);
        if (elemento.chave != CHAVE_INVALIDA) {
           printf("Dado.: ");
           scanf("%u", &elemento.dado);
           intResultado = push(&pilha, elemento);
           if (intResultado == CHAVE_INVALIDA) {
               printf("Erro: Problema ao inserir na pilha .\n");
               printf("      Aplicação interrompida por falha.\n");
               return(EXIT_FAILURE);
           }
        }
    } while (elemento.chave != CHAVE_INVALIDA);
    mostrarPilha(pilha);  
    printf("\n\n");
    printf("Remoção de célula da pilha:\n");
    printf("Observação: Digite...   [1] para remover    [0] para finalizar.\n\n");
    do { 
        printf("Operação: ");
        scanf("%u", &elemento.chave);
        if (elemento.chave != CHAVE_INVALIDA) {
           elemento = pop(&pilha);
           if (elemento.chave == CHAVE_INVALIDA) {
               printf("Erro: Problema ao remover da pilha .\n");
               printf("      A pilha  está vazia.\n");
               printf("      Aplicação interrompida por falha.\n");
               return(EXIT_FAILURE);
           }
           else {
               printf("Remoção realizada: \n\n");
               mostrarElemento(elemento);
           }
        }
    } while (elemento.chave != CHAVE_INVALIDA);
    mostrarPilha(pilha);     
    return (EXIT_SUCCESS);
}

