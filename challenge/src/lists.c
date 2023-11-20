#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"


/*******************************************************/

struct _list
{
    int size;
    int totalcost;
    Node *begin;
    Node *end;
};

struct _node
{
    Node *prev;
    Node *next;
    int count;
    Product *product;
};

struct _product
{
    int serial;
    char name[64];
    float price;
};

/*******************************************************/

List* createList()
{
    List *newList = (List*) calloc(1, sizeof(List));
    newList->begin = NULL;
    newList->end = NULL;
    newList->size = 0;
    newList->totalcost = 0;

    return newList;
}

void deleteList(List **L_ref)
{
    List *L = *L_ref;
    Node *p = L->begin;
    Node *aux = NULL;

    while (p != NULL)
    {
        aux = p;
        p = p->next;
        deleteNode(&aux);
    }
    free(L);
    *L_ref = NULL;
}

Product* createProduct(int serial, const char *name, float price)
{
    Product *newProduct = (Product*) calloc(1, sizeof(Product));
    newProduct->serial = serial;
    strcpy(newProduct->name, name);
    newProduct->price = price;
    return newProduct;
}

Node* createNode(int serial, const char *name, float price)
{
    Node *newNode = (Node*) calloc(1, sizeof(Node));
    newNode->count = 0;
    newNode->next = newNode->prev = NULL;
    newNode->product = createProduct(serial, name, price);

    return newNode;
}

void deleteNode(Node **node)
{
    Node *aux = *node;
    deleteProduct(&aux->product);
    free(aux);
    *node = NULL;
    
}

void printProduct(const Product *p)
{
    puts("");
    printf("* Product name: %s\n", p->name);
    printf("* Product serial: %03d\n", p->serial);
    printf("* Product price: %.2f\n", p->price);
    puts("");
}

void deleteProduct(Product **prod)
{
    Product *aux = *prod;
    free(aux);
    *prod = NULL;
}

void add(List *L, int serial, const char *name, float price)
{
    Node *newNode = createNode(serial, name, price);
    // caso esteja vazia
    if (isEmpty(L)) L->begin = newNode;
    else L->end->next = newNode;

    newNode->prev = L->end;
    L->end = newNode;
    L->size++;
}

void printList(const List *L)
{
    Node *p = L->begin;
    puts("Serials (count): \n");
    printf("L -> ");
    while (p != NULL)
    {   
        printf("%d (%d) -> ", p->product->serial, p->count);
        p = p->next;
    }
    printf("NULL\n");
}

bool isEmpty(const List *L)
{
    return (L->begin == NULL && L->end == NULL);
}


// retorna um ponteiro read-only para o produto encontrado
// ou retorna NULL caso contrário
const Product* access(List *L, int serial)
{
    Product *product = NULL;

    if (!isEmpty(L))
    {
        Node *p = L->begin;
        int cost = 1; // pois já acessou o L->begin;
        
        while (p != NULL && p->product->serial != serial)
        {
            cost++;
            p = p->next;
        }

        if (p != NULL) // achamos o produto com o número de serie 'serial';
        {
            L->totalcost += cost;
            p->count++; // vezes que foi acessado -> aumenta a freq
            product = p->product;

            // reorganizar a lista;
            if (p != L->begin) // se for o primeiro, já está na melhor posição.
            {
                Node *q = p->prev;

                // enquanto há um nó antecessor a p
                // e enquanto a frequência de acessos
                // de q é menor ou igual a p, troque
                while (q != NULL && q->count <= p->count)
                {
                    p->prev = q->prev;
                    q->prev = p;
                    q->next = p->next;
                    p->next = q;

                    if (p->prev == NULL) // se for verdadeiro, p virou a cabeça da lista
                    {
                        L->begin = p;
                    }
                    else 
                    {
                        p->prev->next = p;
                    }

                    if (q->next == NULL) // q é o último elemento da lista 
                    {
                        L->end = q;
                    }
                    else
                    {
                        q->next->prev = q;
                    }

                    q = p->prev;
                }
            }
        }
    }
    else
    {
        fprintf(stderr, "ERROR in 'access'\n");
        fprintf(stderr, "List is empty.\n");
        exit(EXIT_FAILURE);
    }

    return product;
}

void printSerialList(const List *L)
{
    Node *p = L->begin;
    printf("L = (");

    while (p != NULL)
    {
        printf("%d", p->product->serial);

        if (p != L->end)
        {
            printf(", ");
        }
        p = p->next;
    }

    printf(")\n");
    printf("Total cost: = %d\n", L->totalcost);
}