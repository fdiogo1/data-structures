#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*****************************[ INTERFACE PRIVADA ]*****************************/
// O que está aqui, não está disponível para usuários/programas, ou outros arquivos que usam o linked_list.h

#define key(A) A 
#define less(A, B) if((key(A)) < (key(B)))
#define exch(A, B) {int t = A; A = B; B = t;}
#define compexch(A, B) if(less(A, B)) exch(A, B)

struct _snode
{
    int val;
    SNode *next;
};

struct _linked_list // cabeça da lista
{
    size_t size;
    SNode *begin;
    SNode *end; // acesso direto ao último elemento -> O(1) = constante.
};

/*-----------------------------------------------------------------------------*/


/*****************************[ INTERFACE PÚBLICA ]*****************************/

LinkedList* createLinkedList()
{
    LinkedList *L = (LinkedList*) calloc(1, sizeof(LinkedList));
    L->begin = NULL; // só pra ficar claro
    L->end = NULL;
    L->size = 0;

    return L;
}

void destroyLinkedList(LinkedList **L_ref)
{
    LinkedList *L = *L_ref;

    SNode *p = L->begin;
    SNode *aux = NULL;

    // desalocando os nós
    while (p != NULL)
    {
        aux = p;
        p = p->next;
        free(aux);
    }
    free(L);
    *L_ref = NULL; // boa prática de programação

}

SNode* createNode(int x)
{
    SNode *S = (SNode*) calloc(1, sizeof(SNode));
    S->val = x;
    S->next = NULL;

    return S;
}

bool emptyLinkedList(const LinkedList *L)
{
    return L->begin == NULL;
}

void addFirstLinkedList(LinkedList *L, int x)
{
    SNode *newNode = createNode(x);
    if(emptyLinkedList(L))
    {
        L->begin = newNode; // posso colocar: L->begin = L->end = newNode; (tambem funciona)
        L->end = newNode;
    }
    else
    {
        newNode->next = L->begin;
        L->begin = newNode;
    }
    L->size++;
}

void printLinkedList(const LinkedList *L)
{
    if(!emptyLinkedList(L))
    {
        printf("Size: %u\n", L->size);
        SNode *aux = L->begin;
        printf("L -> ");
        while (aux != NULL)
        {
            printf("%d -> ", aux->val);
            aux = aux->next;
        }
        puts("NULL");
    }
    else 
    {
        puts("L -> NULL");
    }
    if (L->end == NULL) printf("Last element = NULL\n");
    else printf("\nLast element = %d\n", L->end->val);
}

void addLastLinkedList(LinkedList *L, int x)
{
    if(emptyLinkedList(L)) addFirstLinkedList(L, x);
    else
    {
        SNode *q = createNode(x);
        L->end->next = q;
        L->end = q;
        L->size++;
    }
}

size_t sizeLinkedList(const LinkedList *L)
{
    return L->size;
}

int lastElementLinkedList(const LinkedList *L)
{
    if (!emptyLinkedList(L)) return L->end->val;
    else
    {
        fprintf(stderr, "ERROR in 'lastElement'\n");
        fprintf(stderr, "List is empty!\n");
        exit(EXIT_FAILURE);
    }
}

int firstElementLinkedList(const LinkedList *L)
{
    if (!emptyLinkedList(L)) return L->begin->val;
    else
    {
        fprintf(stderr, "ERROR in 'lastElement'\n");
        fprintf(stderr, "List is empty!\n");
        exit(EXIT_FAILURE);
    }
}

void removeLinkedList(LinkedList *L, int x)
{
    if (!emptyLinkedList(L))
    {
        SNode *p = L->begin;
    
        // caso 1: elemento está na cabeça da lista 
        if (p->val == x)
        {
            if(L->begin == L->end) L->end = NULL; // se a lista possui apenas um nó, e ele será deletado:
            L->begin = p->next;
            printf("The element %d was succesfully removed from the list.\n", x);
            free(p);
            L->size--;
        }
        else // caso 2: elemento no meio da lista
        {
            SNode *prev = L->begin;
            SNode *pos = L->begin->next;

            while (pos != NULL && pos->val != x)
            {
                prev = prev->next;
                pos = pos->next;
            }

            // um nó de valor X foi encontrado
            // e é apontado pelo ponteiro pos
            if (pos != NULL)
            {
                prev->next = pos->next;
                // se o elemento que foi removido era o último nó da lista
                // caso 3: removendo o último nó
                if (prev->next == NULL) L->end = prev;
                printf("The element %d was succesfully removed from the list.\n", pos->val);
                free(pos);
                L->size--;
            }
            else
            {
                fprintf(stderr, "The element %d wasn't found to be removed.\n", x); // printf de ERRO
            }
        }
    }
    else
    {
        puts("L -> NULL");
        puts("ERROR in 'remove'");
        puts("The linked list is already empty!");
    }
}

