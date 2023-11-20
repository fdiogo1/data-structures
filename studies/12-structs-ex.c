#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _livros Livro;

struct _livros
{
    char title[100]; // 100 bytes  |
    unsigned int pages; // 4 bytes |    TOTAL DA STRUCT: 108 BYTES
    float price; // 4 bytes        |
};

int main (void)
{
    Livro livro1;
    Livro *livro2 = (Livro*) calloc(1, sizeof(Livro));

    printf("Tamanho livro1: %ld bytes\n", sizeof(livro1));
    printf("Tamanho livro2: %ld bytes\n", sizeof(livro2));
    printf("Tamanho *livro2: %ld bytes\n", sizeof(*livro2)); // conteudo do livro2
}