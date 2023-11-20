#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
    CRUD -> create read update delete
        * "implementar um CRUD" -> criar as funções básicas
*/

typedef struct _aluno Aluno;
typedef struct _livros Livro;

Livro* create_book(const char *title, unsigned int pages, float price);
void print_book(const Livro *book);
void delete_book(Livro **book);
Livro* copy_book(const Livro *book);
Aluno* create_student(const char *name, unsigned int age, const Livro *favbook);
void print_student(const Aluno *student);
void delete_student(Aluno **student);
bool same_book(const Livro *book1, const Livro *book2);

struct _aluno
{
    char name[100];
    int age;
    Livro *favbook;
};

struct _livros
{
    char title[100];
    unsigned int pages;
    float price;
};

int main()
{
    Livro *book1 = create_book("Harry Potter", 200, 55);

    //print_book(book1);
    //book1->price = 25.99; -> é possível alterar (update) na main
    //print_book(book1);

    Aluno *ted = create_student("Ted", 27, book1);
    print_student(ted);
    puts("");


    // os livros são iguais?
    puts("ted->favbook == book1");
    puts("os exemplares sao iguais?");
    if(ted->favbook == book1) puts("TRUE");
    else puts("FALSE");

    // a obra é a mesma?
    puts("are they the same book?");
    puts("a obra eh a mesma?");
    if(same_book(ted->favbook, book1)) puts("TRUE");
    else puts("FALSE");

    delete_student(&ted);
    delete_book(&book1);

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
    printf("Price: $%.2f\n", book->price);
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

/******************** CRUD -> ALUNO ********************/
Aluno* create_student(const char *name, unsigned int age, const Livro *favbook) 
{
    Aluno *student = (Aluno*) calloc(1, sizeof(Aluno));
    strcpy(student->name, name);
    student->age = age;
    student->favbook = copy_book(favbook);

    return student;
}

void print_student(const Aluno *student)
{
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    puts("Favorite book: ");
    puts("---------");
    print_book(student->favbook);
}

void delete_student(Aluno **student)
{
    Aluno *aux = *student;
    delete_book(&aux->favbook);
    free(aux);
    *student = NULL;
}
/*******************************************************/