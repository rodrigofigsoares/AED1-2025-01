typedef struct item Item;

typedef struct lista Lista;

Lista * criar_lista ();

int limpar (Lista * LISTA);

int adicionar_elem_final (Lista * LISTA, int ELEM);

int remover_elem_final (Lista * LISTA);

int adicionar_elem_inicio (Lista * LISTA, int ELEM);

int remover_elem_inicio (Lista * LISTA);

int adicionar_elem_pos (Lista * LISTA, int ELEM, int index);

int remover_elem_pos (Lista * LISTA, int index);

void quick_sort_numeros_cres (Lista * LISTA, int inicio, int fim, double * tempo_total, int * n_trocas);

void quick_sort_numeros_decr (Lista * LISTA, int inicio, int fim, double * tempo_total, int * n_trocas);

int adicionar_numero_de_lista_para_arquivo (Lista * LISTA, char * file_name);

int adicionar_numero_de_arquivo_para_lista (char * file_name, Lista * LISTA);

int generate_random_nums (unsigned long long int num_of_nums, char * name);

int tamanho (Lista * LISTA);

int vazia (Lista * LISTA);

int cheia (Lista * LISTA);

int primeiro (Lista * LISTA);

void print_1_n (Lista * LISTA);

void print_n_1 (Lista * LISTA);