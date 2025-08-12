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
/* racoes sobre a estrutura de LISTA LINEAR SIMPLES, que utiliza a repre-    */
/* sentação por contiguidade, ou seja, um VETOR representa a lista.          */
/* O tamanho máximo do vetor é dado pela constante:                          */
/*   TAMANHO_MAXIMO_LISTA                                                    */
/*                                                                           */
/* A chave de cada célula da lista está no intervalo 1..N, sendo o valor     */
/* ZERO considerado flag de "chave inválida" -- CHAVE_INVALIDA               */
/*                                                                           */
/* Operações:                                                                */
/*                                                                           */
/* 0) Criar uma lista vazia                 -> criarListaVazia               */
/* 1) Criar lista com uma Celula            -> criarListaChave               */
/* 1) Insercao de Celula no inicio da lista -> insInicio                     */
/* 2) Insercao de Celula no final  da lista -> insFinal                      */
/* 3) Remocao  de Celula no inicio da lista -> remInicio                     */
/* 4) Remocao  de Celula no final  da lista -> remFinal                      */
/* 5) Mostrar, no video, a lista            -> mostraLista                   */
/* 6) Tamanho (numero de NOS) da lista      -> tamLista                      */
/* 7) Insercao de NO por ordem de chave     -> insOrdem                      */
/* 8) Remocao de NO por chave               -> remChave                      */
/* 9) Ordenar lista por ordem de chave      -> ordenaLista                   */
/* A) Concatena duas listas                 -> concatListas                  */
/* B) Consulta uma certa chave na lista     -> consultaChave                 */
/* C) Consulta certa posicao da lista       -> consultaPosicao               */
/*                                                                           */
/*                                                                           */
/* A estrutura de cada célula da lista obedece ao seguinte leiaute:          */
/*                                                                           */
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

#define TAMANHO_MAXIMO_LISTA 100

/*
 * Representação de uma célula da lista: [<chave>, <dado>], onde a chave pode 
 * estar no intervalo de 1 ao "máximo inteiro" e o valor ZERO é considerado
 * um valor inválido -- flag
 */
typedef struct { 
     unsigned int chave;
     unsigned int dado;
} Celula;  

/*
 * Representação da lista linear simples
 */
typedef struct {
    Celula celulas  [TAMANHO_MAXIMO_LISTA];
    unsigned int    tamanho;
} ListaLinear; 

/*
 * Criação da lista...
 *     Pode-se criar uma lista inicialmente vazia ou com uma <chave/dado>
 *     já inserida.
 * 
 */
int criarListaVazia(ListaLinear * lista) {
    lista->tamanho = 0;
    return (SUCESSO);
}

int criarListaChave(ListaLinear * lista, Celula celula) {
    lista->celulas[0] = celula;
    lista->tamanho    = 1;
    return (SUCESSO);
}

/*
 * Determina, e retorna, o número de células presentes na lista linear.
 */
int tamanhoLista(ListaLinear lista) {
    if (lista.tamanho >= 0) { 
       return(lista.tamanho);   
    }
    else {
       return(FALHA);
    }
}

/*
 *  A inserção de uma <chave/dado> pode ocorrer...
 *    - no início da lista: antes da primeira célula;
 *    - no final da lista: após a última célula;
 *    - em ordem ASCENDENTE de chave. 
 */
int insInicio (ListaLinear * lista, Celula celula) {
    int i;
    
    if (lista->tamanho == TAMANHO_MAXIMO_LISTA) {
        return(FALHA);                 // Overflow da lista. 
    }
    else {
       //
       // Move cada uma das células da lista uma posição à frente, 
       // liberando espaço no início da lista para inserção 
       // 
       for (i = lista->tamanho; (i > 0); i--) {
           lista->celulas[i] = lista->celulas[i-1];
       } 
       //
       // Insere a célula recebida no início da lista.
       //
       lista->celulas[0] = celula;
       lista->tamanho++;
       return(SUCESSO);
    }
}

