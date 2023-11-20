#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h> // p/ funcionar o size_t = que é um unsigned long


/***************************** INTERFACE PÚBLICA *****************************/

typedef struct _snode SNode; // não terá acesso a struct _snode
typedef struct _linked_list LinkedList; // não terá acesso a struct _linked_list

LinkedList* createLinkedList(); // aloca espaço na heap suficiente para a cabeça da lista.
void destroyLinkedList(LinkedList **L); // desaloca o espaço da lista
SNode* createNode(int x); // cria um nó. -> essa função já é utilizada nas funções de inserção.
bool emptyLinkedList(const LinkedList *L); // verifica se a lista está vazia.  1 = verdadeiro  0 = falso
void addFirstLinkedList(LinkedList *L, int x); // inserção na cabeça
void addLastLinkedList(LinkedList *L, int x); // insere na cauda
void printLinkedList(const LinkedList *L); // impressão dos elementos da lista
void removeLinkedList(LinkedList *L, int x); // remove um dado elemento X da lista.
size_t sizeLinkedList(const LinkedList *L); // retorna o tamanho da lista, a quantidade de elementos inseridos
int lastElementLinkedList(const LinkedList *L); // retorna o último elemento da lista
int firstElementLinkedList(const LinkedList *L); // retorna o primeiro elemento da lista
int getElementLinkedList(const LinkedList *L, int index); // retorna um elemento em uma dada posição
SNode *getNodeLinkedList(const LinkedList *L, int index); // retorna o ponteiro de um nó em uma dada posição
int atNodeLinkedList(SNode *node); // retorna o elemento do nó
LinkedList* copyLinkedList(LinkedList *L); // copia uma lista.
void destroyNode(SNode **node); // desaloca um determinado nó
void addAfterLinkedList(LinkedList *L, int index, int x); // insere um nó depois de um nó já existente;

/*****************************************************************************/

#endif

