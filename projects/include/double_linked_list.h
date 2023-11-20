#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

/***************************** INTERFACE PÚBLICA *****************************/

typedef struct __double_linked_list DoubleLinked, List;
typedef struct __nodes DoublyNode, Node;

List* createDualList(); // aloca espaço na heap.
Node* createNode(int x); // cria um novo nó.
void destroyList(List **L_ref); // desaloca uma lista.
void destroyNode(Node **N_ref); // desaloca um nó.
void printList(const List *L); // imprime uma lista.
void inversePrintList(const List *L); // imprime inversamente uma lista.
bool isEmpty(const List *L); // verifica se uma lista está vázia.
void addFirstList(List *L, int x); // adiciona um elemento ao início da lista.
void addLastList(List *L, int x); // adiciona um elemento ao final da lista.
int atBegin(const List *L); // retorna o primeiro elemento de uma lista.
int atEnd(const List *L); // retorna o último elemento de uma lista.
size_t listSize(const List *L); // retorna o tamanho de uma lista.
void removeList(List *L, int x); // remove o elemento de uma lista.
void removeBeginList(List *L); // remove o primeiro elemento de um lista.
void removeEndList(List *L); // remove o último elemento de uma lista.
int getElement(const List *L, int index); // retorna um element em uma dada posição da lista.
List* copyList(const List *L); // clonar uma lista.
List* mergeLists(const List *L, const List *J); // faz a junção de duas listas.

/*****************************************************************************/

#endif