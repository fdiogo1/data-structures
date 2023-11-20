#include "queue.h"

#include "double_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

struct _queue
{
    List *data;
};

Queue* createQueue()
{
    Queue *Q = (Queue*) calloc(1, sizeof(Queue));
    Q->data = createDualList();
    return Q;
}

void destroyQueue(Queue **Q_ref)
{
    Queue *aux = *Q_ref;
    destroyList(&aux->data);
    free(aux);
    *Q_ref = NULL;
}

bool isEmptyQueue(const Queue *Q)
{
    return isEmpty(Q->data);
}

size_t sizeQueue(const Queue *Q)
{
    return listSize(Q->data);
}

void enqueue(Queue *Q, int x)
{
    addLastList(Q->data, x);
}

int peekQueue(const Queue *Q)
{
    if (isEmptyQueue(Q))
    {
        fprintf(stderr, "ERROR in 'peek'\n");
        fprintf(stderr, "The queue is empty.\n");
        exit(EXIT_FAILURE);
    }

    return atBegin(Q->data);
}

int dequeue(Queue *Q)
{
    if (isEmptyQueue(Q))
    {
        fprintf(stderr, "ERROR in 'dequeue'\n");
        fprintf(stderr, "The queue is empty.\n");
        exit(EXIT_FAILURE);
    }

    int x = atBegin(Q->data);
    // removeList(Q->data, x); -> outra forma, mais simples
    removeBeginList(Q->data);
    return x;
}

void printQueue(const Queue *Q)
{
    if (isEmptyQueue(Q))
    {
        fprintf(stderr, "ERROR in 'printQueue'\n");
        fprintf(stderr, "The queue is empty.\n");
        exit(EXIT_FAILURE);
    }
    else 
    {
        puts("===============");
        printf("Size: %d\n", sizeQueue(Q));
        printf("First: %d\n", peekQueue(Q));
        puts("---------------");
        printList(Q->data);
    }
}