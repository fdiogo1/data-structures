#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
    Vetores de structs
        Ex: alocação estática
            Aluno vet[10];    -> vet[1].nome = "Diogo";

        Ex: alocação dinâmica
            Aluno *vet = (Aluno*) calloc(10, sizeof(Aluno));   --> vet[1]->nome = "Diogo";
            P/ desalocar: free(vet); -> vai liberar todo o bloco de memória reservado.

            Outra forma de fazer -> um vetor, que irá guardar ponteiros p/ alunos
                Aluno **vet
*/

typedef struct _livros Livro;
typedef struct _library Library;

Livro* create_book(const char *title, unsigned int pages, float price);
void print_book(const Livro *book);
void delete_book(Livro **book);
Livro* copy_book(const Livro *book);
bool same_book(const Livro *book1, const Livro *book2);
Library* create_library(const int size);
void delete_library(Library **vet);
void print_lib(const Library *vet);


struct _library
{
    unsigned int size; // numero de elementos (livros)
    Livro **books; // matriz de livros; books[0], books[1]... calloc p/ cada um deles
};

struct _livros
{
    char title[200]; // 100 bytes  |
    unsigned int pages; // 4 bytes |    TOTAL DA STRUCT: 108 BYTES
    float price; // 4 bytes        |
};

int main(void)
{
    int size;
    printf("Tamanho da nova biblioteca? ");
    scanf("%d", &size);
    Library *lib = create_library(size);

    print_lib(lib);
    delete_library(&lib);
    printf("lib is null? %d\n", lib == NULL);

}


/******************** CRUD -> BOOKS ********************/
Livro* create_book(const char *title, unsigned int pages, float price)
{
    Livro *book = (Livro*) calloc(1, sizeof(Livro));

    strcpy(book->title, title);
    book->price = price;
    book->pages = pages;

    return book;
}

void print_book(const Livro *book)
{
    printf("Title: %s\n", book->title);
    printf("Pages: %d\n", book->pages);
    printf("Price: R$ %.2f\n", book->price);
}

void delete_book(Livro **book)
{
    Livro *aux = *book;
    free(aux);
    *book = NULL;
}

Livro* copy_book(const Livro *book)
{
    return create_book(book->title, book->pages, book->price);
}

bool same_book(const Livro *book1, const Livro *book2)
{
    if (strcmp(book1->title, book2->title) == 0) return true;
    else return false;
}
/*******************************************************/

Library* create_library(const int size)
{
    Library  *vet = (Library*) calloc(1, sizeof(Library));
    vet->books = (Livro**) calloc(size, sizeof(Livro*));
    vet->size = size;


    for (int i = 0; i < size; i++)
    {
        vet->books[i] = (Livro*) calloc(1, sizeof(Livro));
        printf("Digite o nome do %d livro: ", i+1);
        fflush(stdin);
        scanf("%[^\n]s", vet->books[i]->title);
        printf("Digite a quantidade de paginas do %d livro: ", i+1);
        fflush(stdin);
        scanf("%d", &vet->books[i]->pages);
        printf("Digite o valor do %d livro: ", i+1);
        fflush(stdin);
        scanf("%f", &vet->books[i]->price);
        puts("Livro registrado na livraria com sucesso.\n");
    }

    return vet;
}

void print_lib(const Library *vet)
{
    if (vet != NULL)
    {
        printf("A biblioteca possui %d livro(s), sao eles:\n", vet->size);
        for (int i = 0; i < vet->size; i++)
        {
            print_book(vet->books[i]);
            puts("");
        }
    } 
    else puts("Biblioteca inexistente!");
}

void delete_library(Library **vet)
{
    Library *aux = *vet;
    int size = aux->size;

    for (int i = 0; i < size; i++)
    {
        delete_book(&aux->books[i]);
        printf("aux->books[%d] is null? %d\n", i, aux->books[i] == NULL);

    }
    aux->books = NULL;
    printf("aux->books is null? %d\n", aux->books == NULL);
    free(aux);
    *vet = NULL;
}

