#ifndef CIRCULAR_LISTS_H
#define CIRCULAR_LISTS_H

#include <stdbool.h>

/***************************** INTERFACE PÚBLICA *****************************/

typedef struct _circ_node CircNode;
typedef struct _circ_list CircList;
CircList* create_list();
CircNode* create_node(int x);
void destroyCircList(CircList **L_ref);
void destroyCircNode(CircNode **N_ref);
bool is_Empty(const CircList *List);
void printCircList(const CircList *L);
void printCircList_v2(const CircList *L);
void printCircList_v3(const CircList *L);
void reversePrintCircList(const CircList *L);
void addCircFirst(CircList *L, int x);
void addCircLast(CircList *L, int x);
void removeCircList(CircList *L, int x);
int firstCircElement(const CircList *L);
int lastCircElement(const CircList *L);
int sizeCircList(const CircList *L);

/*****************************************************************************/

#endif