int insFinal (ListaLinear * lista, Celula celula) {
    int i;
    Celula auxiliar;
    
    if (lista->tamanho == TAMANHO_MAXIMO_LISTA) {
        return(FALHA);                 // Overflow da lista. 
    }
    else { 
       // 
       // Insere a célula recebida após a última célula atualmente
       // presente na lista
       // 
       lista->celulas[lista->tamanho] = celula;
       lista->tamanho++;
       return(SUCESSO);
    }
}

int insOrdem (ListaLinear * lista, Celula celula) {
    int i, j;
    
    if (lista->tamanho == TAMANHO_MAXIMO_LISTA) {
        return(FALHA);                 // Overflow da lista. 
    }
    else {
        if (lista->tamanho == 0) {     // Lista está vazia?        
            return (insInicio(lista, celula));
        }
        else {
            if (celula.chave < lista->celulas[0].chave) {
                //    
                // A célula recebida tem chave menor que a da primeira
                // célula da lista --> a insira no início da lista
                // 
                return (insInicio(lista, celula));
            } 
            else { 
                if (celula.chave >= lista->celulas[lista->tamanho-1].chave) {
                    // 
                    // A célula recebida tem chave maior que a da última
                    // célula da lista --> a insira no final da lista
                    //
                    return (insFinal(lista, celula));
                } 
                else {
                   // 
                   // Localiza o 'local' em que a célula recebida deve ser
                   // inserida e a insere. Se necessário, 'abre espaço' no 
                   // meio da lista atual.
                   // 
                   i = 0;
                   while ((celula.chave >= lista->celulas[i].chave) && (i < lista->tamanho)) {
                         i++;
                   }
                   if (i == lista->tamanho) {
                       return(insFinal(lista, celula));
                   }
                   else {
                       for (j = lista->tamanho;(j > i); j--) {
                            lista->celulas[j] = lista->celulas[j-1];   
                       }
                       lista->celulas[i] = celula;
                       lista->tamanho++;
                   }
                }
           }
        }
    }
}

/*
 *  A remoção de uma <chave/dado> pode ocorrer...
 *    - no início da lista: a primeira célula;
 *    - no final da lista: a última célula;
 *    - baseada no valor da chave (a lista está em ordem ASCENDENTE de chaves).
 *   
 *  Observação: A remoção devolve a célula removida ou uma célula com chave 
 *              igual a CHAVE_INVALIDA, indicando erro na remoção. 
 */
Celula remInicio (ListaLinear * lista) {
    int i;
    Celula   celulaResultado;
        
    if (lista->tamanho == 0) {        // A lista está vazia ?
        celulaResultado.chave = CHAVE_INVALIDA;
        return(celulaResultado);
    }
    else {
       // 
       // Remove a primeira célula da lista e atualiza o tamanho desta...
       // 
       celulaResultado = lista->celulas[0];
       for (i = 0; (i < lista->tamanho - 1); i++) {
           lista->celulas[i] = lista->celulas[i+1];
       } 
       lista->tamanho--;
       return(celulaResultado);
    }
}

Celula remFinal (ListaLinear * lista) {
  
    Celula celulaResultado;
    
    if (lista->tamanho == 0) {         // A lista está vazia? 
        celulaResultado.chave = CHAVE_INVALIDA;
        return(celulaResultado);
    }
    else { 
       //
       // Remove a última célula da lista e atualiza o tamanho desta...
       // 
       celulaResultado = lista->celulas[lista->tamanho - 1]; 
       lista->tamanho--;
       return(celulaResultado);
    }
}

