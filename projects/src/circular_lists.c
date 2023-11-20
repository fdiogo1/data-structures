#include "circular_lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct _circ_node
{
    int val;
    CircNode *next;
    CircNode *prev;
};

struct _circ_list
{
    size_t size;
    CircNode *begin;
    CircNode *end;
};

/*****************************[ INTERFACE PÚBLICA ]*****************************/

CircList* create_list()
{
    CircList *newList = (CircList*) calloc(1, sizeof(CircList));
    newList->size = 0;
    newList->begin = NULL;
    newList->end = NULL;

    return newList;
}

CircNode* create_node(int x) 
{
    CircNode *newNode = (CircNode*) calloc(1, sizeof(CircNode));
    newNode->val = x;
    newNode->next = newNode;
    newNode->prev = newNode;

    return newNode;
}

void destroyCircNode(CircNode **N_ref)
{
    CircNode *aux = *N_ref;
    free(aux);
    *N_ref = NULL;
}

void destroyCircList(CircList **L_ref)
{
    CircList *L = *L_ref;
    if (!is_Empty(L))
    { 
        CircNode *p = L->begin;
        CircNode *aux = NULL;

        while (p != L->end)
        {
            aux = p;
            p = p->next;
            destroyCircNode(&aux);
        }

        destroyCircNode(&p);
        free(L);
        *L_ref = NULL;
    }
    else
    {
        fprintf(stderr, "The list is already empty!\n");
        exit(EXIT_FAILURE);
    }
}

bool is_Empty(const CircList *List)
{
    return List->size == 0;
}

void addCircFirst(CircList *L, int x)
{
    CircNode *N = create_node(x);
    if (is_Empty(L))
    {
        L->end = N;
    }
    else
    {
        N->next = L->begin;
        L->begin->prev = N;

        // consertando o encadeamento da lista circular
        N->prev = L->end;
        L->end->next = N;
    }
    L->begin = N;
    L->size++;
}

void addCircLast(CircList *L, int x)
{
    if (is_Empty(L)) addCircFirst(L, x);
    else 
    {
        CircNode *p = create_node(x);
        p->next = L->begin;
        p->prev = L->end;
        L->end->next = p;
        L->begin->prev = p;
        L->end = p;
        L->size++;
    }
}

void removeCircList(CircList *L, int x)
{
    if (!is_Empty(L))
    {
        CircNode *p = NULL;

        if (L->begin->val == x) // caso 1: elemento no inicio da lista
        {
            p = L->begin;

            if (L->begin == L->end) L->begin = L->end = NULL; // único elemento da lista
            else
            {
                p->next->prev = L->end;
                L->end->next = p->next;
                L->begin = p->next;
            }
            printf("The element '%d' was succesfully removed from the list.\n", p->val);
            free(p);
            L->size--;
        }
        else // caso 2: elemento no meio da lista
        {
            p = L->begin->next;

            while (p != L->begin && p->val != x)
            {
                p = p->next;
            }

            if (p != L->begin) // achou o elemento
            {
                if (p == L->end) // caso 3: se for o último elemento
                {
                    p->prev->next = L->begin;
                    L->begin->prev = p->prev;
                    L->end = p->prev;
                }
                else 
                {
                    p->prev->next = p->next;
                    p->next->prev = p->prev;
                }

                printf("The element '%d' was succesfully removed from the list.\n", p->val);
                destroyCircNode(&p);
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
        fprintf(stderr, "ERROR in 'removeCircList'\n");
        fprintf(stderr, "Empty list.\n");
        exit(EXIT_FAILURE);
    }
}

void printCircList(const CircList *L)
{
    if (is_Empty(L))
    {
        fprintf(stderr, "ERROR in 'printCircList'\n");
        fprintf(stderr, "The list is empty!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        CircNode *p = L->begin;
        printf("L -> ");
        while (p != L->end)
        {
            printf("%d -> ", p->val);
            p = p->next;
        }
        printf("%d\n", p->val);
    }
}

void reversePrintCircList(const CircList *L)
{
    if (is_Empty(L))
    {
        fprintf(stderr, "ERROR in 'printCircList'\n");
        fprintf(stderr, "The list is empty!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        CircNode *p = L->end;

        printf("L -> ");
        while (p != L->begin)
        {
            printf("%d -> ", p->val);
            p = p->prev;
        }
        printf("%d\n", p->val);
    }
}

int firstCircElement(const CircList *L)
{
    return L->begin->val;
}

int lastCircElement(const CircList *L)
{
    return L->end->val;
}

int sizeCircList(const CircList *L)
{
    return L->size;
}

void printCircList_v2(const CircList *L)
{
    if (is_Empty(L))
    {
        fprintf(stderr, "ERROR in 'printList'\n");
        fprintf(stderr, "Empty list.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        CircNode *p = L->begin;
        printf("L -> ");
        do
        {
            printf("%d -> ", p->val);
            p = p->next;
        } 
        while (p != L->begin);
    }
}

void printCircList_v3(const CircList *L)
{
    if (is_Empty(L))
    {
        fprintf(stderr, "ERROR in 'printList'\n");
        fprintf(stderr, "Empty list.\n");
        exit(EXIT_FAILURE);
    }
    else 
    {
        CircNode *p = L->begin;
        int size = L->size;
        printf("L -> ");
        for (int i = 0; i < size; i++)
        {
            printf("%d -> ", p->val);
            p = p->next;
        }
    }
}

/*-----------------------------------------------------------------------------*/