int getElementLinkedList(const LinkedList *L, int index)
{
    if(emptyLinkedList(L)) 
    {
        fprintf(stderr, "ERROR in 'getElement'\n");
        fprintf(stderr, "List is empty!\n");
        exit(EXIT_FAILURE);
    }
    else if (index < 0 || index >= L->size)
    {
        fprintf(stderr, "ERROR in 'getElement' -> INVALID INDEX\n");
        fprintf(stderr, "The index is out of bounds: [0, %d]\n", L->size-1);
        exit(EXIT_FAILURE);
    }
    else
    {
        SNode *p = L->begin;

        if (index == 0) return L->begin->val;
        else 
        {

            for (int i = 1; i <= index; i++) p = p->next;
            return p->val;
        }    
    }
}

SNode *getNodeLinkedList(const LinkedList *L, int index)
{
    SNode *p = L->begin;
    if(!emptyLinkedList(L))
    {
        if (index < 0 || index >= L->size) 
        {
            fprintf(stderr, "ERROR in 'getNode' -> INVALID INDEX\n");
            fprintf(stderr, "The index must be in this interval: [0, %d]", L->size-1);
            exit(EXIT_FAILURE);   
        }
        else if (index == 0) return p;
        else
        {
            for (int i = 1; i <= index; i++) p = p->next;
            return p;
        }
    }
    else 
    {
        fprintf(stderr, "ERROR in 'getNode'\n");
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE); 
    }
    
}

int atNodeLinkedList(SNode *node)
{
    return node->val;
}

void destroyNode(SNode **node)
{
    SNode *aux = *node;
    free(aux);
    *node = NULL;
}

LinkedList* copyLinkedList(LinkedList *L)
{
    LinkedList *new = createLinkedList();
    SNode *p = L->begin;
    if (!emptyLinkedList(L))
    {
        while (p != NULL)
        {
            addLastLinkedList(new, p->val);
            p = p->next;
        }
        puts("The list was succesfully copied!");
        return new;
    }
    else 
    {
        fprintf(stderr, "ERROR in 'copyLinkedList'\n");
        fprintf(stderr, "The list you're trying to copy is empty!\n");
        exit(EXIT_FAILURE);
    }
}

void addAfterLinkedList(LinkedList *L, int index, int x)
{
    if (!emptyLinkedList(L))
    {
        if (index < 0 || index >= L->size)
        {
            fprintf(stderr, "ERROR in 'addAfter' -> INVALID INDEX\n");
            fprintf(stderr, "The index must be in this interval: [0, %d]", L->size-1);
            exit(EXIT_FAILURE);   
        }
        else if (index == 0) addFirstLinkedList(L, x);
        else 
        {
            SNode *p = getNodeLinkedList(L, index);
            SNode *new = createNode(x);
            if(L->end == p) L->end = new;
            new->next = p->next;
            p->next = new;
            L->size++;
        }
    }
    else 
    {
        fprintf(stderr, "ERROR in 'addAfter'\n");
        fprintf(stderr, "List is empty!\n");
        exit(EXIT_FAILURE);
    }
}

int atEnd_2(const LinkedList *L)
{
    return L->end->val;
}

/*-----------------------------------------------------------------------------*/

void removeLinkedList_v2(LinkedList *L, int x) // versão enxuta, mais otimizada.
{
    if (!emptyLinkedList(L))
    {
        SNode *prev = NULL;
        SNode *pos = L->begin;

        while (pos != NULL && pos->val != x)
        {
            prev = pos;
            pos = pos->next;
        }

        if (pos != NULL)
        {
            if (L->end == pos) L->end = prev;
            if (L->begin == pos) L->begin = pos->next;
            else prev->next = pos->next;

            free(pos);
        }
    }
}