Celula remChave (ListaLinear * lista, Celula celula) {
    int          i, j, k;
    unsigned int intQuantidadeRemocoes; 
    
    Celula       celulaResultado;
    
    if (lista->tamanho == 0) {       // A lista está vazia? 
        celulaResultado.chave = CHAVE_INVALIDA;
        return(celulaResultado);
    }
    else {
        if (celula.chave == lista->celulas[0].chave) {
            //    
            // A célula a ser removida é a primeira!
            //
            while (celula.chave == lista->celulas[0].chave) {
                  celulaResultado = remInicio(lista);
                  if (celulaResultado.chave == CHAVE_INVALIDA) {
                      return(celulaResultado);  
                  }
            }
        }
        else {
            if (celula.chave == lista->celulas[lista->tamanho - 1].chave) {
                // 
                // A célula a ser removida é a última!
                // 
                while (celula.chave == lista->celulas[lista->tamanho - 1].chave) {
                      celulaResultado = remFinal(lista);
                      if (celulaResultado.chave == CHAVE_INVALIDA) {
                          return(celulaResultado);  
                      }
                }
            } 
            else { 
                // 
                // Procura pela chave a ser removida
                // 
                i = 0;
                while ((celula.chave > lista->celulas[i].chave) && (i < lista->tamanho)) {
                      i++;
                }
                if (i == lista->tamanho) {
                    //
                    // A chave a ser removida não foi encontrada na lista!
                    //
                    celulaResultado.chave = CHAVE_INVALIDA;
                    return(celulaResultado);
                }
                else {
                    //
                    // Conta quanta células da lista possuem a (mesma) chave 
                    // a ser removida
                    //
                    intQuantidadeRemocoes = 0;
                    j = i;
                    while ((celula.chave == lista->celulas[j].chave) && (j < lista->tamanho)) {
                        intQuantidadeRemocoes++;
                        j++;
                    }
                    if (intQuantidadeRemocoes == 0) {
                       celulaResultado.chave = CHAVE_INVALIDA;
                       return(celulaResultado);
                    }
                    else {
                       // 
                       // Remove todas as células cuja chave corresponda à 
                       // solicitada
                       // 
                       celulaResultado = lista->celulas[i]; 
                       for (j = i; (j < (lista->tamanho - intQuantidadeRemocoes)); j++) {
                           if (j + intQuantidadeRemocoes < lista->tamanho) {
                              lista->celulas[j] = lista->celulas[j + intQuantidadeRemocoes];
                           }   
                       }
                       lista->tamanho -= intQuantidadeRemocoes;
                       return(celulaResultado);
                    }
                }
            }
        }
    }
}
/*
 * Retorna a célula (primeira) cuja chave é igual à solicitada ou 
 * uma célula com chave igual a CHAVE_INVALIDA, indicando que não encontrou a
 * célula desejada na lista. 
 */
Celula consultaChave(ListaLinear lista, Celula celula) {
    unsigned int i;
    
    for (i = 0; (i < lista.tamanho); i++) {
        if (lista.celulas[i].chave == celula.chave) {
            return(lista.celulas[i]);
        }
    }
    celula.chave = CHAVE_INVALIDA;
    return(celula);
}

/*
 * Retorna a célula cuja posição é igual à solicitada ou 
 * uma célula com chave igual a CHAVE_INVALIDA, indicando que não existe a
 * célula desejada na lista. 
 * 
 * A primeira célula está na posição UM.
 */
Celula consultaPosicao(ListaLinear lista, unsigned int intPosicao) {
    
    Celula celulaResultado;
    
    if ((intPosicao > 0) && (intPosicao <= lista.tamanho)) { 
        celulaResultado = lista.celulas[intPosicao - 1];
    }
    else {
        celulaResultado.chave = CHAVE_INVALIDA;
    }
    return(celulaResultado);
}

/*
 * Concatena duas listas, desde que a lista final não ultrapasse 
 * o tamanho máximo permitido. Neste caso, retorna uma lista linear
 * "falsa", cujo tamanho é igual a FALHA, indicando que ocorreu um 
 * erro durante a concatenação.
 */
