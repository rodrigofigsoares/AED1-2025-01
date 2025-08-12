#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char * dado = (char*)malloc(sizeof(char));
    char temp_char;
    int i = 0;
    printf("Informe o tipo de dado: ");
    while(1)
    {
        scanf("%c", &temp_char);
        if(temp_char != '\n')
        {
            dado[i] = temp_char;
            dado = realloc(dado, (sizeof(dado)+1));
        }
        else break;
        i++;
    }
    if(strcmp(dado, "char") == 0) printf("char = %lu byte", sizeof(char));
    else if(strcmp(dado, "int") == 0) printf("int = %lu bytes", sizeof(int));
    else if(strcmp(dado, "float") == 0) printf("float = %lu bytes", sizeof(float));
    else if(strcmp(dado, "double") == 0) printf("double = %lu bytes", sizeof(double));
    free(dado);
    printf("\n");
    return 0;
}