#ifndef QUEUE_H
#define QUEUE_H

/****************************************************/

#include <stdbool.h>
#include <stddef.h>

typedef struct _queue Queue;

Queue* createQueue();
void destroyQueue(Queue **Q_ref);

bool isEmptyQueue(const Queue *Q);
size_t sizeQueue(const Queue *Q);

void enqueue(Queue *Q, int x);
int peekQueue(const Queue *Q);
int dequeue(Queue *Q);

void printQueue(const Queue *Q);

/****************************************************/



#endif