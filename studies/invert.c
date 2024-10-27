#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
    App simples para inverter strings.
    Para isso, foi utilizado a estrutura de dados 'Pilha'.
*/  

typedef int Amount;

typedef struct head List;
typedef struct node Node;

struct head 
{
    Amount amt;
    Node *begin;
    Node *end;
};

struct node
{
    char info;
    Node *prev;
    Node *next;
};

List* createList();
void destroyList(List **L_ref);
Node* createNode(char x);
Amount listSize(const List *L);
void addFirstList(List *L, char x);

bool isEmpty (const List *L);

void push(List *L, char x);
char pop(List *L);

int main(int argc, char **argv)
{

    if (argc != 2) 
    {
        puts("Usage: ./invert [string]");
        return 1;
    }

    char *x = argv[1];

    List *invert = createList();

    // empilha cada posição
    for (int i = 0; i < strlen(x); i++)
    {
        push(invert, x[i]);
    }

    printf("First size: %d\n", listSize(invert));
    printf("'invert' == NULL? %d\n", invert == NULL);

    // desempilha, imprimindo o resultado
    printf("the inverse of '%s' is: ", x);
    for (int i = 0; i < strlen(x); i++)
    {
        printf("%c", pop(invert));
    }
    puts("");


    printf("Last size: %d\n", listSize(invert));
    destroyList(&invert);
    printf("'invert' == NULL? %d\n", invert == NULL);

}

List* createList()
{
    List *p = (List*) calloc(1, sizeof(List));
    p->amt = 0;
    p->begin = NULL;
    p->end = NULL;
    return p;
}

Node* createNode(char x)
{
    Node *q = (Node*) calloc(1, sizeof(Node));
    q->info = x;
    q->next = NULL;
    q->prev = NULL;
    return q;
}

bool isEmpty (const List *L)
{
    return L->amt == 0;
}

void addFirstList(List *L, char x)
{
    Node *new = createNode(x);

    if (isEmpty(L)) L->begin = L->end = new;
    else
    {
        new->next = L->begin;
        L->begin->prev = new;
        L->begin = new;
    }
    L->amt++;
}

void push(List *L, char x)
{
    if (isEmpty(L)) addFirstList(L, x);
    else 
    {
        Node *new = createNode(x);
        L->end->next = new;
        new->prev = L->end;
        L->end = new;
        L->amt++;
    }
}


char pop(List *L)
{
    if (isEmpty(L))
    {
        fprintf(stderr, "ERROR in 'removeEndList'\n");
        fprintf(stderr, "List is empty!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        Node *p;
        p = L->end;

        char x = L->end->info;

        if (L->begin == p)
        {
            L->begin = L->end = NULL;
        }
        else 
        {
            L->end = p->prev;
            L->end->next = NULL;
        }

        free(p);
        L->amt--;

        return x;
    }
}

void destroyList(List **L_ref)
{
    List *L = *L_ref;
    Node *p = L->begin;
    Node *aux = NULL;

    while (p != NULL)
    {
        puts("teste a");
        aux = p;
        p = p->next;
        free(aux);
        puts("teste");
    }

    free(L);
    *L_ref = NULL;
}

Amount listSize(const List *L)
{
    return L->amt;
}

