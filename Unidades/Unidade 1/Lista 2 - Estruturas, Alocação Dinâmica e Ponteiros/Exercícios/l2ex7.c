#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void le_tipo(char * tipo);
char decide_tipo(char * tipo);
void vetor_char(int tam);
void vetor_int(int tam);
void vetor_float(int tam);
void vetor_double(int tam);

int main() {
    int tamanho;
    char * tipo = (char*)malloc(sizeof(char));
    char type;
    printf("Informe o tamanho do vetor a ser lido: ");
    scanf("%d%*c", &tamanho);
    printf("Informe o tipo do vetor (char, int, float, double): ");
    le_tipo(tipo);
    type = decide_tipo(tipo);
    switch(type)
    {
        case 'c':
            vetor_char(tamanho);
            break;
        case 'i':
            vetor_int(tamanho);
            break;
        case 'f':
            vetor_float(tamanho);
            break;
        case 'd':
            vetor_double(tamanho);
            break;
        case 'n':
            break;
    }
    free(tipo);
    return 0;
}

void vetor_char(int tam) {
    char * vetor = (char*)malloc(tam*sizeof(char));
    for(int i=0;i<tam;i++) scanf("%c", &vetor[i]);
    printf("Elementos do vetor = {");
    for(int i=0;i<tam;i++) 
    {
        if(i == tam-1) printf("%c}\n", vetor[i]);
        else printf("%c, ", vetor[i]);
    }
    free(vetor);
}

void vetor_int(int tam) {
    int * vetor = (int*)malloc(tam*sizeof(int));
    for(int i=0;i<tam;i++) scanf("%d", &vetor[i]);
    printf("Elementos do vetor = {");
    for(int i=0;i<tam;i++) 
    {
        if(i == tam-1) printf("%d}\n", vetor[i]);
        else printf("%d, ", vetor[i]);
    }
    free(vetor);
}

void vetor_float(int tam) {
    float * vetor = (float*)malloc(tam*sizeof(float));
    for(int i=0;i<tam;i++) scanf("%f", &vetor[i]);
    printf("Elementos do vetor = {");
    for(int i=0;i<tam;i++) 
    {
        if(i == tam-1) printf("%.2f}\n", vetor[i]);
        else printf("%.2f, ", vetor[i]);
    }
    free(vetor);
}

void vetor_double(int tam) {
    double * vetor = (double*)malloc(tam*sizeof(double));
    for(int i=0;i<tam;i++) scanf("%lf", &vetor[i]);
    printf("Elementos do vetor = {");
    for(int i=0;i<tam;i++) 
    {
        if(i == tam-1) printf("%.2lf}\n", vetor[i]);
        else printf("%.2lf, ", vetor[i]);
    }
    free(vetor);
}

char decide_tipo(char * tipo) {
    if(strcmp(tipo, "char") == 0) return 'c';
    else if(strcmp(tipo, "int") == 0) return 'i';
    else if(strcmp(tipo, "float") == 0) return 'f';
    else if(strcmp(tipo, "double") == 0) return 'd';
    else return 'n';
}

void le_tipo(char * tipo) {
    char temp_char;
    int i = 0;
    while(1)
    {
        scanf("%c", &temp_char);
        if(temp_char != '\n')
        {
            tipo[i] = temp_char;
            tipo = realloc(tipo, sizeof(tipo)+1);
        }
        else break;
        i++;
    }
}