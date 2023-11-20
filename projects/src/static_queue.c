#include "static_queue.h"

#include <stdlib.h>
#include <stdio.h>

struct _static_queue
{
    int *data;
    long capacity;    
    long size;
    int begin;
    int end;
};

StaticQueue* createStaticQueue(long capacity)
{
    StaticQueue *Q = (StaticQueue*) calloc(1, sizeof(StaticQueue));
    Q->data = (int*) calloc(capacity, sizeof(int));
    Q->size = 0;
    Q->capacity = capacity;
    Q->begin = 0; // indíce
    Q->end = 0; // indíce
    return Q;
}

void destroyStaticQueue(StaticQueue **Q_ref)
{
    StaticQueue *aux = *Q_ref;
    free(aux->data);
    free(aux);
    *Q_ref = NULL;
}

bool isEmptyStaticQueue(const StaticQueue *Q)
{
    return Q->size == 0;
}

bool isFullStaticQueue(const StaticQueue *Q)
{
    return Q->size == Q->capacity;
}

bool sizeStaticQueue(const StaticQueue *Q)
{
    return Q->size;
}

void enqueueStaticQueue(StaticQueue *Q, int x)
{
    if (isFullStaticQueue(Q))
    {
        fprintf(stderr, "ERROR in 'enqueue'\n");
        fprintf(stderr, "Full queue.'\n");
        exit(EXIT_FAILURE);
    }
    else 
    {
        Q->data[Q->end] = x;
        Q->end = (Q->end + 1) % Q->capacity;
        Q->size++;
    }
}

int peekStaticQueue(const StaticQueue *Q)
{
    if (isEmptyStaticQueue(Q))
    {
        fprintf(stderr, "ERROR in 'enqueue'\n");
        fprintf(stderr, "Empty queue.'\n");
        exit(EXIT_FAILURE);
    }

    return Q->data[Q->begin];
}

int dequeueStaticQueue(StaticQueue *Q)
{
    if (isEmptyStaticQueue(Q))
    {
        fprintf(stderr, "ERROR in 'enqueue'\n");
        fprintf(stderr, "Empty queue.'\n");
        exit(EXIT_FAILURE);
    }

    int x = Q->data[Q->begin];
    Q->begin = (Q->begin + 1) % Q->capacity;
    Q->size--;
    return x;
}

void printStaticQueue(const StaticQueue *Q)
{
    if (isEmptyStaticQueue(Q))
    {
        fprintf(stderr, "ERROR in 'enqueue'\n");
        fprintf(stderr, "Empty queue.'\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        long s, i;
        puts("===================");
        printf("Capacity: %ld\n", Q->capacity);
        printf("Size: %ld\n", Q->size);
        printf("Begin: %d\n", Q->begin);
        printf("End: %d\n", Q->end);
        puts("-----------------");
        for (s = 0, i = Q->begin; s < Q->size; s++, i = (i + 1) % Q->capacity)
        {
            printf("data[%ld] = '%d'\n", i, Q->data[i]);
        }
        puts("===================");
    }
}