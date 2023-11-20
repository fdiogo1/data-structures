#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "linked_list.h"

int main(void)
{  
    LinkedList *L = createLinkedList();
    //printf("Element in position 7: %d\n", getElementLinkedList(L, 7));
    
    addFirstLinkedList(L, 10);
    addLastLinkedList(L, 2);
    addLastLinkedList(L, 4);
    addLastLinkedList(L, 5);
    addLastLinkedList(L, 7);
    addLastLinkedList(L, 19);
    printLinkedList(L);

    

    addAfterLinkedList(L, 1, 102);
    printLinkedList(L);

    printf("The first element is: %d\n", firstElementLinkedList(L));

    destroyLinkedList(&L);
}