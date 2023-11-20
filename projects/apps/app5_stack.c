#include "stack.h"
#include <stdio.h>

int main(void)
{
    Stack *pilha = createStack();
    push(pilha, 15);
    push(pilha, 20);
    push(pilha, 25);
    printf("top element: %d\n", peek(pilha));
    printf("removing last element: %d\n", pop(pilha));
    printf("new top element: %d\n", peek(pilha));

    printStack(pilha);

    printf("pilha is NULL? %d\n", pilha == NULL);
    destroyStack(&pilha);
    printf("pilha is NULL? %d\n", pilha == NULL);
}