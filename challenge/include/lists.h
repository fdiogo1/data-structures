#ifndef LISTAS_DESAFIO_H
#define LISTAS_DESAFIO_H

#include <stdbool.h>

/************************************************************************/

typedef struct _list List;
typedef struct _product Product;
typedef struct _node Node;

List* createList();
void deleteList(List **L);
void printList(const List *L);
bool isEmpty(const List *L);
void add(List *L, int serial, const char *name, float price);
Product* createProduct(int serial, const char *name, float price);
void printProduct(const Product *p);
void deleteProduct(Product **prod);
void deleteNode(Node **node);
Node* createNode(int serial, const char *name, float price);
void printSerialList(const List *L);
const Product* access(List *L, int serial); // ponteiro constante = vai ser uma referencia para o produto, mas não será possível realizar alterações na main
// ponteiro read-only


/************************************************************************/
#endif