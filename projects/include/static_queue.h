#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <stdbool.h>

/***************************** INTERFACE PÚBLICA *****************************/

typedef struct _static_queue StaticQueue;

StaticQueue* createStaticQueue(long capacity);
void destroyStaticQueue(StaticQueue **Q_ref);

bool isEmptyStaticQueue(const StaticQueue *Q);
bool isFullStaticQueue(const StaticQueue *Q);
bool sizeStaticQueue(const StaticQueue *Q);

void enqueueStaticQueue(StaticQueue *Q, int x);
int peekStaticQueue(const StaticQueue *Q);
int dequeueStaticQueue(StaticQueue *Q);

void printStaticQueue(const StaticQueue *Q);

/*****************************************************************************/

#endif