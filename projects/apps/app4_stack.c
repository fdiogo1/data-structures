#include "static_stack.h"
#include <stdio.h>

int main(void)
{
    long capacity;
    printf("Capacity: ");
    scanf("%ld", &capacity);
    StaticStack *S = create_StaticStack(capacity);

    push_StaticStack(S, 5);
    push_StaticStack(S, 3);
    push_StaticStack(S, 2);
    push_StaticStack(S, 15);

    print_StaticStack(S);

    printf("Desempilhando: %d\n", pop_StaticStack(S));
    print_StaticStack(S);

    destroyStaticStack(&S);

    printf("S is NULL? %d\n", S == NULL);
}