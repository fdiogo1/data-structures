#include "queue.h"
#include <stdio.h>

int main(void)
{
    Queue *fila = createQueue();

    enqueue(fila, 10);
    enqueue(fila, 12);
    enqueue(fila, 20);
    enqueue(fila, 50);
    enqueue(fila, 16);
    printf("peeking 'fila': %d\n", peekQueue(fila));
    printQueue(fila);

    printf("fila == NULL? %d\n", fila == NULL);
    destroyQueue(&fila);
    printf("fila == NULL? %d\n", fila == NULL);
}