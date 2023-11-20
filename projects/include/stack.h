#ifndef STACK_H
#define STACK_H

/***********************************/

#include <stdbool.h>
#include <stddef.h>

typedef struct _stack Stack;

Stack* createStack();
void destroyStack(Stack **S_ref);

bool isEmptyStack(const Stack *S);
size_t sizeStack(const Stack *S);

void push(Stack *S, int x);
int peek(const Stack *S);
int pop(Stack *S);

void printStack(const Stack *S);

/***********************************/

#endif