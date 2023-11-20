#ifndef STATIC_STACK_H
#define STATIC_STACK_H


/**************************************************************/

#include <stdbool.h>
#include <stddef.h>

typedef struct _static_stack StaticStack;

StaticStack* create_StaticStack(long capacity);
void destroyStaticStack(StaticStack **S_ref);

bool isEmpty_StaticStack(const StaticStack *S);
bool isFull_StaticStack(const StaticStack *S);

void push_StaticStack(StaticStack *S, int x);
int peek_StaticStack(const StaticStack *S);
int pop_StaticStack(StaticStack *S);

void print_StaticStack(const StaticStack *S);

/**************************************************************/

#endif