#include "double_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*****************************[ INTERFACE PRIVADA ]*****************************/

#define key(A) A 
#define less(A, B) if(key(A) < key(B))
#define exch(A, B) {int t = A; A = B; B = t;}
#define compexch(A, B) if(less(A, B)) exch(A, B)

struct __double_linked_list // head
{
    size_t size;
    Node *begin;
    Node *end;
};

struct __nodes // nodes
{
    int val; // info
    Node *prev;
    Node *next;
};

/*-----------------------------------------------------------------------------*/

/*****************************[ INTERFACE PÚBLICA ]*****************************/

List* createDualList()
{
    List *L = (List*) calloc(1, sizeof(List));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;
    return L;
}

Node* createNode(int x)
{
    Node *node = (Node*) calloc(1, sizeof(Node));
    node->val = x;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void destroyList(List **L_ref)
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

void destroyNode(Node **N_ref)
{
    Node *N = *N_ref;
    free(N);
    *N_ref = NULL;
}

void printList(const List *L)
{
    if (!isEmpty(L)) 
    {   
        Node *p = L->begin;
        // printf("--------------\n");
        // printf("Actual size: %d\n", L->size);
        // printf("First element in 'list': %d\n", L->begin->val);
        // printf("Last element in 'list': %d\n\n", L->end->val);
        printf("L -> ");
        while (p != NULL)
        {
            printf("%d -> ", p->val);
            p = p->next;
        }
        if (p == NULL) printf("NULL\n");
        printf("--------------\n");
    }
    else 
    {
        fprintf(stderr, "ERROR in 'printList'\n");
        fprintf(stderr, "List is empty.\n");
        exit(EXIT_FAILURE);
    }
}

void inversePrintList(const List *L)
{
    if (isEmpty(L))
    {
        fprintf(stderr, "ERROR in 'inversePrint'\n");
        fprintf(stderr, "List is empty!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        Node *p = L->end;
        printf("L -> ");
        while (p != NULL)
        {
            printf("%d -> ", p->val);
            p = p->prev;
        }
        printf("NULL\n");
    }
}

bool isEmpty(const List *L)
{
    return L->begin == NULL; // 1 = verdadeiro, 0 = falso
}

void addFirstList(List *L, int x)
{
    Node *new = createNode(x);

    if (isEmpty(L)) L->begin = L->end = new;
    else
    {
        new->next = L->begin;
        L->begin->prev = new;
        L->begin = new;
    }
    L->size++;
}

void addLastList(List *L, int x)
{
    if (isEmpty(L)) addFirstList(L, x);
    else 
    {
        Node *new = createNode(x);
        L->end->next = new;
        new->prev = L->end;
        L->end = new;
        L->size++;
    }
}

int atBegin(const List *L)
{
    return L->begin->val;
}

int atEnd(const List *L)
{
    if (isEmpty(L))
    {
        fprintf(stderr, "ERROR in 'atEnd'\n");
        fprintf(stderr, "The list is empty!\n");
        exit(EXIT_FAILURE);
    }
    
    return L->end->val;
}

size_t listSize(const List *L)
{
    return L->size;
}

void removeList(List *L, int x)
{
    if(!isEmpty(L))
    {
        Node *p = NULL;

        // caso 1: elemento está na cabeça da lista
        if(L->begin->val == x)
        {
            p = L->begin;
            // se a lista possui apenas 1 elemento
            if (L->begin == L->end)
            {
                L->begin = L->end = NULL;
            }
            else 
            {
                L->begin = p->next;
                L->begin->prev = NULL;
            }
            printf("The element '%d' was successfully removed from the list.\n", x);
            free(p);
            L->size--;
        }
        // else if (L->end->val == x) // caso 2: elemento no fim da lista
        // {   
        //     p = L->end;
        //     L->end = p->prev;
        //     L->end->next = NULL;
        //     printf("The element '%d' was successfully removed from the list.\n", x);
        //     free(p);
        //     L->size--;
        // }
        else // caso 2: elemento no meio da lista
        {
            p = L->begin->next;
            while (p != NULL && p->val != x)
            {
                p = p->next;
            }

            if (p != NULL)
            {
                // caso 3: se for o último elemento
                if (L->end == p)
                {
                    p->prev->next = NULL;
                    L->end = p->prev;
                }
                else
                {
                    p->prev->next = p->next;
                    p->next->prev = p->prev;
                }
                printf("The element '%d' was successfully removed from the list.\n", x);
                free(p);
                L->size--;
            }
            else
            {
                printf("It wasn't possible to find the element '%d' in the list.\n", x);
            }
        }
    }
    else
    {
        fprintf(stderr, "ERROR in 'removeList'\n");
        fprintf(stderr, "List is empty!\n");
        exit(EXIT_FAILURE);
    }
}

void removeBeginList(List *L)
{
    if (isEmpty(L))
    {
        fprintf(stderr, "ERROR in 'removeBeginList'\n");
        fprintf(stderr, "List is empty!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        Node *p = L->begin;

        if (L->end == p)
        {
            L->begin = L->end = NULL;
        }
        else 
        {
            L->begin = p->next;
            L->begin->prev = NULL;
        }
        free(p);
        L->size--;
    }
}

void removeEndList(List *L)
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
        L->size--;
    }
}

int getElement(const List *L, int index)
{
    if (isEmpty(L))
    {
        fprintf(stderr, "ERROR in 'getElement'\n");
        fprintf(stderr, "List is empty!\n");
        exit(EXIT_FAILURE);
    }
    else if (index < 0 || index >= L->size)
    {
        fprintf(stderr, "ERROR in 'getElement' = Invalid index '%d'\n", index);
        fprintf(stderr, "The index must be between: [0, %d]\n", L->size-1);
        exit(EXIT_FAILURE);   
    }
    else
    {
        if (index == 0) return L->begin->val;
        else
        {
            Node *p = L->begin;
            for (int i = 0; i < index; i++) p = p->next;
            return p->val;
        }
    }
}

List* copyList(const List *L)
{
    List *new = createDualList();

    if (isEmpty(L))
    {
        fprintf(stderr, "ERROR in 'copyList'\n");
        fprintf(stderr, "The list you're trying to copy is empty!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        Node *p = L->begin;
        while (p != NULL)
        {
            addLastList(new, p->val);
            p = p->next;
        }
        return new;
    }
}

List* mergeLists(const List *L, const List *J)
{
    if (isEmpty(L) || isEmpty(J))
    {
        fprintf(stderr, "ERROR in 'mergeLists'\n");
        fprintf(stderr, "One of the lists is empty!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        List *newList = createDualList();
        Node *p = L->begin;
        Node *q = J->begin;

        while (p != NULL)
        {
            addLastList(newList, p->val);
            p = p->next;
        }

        while (q != NULL)
        {
            addLastList(newList, q->val);
            q = q->next;
        }
        return newList;
    }
}

/*-----------------------------------------------------------------------------*/