ListaLinear concatListas(ListaLinear *lista1, ListaLinear *lista2) {
    unsigned int i;
    int          intResultado;
    Celula       celula;
    ListaLinear  listaResultado;
    
    i = criarListaVazia(&listaResultado);
    if ((lista1->tamanho + lista2->tamanho) > TAMANHO_MAXIMO_LISTA) {
        listaResultado.tamanho = FALHA;
        return (listaResultado); 
    }
    else {
        for (i = 0; (i < lista1->tamanho); i++) {
            celula       = consultaPosicao(*lista1,(unsigned int) (i+1));
            intResultado = insFinal(&listaResultado, celula);
            if (intResultado == CHAVE_INVALIDA) {
                listaResultado.tamanho = FALHA;
                return (listaResultado);
            }
        }
        for (i = 0; (i < lista2->tamanho); i++) {
            celula       = consultaPosicao(*lista2,(unsigned int) (i+1));
            intResultado = insFinal(&listaResultado, celula);
            if (intResultado == CHAVE_INVALIDA) {
                listaResultado.tamanho = FALHA;
                return (listaResultado);
            }
        }
    }
}

/*
 * Apresenta, no dispositivo de saída (monitor de vídeo), o valor
 * da <chave> e do <dado> de uma célula recebida como entrada.
 */
void mostrarCelula(Celula celula) {
    printf("Chave......: %u\n", celula.chave);
    printf("Dado.......: %u\n", celula.dado);
}

/*
 * Mostra as células da lista, a partir de sua 'cabeça' até sua 'cauda'.
 */
void mostrarLista(ListaLinear lista) {
    unsigned int i;
    
    if (lista.tamanho == 0) { 
       printf("Atenção: A lista está vazia.\n");   
    }
    else {
       printf("A lista linear possui %u elementos.\n\n", lista.tamanho); 
       for (i = 0; (i < lista.tamanho); i++) {
           printf("Elemento nº: %u\n", (i+1)); 
           mostrarCelula(lista.celulas[i]);
       }
    }
}
/*
 * Programa principal: utiliza as funções de lista linear
 * 
 */
