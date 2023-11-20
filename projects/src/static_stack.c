#include "static_stack.h"
#include <stdlib.h>
#include <stdio.h>

/*==========================================================*/

struct _static_stack
{
    int *data;
    long capacity;
    long size;
    long top;
};

/*==========================================================*/

StaticStack* create_StaticStack(long capacity)
{
    StaticStack *S = (StaticStack*) calloc(1, sizeof(StaticStack));
    S->capacity = capacity;
    S->size = 0;
    S->top = -1;
    S->data = (int*) calloc(S->capacity, sizeof(int));
    return S;
}

void destroyStaticStack(StaticStack **S_ref)
{
    StaticStack *aux = *S_ref;
    free(aux->data);
    free(aux);
    *S_ref = NULL;
}

bool isEmpty_StaticStack(const StaticStack *S)
{
    return S->top == -1;
}

bool isFull_StaticStack(const StaticStack *S)
{
    return S->top == (S->capacity - 1);
}

void push_StaticStack(StaticStack *S, int x)
{
    if (isFull_StaticStack(S))
    {
        fprintf(stderr, "ERROR in 'push'\n");
        fprintf(stderr, "The stack is full!\n");
        fprintf(stderr, "Size (max): %ld (%ld)\n", S->size, S->capacity);
        exit(EXIT_FAILURE);
    }
    else 
    {
        S->data[++S->top] = x;
        S->size++;
    }
}

int peek_StaticStack(const StaticStack *S)
{
    if (isEmpty_StaticStack(S))
    {
        fprintf(stderr, "ERROR in 'push'\n");
        fprintf(stderr, "The stack is empty!\n");
        exit(EXIT_FAILURE);
    }
    return S->data[S->top];
}

int pop_StaticStack(StaticStack *S)
{
    if (isEmpty_StaticStack(S))
    {
        fprintf(stderr, "ERROR in 'push'\n");
        fprintf(stderr, "The stack is empty!\n");
        exit(EXIT_FAILURE);
    }

    int x = S->data[S->top--];
    S->size--;
    return x;
}

void print_StaticStack(const StaticStack *S)
{
    if (isEmpty_StaticStack(S))
    {
        fprintf(stderr, "ERROR in 'push'\n");
        fprintf(stderr, "The stack is empty!\n");
        exit(EXIT_FAILURE);
    }
    else 
    {
        puts("===================");
        printf("Capacity: %ld\n", S->capacity);
        printf("Size: %ld\n", S->size);
        printf("Top: %ld\n", S->top);
        puts("-----------------");
        for (long i = 0; i <= S->top; i++)
        {
            printf("data[%ld] = '%d'\n", i, S->data[i]);
        }
        puts("===================");
    }
}
