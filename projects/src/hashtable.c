#include "hashtable.h"
#include "mlibs.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

typedef struct _list List;
typedef struct _node Node;

#define TABLE_SIZE 26 // A to Z

struct _list
{
    int size;
    Node *begin;
    Node *end;
};

struct _node 
{
    char name[50];
    Node *next;
    Node *prev;
};

struct _hash
{
    int size;
    char name[25];
    List *table[TABLE_SIZE];
};

List *loadList()
{
    List *list = (List *) calloc(1, sizeof(List));
    return list;
}

Hash *loadTable(string name)
{
    Hash *table = (Hash *) calloc(1, sizeof(Hash));
    strcpy(table->name, name);

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table->table[i] = loadList();
    }

    return table;
}

Node *createNode(char *x)
{
    Node *p = (Node *) calloc(1, sizeof(Node));
    strcpy(p->name, x);
    return p;
}

void unloadList(List **L_ref)
{
    List *L = *L_ref;
    Node *p = L->begin;
    Node *aux = NULL;

    while (p != NULL)
    {
        aux = p;
        p = p->next;
        free(aux);
    }

    free(L);
    *L_ref = NULL;
}

void unloadTable(Hash **H_ref)
{
    Hash *H = *H_ref;

    for (int i = 0; i > TABLE_SIZE; i++)
    {
        unloadList(&H->table[i]);
    }

    free(H);
    *H_ref = NULL;
}

int hash(const char *name)
{
    return (toupper(name[0]) - 'A');
}

bool isEmpty(const List *L)
{
    return L->begin == NULL;
}

void insert(Hash *table, char *name)
{
    int index = hash(name);
    Node *new = createNode(name);
    List *L = table->table[index];
    
    if (isEmpty(L))
    {
        L->begin = L->end = new;
    }
    else 
    {
        L->end->next = new;
        new->prev = L->end;
        L->end = new;
    }
    L->size++;
    table->size++;
}

void printList(const List *L)
{
    Node *p = L->begin;
    while (p != NULL)
    {
        printf("- %s\n", p->name);
        p = p->next;
    }
}

void printTable(const Hash *t)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (!isEmpty(t->table[i]))
        {
            printf("Letter [%c]:\n", i+65);
            printList(t->table[i]);
        }
    }
}

void find(const Hash *table, string name)
{
    int index = hash(name);

    Node *p = table->table[index]->begin;

    while (p != NULL && compareStrings(name, p->name) != 0)
    {
        p = p->next;
    }

    if (p != NULL)
    {
        printf("'%s' hashes to position '%d' on table '%s'!\n", name, index, table->name);
    }
    else 
    {
        printf("'%s' not found on table '%s'!\n", name, table->name);
    }
}