int main(int argc, char** argv) {
    unsigned int i;
    int          intResultado;
    ListaLinear  listaLinear;
    Celula       celula;
    //
    // Cria, inicialmente, uma lista vazia...
    //
    intResultado =  criarListaVazia(&listaLinear);
    if (intResultado == FALHA) {
        return(EXIT_FAILURE);
    }
    mostrarLista(listaLinear);
    //
    // Inserção no início da lista...
    //
    printf("Inserção no INÍCIO da lista:\n");
    printf("Observação: Forneça <chave> igual a [0] para finalizar.\n\n");
    do { 
        printf("Chave: ");
        scanf("%u", &celula.chave);
        if (celula.chave != CHAVE_INVALIDA) {
           printf("Dado.: ");
           scanf("%u", &celula.dado);
           intResultado = insInicio(&listaLinear, celula);
           if (intResultado == FALHA) {
               printf("Erro: Problema ao inserir no INÍCIO da lista.\n");
               printf("      Aplicação interrompida por falha.\n");
               return(EXIT_FAILURE);
           }
        }
    } while (celula.chave != CHAVE_INVALIDA); 
    mostrarLista(listaLinear);
    //
    // Inserção no final da lista...
    // 
    printf("Inserção no FINAL da lista:\n");
    printf("Observação: Forneça <chave> igual [0] para finalizar.\n\n");
    do { 
        printf("Chave: ");
        scanf("%u", &celula.chave);
        if (celula.chave != CHAVE_INVALIDA) {
           printf("Dado.: ");
           scanf("%u", &celula.dado);
           intResultado = insFinal(&listaLinear, celula);
           if (intResultado == CHAVE_INVALIDA) {
               printf("Erro: Problema ao inserir no FINAL da lista.\n");
               printf("      Aplicação interrompida por falha.\n");
               return(EXIT_FAILURE);
           }
        }
    } while (celula.chave != CHAVE_INVALIDA);
    mostrarLista(listaLinear);
     
    //
    // Inserção ordenada (considera ordem ASCENDENTE de chaves)...
    // 
    printf("\n\n");
    printf("Inserção em ORDEM da lista:\n");
    printf("Observação: Forneça <chave> igual a [0] para finalizar.\n\n");
    do { 
        printf("Chave: ");
        scanf("%u", &celula.chave);
        if (celula.chave != CHAVE_INVALIDA) {
           printf("Dado.: ");
           scanf("%u", &celula.dado);
           intResultado = insOrdem(&listaLinear, celula);
           if (intResultado == CHAVE_INVALIDA) {
               printf("Erro: Problema ao inserir em ORDEM na lista.\n");
               printf("      Aplicação interrompida por falha.\n");
               return(EXIT_FAILURE);
           }
        }
    } while (celula.chave != CHAVE_INVALIDA);
    mostrarLista(listaLinear);
   
    printf("\n\n");
    printf("Remoção de célula no INÍCIO da lista:\n");
    printf("Observação: Digite...   [1] para remover    [0] para finalizar.\n\n");
    do { 
        printf("Operação: ");
        scanf("%u", &celula.chave);
        if (celula.chave != CHAVE_INVALIDA) {
           celula = remInicio(&listaLinear);
           if (celula.chave == CHAVE_INVALIDA) {
               printf("Erro: Problema ao remover no INÍCIO da lista.\n");
               printf("      A lista está vazia.\n");
               printf("      Aplicação interrompida por falha.\n");
               return(EXIT_FAILURE);
           }
           else {
               printf("Primeira célula da lista foi removida: \n\n");
               mostrarCelula(celula);
           }
        }
    } while (celula.chave != CHAVE_INVALIDA);
    mostrarLista(listaLinear);
    
    printf("\n\n");
    printf("Remoção de célula no FINAL da lista:\n");
    printf("Observação: Digite...   [1] para remover    [0] para finalizar.\n\n");
    do { 
        printf("Operação: ");
        scanf("%u", &celula.chave);
        if (celula.chave != CHAVE_INVALIDA) {
           celula = remFinal(&listaLinear);
           if (celula.chave == CHAVE_INVALIDA) {
               printf("Erro: Problema ao remover no FINAL da lista.\n");
               printf("      A lista está vazia.\n");
               printf("      Aplicação interrompida por falha.\n");
               return(EXIT_FAILURE);
           }
           else {
               printf("Última célula da lista foi removida: \n\n");
               mostrarCelula(celula);
           }
        }
    } while (celula.chave != CHAVE_INVALIDA);
    mostrarLista(listaLinear);
    
    printf("\n\n");
    printf("Remoção de célula por CHAVE:\n");
    printf("Digite o valor da chave desejada ou [0] para finalizar.\n\n");
    do { 
        printf("Chave: ");
        scanf("%u", &celula.chave);
        if (celula.chave != CHAVE_INVALIDA) {
           celula = remChave(&listaLinear, celula);
           if (celula.chave == CHAVE_INVALIDA) {
               printf("Erro: Problema ao remover por CHAVE na lista.\n");
               printf("      A lista está vazia ou a chave solicitada não foi encontrada na lista.\n");
               printf("      Aplicação interrompida por falha.\n");
               return(EXIT_FAILURE);
           }
           else {
               printf("\n\n");
               printf("Todas as células com a chave fornecida foram removidas.\n\n");
               mostrarLista(listaLinear);
           }
        }
    } while (celula.chave != CHAVE_INVALIDA);
    
    printf("\n\n");
    printf("Consulta a lista por CHAVE:\n");
    printf("Digite o valor da chave desejada ou [0] para finalizar.\n\n");
    do { 
        printf("Chave: ");
        scanf("%u", &celula.chave);
        if (celula.chave != CHAVE_INVALIDA) {
           celula = consultaChave(listaLinear, celula);
           if (celula.chave == CHAVE_INVALIDA) {
               printf("Célula com chave solicitada não está na lista.\n\n");
               celula.chave  = 1; 
           }
           else {
               printf("\n\n");
               printf("Célula com chave solicitada encontrada:\n\n");
               mostrarCelula(celula);
           }
        }
    } while (celula.chave != CHAVE_INVALIDA);

    return (EXIT_SUCCESS);
}

