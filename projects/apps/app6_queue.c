#include "static_queue.h"
#include <stdio.h>

int main(void)
{
    StaticQueue *Q = createStaticQueue(5);

    puts("enqueue: 10, 20, 30");
    enqueueStaticQueue(Q, 10);
    enqueueStaticQueue(Q, 20);
    enqueueStaticQueue(Q, 30);
    printStaticQueue(Q);

    puts("\npeek");
    int x = peekStaticQueue(Q);
    printf("x = %d\n", x);
    printStaticQueue(Q);

    puts("\ndequeue");
    int y = dequeueStaticQueue(Q);
    printf("y = %d\n", y);
    printStaticQueue(Q);

    puts("\nenqueue: 40, 50");
    enqueueStaticQueue(Q, 40);
    enqueueStaticQueue(Q, 50);
    printStaticQueue(Q);

    puts("\ndequeue");
    int z = dequeueStaticQueue(Q);
    printf("z = %d\n", z);
    printStaticQueue(Q);

    puts("\nenqueue: 100, 200");
    enqueueStaticQueue(Q, 100);
    enqueueStaticQueue(Q, 200);
    printStaticQueue(Q);

    printf("Q is NULL? %d\n", Q == NULL);
    destroyStaticQueue(&Q);
    printf("Q is NULL? %d\n", Q == NULL);
}