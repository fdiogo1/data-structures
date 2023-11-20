#include "stack.h"
#include "double_linked_list.h"

#include <stdlib.h>
#include <stdio.h>

struct _stack
{
    List *data;
};

Stack* createStack()
{
    Stack *S = (Stack*) calloc(1, sizeof(Stack));
    S->data = createDualList();
    return S;
}

void destroyStack(Stack **S_ref)
{
    Stack *aux = *S_ref;
    destroyList(&aux->data);
    free(aux);
    *S_ref = NULL;
}

bool isEmptyStack(const Stack *S)
{
    return isEmpty(S->data);
}

size_t sizeStack(const Stack *S)
{
    return listSize(S->data);
}

void push(Stack *S, int x)
{
    addLastList(S->data, x);
}

int peek(const Stack *S)
{
    if (isEmptyStack(S))
    {
        fprintf(stderr, "ERROR in 'peek'\n");
        fprintf(stderr, "The stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return atEnd(S->data);
}

int pop(Stack *S)
{
    if (isEmptyStack(S))
    {
        fprintf(stderr, "ERROR in 'pop'\n");
        fprintf(stderr, "The stack is empty\n");
        exit(EXIT_FAILURE);
    }

    int x = atEnd(S->data);
    removeEndList(S->data);
    return x;
}

void printStack(const Stack *S)
{
    if (isEmptyStack(S))
    {
        fprintf(stderr, "ERROR in 'printStack'\n");
        fprintf(stderr, "The stack is empty\n");
        exit(EXIT_FAILURE);
    }
    else 
    {
        printList(S->data);
    }
}